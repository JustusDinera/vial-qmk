/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
butq WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define INC_VAL 10

// Layer defines
#define L_BASE 0
#define L_NUMBER 2
#define L_SYMBOL 4
#define L_FUNCTION 8
#define L_MIDI (1 << 18)
#define L_OBS (1 << 7)
#define L_GAME (1 << 12)
//#define L_MIDI (1 << 18)

typedef union {
  uint32_t raw;
  struct {
    uint8_t h;
    uint8_t s;
    uint8_t v;
    uint8_t reserved;
  }hsv;
} user_config_t;

uint8_t mainKeys[] = {0xff,0x0,0};
uint8_t standardMode;
user_config_t underglow;


// add user keycodesb
enum user_keycode {
    OBS_ss = USER00,
    OBS_pa,
    MUTE,
    cam,
    USATI,
    USATD,
    UHUEI,
    UHUED,
    UVALI,
    UVALD
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][2][2] = {
    [0] = {
        ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
        ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)
    },
    [1] = {
        ENCODER_CCW_CW(RGB_HUD, RGB_HUI),
        ENCODER_CCW_CW(RGB_SAD, RGB_SAI)
    },
    [2] = {
        ENCODER_CCW_CW(RGB_VAD, RGB_VAI),
        ENCODER_CCW_CW(RGB_SPD, RGB_SPI)
    },
    [3] = {
        ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),
        ENCODER_CCW_CW(KC_RIGHT, KC_LEFT)
    }
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          QK_BOOT, FN_MO13,  KC_SPC,     KC_ENT, FN_MO23, KC_LGUI
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`------------- -------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

// helper to write a uint8 to OLED
static void oled_write_uint8(uint8_t number, bool invert){
    char tempStr[] = {'\0', '\0', '\0', '\0'};

    itoa(number, tempStr, 10);
    oled_write(tempStr, invert);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    oled_clear();
    if (default_layer_state == L_BASE || default_layer_state == 1)
    {
        switch (state) {
        case L_BASE:
        case 1:
            rgb_matrix_mode(standardMode);
            break;
        // function layer
        case L_FUNCTION:
        case L_FUNCTION|L_NUMBER:
        case L_FUNCTION|L_SYMBOL:
        case L_FUNCTION|L_NUMBER|L_SYMBOL:
            rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_funcLayer);
    #ifdef CONSOLE_ENABLE
            print("layer state: state function\n");
            uprintf("last matrix mode: %lu\n", state);
    #endif
            break;
        default: //  for any other layers, or the default layer
    #ifdef CONSOLE_ENABLE
            print("layer state: state default\n");
            uprintf("last matrix mode:    %lu\n", state);
            uprintf("current matrix mode: %u\n", rgb_matrix_get_mode());
    #endif
            //rgb_matrix_mode(standardMode);
            break;
        }
    }
  return state;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    oled_clear();
    switch (state) {
    case L_BASE:
    case 1:
        rgb_matrix_mode(standardMode);
        break;
    case L_MIDI:
        //state = rgb_matrix_get_mode();
        rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_piano);
#ifdef CONSOLE_ENABLE
        print("default layer state: state midi\n");
        uprintf("last matrix mode: %lu\n", state);
#endif
        break;
    case L_OBS:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_obsLayer);
#ifdef CONSOLE_ENABLE
        print("default layer state: state OBS\n");
        uprintf("last matrix mode: %lu\n", state);
#endif
        break;
    case L_FUNCTION:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_funcLayer);
#ifdef CONSOLE_ENABLE
        print("default layer state: state function\n");
        uprintf("last matrix mode: %lu\n", state);
#endif
        break;
    case L_GAME:
        rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_gameLayer);
#ifdef CONSOLE_ENABLE
        print("default layer state: state game\n");
        uprintf("last matrix mode: %lu\n", state);
#endif
        break;
    default: //  for any other layers, or the default layer
#ifdef CONSOLE_ENABLE
        print("default layer state: state default\n");
        uprintf("last matrix mode:    %lu\n", state);
        uprintf("current matrix mode: %u\n", rgb_matrix_get_mode());
#endif
        //if (state != rgb_matrix_get_mode())
        //rgb_matrix_mode(standardMode);
        break;
    }
  return state;
}

#ifdef OLED_ENABLE
#include <stdio.h>
#include "raw_hid.h"
#include "print.h"

#include "string.h"

// What the screen look like if no connection is established. This shows a "No connection" message
char current_screen[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 56, 68,  4,  4,  4,  4,  4, 68, 56,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,  0, 48,248,240,224,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 78, 81, 81, 81, 81, 81,206,  0,  0,  0,  0,  0,  0,  0,  0,136,200,200,136,168,168,152,152,136,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,129,195,  6, 12,156, 56,112,195,135,255,254,252,192,  3, 31,255,254,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 20, 20, 20, 20, 20, 20,243,  0,  0,  0,  0,  0,  0,  0,  0, 28, 34, 34, 34, 34, 34, 28,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  0,  8, 31, 31, 14,192,241,243,103, 15, 31, 48,120,255,255, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 25, 25,  1,  1,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  0, 14, 31, 15,  6,  0,  1,  3,  6,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
};

/*
 * Payload structure. Index identifies where on the OLED to write to.
 * Report IDs aren't used but cause a pain (not writing, occasionally being stripped off etc.)
 * For this reason, the first byte should always be "1"
 * |  1  | 2 | 3 --------- 32 |
 * |REPID|IDX|     DATA       |
 */
static const int PAYLOAD_SIZE = 32;

void raw_hid_receive_kb(uint8_t *data, uint8_t length) {
    // TODO: Read report ID to determine the OLED screen to write to
    //raw_hid_send(data, length);
    //uint8_t* index = &data[1];
    //mainKeys[0] = data[3];
    //mainKeys[1] = data[3];
    //mainKeys[2] = data[3];
    //memcpy(&current_screen[(PAYLOAD_SIZE - 2) * (*index)], &data[2], (PAYLOAD_SIZE - 2));
#ifdef CONSOLE_ENABLE
    uprintf("raw hid data: ");
    for (uint8_t i = 0; i < length; i++){
        uprintf("%x", data[i]);
    }
    uprintf("\n");
#endif
}

/*
static void render_oled(void) {
    oled_write_raw(current_screen, sizeof(current_screen));
}
*/

oled_rotation_t oled_init_user(oled_rotation_t rotation) {

  if (!is_keyboard_master()) {
    return OLED_ROTATION_270;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {

    oled_write_P(PSTR("Layer: "), false);

    switch (default_layer_state)
    {
        case L_BASE:
        case 1:
            switch (layer_state) {
                case L_BASE:
                    oled_write_ln_P(PSTR("Home          "), false);
                    break;
                case L_NUMBER:
                    oled_write_ln_P(PSTR("Number        "), false);
                    break;
                case L_SYMBOL:
                    oled_write_ln_P(PSTR("Symbol        "), false);
                    break;
                case L_FUNCTION:
                case L_FUNCTION|L_NUMBER:
                case L_FUNCTION|L_SYMBOL:
                case L_FUNCTION|L_NUMBER|L_SYMBOL:
                    oled_write_ln_P(PSTR("Function      "), false);
                    break;
                }
            break;
        case L_MIDI:
            oled_write_P(PSTR("MIDI  "), false);
            // write channle
            oled_write("CH: ", false);
            oled_write_uint8(midi_config.channel, true);

            // write velocity
            oled_write("\nVel:    ", false);
            oled_write_uint8(midi_config.velocity, true);

            // write octave
            oled_write("\nOct:    ", false);
            oled_write("A", true);
            oled_write_uint8(midi_config.octave, true);

            // write transpose
            oled_write("\ntransp: ", false);
            oled_write_uint8(midi_config.transpose, true);

            break;
        case L_GAME:
            oled_write_P(PSTR("GAME  \n"), false);
            oled_write_P(PSTR("Wallworld"), false);
            oled_write_P(PSTR("GAME  "), false);
            oled_write_P(PSTR("GAME  "), false);

        default:
            // debug output on oled if layer does not match a layer state

            oled_write_P(PSTR("default layer state : "), false);
            oled_write_uint8(default_layer_state, false);
            oled_write_P(PSTR("\nlayer state : "), false);
            oled_write_uint8(layer_state, false);

            break;
    }

}


char keylog_str[24] = {};

// left display
const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}


void write_wpm(void){
        oled_write_P(PSTR("\nWPM: "), false);
        oled_write_uint8(get_current_wpm(), false);
        oled_write("\n", false);
}

// Basic task to render the OLEDs
bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        if (default_layer_state != L_MIDI){
            oled_render_keylog();
            write_wpm();
        }
    } else {
        //render_oled();
        oled_render_keylog();
    }
#ifdef CONSOLE_ENABLE
    uprintf("wpm: %u\n", get_current_wpm());
#endif // CONSOLE_ENABLE
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }

  switch (keycode)
  {
  case RGB_MOD:
    rgb_matrix_step();
    standardMode = rgb_matrix_get_mode();
    rgb_matrix_step_reverse();
    break;
  case RGB_RMOD:
    rgb_matrix_step_reverse();
    standardMode = rgb_matrix_get_mode();
    rgb_matrix_step();
    break;
  case USATI:
    if (underglow.hsv.s + INC_VAL > 255)
        underglow.hsv.s = 255;
    else
        underglow.hsv.s += INC_VAL;
    eeconfig_update_user(underglow.raw);
    break;
  case USATD:
    if (underglow.hsv.s -= INC_VAL < 0)
        underglow.hsv.s = 0;
    else
        underglow.hsv.s -= INC_VAL;
    eeconfig_update_user(underglow.raw);
    break;
  case UHUEI:
    underglow.hsv.h += INC_VAL;
    eeconfig_update_user(underglow.raw);
    break;
  case UHUED:
    underglow.hsv.h -= INC_VAL;
    break;
  case UVALI:
    if (underglow.hsv.v + INC_VAL > 255)
        underglow.hsv.v = 255;
    else
        underglow.hsv.v += INC_VAL;
    eeconfig_update_user(underglow.raw);
      break;
  case UVALD:
    if (underglow.hsv.v - INC_VAL < 0)
        underglow.hsv.v = 0;
    else
        underglow.hsv.v -= INC_VAL;
    eeconfig_update_user(underglow.raw);
    break;

  default:
    break;
  }
  return true;
}
#endif // OLED_ENABLE

void keyboard_pre_init_user(void) {
    underglow.raw = eeconfig_read_user();
}

void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
    // Customise these values to desired behaviour
    debug_enable=true;
    //debug_matrix=true;
    debug_keyboard=true;
    //debug_mouse=true;
#endif // CONSOLE_ENABLE
    standardMode = rgb_matrix_get_mode();
}
