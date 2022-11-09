// Copyright 2022 Álvaro Cortés (@ACortesDev)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#include "layers.h"
#include "keycodes.h"
#include "process_records.h"

#ifdef OLED_ENABLE
#    include "oled.h"
#endif

/* Layer keymaps */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_COLEMAK] = LAYOUT(
    KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS,
    KC_BSPC, LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), KC_D, KC_H, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_QUOT,
    T_SFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ESC,
    KC_LALT, KC_LCTL, LT(_RAISE, KC_SPACE), LT(_LOWER, KC_ENTER), T_SFT, KC_LGUI
    ),

[_LOWER] = LAYOUT(
    _______, _______, KC_7, KC_8, KC_9, KC_MINS, KC_PGUP,                                      KC_HOME, KC_UP, KC_END, KC_ESC, XXXXXXX,
    _______, KC_SLSH, KC_4, KC_5, KC_6, KC_PLUS, KC_PGDN,                                   KC_KP_4, KC_KP_5, KC_KP_6, KC_DEL, XXXXXXX,
    _______, KC_ASTR, KC_1, KC_2, KC_3, KC_EQL,                                             XXXXXXX, KC_KP_1, KC_KP_2, KC_KP_3, XXXXXXX, _______,
    _______, _______, _______,                                                              _______, _______, _______
    ),

[_RAISE] = LAYOUT(
    _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_F11,
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_GRV, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_F12,
    _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TILD, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
    _______, _______, _______, _______, _______, _______
    ),

[_ADJUST] = LAYOUT(
    //,-----------------------------------------------------.       ,-----------------------------------------------------.
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, VSCTERM, KC_PSCR, CHNLANG, XXXXXXX, XXXXXXX, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //|--------+--------+--------+--------+--------+--------|       |--------+--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX
    //                            `-------------------------'       `--------------------------'
    ),


layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
