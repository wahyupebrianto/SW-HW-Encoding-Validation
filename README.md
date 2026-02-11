## Spiking Neural Network Encoding for FPGA (MNIST)

This repo implements three spike encoders (rate, latency, delta-modulation) for MNIST, with a PyTorch/snnTorch SNN reference and matching C++/HLS implementations for FPGA (Zynq-7000).

---

### Project Structure

- `sofware_snn_encoding/`
  - `snn_utils.py`: rate / latency / delta encoders, SNN model, `forward_pass`.
  - `2_training_evaluation.py`: trains and evaluates SNN on MNIST for all encodings.
- `fpga_snn_encoding/`
  - `src/encoding.{h,cpp}`: HLS C++ encoders (rate, latency, delta).
  - `src/testbench_*.cpp`: C testbenches for each encoder.
  - `scripts/generate_mnist_for_hls_baru.py`: export MNIST to `.dat` + `mnist_data.h`.
  - `scripts/run_hls.tcl`: run C simulation and synthesis in Vivado/Vitis HLS.

---

### Requirements

- **Software**: Python 3.8+, `torch`, `torchvision`, `snntorch`, `numpy`, `matplotlib`
- **Hardware**: Vivado HLS or Vitis HLS (Zynq-7000 target)

Install Python deps (example):

```bash
pip install torch torchvision snntorch numpy matplotlib
```

---

### Run Software SNN Experiments

```bash
git clone https://github.com/wahyupebrianto/SW-HW-Encoding-Validation.git

cd sofware_snn_encoding
python 2_training_evaluation.py
```

This script:
- Downloads MNIST.
- Encodes images with rate, latency, and delta-modulation.
- Trains the SNN and prints accuracy and spike sparsity per encoding.

---

### Prepare Data for HLS

```bash
cd fpga_snn_encoding/scripts
python generate_mnist_for_hls_baru.py
```

Generates:
- `mnist_test_images.dat`, `mnist_test_labels.dat`
- `../src/mnist_data.h`

---

### Run HLS (Simulation + Synthesis)

From `fpga_snn_encoding/`:

```bash
cd fpga_snn_encoding
vitis_hls -f scripts/run_hls.tcl
# or: vivado_hls -f scripts/run_hls.tcl
```

The TCL script:
- Runs C simulation of rate/latency/delta encoders with MNIST data.
- Synthesizes RTL and reports resource usage and timing.

---

### Typical Use

1. Software: run `2_training_evaluation.py`, note accuracy and sparsity per encoding.
2. Hardware: export data, run HLS, inspect encoder correctness and resource reports.
3. Compare software vs hardware behavior and cost (accuracy, sparsity, LUT/FF/BRAM, frequency).

