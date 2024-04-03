#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define button_pin 15
#define LED_PIN 25

int main() {
    stdio_init_all();

    adc_init(); // init the adc module
    adc_gpio_init(26); // set ADC0 pin to be adc input instead of GPIO
    adc_select_input(0); // select to read from ADC0

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);

    gpio_init(button_pin);
    gpio_set_dir(button_pin, GPIO_IN);
    gpio_pull_up(button_pin);

    while (!stdio_usb_connected()) {
        sleep_ms(100);
    }
    printf("Start!\n");
 
    while(1) {
        int button_state = gpio_get(button_pin);
        if (button_state == 0) {
            gpio_put(LED_PIN, 0);
            int message;
            printf("Enter desired # of samples:\r\n");
            scanf("%d", &message);
            printf("# samples: %d\r\n",message);
            for (int i=0; i<message; i++) {
                uint16_t result = adc_read();
                float volts = (float)result * (float)3.3 / (float)4095;
                printf("voltage = %.3f\r\n", volts);
                sleep_ms(10);
            }
            gpio_put(LED_PIN, 1);
        }
    }
}