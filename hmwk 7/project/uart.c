#include "uart.h"
#include "pico/stdlib.h"
#include "hardware/uart.h"
#include "hardware/irq.h"
#include "ssd1306.h"

static int chars_rxed = 0;

// RX interrupt handler

volatile int i = 0;
char m[100];

void on_uart_rx() {
    while (uart_is_readable(UART_ID)) {
        uint8_t ch = uart_getc(UART_ID);
        if (ch == '\r') {
            ssd1306_clear();
            drawMessage(10, 10, m);
            i = 0;
        } 
        else {
            m[i] = ch;
            i++;
        }
    }
}