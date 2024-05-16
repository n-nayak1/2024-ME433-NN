#include <stdio.h>
#include "hardware/i2c.h"
#include "pico/binary_info.h"
#include "pico/stdlib.h"

#define ADDR _u(0b1101000)

// config registers
#define CONFIG 0x1A
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C
#define PWR_MGMT_1 0x6B
#define PWR_MGMT_2 0x6C
// sensor data registers:
#define ACCEL_XOUT_H 0x3B
#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40
#define TEMP_OUT_H   0x41
#define TEMP_OUT_L   0x42
#define GYRO_XOUT_H  0x43
#define GYRO_XOUT_L  0x44
#define GYRO_YOUT_H  0x45
#define GYRO_YOUT_L  0x46
#define GYRO_ZOUT_H  0x47
#define GYRO_ZOUT_L  0x48
#define WHO_AM_I     0x75

void whoami(uint8_t* who) {
    uint8_t buf[1];
    uint8_t reg = WHO_AM_I;
    i2c_write_blocking(i2c_default, ADDR, &reg, 1, true);
    i2c_read_blocking(i2c_default, ADDR, buf, 1, false);
    *who = buf[0];
}

void chip_init() {
    // set PWR to 0x00
    uint8_t buf[2];
    buf[0] = PWR_MGMT_1;
    buf[1] = 0x00;
    i2c_write_blocking(i2c_default, ADDR, buf, 2, false);

    // set ACCEL to plus minus 2g
        // AFS_SEL = 0
        // buf = 0b00 < 3 = 0x00
    buf[0] = ACCEL_CONFIG;
    buf[1] = 0x00;
    i2c_write_blocking(i2c_default, ADDR, buf, 2, false);

    // set GYRO to plus minus 2000
        // FS_SEL = 3
        // buf = 0b11 << 3 = 0x18
    buf[0] = GYRO_CONFIG;
    buf[1] = 0x18;
    i2c_write_blocking(i2c_default, ADDR, buf, 2, false);
}

void read(uint8_t buf[6]) {
    uint8_t reg = ACCEL_XOUT_H;
    i2c_write_blocking(i2c_default, ADDR, &reg, 1, true);
    i2c_read_blocking(i2c_default, ADDR, buf, 6, false);
}


void convert(uint8_t buf[6], float new_vals[3]) {
    int16_t intermediate[3];
    for (int i = 0; i < 3; i++) {
        intermediate[i] = (int16_t)((buf[i * 2] << 8) | buf[(i * 2) + 1]);
    }
    for (int i = 0; i < 3; i++) {
        float val = (float)(intermediate[i])*.000061;
        if (val > 1 && val < 3) {
            val = 1;
        }
        else if (val > 3 && val < 4) {
            val = val - 4;
        }
        new_vals[i] = val;
    }
}

int main() {
    stdio_init_all();
    i2c_init(i2c_default, 400 * 1000);
    gpio_set_function(PICO_DEFAULT_I2C_SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(PICO_DEFAULT_I2C_SCL_PIN, GPIO_FUNC_I2C);

    chip_init();

    while (!stdio_usb_connected()) {
        sleep_ms(100);
    }
    printf("Start!\n");
    uint8_t who;
    whoami(&who);
    printf("he is 0x%02X\n", who);

    while (1) {
        uint8_t buf[6];
        float new_vals[3];
        read(buf);
        convert(buf, new_vals);
        
        printf("Ax = %f\n", new_vals[0]);
        printf("Ay = %f\n", new_vals[1]);
        printf("Az = %f\n\n", new_vals[2]);

        sleep_ms(1000);
    }
}
