/* Copyright 2021 Glorious, LLC <salman@pcgamingrace.com>

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
#include "rgb_matrix_map.h"

enum layers {
    WIN_BASE,
    WIN_FN,
    MAC_BASE,
    MAC_FN,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the RESET key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [WIN_BASE] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,           KC_PSCR,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, TT(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [WIN_FN] = LAYOUT(
        _______, KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,           _______,
        QK_BOOT, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, KC_KP_MINUS, KC_KP_PLUS, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PERC, _______, _______, RESET,            _______,
        _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ASTERISK, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, KC_KP_0,  KC_KP_0,  KC_KP_DOT,KC_KP_SLASH,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, TO(0), _______, _______, _______, _______
    ),

    [MAC_BASE] = LAYOUT(
        KC_ESC,  KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,           SGUI(KC_4),
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LALT, KC_LGUI,                            KC_SPC,                             KC_RALT, TT(3),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [MAC_FN] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______,          _______,
        QK_BOOT, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_0, KC_KP_MINUS, KC_KP_PLUS, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PERC, _______, _______, RESET,            _______,
        _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_ASTERISK, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, KC_KP_0,  KC_KP_0,  KC_KP_DOT,KC_KP_SLASH,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, TO(2), _______, _______, _______, _______
    ),

};
// clang-format on

const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [WIN_BASE] = { ENCODER_CCW_CW(LCTL(KC_Z), LCTL(KC_Y)) },
    [WIN_FN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_BASE] = { ENCODER_CCW_CW(LCTL(KC_Z), LCTL(KC_Y)) },
    [MAC_FN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
};

const uint16_t PROGMEM combo1[] = {KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo1, TG(2)),
};

#ifdef RGB_MATRIX_ENABLE

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

bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {

    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(LED_CAPS, RGB_RED); // Caps Lock key

        for (uint8_t i=0; i<sizeof(LED_SIDE_LEFT)/sizeof(LED_SIDE_LEFT[0]); i++) {
            rgb_matrix_set_color(LED_SIDE_LEFT[i], RGB_RED);
        }
    } else if (rgb_matrix_get_mode() == RGB_MATRIX_TYPING_HEATMAP) {
        // Fix Gradient 4 (heatmap) not turning off caps lock light
        for (uint8_t i=0; i<sizeof(LED_SIDE_LEFT)/sizeof(LED_SIDE_LEFT[0]); i++) {
            rgb_matrix_set_color(LED_SIDE_LEFT[i], RGB_OFF);
        }
    }

    if (rgb_matrix_get_mode() == RGB_MATRIX_TYPING_HEATMAP) {
        for (uint8_t i=0; i<sizeof(LED_SIDE_RIGHT)/sizeof(LED_SIDE_RIGHT[0]); i++) {
            rgb_matrix_set_color(LED_SIDE_RIGHT[i], RGB_OFF);
        }
    }

    uint8_t current_layer = get_highest_layer(layer_state);
    switch (current_layer) {
        case WIN_BASE: // base layer

            for (uint8_t i=0; i<sizeof(LED_SIDE_RIGHT)/(2*sizeof(LED_SIDE_RIGHT[0])); i++) {
                    rgb_matrix_set_color(LED_SIDE_RIGHT[i], RGB_BLUE);
            }
            break;

        case WIN_FN:
            // Fn layer

            for (uint8_t i=0; i<sizeof(LED_SIDE_RIGHT)/sizeof(LED_SIDE_RIGHT[0]); i++) {
                rgb_matrix_set_color(LED_SIDE_RIGHT[i], RGB_CHARTREUSE);
            }

            for (uint8_t i=0; i<sizeof(LED_SIDE_RIGHT)/(2*sizeof(LED_SIDE_RIGHT[0])); i++) {
                rgb_matrix_set_color(LED_SIDE_RIGHT[i], RGB_BLUE);
            }


            // numpad layer
            if (host_keyboard_led_state().num_lock) {

                for (uint8_t i=0; i<sizeof(LED_LIST_NUMPAD)/sizeof(LED_LIST_NUMPAD[0]); i++) {
                    rgb_matrix_set_color(LED_LIST_NUMPAD[i], RGB_CHARTREUSE);
                }

            }

            break;

        case MAC_BASE:

            for (uint8_t i=4; i<sizeof(LED_SIDE_RIGHT)/sizeof(LED_SIDE_RIGHT[0]); i++) {
                rgb_matrix_set_color(LED_SIDE_RIGHT[i], RGB_WHITE);
            }

            break;


        case MAC_FN: // Mac numpad layer

            for (uint8_t i=0; i<sizeof(LED_SIDE_RIGHT)/sizeof(LED_SIDE_RIGHT[0]); i++) {
                    rgb_matrix_set_color(LED_SIDE_RIGHT[i], RGB_CHARTREUSE);
            }

            for (uint8_t i=4; i<sizeof(LED_SIDE_RIGHT)/sizeof(LED_SIDE_RIGHT[0]); i++) {
                rgb_matrix_set_color(LED_SIDE_RIGHT[i], RGB_WHITE);
            }

            for (uint8_t i=0; i<sizeof(LED_LIST_NUMPAD)/sizeof(LED_LIST_NUMPAD[0]); i++) {
                rgb_matrix_set_color(LED_LIST_NUMPAD[i], RGB_CHARTREUSE);
            }


            break;

    }
    return false;
}

#endif

