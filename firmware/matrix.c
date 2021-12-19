/*
 * Copyright 2013 Oleg Kostyuk <cub.uanic@gmail.com>
 *           2020 Pierre Chevalier <pierrechevalier83@gmail.com>
 *           2021 David Desrochers (@beadybiddle)
 * SPDX-License-Identifier: GPL-2.0-or-later
*/

#include QMK_KEYBOARD_H
#include "i2c_master.h"
#include "print.h"

extern i2c_status_t mcp23017_status;
#define I2C_TIMEOUT 1000
#define I2C_WRITE   0x00
#define I2C_READ    0x01

// | 0  | 1  | 0  | 0  | A2 | A1 | A0 |
// | 0  | 1  | 0  | 0  | 0  | 0  | 0  |
#define I2C_ADDR       0b0100000
#define I2C_ADDR_WRITE ((I2C_ADDR << 1) | I2C_WRITE)
#define I2C_ADDR_READ  ((I2C_ADDR << 1) | I2C_READ )
#define IODIRA         0x00 // i/o direction register
#define IODIRB         0x01
#define GPPUA          0x0C // GPIO pull-up resistor register
#define GPPUB          0x0D
#define GPIOA          0x12 // general purpose i/o port register (write modifies OLAT)
#define GPIOB          0x13
#define OLATA          0x14 // output latch register
#define OLATB          0x15

bool i2c_initialized = 0;
i2c_status_t mcp23017_status = I2C_ADDR;

uint8_t init_mcp23017(void) {
    print("starting init\n");
    mcp23017_status = I2C_ADDR;

    // I2C subsystem
    if (i2c_initialized == 0) {
        i2c_init(); // on pins D(1,0)
        i2c_initialized = true;
        wait_ms(I2C_TIMEOUT);
    }

    // set pin direction
    // unused/input : 1
    // driving      : 0
    uint8_t buf[] = {IODIRA, 0b11111111, 0b11111111};
    dprint("before transmit\n");
    mcp23017_status = i2c_transmit(I2C_ADDR_WRITE, buf, sizeof(buf), I2C_TIMEOUT);
    xprintf("after iodir transmit %x\n", mcp23017_status);
    if (!mcp23017_status) {
        // set pull-up
        uint8_t pullup_buf[] = {GPPUA, 0b11111111, 0b11111111};
        mcp23017_status = i2c_transmit(I2C_ADDR_WRITE, pullup_buf, sizeof(pullup_buf), I2C_TIMEOUT);
        uprintf("after pullup transmit %x\n", mcp23017_status);
    }
    return mcp23017_status;
}

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];  // debounced values

static matrix_row_t read_cols(uint8_t row);
static uint8_t      reverse_byte(uint8_t byte);
static void         unselect_rows(void);
static void         select_row(uint8_t row);

static uint8_t mcp23017_reset_loop;

void matrix_init_custom(void) {
    debug_enable = true;
    debug_matrix = true;
    dprint("matrix_init_custom\n");

    mcp23017_status = init_mcp23017();
    unselect_rows();

    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
    }
}

// needed for functioning after suspend/wakeup
void matrix_power_up(void) {
    mcp23017_status = init_mcp23017();

    unselect_rows();

    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
    }
}

// Reads and stores a row, returning
// whether a change occurred.
static inline bool store_matrix_row(matrix_row_t current_matrix[], uint8_t index) {
    matrix_row_t temp = read_cols(index);
    if (current_matrix[index] != temp) {
        current_matrix[index] = temp;
        return true;
    }
    return false;
}

bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    if (mcp23017_status) {  // if there was an error
        if (++mcp23017_reset_loop == 0) {
            dprint("trying to reset mcp23017\n");
            mcp23017_status = init_mcp23017();
            if (mcp23017_status) {
                dprint("expander? i hardly know 'er!\n");
            } else {
                dprint("expander attached\n");
            }
        }
    }

    bool changed = false;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);

        changed |= store_matrix_row(current_matrix, i);

        unselect_rows();
    }
    return changed;
}

static matrix_row_t read_cols(uint8_t row) {
    if (mcp23017_status) {  // if there was an error
        return 0;
    } else {
        uint8_t buf[] = {GPIOA};
        mcp23017_status = i2c_transmit(I2C_ADDR_WRITE, buf, sizeof(buf), I2C_TIMEOUT);
        uint8_t data[] = {0, 0}; // { GPIOB, GPIOA }
        if (!mcp23017_status) {
            mcp23017_status = i2c_receive(I2C_ADDR_READ, &data[1], sizeof(data[1]), I2C_TIMEOUT);
        }

        uint8_t buf2[] = {GPIOB};
        mcp23017_status = i2c_transmit(I2C_ADDR_WRITE, buf2, sizeof(buf2), I2C_TIMEOUT);
        if (!mcp23017_status) {
            mcp23017_status = i2c_receive(I2C_ADDR_READ, data, sizeof(data[0]), I2C_TIMEOUT);
        }

        uint16_t current_row_value = reverse_byte(~(data[0]) << 1);
        current_row_value <<= 8;
        current_row_value |= ~(data[1]) & 0x00FF;

        return current_row_value;
    }
}

static uint8_t reverse_byte(uint8_t byte) {
    uint8_t etyb = 0;
    for (int i = 0; i < 8; i++) {
        if (byte & (1 << i)) {
           etyb |= 1 << (7 - i);  
        }
    }
    return etyb;
}

static void unselect_rows(void) {
    pin_t matrix_row_pins_mcu[MATRIX_ROWS] = MATRIX_ROW_PINS_MCU;
    for (int pin_index = 0; pin_index < MATRIX_ROWS; pin_index++) {
        pin_t pin = matrix_row_pins_mcu[pin_index];
        setPinInput(pin);
        writePinLow(pin);
    }
}

static void select_row(uint8_t row) {
    pin_t matrix_row_pins_mcu[MATRIX_ROWS] = MATRIX_ROW_PINS_MCU;
    pin_t pin = matrix_row_pins_mcu[row];
    setPinOutput(pin);
    writePinLow(pin);
}
