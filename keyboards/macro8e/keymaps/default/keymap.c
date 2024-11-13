// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _LAYOUT_1,
    _LAYOUT_2,
    _LAYOUT_3
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,
        KC_5,    KC_6,    KC_7,    KC_8
    ),

    [_LAYOUT_1] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,
        KC_5,    KC_6,    KC_7,    KC_8
    ),

    [_LAYOUT_2] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,
        KC_5,    KC_6,    KC_7,    KC_8
    ),

    [_LAYOUT_3] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,
        KC_5,    KC_6,    KC_7,    KC_8
    )
};

bool dip_switch_update_user(uint8_t index, bool active) {
    if (index == 0 && active) {
        tap_code(KC_K);
    }
    return false;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_RIGHT);
    } else {
        tap_code(KC_LEFT);
    }
    return false; 
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    return true;
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return rotation;
}

bool oled_task_user(void) {
    // Clear the display
    oled_clear();
    // Write the layer status
    oled_set_cursor(0,0);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("BASE [0]"), false);
            break;
        case _LAYOUT_1:
            oled_write_P(PSTR("LAYOUT [1]"), false);
            break;
        case _LAYOUT_2:
            oled_write_P(PSTR("LAYOUT [2]"), false);
            break;
        case _LAYOUT_3:
            oled_write_P(PSTR("LAYOUT [3]"), false);
            break;
    }
    return false;
}
#endif