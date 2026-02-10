"""
generate_mnist_for_hls.py - Generate FULL MNIST test data (10,000 samples)
"""

import torch
import torchvision
from torchvision import transforms
import numpy as np

print("="*60)
print("MNIST DATA GENERATOR FOR HLS - FULL DATASET")
print("="*60)

# Load MNIST test set
transform = transforms.Compose([transforms.ToTensor()])
test_dataset = torchvision.datasets.MNIST(
    root='../data', train=False, download=True, transform=transform
)

print(f"\n✓ Loaded MNIST test set: {len(test_dataset)} images")

# Use ALL test images
NUM_IMAGES = len(test_dataset)  # 10,000

# Create binary data
binary_images = []
binary_labels = []

print("\n" + "="*60)
print(f"GENERATING {NUM_IMAGES} TEST IMAGES")
print("="*60)

for idx in range(NUM_IMAGES):
    img, label = test_dataset[idx]
    img_np = img.squeeze().numpy()  # [28, 28], values in [0, 1]
    
    # Flatten to 784 values
    img_flat = img_np.flatten()
    
    binary_images.extend(img_flat.astype(np.float32))
    binary_labels.append(label)
    
    if (idx + 1) % 1000 == 0:
        print(f"Processed {idx + 1}/{NUM_IMAGES} images...")

# Save binary files
binary_images_array = np.array(binary_images, dtype=np.float32)
binary_labels_array = np.array(binary_labels, dtype=np.int32)

binary_images_array.tofile('../data/mnist_test_images.dat')
binary_labels_array.tofile('../data/mnist_test_labels.dat')

print(f"\n✓ Saved: ../data/mnist_test_images.dat")
print(f"  Size: {len(binary_images_array)} float32 ({NUM_IMAGES} × 784)")
print(f"✓ Saved: ../data/mnist_test_labels.dat")
print(f"  Size: {len(binary_labels_array)} int32")

# Generate C header with constants only
with open('../src/mnist_data.h', 'w') as f:
    f.write("// Auto-generated MNIST test data header\n")
    f.write("// Full test set: 10,000 images\n\n")
    f.write("#ifndef MNIST_DATA_H\n")
    f.write("#define MNIST_DATA_H\n\n")
    f.write("#define NUM_TEST_IMAGES 10000\n")
    f.write("#define TEST_IMAGE_SIZE 784\n\n")
    f.write("// Data loaded from binary files:\n")
    f.write("//   - mnist_test_images.dat (10000 × 784 float32)\n")
    f.write("//   - mnist_test_labels.dat (10000 int32)\n\n")
    f.write("#endif // MNIST_DATA_H\n")

print(f"✓ Saved: ../src/mnist_data.h (header only)")

print("\n" + "="*60)
print("DATA GENERATION COMPLETE")
print("="*60)
print(f"\nGenerated {NUM_IMAGES} test images")
print("Files created:")
print("  1. mnist_test_images.dat - Binary image data")
print("  2. mnist_test_labels.dat - Binary labels")
print("  3. mnist_data.h          - C header with constants")
print("="*60)