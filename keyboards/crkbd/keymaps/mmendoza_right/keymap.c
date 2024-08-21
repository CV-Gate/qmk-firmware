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

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  RSFT_T(KC_ENT),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_LCTL,   MO(2), KC_RALT
                                     //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
         KC_0,    KC_1,    KC_2,    KC_3, KC_PPLS, KC_PMNS,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_4,    KC_5,    KC_6, KC_PAST, KC_PSLS,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_7,    KC_8,    KC_9, KC_PEQL, KC_PDOT,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NUBS, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINUS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_EQUAL, XXXXXXX, XXXXXXX, LALT(KC_LBRC), LALT(KC_RBRC), XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_GRAVE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, LALT(KC_QUOTE), LALT(KC_BACKSLASH), KC_LSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, RGB_TOG,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
#include <stdio.h>

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270; // Set slave to 270 degrees
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

typedef struct {
    const uint16_t data_len;
    const char* block_map;
    const char* block_list;
} compressed_oled_frame_t;

static void oled_write_compressed_P(compressed_oled_frame_t frame) {
    uint16_t block_index = 0;
    for (uint16_t i=0; i<frame.data_len; i++) {
        uint8_t bit = i%8;
        uint8_t map_index = i/8;
        uint8_t _block_map = (uint8_t)pgm_read_byte_near(frame.block_map + map_index);
        uint8_t nonzero_byte = (_block_map & (1 << bit));
        if (nonzero_byte) {
            const char data = (const char)pgm_read_byte_near(frame.block_list + block_index++);
            oled_write_raw_byte(data, i);
        } else {
            const char data = (const char)0x00;
            oled_write_raw_byte(data, i);
        }
    }
}

static const char PROGMEM frame_map[] = {
    0x00, 0x00, 0x00, 0x00, 0x10, 0x0a, 0xf0, 0x18, 0xf0, 0xff, 0xff, 0x1f, 0xc0, 0xff, 0xff,
    0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xff,
    0xff, 0x3f, 0xf8, 0xff, 0xff, 0x3f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0xe0, 0xff, 0xff, 0x03, 0xfe, 0xff, 0xff, 0x3f, 0x60, 0x00, 0x00, 0x02,
    0x00, 0x00
};
static const char PROGMEM frame_list[] = {
    0x80, 0x30, 0x80, 0x80, 0x80, 0x30, 0x30, 0x80, 0x80, 0x7f, 0xf8, 0xf0, 0xf0, 0xf8, 0xfc,
    0xc6, 0xc7, 0xc6, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xfc, 0xe4, 0xc7, 0xc7, 0xfc, 0xfc, 0xf0,
    0xf0, 0xf0, 0xff, 0x7f, 0x03, 0x43, 0x07, 0x1f, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
    0x03, 0x03, 0x03, 0x03, 0x03, 0x1f, 0x1f, 0x03, 0x43, 0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8,
    0x38, 0x38, 0x38, 0x3f, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0x3f, 0x3c, 0x38, 0x38,
    0xf8, 0xf8, 0xf8, 0xf8, 0xe0, 0xe0, 0x07, 0x07, 0x07, 0x07, 0x87, 0x87, 0x87, 0xfe, 0x3e,
    0x1e, 0x3e, 0xff, 0xff, 0xff, 0xff, 0xff, 0x1e, 0x1e, 0x3e, 0xfe, 0x86, 0x87, 0x87, 0x07,
    0x07, 0x07, 0x07, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
    0xf0, 0xf0, 0xf0, 0xf0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0x1c, 0x1e, 0x1e, 0x7f, 0xf1, 0xf1,
    0x71, 0x7f, 0x1f, 0x1f, 0x19, 0x11, 0x11, 0x7f, 0x7f, 0x7f, 0x11, 0x11, 0x11, 0x1f, 0x1f,
    0x7f, 0x7f, 0xf1, 0xf1, 0x7f, 0x7f, 0x1e, 0x1c, 0x01, 0x01, 0x01
};
static const compressed_oled_frame_t PROGMEM frame = {496, frame_map, frame_list};

bool oled_task_user() {
    oled_write_compressed_P(frame);
    return false;
}


#endif // OLED_ENABLE
