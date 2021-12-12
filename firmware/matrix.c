/*
 * TODO license
 */

/*
 * This code is adapted from the Ferris 0.1 and Ergodox EZ Glow
 */

#include QMK_KEYBOARD_H
#include "i2c_master.h"

extern i2c_status_t mcp23017_status;
#define I2C_TIMEOUT 100

/* 
 * I2C address:
 * http://ww1.microchip.com/downloads/en/devicedoc/20001952c.pdf
 * All address pins (A2..A0) of the mcp23017 are grounded by default using bridged solder jumpers
 * | 0  | 1  | 0  | 0  | A2 | A1 | A0 |
 */
#define I2C_ADDR       0b0100000
#define I2C_ADDR_WRITE ( (I2C_ADDR << 1) | I2C_WRITE )
#define I2C_ADDR_READ  ( (I2C_ADDR << 1) | I2C_READ  )
#define IODIRA         0x00 // i/o direction registers
#define IODIRB         0x01
#define GPPUA          0x0C // GPIO pull-up resistor registers
#define GPPUB          0x0D
#define GPIOA          0x12 // general purpose i/o port registers (write modifies OLAT)
#define GPIOB          0x13
#define OLATA          0x14 // output latch registers
#define OLATB          0x15

bool i2c_initialized = 0;
i2c_status_t mcp23017_status = I2C_ADDR;

uint8_t init_mcp23017(void) {
    print("starting init");
    mcp23017_status = I2C_ADDR;

    // I2C subsystem
    if (i2c_initialized == 0) {
        i2c_init();  // on pins D(1,0)
        i2c_initialized = true;
        wait_ms(I2C_TIMEOUT);
    }

    // - input/unused : 1
    // - driving      : 0
    uint8_t buf[] = {IODIRA, 0b11111111, 0b11111111}; // none of the expander GPIO is driving
    mcp23017_status = i2c_transmit(I2C_ADDR_WRITE, buf, sizeof(buf), I2C_TIMEOUT);
    if (!mcp23017_status) {
        uint8_t pullup_buf[] = {GPPUA, 0b11111111, 0b11111111}; // pullup all since all are input or unused
        mcp23017_status = i2c_transmit(I2C_ADDR_WRITE, pullup_buf, sizeof(pullup_buf), I2C_TIMEOUT);
    }
    return mcp23017_status;
}

// matrix state(1:on, 0:off)
static matrix_row_t matrix[MATRIX_ROWS]; // debounced values

static matrix_row_t read_cols(uint8_t row);
static void         init_cols(void);
static void         unselect_rows(void);
static void         select_row(uint8_t row);

static uint8_t mcp23017_reset_loop;

void matrix_init_custom(void) {
    mcp23017_status = init_mcp23017();

    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
    }
}

void matrix_power_up(void) {
    mcp23017_status = init_mcp23017();

    unselect_rows();
    init_cols();

    // initialize matrix state: all keys off
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
    }
}

// reads and stores a row, returning whether a change occurred.
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
                dprint("expander not responding\n");
            } else {
                dprint("expander attached\n");
            }
        }
    }

    bool changed = false;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        select_row(i);

        // TODO we don't need a 30us delay anymore, because selecting a
        // left-hand row requires more than 30us for i2c.

        changed |= store_matrix_row(current_matrix, i);

        unselect_rows();
    }
    return changed;
}

static void init_cols(void) {
    // init on mcp23017 not needed, already done as part of init_mcp23017()
    // init on mcu not needed because no cols on are MCU GPIO
}

// return value is ordered {GPx14, ..., GPx0} with 0s for depressed switches
// colN corresponds to GPxN
// array needs to be reversed because reasons TODO
// TODO write directly to current_row_value instead of using data middle man
static matrix_row_t read_cols(uint8_t row) {
    matrix_row_t current_row_value = 0;
    if (mcp23017_status) {  // if there was an error
        return 0;
    } else {
        // read cols on GPIOA (0-7)
        uint8_t buf[] = {GPIOA};
        mcp23017_status = i2c_transmit(I2C_ADDR_WRITE, buf, sizeof(buf), I2C_TIMEOUT);
        uint8_t data[] = {0};
        if (!mcp23017_status) {
            mcp23017_status = i2c_receive(I2C_ADDR_READ, data, sizeof(data), I2C_TIMEOUT);
            current_row_value |= ~(data[0]); // bitwise not is needed since switches are read low (0) if closed
        }

        // read cols on GPIOB (8-14)
        uint8_t buf2[] = {GPIOB};
        mcp23017_status = i2c_transmit(I2C_ADDR_WRITE, buf2, sizeof(buf2), I2C_TIMEOUT);
        uint8_t data2[] = {0};
        if (!mcp23017_status) {
            mcp23017_status = i2c_receive(I2C_ADDR_READ, data2, sizeof(data2), I2C_TIMEOUT);
            current_row_value |= ~(data2[0] << 8);
        }

        return current_row_value;
    }
}

static void unselect_rows(void) {
    pin_t matrix_row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
    for (int pin_index = 0; pin_index < MATRIX_ROWS; pin_index++) {
        pin_t pin = matrix_row_pins[pin_index];
        setPinInput(pin);
        writePinLow(pin);
    }
}

static void select_row(uint8_t row) {
    pin_t matrix_row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
    pin_t pin = matrix_row_pins[row];
    setPinOutput(pin);
    writePinLow(pin);
}