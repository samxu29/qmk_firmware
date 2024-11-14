// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    _MEDIA,
    _MODKEY,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MEDIA] = LAYOUT(
        KC_LCBR,    KC_L,       KC_COLN,    KC_RCBR,
        KC_RABK,    KC_LEFT,    KC_RIGHT,   KC_LABK
    ),

    [_MODKEY] = LAYOUT(
        KC_ESC,     KC_SPC,     KC_DEL,     KC_BSPC,
        KC_LSFT,    KC_LCTL,    KC_LALT,    KC_ENT
    ),
};

bool dip_switch_update_user(uint8_t index, bool active) {
    
    if (index == 0 && active) {
        layer_invert(_MODKEY);
    }
    return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_AUDIO_VOL_UP);
    } else {
        tap_code(KC_AUDIO_VOL_DOWN);
    }
    return false; 
}
// bool encoder_update_user(uint8_t index, bool clockwise) {
//     switch (get_highest_layer(layer_state)) {
//         case _MEDIA:
//             if (clockwise) {
//                 tap_code(KC_RIGHT);
//             } else {
//                 tap_code(KC_LEFT);
//             }
//             break;
            
//         case _MODKEY:
//             if (clockwise) {
//                 tap_code(KC_AUDIO_VOL_UP);
//             } else {
//                 tap_code(KC_AUDIO_VOL_DOWN);
//             }
//             break;
//     }
//     return false;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}


void keyboard_post_init_user(void) {
    // Initialize LED pins
    LED_PIN_INIT
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Turn off all LEDs
    writePin(LED_1_PIN, 0);
    writePin(LED_2_PIN, 0);
    writePin(LED_3_PIN, 0);
    writePin(LED_4_PIN, 0);

    // Turn on LED for current layer
    switch (get_highest_layer(state)) {
        case _MEDIA:
            writePin(LED_1_PIN, 1);
            writePin(LED_4_PIN, 1);
            break;
        case _MODKEY:
            writePin(LED_2_PIN, 1);
            writePin(LED_3_PIN, 1);
            break;
    }
    return state;
}

#ifdef OLED_ENABLE

    oled_rotation_t oled_init_user(oled_rotation_t rotation) {
        return rotation;
    }

    static void render_logo(void) {
        static const char PROGMEM qmk_logo[] = {
            0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
            0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
            0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
        };

        oled_write_P(qmk_logo, false);
    }

    bool oled_task_user(void) {
        oled_write_ln_P(PSTR("LAYER:"), false);

        switch (get_highest_layer(layer_state)) {
            case _MEDIA:
                oled_write_P(PSTR(" \t MEDIA\t \n\n\n"), false);
                break;
            case _MODKEY:
                oled_write_P(PSTR(" \t MODKEY\t \n\n\n"), false);
                break;
        }

        render_logo();

        return false;
    }

#endif

