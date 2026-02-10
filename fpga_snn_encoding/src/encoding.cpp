
#include "encoding.h"
#include <math.h>

// LFSR Random Number Generator (returns [0, 1])
static uint32_t lfsr_state_global = 12345;

static inline float lfsr_rand_float() {
    // 32-bit Galois LFSR
    uint32_t bit = ((lfsr_state_global >> 0) ^ (lfsr_state_global >> 2) ^ 
                    (lfsr_state_global >> 3) ^ (lfsr_state_global >> 5)) & 1;
    lfsr_state_global = (lfsr_state_global >> 1) | (bit << 31);
    
    // Return [0, 1] float
    return (float)lfsr_state_global / (float)0xFFFFFFFF;
}

// Box-Muller transform for Gaussian random
static inline float gaussian_rand(float sigma) {
    // Generate two uniform random numbers
    float u1 = lfsr_rand_float();
    float u2 = lfsr_rand_float();
    
    // Avoid log(0)
    if (u1 < 1e-10f) u1 = 1e-10f;
    
    // Box-Muller transform
    float z0 = sqrtf(-2.0f * logf(u1)) * cosf(2.0f * 3.14159265f * u2);
    
    return z0 * sigma;
}

// 1. RATE ENCODING - Now matches software exactly
void rate_encoding(
    pixel_t img[IMG_SIZE],      // [0, 1] float
    spike_t spikes[T][IMG_SIZE],
    uint16_t seed
) {
    #pragma HLS INTERFACE s_axilite port=return
    #pragma HLS INTERFACE m_axi depth=IMG_SIZE port=img offset=slave
    #pragma HLS INTERFACE m_axi depth=T*IMG_SIZE port=spikes offset=slave
    #pragma HLS INTERFACE s_axilite port=seed
    
    lfsr_state_global = (uint32_t)seed;
    
    TIME_LOOP: for (int t = 0; t < T; t++) {
        PIXEL_LOOP: for (int i = 0; i < IMG_SIZE; i++) {
            #pragma HLS PIPELINE II=1
            
            float rand_val = lfsr_rand_float();  // [0, 1]
            float intensity = img[i];             // [0, 1]
            
            // Matches software: rand() < img
            spikes[t][i] = (rand_val < intensity) ? 1 : 0;
        }
    }
}

// 2. LATENCY ENCODING
void latency_encoding(
    pixel_t img[IMG_SIZE],      // [0, 1] float
    spike_t spikes[T][IMG_SIZE],
    uint16_t seed
) {
    #pragma HLS INTERFACE s_axilite port=return
    #pragma HLS INTERFACE m_axi depth=IMG_SIZE port=img offset=slave
    #pragma HLS INTERFACE m_axi depth=T*IMG_SIZE port=spikes offset=slave
    #pragma HLS INTERFACE s_axilite port=seed
    
    // Initialize
    INIT_T: for (int t = 0; t < T; t++) {
        INIT_I: for (int i = 0; i < IMG_SIZE; i++) {
            #pragma HLS PIPELINE II=1
            spikes[t][i] = 0;
        }
    }
    
    lfsr_state_global = (uint32_t)seed;
    
    PIXEL_LOOP: for (int i = 0; i < IMG_SIZE; i++) {
        #pragma HLS PIPELINE II=3
        
        float intensity = img[i];  // [0, 1]
        
        // Matches software: mu = (1 - img) * (T - 1)
        float mu = (1.0f - intensity) * (float)(T - 1);
        
        // Matches software: Gaussian jitter with sigma=1.5
        float noise = gaussian_rand(1.5f);
        
        float latency_float = mu + noise;
        
        // Round and clamp
        int spike_time = (int)(latency_float + 0.5f);
        if (spike_time < 0) spike_time = 0;
        if (spike_time >= T) spike_time = T - 1;
        
        spikes[spike_time][i] = 1;
    }
}

// 3. DELTA ENCODING
void delta_encoding(
    pixel_t img[IMG_SIZE],      // [0, 1] float
    spike_t spikes[T][IMG_SIZE],
    float threshold,             // 0.05 (same as software)
    float leak                   // 0.95 (same as software)
) {
    #pragma HLS INTERFACE s_axilite port=return
    #pragma HLS INTERFACE m_axi depth=IMG_SIZE port=img offset=slave
    #pragma HLS INTERFACE m_axi depth=T*IMG_SIZE port=spikes offset=slave
    #pragma HLS INTERFACE s_axilite port=threshold
    #pragma HLS INTERFACE s_axilite port=leak
    
    // Integrator state (float to match software)
    float integrator[IMG_SIZE];
    #pragma HLS ARRAY_PARTITION variable=integrator cyclic factor=8
    
    INIT_LOOP: for (int i = 0; i < IMG_SIZE; i++) {
        #pragma HLS PIPELINE II=1
        integrator[i] = 0.0f;
    }
    
    TIME_LOOP: for (int t = 0; t < T; t++) {
        PIXEL_LOOP: for (int i = 0; i < IMG_SIZE; i++) {
            #pragma HLS PIPELINE II=3
            
            // Matches software: integrator = leak * integrator + img
            integrator[i] = leak * integrator[i] + img[i];
            
            // Matches software: bipolar threshold detection
            if (integrator[i] > threshold) {
                spikes[t][i] = 1;
                integrator[i] -= threshold;
            }
            else if (integrator[i] < -threshold) {
                spikes[t][i] = -1;
                integrator[i] += threshold;
            }
            else {
                spikes[t][i] = 0;
            }
        }
    }
}

// 4. UTILITY
uint32_t count_spikes(spike_t spikes[T][IMG_SIZE]) {
    #pragma HLS INLINE off
    
    uint32_t count = 0;
    
    for (int t = 0; t < T; t++) {
        for (int i = 0; i < IMG_SIZE; i++) {
            #pragma HLS PIPELINE II=1
            if (spikes[t][i] != 0) count++;
        }
    }
    
    return count;
}