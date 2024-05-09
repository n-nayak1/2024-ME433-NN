#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/pwm.h"

#define pin 15
#define wrap 20000
#define div 125
#define tmax .125
#define tmin .025

void initPWM() {
    gpio_set_function(pin, GPIO_FUNC_PWM); // Set the pin to be PWM
    uint slice_num = pwm_gpio_to_slice_num(pin); // Get PWM slice number
    pwm_set_clkdiv(slice_num, div); // divider
    pwm_set_wrap(slice_num, wrap);
    pwm_set_enabled(slice_num, true); // turn on the PWM
    pwm_set_gpio_level(pin, wrap / 2); // set the duty cycle to 50%
}

float lin_scale(int val, float old_min, float old_max, float new_min, float new_max) {
    float multiplier = (new_max - new_min) / (old_max - old_min);
    float scaled_val = (val - old_min) * multiplier + new_min;
    return scaled_val;
}

void set_angle(int theta) {
    float newPWM = lin_scale(theta, 0, 180, tmin, tmax) * wrap;
    pwm_set_gpio_level(pin, newPWM); // set the duty cycle
}

int main() {
    initPWM();
    set_angle(0);
    while(1) {
        for (int i = 0; i <= 180; i++) {
            set_angle(i);
            sleep_ms(10);
        }
        for (int j = 180; j >= 0; j--) {
            set_angle(j);
            sleep_ms(10);
        }
    }
}

