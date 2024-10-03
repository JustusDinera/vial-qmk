#pragma once

#define VIAL_KEYBOARD_UID {0xAC, 0xAB, 0x13, 0x12, 0xAC, 0xAB, 0x13, 0x12}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 1 }

#define NUM_ENCODERS 2
#define NUM_DIRECTIONS 2

//#define NUM_ENCODERMAP_LAYERS ((uint8_t)(sizeof(encoder_map) / ((NUM_ENCODERS) * (2) * sizeof(uint16_t))))

// split keyboard support
#define MASTER_LEFT
//#define EE_HANDS
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000

#define DYNAMIC_KEYMAP_LAYER_COUNT 10
