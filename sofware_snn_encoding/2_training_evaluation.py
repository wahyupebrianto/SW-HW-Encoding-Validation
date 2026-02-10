import torch
import torch.nn as nn
import torchvision
from torchvision import transforms
from torch.utils.data import DataLoader
import matplotlib.pyplot as plt
from tqdm import tqdm
from snn_utils import *

set_seed(42)
device = torch.device('cuda' if torch.cuda.is_available() else 'cpu')
print(f"Device: {device}")
# ## 2.1 Configuration
BATCH_SIZE = 128
NUM_STEPS = 25
BETA = 0.9
NUM_EPOCHS = 15
LEARNING_RATE = 0.001
HIDDEN_SIZES = [256, 128]
print(f"Configuration:")
print(f"  Architecture: 784 -> {' -> '.join(map(str, HIDDEN_SIZES))} -> 10")
print(f"  Purpose: Encoding validation vehicle")

# ## 2.2 Dataset
transform = transforms.Compose([transforms.ToTensor()])

train_dataset = torchvision.datasets.MNIST('./data', train=True, download=True, transform=transform)
test_dataset = torchvision.datasets.MNIST('./data', train=False, download=True, transform=transform)

train_loader = DataLoader(train_dataset, batch_size=BATCH_SIZE, shuffle=True, 
                         num_workers=4, pin_memory=True if device.type == 'cuda' else False)
test_loader = DataLoader(test_dataset, batch_size=BATCH_SIZE, shuffle=False,
                        num_workers=4, pin_memory=True if device.type == 'cuda' else False)
print(f"Full dataset: {len(train_dataset):,} train, {len(test_dataset):,} test")

# ## 2.3 Encoding Function
def encode_batch(images, encoding_type, num_steps=25):
    """Encode batch"""
    B, _, H, W = images.shape
    device = images.device
    encoded = torch.zeros(B, num_steps, H, W, device=device)
    
    for i in range(B):
        img = images[i].squeeze()
        
        if encoding_type == 'rate':
            encoded[i] = rate_encoding(img, num_steps)
        elif encoding_type == 'latency':
            encoded[i] = latency_encoding(img, num_steps)
        elif encoding_type == 'delta':
            encoded[i] = delta_modulation(img, num_steps)
    
    return encoded
# ## 2.4 Training Function
def train_snn(net, encoding_type, num_epochs=NUM_EPOCHS):
    """Train SNN - Focus on encoding, not network"""
    net = net.to(device)
    optimizer = torch.optim.Adam(net.parameters(), lr=LEARNING_RATE)
    criterion = nn.CrossEntropyLoss()
    
    history = {
        'loss': [], 
        'accuracy': [], 
        'encoding_sparsity': [], 
        'network_firing_rate': []
    }
    
    for epoch in range(num_epochs):
        net.train()
        epoch_loss, correct, total = 0, 0, 0
        
        # Encoding metrics
        epoch_input_spikes, epoch_input_neurons = 0, 0
        epoch_output_spikes, epoch_output_neurons = 0, 0
        
        pbar = tqdm(train_loader, desc=f'Epoch {epoch+1}/{num_epochs}')
        
        for images, labels in pbar:
            images, labels = images.to(device), labels.to(device)
            
            # Encode
            spike_data = encode_batch(images, encoding_type, NUM_STEPS)
            
            # Track encoding spikes
            epoch_input_spikes += spike_data.abs().sum().item()
            epoch_input_neurons += spike_data.numel()
            
            # Forward pass (FIXED - no fake energy calculation)
            optimizer.zero_grad()
            spk_rec = forward_pass(net, spike_data, device)
            
            # Loss
            output_rate = spk_rec.sum(0)
            loss = criterion(output_rate, labels)
            
            loss.backward()
            optimizer.step()
            
            # Metrics
            epoch_loss += loss.item()
            _, predicted = output_rate.max(1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()
            
            # Track output
            epoch_output_spikes += spk_rec.abs().sum().item()
            epoch_output_neurons += spk_rec.numel()
            
            pbar.set_postfix({
                'loss': f'{loss.item():.4f}', 
                'acc': f'{100*correct/total:.1f}%'
            })
        
        # Epoch summary
        avg_loss = epoch_loss / len(train_loader)
        accuracy = 100 * correct / total
        enc_sparsity = 100 * (1 - epoch_input_spikes / epoch_input_neurons)
        net_firing = 100 * epoch_output_spikes / epoch_output_neurons
        
        history['loss'].append(avg_loss)
        history['accuracy'].append(accuracy)
        history['encoding_sparsity'].append(enc_sparsity)
        history['network_firing_rate'].append(net_firing)
        
        print(f"Epoch {epoch+1}: Loss={avg_loss:.4f}, Acc={accuracy:.2f}%, "
              f"Enc_Sparsity={enc_sparsity:.2f}%, Net_Firing={net_firing:.2f}%")
    
    return net, history
# ## 2.5 Evaluation Function (FIXED)
def evaluate_model(net, encoding_type):
    """Evaluate encoding + classification"""
    net.eval()
    correct, total = 0, 0
    total_input_spikes, total_input_neurons = 0, 0
    total_output_spikes, total_output_neurons = 0, 0
    
    with torch.no_grad():
        for images, labels in tqdm(test_loader, desc=f'Testing {encoding_type}'):
            images, labels = images.to(device), labels.to(device)
            
            spike_data = encode_batch(images, encoding_type, NUM_STEPS)
            
            total_input_spikes += spike_data.abs().sum().item()
            total_input_neurons += spike_data.numel()
            
            spk_rec = forward_pass(net, spike_data, device)
            
            output_rate = spk_rec.sum(0)
            _, predicted = output_rate.max(1)
            
            total += labels.size(0)
            correct += (predicted == labels).sum().item()
            
            total_output_spikes += spk_rec.abs().sum().item()
            total_output_neurons += spk_rec.numel()
    
    accuracy = 100 * correct / total
    enc_sparsity = 100 * (1 - total_input_spikes / total_input_neurons)
    net_firing = 100 * total_output_spikes / total_output_neurons
    
    #Normalized efficiency metric
    normalized_spike_rate = total_input_spikes / total_input_neurons
    
    return {
        'accuracy': accuracy,
        'encoding_sparsity': enc_sparsity,
        'network_firing_rate': net_firing,
        'normalized_spike_rate': normalized_spike_rate
    }
# ## 2.6 Train Models
# Rate
print("\n" + "="*60)
print("TRAINING: RATE CODING")
print("="*60)
net_rate = SNN(hidden_sizes=HIDDEN_SIZES, beta=BETA)
net_rate, history_rate = train_snn(net_rate, 'rate')
torch.save(net_rate.state_dict(), 'snn_rate_full.pth')

# Latency
print("\n" + "="*60)
print("TRAINING: LATENCY CODING")
print("="*60)
net_latency = SNN(hidden_sizes=HIDDEN_SIZES, beta=BETA)
net_latency, history_latency = train_snn(net_latency, 'latency')
torch.save(net_latency.state_dict(), 'snn_latency_full.pth')

# Delta
print("\n" + "="*60)
print("TRAINING: DELTA MODULATION")
print("="*60)
net_delta = SNN(hidden_sizes=HIDDEN_SIZES, beta=BETA)
net_delta, history_delta = train_snn(net_delta, 'delta')
torch.save(net_delta.state_dict(), 'snn_delta_full.pth')

# ## 2.7 Training Curves
histories = {'Rate': history_rate, 'Latency': history_latency, 'Delta': history_delta}
colors = {'Rate': '#FF6B6B', 'Latency': '#4ECDC4', 'Delta': '#45B7D1'}
fig, axes = plt.subplots(2, 2, figsize=(14, 10))

# Loss
for name, hist in histories.items():
    axes[0, 0].plot(hist['loss'], marker='o', label=name, color=colors[name], linewidth=2)
axes[0, 0].set_xlabel('Epoch', fontweight='bold')
axes[0, 0].set_ylabel('Loss', fontweight='bold')
axes[0, 0].set_title('Training Loss', fontweight='bold', fontsize=14)
axes[0, 0].legend()
axes[0, 0].grid(alpha=0.3)

# Accuracy
for name, hist in histories.items():
    axes[0, 1].plot(hist['accuracy'], marker='s', label=name, color=colors[name], linewidth=2)
axes[0, 1].set_xlabel('Epoch', fontweight='bold')
axes[0, 1].set_ylabel('Accuracy (%)', fontweight='bold')
axes[0, 1].set_title('Training Accuracy', fontweight='bold', fontsize=14)
axes[0, 1].legend()
axes[0, 1].grid(alpha=0.3)

# Encoding Sparsity
for name, hist in histories.items():
    axes[1, 0].plot(hist['encoding_sparsity'], marker='^', label=name, color=colors[name], linewidth=2)
axes[1, 0].set_xlabel('Epoch', fontweight='bold')
axes[1, 0].set_ylabel('Sparsity (%)', fontweight='bold')
axes[1, 0].set_title('Encoding Sparsity (Higher=Better)', fontweight='bold', fontsize=14)
axes[1, 0].legend()
axes[1, 0].grid(alpha=0.3)

# Network Firing
for name, hist in histories.items():
    axes[1, 1].plot(hist['network_firing_rate'], marker='d', label=name, color=colors[name], linewidth=2)
axes[1, 1].set_xlabel('Epoch', fontweight='bold')
axes[1, 1].set_ylabel('Firing Rate (%)', fontweight='bold')
axes[1, 1].set_title('Network Firing Rate', fontweight='bold', fontsize=14)
axes[1, 1].legend()
axes[1, 1].grid(alpha=0.3)

plt.tight_layout()
plt.savefig('training_curves.png', dpi=150, bbox_inches='tight')
plt.show()
print("✓ Saved: training_curves.png")


# ## 2.8 Test Evaluation
print("\n" + "="*60)
print("TEST SET EVALUATION")
print("="*60)

results = {}
for name, net, enc_type in [('Rate', net_rate, 'rate'),
                             ('Latency', net_latency, 'latency'),
                             ('Delta', net_delta, 'delta')]:
    results[name] = evaluate_model(net, enc_type)
    print(f"\n{name}:")
    print(f"  Accuracy:          {results[name]['accuracy']:.2f}%")
    print(f"  Encoding Sparsity: {results[name]['encoding_sparsity']:.2f}%")
    print(f"  Norm. Spike Rate:  {results[name]['normalized_spike_rate']:.4f}")

print("\n" + "="*80)
print("SUMMARY TABLE")
print("="*80)
print(f"{'Encoding':<12} {'Accuracy (%)':<15} {'Sparsity (%)':<15} {'Norm. Rate':<12}")
print("-"*80)
for name, data in results.items():
    print(f"{name:<12} {data['accuracy']:<15.2f} {data['encoding_sparsity']:<15.2f} "
          f"{data['normalized_spike_rate']:<12.4f}")
print("="*80)

# ## 2.9 Final Visualization
fig, axes = plt.subplots(1, 3, figsize=(16, 5))

encodings = list(results.keys())
accuracies = [results[e]['accuracy'] for e in encodings]
sparsities = [results[e]['encoding_sparsity'] for e in encodings]
norm_rates = [results[e]['normalized_spike_rate'] for e in encodings]
colors_list = ['#FF6B6B', '#4ECDC4', '#45B7D1']

# Accuracy
bars = axes[0].bar(encodings, accuracies, color=colors_list, alpha=0.8, edgecolor='black')
axes[0].set_ylabel('Accuracy (%)', fontweight='bold')
axes[0].set_title('Classification Accuracy', fontweight='bold', fontsize=13)
axes[0].set_ylim([90, 100])
axes[0].grid(axis='y', alpha=0.3)
for bar in bars:
    h = bar.get_height()
    axes[0].text(bar.get_x() + bar.get_width()/2., h + 0.5,
                f'{h:.2f}%', ha='center', fontweight='bold')

# Sparsity
bars = axes[1].bar(encodings, sparsities, color=colors_list, alpha=0.8, edgecolor='black')
axes[1].set_ylabel('Sparsity (%)', fontweight='bold')
axes[1].set_title('Encoding Sparsity\n(Higher=Better)', fontweight='bold', fontsize=13)
axes[1].set_ylim([75, 100])
axes[1].grid(axis='y', alpha=0.3)
for bar in bars:
    h = bar.get_height()
    axes[1].text(bar.get_x() + bar.get_width()/2., h + 0.5,
                f'{h:.2f}%', ha='center', fontweight='bold')

# Normalized rate
bars = axes[2].bar(encodings, norm_rates, color=colors_list, alpha=0.8, edgecolor='black')
axes[2].set_ylabel('Norm. Spike Rate', fontweight='bold')
axes[2].set_title('Normalized Spike Rate\n(Lower=Better) ⭐', fontweight='bold', fontsize=13)
axes[2].grid(axis='y', alpha=0.3)
for bar in bars:
    h = bar.get_height()
    axes[2].text(bar.get_x() + bar.get_width()/2., h + 0.002,
                f'{h:.4f}', ha='center', fontweight='bold')

plt.tight_layout()
plt.savefig('final_results.png', dpi=150, bbox_inches='tight')
plt.show()
print("✓ Saved: final_results.png")