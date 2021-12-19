// Copyright 2021 David Desrochers (@beadybiddle)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "print.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_beadybiddle(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,  KC_PSCR,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,
        TT(_FN), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_HOME, KC_UP,            KC_END,
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC,           KC_BSPC,          KC_SPC,  KC_DEL,  KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN,          KC_RGHT
    ),
    [_FN] = LAYOUT_beadybiddle(
        RESET,   RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, RGB_SPD, RGB_SPI, KC_MUTE, KC_VOLD, KC_VOLU,  KC_INS,
        _______, KC_CALC, KC_EQL,  KC_PSLS, KC_PAST, _______, _______, _______, _______, _______, _______, _______, _______, OUT_USB,  OUT_BT,
        _______, KC_P7,   KC_P8,   KC_P9,   KC_PMNS, _______, _______, KC_HOME, KC_UP,   KC_END,  _______, _______, _______, OUT_AUTO,
        _______, KC_P4,   KC_P5,   KC_P6,   KC_PPLS, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,          _______,
        _______, KC_P1,   KC_P2,   KC_P3,   KC_PDOT, _______, _______, _______, _______, _______, _______, KC_PGUP, _______,          KC_PGDN,
        _______, _______, KC_P0,   KC_PENT,          _______,          _______, _______, _______, KC_SLEP, _______, _______,          _______
    )
};

// runs once on keyboard init
void keyboard_post_init_user(void) {
  debug_enable=true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time);
#endif 
  return true;
}

// // runs on layer state change
// layer_state_t layer_state_set_user(layer_state_t state) {
// #ifdef CONSOLE_ENABLE
//     uprintf("layer %u", state);
// #endif 
// #ifdef RGB_MATRIX_ENABLE
//     case _BASE:
//         // TODO
//         break;
//     case _FN:
//         // TODO
//         break;
// #endif
//     return state;
// }