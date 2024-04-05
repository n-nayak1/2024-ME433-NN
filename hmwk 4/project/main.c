#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/adc.h"

#define button_pin 15
#define LED_PIN 25

void gpio_set_function(uint gpio, enum gpio_function fn) {
    check_gpio_param(gpio);
    invalid_params_if(GPIO, ((uint32_t)fn << IO_BANK0_GPIO0_CTRL_FUNCSEL_LSB) & ~IO_BANK0_GPIO0_CTRL_FUNCSEL_BITS);
    // Set input enable on, output disable off
    hw_write_masked(&padsbank0_hw->io[gpio],
                   PADS_BANK0_GPIO0_IE_BITS,
                   PADS_BANK0_GPIO0_IE_BITS | PADS_BANK0_GPIO0_OD_BITS
    );
    // Zero all fields apart from fsel; we want this IO to do what the peripheral tells it.
    // This doesn't affect e.g. pullup/pulldown, as these are in pad controls.
    iobank0_hw->io[gpio].ctrl = fn << IO_BANK0_GPIO0_CTRL_FUNCSEL_LSB;
}

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