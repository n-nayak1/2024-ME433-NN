#include "pico/stdlib.h"

#define LED_PIN 25

int main() {
    // Initialize the LED pin
    gpio_init(LED_PIN);
    // Configure the LED pin as an output
    gpio_set_dir(LED_PIN, GPIO_OUT);
    // Loop
    while (1) {
        // Set high
        gpio_put(LED_PIN, 1);
        // Sleep
        sleep_ms(200);
        // Set low
        gpio_put(LED_PIN, 0);
        // Sleep
        sleep_ms(200);
    }
}