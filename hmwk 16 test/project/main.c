#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"
#include "hardware/uart.h"
#include "hardware/irq.h"
#include "hardware/pwm.h"

#define LED_PIN 25
#define UART_TX_PIN 0
#define UART_RX_PIN 1
#define UART_ID uart0
#define BAUD_RATE 115200
#define DATA_BITS 8
#define STOP_BITS 1
#define PARITY    UART_PARITY_NONE

#define leftPWM 15
#define rightPWM 13
#define wrap 5000
#define div 1

void initPWM() {
    gpio_set_function(leftPWM, GPIO_FUNC_PWM); // Set the pin to be PWM
    uint left_slice_num = pwm_gpio_to_slice_num(leftPWM); // Get PWM slice number
    pwm_set_clkdiv(left_slice_num, div); // divider
    pwm_set_wrap(left_slice_num, wrap);
    pwm_set_enabled(left_slice_num, true); // turn on the PWM
    pwm_set_gpio_level(leftPWM, wrap / 2); // set the duty cycle to 50%

    gpio_set_function(rightPWM, GPIO_FUNC_PWM); // Set the pin to be PWM
    uint right_slice_num = pwm_gpio_to_slice_num(rightPWM); // Get PWM slice number
    pwm_set_clkdiv(right_slice_num, div); // divider
    pwm_set_wrap(right_slice_num, wrap);
    pwm_set_enabled(right_slice_num, true); // turn on the PWM
    pwm_set_gpio_level(rightPWM, wrap / 2); // set the duty cycle to 50%
}

void set_left_PWM(int duty_cycle) {
    float newPWM = ((float)duty_cycle / 100) * wrap;
    pwm_set_gpio_level(leftPWM, newPWM); // set the duty cycle
}

void set_right_PWM(int duty_cycle) {
    float newPWM = ((float)duty_cycle / 100) * wrap;
    pwm_set_gpio_level(rightPWM, newPWM); // set the duty cycle
}

void make_waveform_right(int arr[], int size, int start_value, int break_point, int end_value) {
    // Set the initial values up to the breakpoint
    for (int i = 0; i < break_point; i++) {
        arr[i] = start_value;
    }

    // Calculate the slope for the downward section
    float slope = (float)(start_value - end_value) / (size - 1 - break_point);

    // Set the values from the breakpoint to the end with a downward slope
    for (int i = break_point; i < size; i++) {
        arr[i] = start_value - (int)(slope * (i - break_point));
    }
}

// Function to create a waveform that starts at start_value, linearly increases to max_value at peak_index, and then stays at max_value
void make_waveform_left(int arr[], int size, int start_value, int max_value, int peak_index) {
    // Calculate the slope for the increasing section
    float slope = (float)(max_value - start_value) / peak_index;

    // Set the values up to the peak index
    for (int i = 0; i <= peak_index; i++) {
        arr[i] = start_value + (int)(slope * i);
    }

    // Set the values from the peak index to the end to the max value
    for (int i = peak_index + 1; i < size; i++) {
        arr[i] = max_value;
    }
}

// RX interrupt handler

volatile int i = 0;
char m[100];
volatile int number_received = 0;

void on_uart_rx() {
    while (uart_is_readable(UART_ID)) {
        uint8_t ch = uart_getc(UART_ID);
        if (ch == '\r' || ch == '\n') {
            m[i] = '\0'; // Null-terminate the string
            number_received = atoi(m); // Convert the string to an integer
            if (number_received >= 100) {
                number_received = 100;
            }
            else if (number_received <= 1) {
                number_received = 1;
            }
            printf("Number received: %d\n", number_received); // Print the received number for debugging
            i = 0; // Reset the index for the next input
        } 
        else {
            m[i] = ch;
            i++;
        }
    }
}

int main() {
    stdio_init_all();
    initPWM();

    // initialize I2C communication
    i2c_init(i2c_default, 100 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);

    // initialize onboard LED pin
    gpio_init(LED_PIN); 
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_put(LED_PIN, 1);

    // UART SETUP
    uart_init(UART_ID, 2400);

    // Set the TX and RX pins by using the function select on the GPIO
    // Set datasheet for more information on function select
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    // Actually, we want a different speed
    // The call will return the actual baud rate selected, which will be as close as
    // possible to that requested
    int __unused actual = uart_set_baudrate(UART_ID, BAUD_RATE);

    // Set UART flow control CTS/RTS, we don't want these, so turn them off
    uart_set_hw_flow(UART_ID, false, false);

    // Set our data format
    uart_set_format(UART_ID, DATA_BITS, STOP_BITS, PARITY);

    // Turn off FIFO's - we want to do this character by character
    uart_set_fifo_enabled(UART_ID, false);

    // Set up a RX interrupt
    // We need to set up the handler first
    // Select correct interrupt for the UART we are using
    int UART_IRQ = UART_ID == uart0 ? UART0_IRQ : UART1_IRQ;

    // And set up and enable the interrupt handlers
    irq_set_exclusive_handler(UART_IRQ, on_uart_rx);
    irq_set_enabled(UART_IRQ, true);

    // Now enable the UART to send interrupts - RX only
    uart_set_irq_enables(UART_ID, true, false);

    uart_puts(UART_ID, "Starting communication\r\n");

    int leftWaveform[100];
    int rightWaveform[100];
    make_waveform_right(rightWaveform, 100, 100, 60, 0);
    make_waveform_left(leftWaveform, 100, 0, 100, 40);


    while (1) {
        // do nothing
        printf("number is: %d\r\n", number_received);
        printf("left PWM is: %d\r\n", leftWaveform[number_received - 1]);
        printf("right PWM is: %d\r\n", rightWaveform[number_received - 1]);
        set_left_PWM(number_received);
        set_right_PWM(number_received);
    }
}
