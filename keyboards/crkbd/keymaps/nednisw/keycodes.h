// Copyright 2022 Álvaro Cortés (@ACortesDev)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

#include QMK_KEYBOARD_H
#include "layers.h"

/* Tap-Hold keycodes */
#define KC_LOWER LT(_LOWER, KC_ENT) /* Tap for Enter, Hold for LOWER layer */
#define KC_RAISE LT(_RAISE, KC_SPC) /* Tap for Space, Hold for RAISE layer */

/* Tap Dance keycodes */
#if defined(TAP_DANCE_ENABLE)
    #include "tap_dances.h"
    #define KC_T_SFT T_SFT /* Single tap for Shift, Double tap for CAPS Lock */
#else
    #define KC_T_SFT KC_LSFT
#endif

/* Macros */
enum custom_keycodes {
    VSCTERM = SAFE_RANGE,
    CHNLANG,
    PARANTHESES_OPEN,
    PARANTHESES_CLOSE,
    KCODE_EQUALS,
    KCODE_AT,
    KCODE_EXCL,
    KCODE_HASH,
    KCODE_DOLLAR,
    KCODE_PERCENT,
    KCODE_SQR,
    KCODE_AND,
    KCODE_TILDE,
    KCODE_UP_COMMA,
    KCODE_PIPE,
    KCODE_SLASH
};
