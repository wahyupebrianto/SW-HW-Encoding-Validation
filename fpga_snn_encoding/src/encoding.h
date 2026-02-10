// * Use float [0, 1] instead of uint8_t [0, 255]

#ifndef ENCODING_H
#define ENCODING_H

#include <stdint.h>

// CONFIGURATION
#define IMG_HEIGHT 28
#define IMG_WIDTH  28
#define IMG_SIZE   (IMG_HEIGHT * IMG_WIDTH)  // 784 pixels
#define T 25  // Timesteps

// DATA TYPES
typedef float    pixel_t;   // CHANGED: Now [0, 1] to match software!
typedef int8_t   spike_t;   // Bipolar spikes: -1, 0, +1

// FUNCTION PROTOTYPES
void rate_encoding(
    pixel_t img[IMG_SIZE],
    spike_t spikes[T][IMG_SIZE],
    uint16_t seed
);

void latency_encoding(
    pixel_t img[IMG_SIZE],
    spike_t spikes[T][IMG_SIZE],
    uint16_t seed
);

void delta_encoding(
    pixel_t img[IMG_SIZE],
    spike_t spikes[T][IMG_SIZE],
    float threshold,
    float leak
);

uint32_t count_spikes(spike_t spikes[T][IMG_SIZE]);

#endif