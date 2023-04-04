/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


// Vial
#define VIAL_KEYBOARD_UID {0x3B, 0x6B, 0xA0, 0x29, 0x80, 0x56, 0xED, 0xD1}
#define VIAL_UNLOCK_COMBO_ROWS {0, 2}
#define VIAL_UNLOCK_COMBO_COLS {0, 5}
#define DYNAMIC_KEYMAP_LAYER_COUNT 6
#define TAPPING_TERM 180
#define IGNORE_MOD_TAP_INTERRUPT

// LED Matrix
#define RGB_NUM 54

// LED Effects
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP

// Layers
#define LAYER_STATE_8BIT

//#define USE_MATRIX_I2C
#ifdef KEYBOARD_crkbd_rev1_legacy
#    undef USE_I2C
#    define USE_SERIAL
#endif

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS


// Rotary Encoder
#define DEBOUNCE 5
#define ENCODERS_PAD_A { B4 }   //Port encoder left
#define ENCODERS_PAD_B { B2 }
#define ENCODERS_PAD_A_RIGHT { B4 } //Port encoder right
#define ENCODERS_PAD_B_RIGHT { B2 }
// split keyboard support
#define SPLIT_USB_DETECT

#define USE_SERIAL_PD2
#ifdef RGBLIGHT_ENABLE
#    undef RGBLED_NUM
#    define RGBLIGHT_ANIMATIONS
#    define RGBLED_NUM 54
#    undef RGBLED_SPLIT
#    define RGBLED_SPLIT \
        { 27, 27 }
#    define RGBLIGHT_LIMIT_VAL 120
#    define RGBLIGHT_HUE_STEP  10
#    define RGBLIGHT_SAT_STEP  17
#    define RGBLIGHT_VAL_STEP  17
#endif

//#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
