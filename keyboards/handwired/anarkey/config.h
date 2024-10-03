#pragma once

#define MASTER_LEFT // Store which side I am in EEPROM

#define NUM_ENCODERS 2

/* Keyboard matrix assignments */
#define MATRIX_COL_PINS {GP18, GP19, GP20, GP21, GP22, GP23}
#define MATRIX_ROW_PINS {GP5, GP6, GP7, GP8, GP9, GP10}

/* Encoders */
#define ENCODERS_PAD_A {GP11}
#define ENCODERS_PAD_B {GP12}

#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2000
#define SPLIT_USB_TIMEOUT_POLL 10
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000

/* Trackball */
/*
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP18
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP19
#define POINTING_DEVICE_CS_PIN GP10
#define ROTATIONAL_TRANSFORM_ANGLE -30 // Optional: Rotates the trackball
#define POINTING_DEVICE_INVERT_X // Optional: Inverts trackball X
*/
/* Reset */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP25
// This LED blinks when entering bootloader
