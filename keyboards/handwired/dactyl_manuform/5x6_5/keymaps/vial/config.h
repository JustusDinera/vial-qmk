/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x40, 0xFB, 0x4C, 0x76, 0x76, 0x13, 0x7F, 0xB2}

// Vial unlock
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

#define MIDI_ADVANCED

#define MASTER_LEFT

#define DEBOUNCE 5
#define ENCODERS_PAD_A { B2 }   //Port encoder left
#define ENCODERS_PAD_B { B4 }
#define ENCODERS_PAD_A_RIGHT { B4 } //Port encoder right
#define ENCODERS_PAD_B_RIGHT { B2 }

// reset behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET // Activates the double-tap behavior
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 200U // Timeout window in ms in which the double tap can occur.

#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000

// Vial features
#define DYNAMIC_KEYMAP_LAYER_COUNT 20
#define VIAL_KEY_OVERRIDE_ENTRIES 8
#define VIAL_TAP_DANCE_ENTRIES 8
#define VIAL_COMBO_ENTRIES 8
