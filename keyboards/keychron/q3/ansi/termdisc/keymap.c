/* Copyright 2022 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"
//#include "rgb_matrix_user.h"
//#include "keymap.h"

#include "rgb_matrix_map.h"

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,             KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_SNAP,  KC_SIRI,  RGB_MOD,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN, MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_tkl_ansi(
        _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_0,  KC_KP_MINUS,  KC_KP_PLUS,    _______,    _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  KC_KP_4,  KC_KP_5,  KC_KP_6,  LSFT(KC_5),  _______,  _______,    RESET,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_ASTERISK,  _______,              _______,
        _______,            NK_TOGG,  _______,  _______,  _______,  _______,  _______,  KC_KP_0,  KC_KP_0,  KC_KP_DOT,KC_KP_SLASH,             _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_tkl_ansi(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_PSCR,  KC_SCROLLLOCK,  KC_PAUSE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  KC_INS,   KC_HOME,  KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,    KC_BSLS,  KC_DEL,   KC_END,   KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_tkl_ansi(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,  TG(WIN_FN),  KC_MUTE,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_KP_7,  KC_KP_8,  KC_KP_9,  KC_KP_0,  KC_KP_MINUS,  KC_KP_PLUS,    _______,    _______,  _______,  _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  KC_KP_4,  KC_KP_5,  KC_KP_6,  LSFT(KC_5),  _______,  _______,    RESET,  _______,  _______,  _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  KC_KP_1,  KC_KP_2,  KC_KP_3,  KC_KP_ASTERISK,  _______,              _______,
        _______,            NK_TOGG,  _______,  _______,  _______,  _______,  _______,  KC_KP_0,  KC_KP_0,  KC_KP_DOT,KC_KP_SLASH,             _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,    _______,  _______,  _______,  _______),

};


void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if(!process_record_keychron(keycode, record)) {
        return false;
    }

    return true;
}

keypos_t led_index_key_position[DRIVER_LED_TOTAL];

void rgb_matrix_init_user(void) {
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            uint8_t led_index = g_led_config.matrix_co[row][col];
            if (led_index != NO_LED) {
                led_index_key_position[led_index] = (keypos_t){.row = row, .col = col};
            }
        }
    }
}

void rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(LED_CAPS, RGB_RED); // Caps Lock key

        for (uint8_t i=0; i<sizeof(LED_LIST_FUNCROW)/sizeof(LED_LIST_FUNCROW[0]); i++) {
            rgb_matrix_set_color(LED_LIST_FUNCROW[i], RGB_RED);
        }

    }

    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {
/*
        case MAC_BASE:
        case WIN_BASE:

            break;
*/
        case MAC_FN:
            for (uint8_t i=0; i<sizeof(LED_LIST_NUMPAD)/sizeof(LED_LIST_NUMPAD[0]); i++) {
                    rgb_matrix_set_color(LED_LIST_NUMPAD[i], RGB_CHARTREUSE);
                }

            rgb_matrix_set_color(LED_FN, RGB_CHARTREUSE);

            break;

        case WIN_FN:
            if (host_keyboard_led_state().num_lock) {

                for (uint8_t i=0; i<sizeof(LED_LIST_NUMPAD)/sizeof(LED_LIST_NUMPAD[0]); i++) {
                    rgb_matrix_set_color(LED_LIST_NUMPAD[i], RGB_CHARTREUSE);
                }

                rgb_matrix_set_color(LED_SCROLLLOCK, RGB_CHARTREUSE); // use Scroll Lock as Num Lock

            }
            rgb_matrix_set_color(LED_FN, RGB_CHARTREUSE);
            break;

    }
}

