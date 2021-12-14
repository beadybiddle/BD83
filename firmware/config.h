// Copyright 2021 David Desrochers (@beadybiddle)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0xBE4D
#define PRODUCT_ID   0xBD83
#define DEVICE_VER   0x0001
#define MANUFACTURER beadybiddle
#define PRODUCT      bd83

/* matrix deets */
#define MATRIX_ROWS 6
#define MATRIX_COLS 15
#define MATRIX_ROW_PINS_MCU { F0, F1, F4, F5, F6, F7}
#define MATRIX_COL_PINS_MCP { A0, A1, A2, A3, A4, A5, A6, A7, B6, B5, B4, B3, B2, B1, B0}
#define MATRIX_ROW_PINS { F0, F1, F4, F5, F6, F7}
#define MATRIX_COL_PINS { A1, A1, A1, A1, A1, A1, A1, A1, A1, A1, A1, A1, A1, A1, A1} // just placeholder pins
#define MATRIX_IO_DELAY 30
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* double tap to sticky layer via TT */
#define TAPPING_TOGGLE 2

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// /* Bootmagic Lite key configuration */
// //#define BOOTMAGIC_LITE_ROW 0
// //#define BOOTMAGIC_LITE_COLUMN 0

#ifdef RGB_MATRIX_ENABLE
	/* RGB driving */
	#define DRIVER_COUNT 2
	#define DRIVER_1_LED_TOTAL 44
	#define DRIVER_2_LED_TOTAL 39
	#define DRIVER_LED_TOTAL (DRIVER_1_LED_TOTAL + DRIVER_2_LED_TOTAL)
	// 00 <-> GND
	// 01 <-> SCL
	// 10 <-> SDA
	// 11 <-> VCC
	// address as 0b101(ADDR2)(ADDR1)
	#define DRIVER_ADDR_1 0b1010000 // master
	#define DRIVER_ADDR_2 0b1010011 // slave 1
	#define DRIVER_SYNC_1 01 // sync clock master
	#define DRIVER_SYNC_2 10 // sync clock slave

	#define RGB_MATRIX_LED_PROCESS_LIMIT (DRIVER_LED_TOTAL + 4) / 5
	#define RGB_MATRIX_LED_FLUSH_LIMIT 16 // 60 Hz equivalent
	#define RGB_DISABLE_TIMEOUT 600000 // 10 minute timeout
	#define RGB_DISABLE_WHEN_USB_SUSPENDED
	#define RGBLIGHT_SLEEP // sleep when host sleeps
	#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 200 // to limit power consumption
	#define RGB_MATRIX_KEYPRESSES
	#define RGB_MATRIX_FRAMEBUFFER_EFFECTS

	/* RGB startup defaults */
	#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_REACTIVE
	#define RGB_MATRIX_STARTUP_HUE 90 // goldish
	#define RGB_MATRIX_STARTUP_SAT 225
	#define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS
	#define RGB_MATRIX_STARTUP_SPD 127

	// #define RGBLIGHT_HUE_STEP 10
	// #define RGBLIGHT_SAT_STEP 17
	// #define RGBLIGHT_VAL_STEP 17

	// TODO RGB COLOR LAYERS

	#define ENABLE_RGB_MATRIX_ALPHAS_MODS
	#define ENABLE_RGB_MATRIX_BREATHING
	#define ENABLE_RGB_MATRIX_CYCLE_ALL
	#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
	#define ENABLE_RGB_MATRIX_DIGITAL_RAIN
	#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
	#define ENABLE_RGB_MATRIX_SOLID_REACTIVE
	#define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
	#define ENABLE_RGB_MATRIX_SPLASH
	#define ENABLE_RGB_MATRIX_MULTISPLASH
	#define ENABLE_RGB_MATRIX_SOLID_SPLASH
	#define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#endif