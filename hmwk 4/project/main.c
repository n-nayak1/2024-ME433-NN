#include <stdio.h>
#include <string.h>
#include <math.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/spi.h"

#define NUM_SAMPLES 200
#define NUM_SINE_CYCLES 8
#define NUM_TRIANGLE_CYCLES 4

static inline void cs_select() {
    asm volatile("nop \n nop \n nop");
    gpio_put(PICO_DEFAULT_SPI_CSN_PIN, 0);  // Active low
    asm volatile("nop \n nop \n nop");
}

static inline void cs_deselect() {
    asm volatile("nop \n nop \n nop");
    gpio_put(PICO_DEFAULT_SPI_CSN_PIN, 1);
    asm volatile("nop \n nop \n nop");
}

// channel A is 0 and B is 1
static void write_register1(int ch, int num) {
    uint8_t buf[2];
    uint8_t ch1 = (uint8_t)(ch);
    uint16_t num1 = (uint16_t)(num);
    uint8_t reg = (ch1 << 7) | (0b111 << 4) | (num1 >> 6);
    uint8_t data = (uint8_t)(num1 & (0b111111)) << 2;
    buf[0] = reg;  
    buf[1] = data;
    cs_select();
    spi_write_blocking(spi_default, buf, 2);
    cs_deselect();
    sleep_ms(10);
}

void generate_sine_wave(int *sine_wave, int num_samples, int num_cycles) {
    for (int i = 0; i < num_samples; i++) {
        double angle = (2.0 * M_PI * num_cycles * i) / num_samples;
        sine_wave[i] = (int)(512.0 * sin(angle) + 512.0);
    }
}

void generate_triangle_wave(int *triangle_wave, int num_samples, int num_cycles) {
    for (int i = 0; i < num_samples; i++) {
        double frac_cycle = (double)i / num_samples * num_cycles;
        double triangle_value = fmod(frac_cycle, 1.0);
        triangle_wave[i] = (int)(1023.0 * (2.0 * fabs(triangle_value - 0.5)));
    }
}

int main() {
    stdio_init_all();

    // This example will use SPI0 at 12 kHz
    spi_init(spi_default, 99999);  // initially set to 500k, eventually set to ~10 MHz (up to 20)
        // DO NOT NEED gpio_set_function(PICO_DEFAULT_SPI_RX_PIN, GPIO_FUNC_SPI);
    gpio_set_function(PICO_DEFAULT_SPI_SCK_PIN, GPIO_FUNC_SPI);
    gpio_set_function(PICO_DEFAULT_SPI_TX_PIN, GPIO_FUNC_SPI);
    

    gpio_init(PICO_DEFAULT_SPI_CSN_PIN);
    gpio_set_dir(PICO_DEFAULT_SPI_CSN_PIN, GPIO_OUT);
    gpio_put(PICO_DEFAULT_SPI_CSN_PIN, 1);

    int sine_wave[NUM_SAMPLES];
    int triangle_wave[NUM_SAMPLES];

    generate_sine_wave(sine_wave, NUM_SAMPLES, NUM_SINE_CYCLES);

    generate_triangle_wave(triangle_wave, NUM_SAMPLES, NUM_TRIANGLE_CYCLES);


    while (1) {
        for (int i = 0; i < 200; i++) {
            write_register1(0, sine_wave[i]);
            write_register1(1, triangle_wave[i]);
        }
    }
}
