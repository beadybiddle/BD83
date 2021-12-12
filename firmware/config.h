// Copyright 2021 David Desrochers (@beadybiddle)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0xFEED
#define PRODUCT_ID   0xBD83
#define DEVICE_VER   0x0001
#define MANUFACTURER beadybiddle
#define PRODUCT      bd83

/* key matrix size */
#define MATRIX_ROWS 6
#define MATRIX_COLS 15

// #define UNUSED_MCU 9
// #define UNUSED_MCP 1

/*
 * Keyboard Matrix Assignments
 * rows are on MCU
 * cols are on expander (MCP)
 */
#define MATRIX_ROW_PINS_MCU { F0, F1, F4, F5, F6, F7 }
// #define MATRIX_COL_PINS_MCP { A0, A1, A2, A3, A4, A5, A6, A7, B6, B5, B4, B3, B2, B1, B0 }
// #define UNUSED_PINS_MCU { B1, B2, B3, B6, B7, C7, D2, D3, D6 } // TODO figure out if BLE pins are "unused"
// #define UNUSED_PINS_MCP { B7 } // all but one of the 16 mcp23017 gpio are used for cols

#define DIODE_DIRECTION COL2ROW

// /* Bluetooth */
// #define AdafruitBLEResetPin TODO
// #define AdafruitBleCSPin TODO
// #define AdafruitBLEIRQPin TODO

// /* RGB driving */
// #define DRIVER_COUNT 2
// #define DRIVER_1_LED_TOTAL 44
// #define DRIVER_2_LED_TOTAL 39
// #define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)
// // 00 <-> GND
// // 01 <-> SCL
// // 10 <-> SDA
// // 11 <-> VCC
// // ADDR1 represents A1:A0 of the 7-bit address.
// // ADDR2 represents A3:A2 of the 7-bit address.
// // The result is: 0b101(ADDR2)(ADDR1)
// #define DRIVER_ADDR_1 0b1010000 // master
// #define DRIVER_ADDR_2 0b1010011 // slave 1
// #define DRIVER_SYNC_1 01 // sync clock master
// #define DRIVER_SYNC_2 10 // sync clock slave

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
//#define SOFT_SERIAL_PIN D0  // or D1, D2, D3, E6

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* triple tap to sticky layer via TT */
#define TAPPING_TOGGLE 2

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0

// #define RGB_MATRIX_KEYPRESSES
// #define RGB_MATRIX_FRAMEBUFFER_EFFECTS
// #define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5
// #define RGB_MATRIX_LED_FLUSH_LIMIT 16 // 60 Hz equivalent
// #define RGB_DISABLE_TIMEOUT 600000 // 10 minute timeout
// #define RGB_DISABLE_WHEN_USB_SUSPENDED // disable RGB when wireless
// #define RGBLIGHT_SLEEP // sleep when host sleeps
// #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // to limit power consumption

// /* RGB startup defaults */
// #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE
// #define RGB_MATRIX_STARTUP_HUE 90 // goldish
// #define RGB_MATRIX_STARTUP_SAT 225
// #define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
// #define RGB_MATRIX_STARTUP_SPD 127

// // #define RGBLIGHT_HUE_STEP 10
// // #define RGBLIGHT_SAT_STEP 17
// // #define RGBLIGHT_VAL_STEP 17

// // TODO RGB COLOR LAYERS

// /* disable ugly modes */
// #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
// #define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
// #define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
// #define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
// #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
// #define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
// #define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
// #define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
// #define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
// #define DISABLE_RGB_MATRIX_DUAL_BEACON
// #define DISABLE_RGB_MATRIX_RAINBOW_BEACON
// #define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
// #define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
// #define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS