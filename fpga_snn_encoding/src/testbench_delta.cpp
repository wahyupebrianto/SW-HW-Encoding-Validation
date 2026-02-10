// testbench_delta.cpp

#include "encoding.h"
#include "mnist_data.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>

using namespace std;

float calculate_sparsity(spike_t spikes[T][IMG_SIZE]) {
    int zero_count = 0;
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < IMG_SIZE; i++) {
            if (spikes[t][i] == 0) zero_count++;
        }
    }
    return (float)zero_count / (T * IMG_SIZE) * 100.0f;
}

float calculate_norm_rate(spike_t spikes[T][IMG_SIZE]) {
    int spike_count = 0;
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < IMG_SIZE; i++) {
            if (spikes[t][i] != 0) spike_count++;
        }
    }
    return (float)spike_count / (IMG_SIZE * T);
}

int main() {
    cout << "=======================================" << endl;
    cout << "DELTA ENCODING TEST - 10K IMAGES" << endl;
    cout << "=======================================" << endl;
    
    //ifstream img_file("../data/mnist_test_images.dat", ios::binary);
    ifstream img_file("E:/1_Research/Neuromorphic/NEUROMORPHIC/First_research/fpga_snn_encoding/data/mnist_test_images.dat",
        ios::binary);
    if (!img_file) {
        cerr << "ERROR: Cannot open mnist_test_images.dat" << endl;
        return 1;
    }
    
    pixel_t img[IMG_SIZE];
    spike_t spikes[T][IMG_SIZE];
    
    double sum_sparsity = 0.0;
    double sum_norm_rate = 0.0;
    float threshold = 0.05f;
    float leak = 0.95f;
    
    cout << "Processing images..." << endl;
    
    for (int idx = 0; idx < NUM_TEST_IMAGES; idx++) {
        img_file.read(reinterpret_cast<char*>(img), IMG_SIZE * sizeof(float));
        if (img_file.fail()) break;
        
        delta_encoding(img, spikes, threshold, leak);
        
        sum_sparsity += calculate_sparsity(spikes);
        sum_norm_rate += calculate_norm_rate(spikes);
        
        if ((idx + 1) % 1000 == 0) {
            cout << "  " << (idx + 1) << "/10000" << endl;
        }
    }
    
    img_file.close();
    
    float avg_sparsity = sum_sparsity / NUM_TEST_IMAGES;
    float avg_norm = sum_norm_rate / NUM_TEST_IMAGES;
    
    cout << "\n=======================================" << endl;
    cout << "DELTA ENCODING RESULTS" << endl;
    cout << "=======================================" << endl;
    printf("Sparsity:    %.2f%%\n", avg_sparsity);
    printf("Norm Rate:   %.4f\n", avg_norm);
    
    // Validation real results in software
    const float SW_SPARSITY = 81.19;
    const float SW_NORM = 0.1881;
    float err_sp = fabs(avg_sparsity - SW_SPARSITY);
    float err_nr = fabs(avg_norm - SW_NORM);
    
    printf("\nSoftware:    %.2f%% / %.4f\n", SW_SPARSITY, SW_NORM);
    printf("Error:       %.2f%% / %.4f\n", err_sp, err_nr);
    
    if (err_sp < 10.0f && err_nr < 0.05f) {
        cout << "\n✓ PASS - Acceptable deviation" << endl;
    } else {
        cout << "\n⚠ WARNING - High deviation" << endl;
    }
    
    return 0;
}