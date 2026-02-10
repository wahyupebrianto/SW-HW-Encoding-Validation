import torch
import torch.nn as nn
import snntorch as snn
import numpy as np

def set_seed(seed=42):
    """Set all random seeds"""
    torch.manual_seed(seed)
    torch.cuda.manual_seed_all(seed)
    np.random.seed(seed)
    import random
    random.seed(seed)
    torch.backends.cudnn.deterministic = True
    torch.backends.cudnn.benchmark = False

def rate_encoding(img, T=25):
    """Rate coding - vectorized"""
    img = img.clamp(0, 1)
    return (torch.rand(T, *img.shape, device=img.device) < img ).float()


def latency_encoding(img, T=25, sigma=1.5):
    """Latency coding - time-to-first-spike with jitter"""
    img = img.clamp(0, 1)
    mu = (1 - img) * (T - 1)
    noise = torch.randn_like(mu) * sigma
    lat = (mu + noise).round().clamp(0, T - 1).long()
    
    spikes = torch.zeros(T, *img.shape, device=img.device)
    spikes.scatter_(0, lat.unsqueeze(0), 1.0)
    return spikes


def delta_modulation(img, T=25, thr=0.05, leak=0.95):
    """Delta modulation - sigma-delta ADC inspired"""
    img = img.clamp(0, 1)
    device = img.device
    
    spikes = torch.zeros(T, *img.shape, device=device)
    integrator = torch.zeros_like(img)
    
    for t in range(T):
        integrator = leak * integrator + img
        pos_mask = integrator > thr
        neg_mask = integrator < -thr
        spikes[t] = pos_mask.float() - neg_mask.float()
        integrator -= thr * spikes[t]
    
    return spikes



class SNN(nn.Module):
    def __init__(self, hidden_sizes=[256, 128], beta=0.9):
        super().__init__()
        
        layers = []
        lif_layers = []
        
        input_size = 784
        for h_size in hidden_sizes:
            layers.append(nn.Linear(input_size, h_size))
            lif_layers.append(snn.Leaky(beta=beta))
            input_size = h_size
        
        layers.append(nn.Linear(input_size, 10))
        lif_layers.append(snn.Leaky(beta=beta))
        
        self.layers = nn.ModuleList(layers)
        self.lif_layers = nn.ModuleList(lif_layers)
        self.n_layers = len(layers)
    
    def forward(self, x, mem_states):
        """Single timestep forward"""
        x = x.view(x.size(0), -1)
        
        new_mem_states = []
        for i, (fc, lif) in enumerate(zip(self.layers, self.lif_layers)):
            cur = fc(x)
            x, mem = lif(cur, mem_states[i])
            new_mem_states.append(mem)
        
        return x, new_mem_states
    
    def init_mem(self, batch_size, device):
        """Initialize membrane potentials"""
        return [lif.init_leaky() for lif in self.lif_layers]


def forward_pass(net, spike_data, device):
    """
    Forward pass for classification.
    Returns output spikes only (no fake energy stats).
    """
    B, T, H, W = spike_data.shape
    
    mem_states = net.init_mem(B, device)
    spk_rec = []
    
    for t in range(T):
        spk, mem_states = net(spike_data[:, t], mem_states)
        spk_rec.append(spk)
    
    return torch.stack(spk_rec)  # [T, B, 10]