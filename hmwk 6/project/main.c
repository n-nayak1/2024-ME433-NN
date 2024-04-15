#include <stdio.h>
#include <string.h>
#include <math.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "ssd1306.h"
#include "hardware/adc.h"

#define LED_PIN 25
#define ADC_PIN 26

int main() {
    stdio_init_all();

    // initialize I2C communication
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);

    ssd1306_setup(); // initialize display

    // initialize ADC
    adc_init();  
    adc_gpio_init(ADC_PIN); 
    adc_select_input(0); 

    // initialize onboard LED pin
    gpio_init(LED_PIN); 
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);

    char adc[50];
    char fps[50];

    while (1) {
        // do nothing
        unsigned int start = to_us_since_boot(get_absolute_time());

        uint16_t result = adc_read();
        float volts = (float)result * (float)3.3 / (float)4095;
        sprintf(adc, "voltage = %.3f", volts);
        drawMessage(10,10,adc);

        unsigned int stop = to_us_since_boot(get_absolute_time());

        unsigned int t = stop - start;
        sprintf(fps, "FPS = %f", 1000000.0/t);
        drawMessage(10, 20, fps);
        sleep_ms(100);
    }
}
