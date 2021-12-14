// Copyright 2021 David Desrochers (@beadybiddle)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "bd83.h"

#ifdef RGB_MATRIX_ENABLE
	const is31_led __flash g_is31_leds[DRIVER_1_LED_TOTAL] = {
	/* Refer to IS31 manual for these locations
	 *   driver
	 *   |  R location
	 *   |  |       G location
	 *   |  |       |       B location
	 *   |  |       |       | */
	    { 0, B_1,  A_1,  C_1  },
	    { 0, B_2,  A_2,  C_2  },
	    { 0, B_3,  A_3,  C_3  },
	    { 0, B_4,  A_4,  C_4  },
	    { 0, B_5,  A_5,  C_5  },
	    { 0, B_6,  A_6,  C_6  },
	    { 0, B_7,  A_7,  C_7  },
	    { 0, B_8,  A_8,  C_8  },
	    { 0, B_9,  A_9,  C_9  },
	    { 0, B_10, A_10, C_10 },
	    { 0, B_11, A_11, C_11 },
	    { 0, B_12, A_12, C_12 },
	    { 0, B_13, A_13, C_13 },
	    { 0, B_14, A_14, C_14 },
	    { 0, B_15, A_15, C_15 },

	    { 0, E_1,  D_1,  F_1  },
	    { 0, E_2,  D_2,  F_2  },
	    { 0, E_3,  D_3,  F_3  },
	    { 0, E_4,  D_4,  F_4  },
	    { 0, E_5,  D_5,  F_5  },
	    { 0, E_6,  D_6,  F_6  },
	    { 0, E_7,  D_7,  F_7  },
	    { 0, E_8,  D_8,  F_8  },
	    { 0, E_9,  D_9,  F_9  },
	    { 0, E_10, D_10, F_10 },
	    { 0, E_11, D_11, F_11 },
	    { 0, E_12, D_12, F_12 },
	    { 0, E_13, D_13, F_13 },
	    { 0, E_14, D_14, F_14 },
	    { 0, E_15, D_15, F_15 },

	    { 0, H_1,  G_1,  I_1  },
	    { 0, H_2,  G_2,  I_2  },
	    { 0, H_3,  G_3,  I_3  },
	    { 0, H_4,  G_4,  I_4  },
	    { 0, H_5,  G_5,  I_5  },
	    { 0, H_6,  G_6,  I_6  },
	    { 0, H_7,  G_7,  I_7  },
	    { 0, H_8,  G_8,  I_8  },
	    { 0, H_9,  G_9,  I_9  },
	    { 0, H_10, G_10, I_10 },
	    { 0, H_11, G_11, I_11 },
	    { 0, H_12, G_12, I_12 },
	    { 0, H_13, G_13, I_13 },
	    { 0, H_14, G_14, I_14 },
	    // no col 15 led

	    // driver 2, u4
	    { 1, B_1,  A_1,  C_1  },
	    { 1, B_2,  A_2,  C_2  },
	    { 1, B_3,  A_3,  C_3  },
	    { 1, B_4,  A_4,  C_4  },
	    { 1, B_5,  A_5,  C_5  },
	    { 1, B_6,  A_6,  C_6  },
	    { 1, B_7,  A_7,  C_7  },
	    { 1, B_8,  A_8,  C_8  },
	    { 1, B_9,  A_9,  C_9  },
	    { 1, B_10, A_10, C_10 },
	    { 1, B_11, A_11, C_11 },
	    { 1, B_12, A_12, C_12 },
	    // no col 13 led
	    { 1, B_14, A_14, C_14 },
	    // no col 15 led

	    { 1, E_1,  D_1,  F_1  },
	    { 1, E_2,  D_2,  F_2  },
	    { 1, E_3,  D_3,  F_3  },
	    { 1, E_4,  D_4,  F_4  },
	    { 1, E_5,  D_5,  F_5  },
	    { 1, E_6,  D_6,  F_6  },
	    { 1, E_7,  D_7,  F_7  },
	    { 1, E_8,  D_8,  F_8  },
	    { 1, E_9,  D_9,  F_9  },
	    { 1, E_10, D_10, F_10 },
	    { 1, E_11, D_11, F_11 },
	    { 1, E_12, D_12, F_12 },
	    { 1, E_13, D_13, F_13 },
	    // no col 14 led
	    { 1, E_15, D_15, F_15 },

	    { 1, H_1,  G_1,  I_1  },
	    { 1, H_2,  G_2,  I_2  },
	    { 1, H_3,  G_3,  I_3  },
	    { 1, H_4,  G_4,  I_4  },
	    // no col 5 led
	    { 1, H_6,  G_6,  I_6  },
	    // no col 7 led
	    { 1, H_8,  G_8,  I_8  },
	    { 1, H_9,  G_9,  I_9  },
	    { 1, H_10, G_10, I_10 },
	    { 1, H_11, G_11, I_11 },
	    { 1, H_12, G_12, I_12 },
	    { 1, H_13, G_13, I_13 },
	    // no col 14 led
	    { 1, H_15, G_15, I_15 }
	};

	led_config_t g_led_config = {
	    {
	        // Key Matrix to LED Index (same as switch layout since LEDs are 1:1 per-key and mirrored)
	        {  0,  1,  2,  3,  4,      5,  6,      7,  8,  9, 10, 11, 12,     13,     14     },
	        { 15, 16, 17, 18, 19,     20, 21,     22, 23, 24, 25, 26, 27,     28,     29     },
	        { 30, 31, 32, 33, 34,     35, 36,     37, 38, 39, 40, 41, 42,     43,     NO_LED },
	        { 44, 45, 46, 47, 48,     49, 50,     51, 52, 53, 54, 55, NO_LED, 56,     NO_LED },
	        { 57, 58, 59, 60, 61,     62, 63,     64, 65, 66, 67, 68, 69,     NO_LED, 70     },
	        { 71, 72, 73, 74, NO_LED, 75, NO_LED, 76, 77, 78, 79, 80, 81,     NO_LED, 82     }
	    }, {
	        // LED Index to Physical Position ([0-224], [0-64])
	        { 0,  0   }, { 16,  0   }, { 32,  0   }, { 48,  0   }, { 64,  0   }, { 80,  0   }, { 96,  0   },  { 112,  0   }, { 128,  0   }, { 144,  0   }, { 160,  0   }, { 176,  0   }, { 192,  0   }, { 208,  0   }, { 224,  0   },
	        { 0, 12.8 }, { 16, 12.8 }, { 32, 12.8 }, { 48, 12.8 }, { 64, 12.8 }, { 80, 12.8 }, { 96, 12.8 },  { 112, 12.8 }, { 128, 12.8 }, { 144, 12.8 }, { 160, 12.8 }, { 176, 12.8 }, { 192, 12.8 }, { 208, 12.8 }, { 224, 12.8 },
	        { 4, 25.6 }, { 24, 25.6 }, { 40, 25.6 }, { 56, 25.6 }, { 72, 25.6 }, { 88, 25.6 }, { 104, 25.6 }, { 120, 25.6 }, { 136, 25.6 }, { 152, 25.6 }, { 168, 25.6 }, { 184, 25.6 }, { 200, 25.6 }, { 220, 25.6 },
	        { 6, 38.4 }, { 28, 38.4 }, { 44, 38.4 }, { 60, 38.4 }, { 76, 38.4 }, { 92, 38.4 }, { 108, 38.4 }, { 124, 38.4 }, { 140, 38.4 }, { 156, 38.4 }, { 172, 38.4 }, { 188, 38.4 },                { 214, 38.4 },
	        { 8, 51.2 }, { 32, 51.2 }, { 48, 51.2 }, { 64, 51.2 }, { 80, 51.2 }, { 96, 51.2 }, { 112, 51.2 }, { 128, 51.2 }, { 144, 51.2 }, { 160, 51.2 }, { 176, 51.2 }, { 192, 51.2 }, { 208, 51.2 },                { 224, 51.2 },
	        { 2, 64   }, { 22, 64   }, { 42, 64   }, { 68, 64   },               { 94, 64   },                { 120, 64   }, { 144, 64   }, { 160, 64   }, { 176, 64   }, { 192, 64   }, { 208, 64   },                { 224, 64   }
	    }, {
	        // LED Index to Flag
	          4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
	          4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
	           4 ,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,   4 ,
	            1 ,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,    4   ,
	            1  ,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,  4,
	           1,   1,   1,    4  ,   4,    4  ,  4,  1,  1,  4,  4,  4
	    }
	};
#endif