// Copyright 2021 David Desrochers (@beadybiddle)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "bd83.h"

const is31_led __flash g_is31_leds[DRIVER_1_LED_TOTAL] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |  R location
 *   |  |       G location
 *   |  |       |       B location
 *   |  |       |       | */
    {0, B_1,    A_1,    C_1},
    {1, B_1,    A_1,    C_1}
}