// Copyright 2022 Álvaro Cortés (@ACortesDev)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "layers.h"
#include "keycodes.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* Macros */
    switch (keycode) {
        case VSCTERM:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("`")); // Ctrl + ` (to toggle vscode terminal)
            }
            return false;
        case CHNLANG:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(SS_LSFT("n"))); // Ctrl + Shift + N (to change keyboard layout)
            }
            return false;

        case PARANTHESES_OPEN:
            if (record->event.pressed) {
                SEND_STRING("(");
            }
            return false;
        
        case PARANTHESES_CLOSE:
            if (record->event.pressed) {
                SEND_STRING(")");
            }
            return false;

        case KCODE_EQUALS:
            if (record->event.pressed) {
                SEND_STRING("=");
            }
            return false;

        case KCODE_AT:
            if (record->event.pressed) {
                SEND_STRING("@");
            }
            return false;

        case KCODE_EXCL:
            if (record->event.pressed) {
                SEND_STRING("!");
            }
            return false;

        case KCODE_HASH:
            if (record->event.pressed) {
                SEND_STRING("#");
            }
            return false;

        case KCODE_DOLLAR:
            if (record->event.pressed) {
                SEND_STRING("$");
            }
            return false;

        case KCODE_PERCENT:
            if (record->event.pressed) {
                SEND_STRING("%");
            }
            return false;

        case KCODE_SQR:
            if (record->event.pressed) {
                SEND_STRING("^");
            }
            return false;

        case KCODE_AND:
            if (record->event.pressed) {
                SEND_STRING("&");
            }
            return false;

        case KCODE_TILDE:
            if (record->event.pressed) {
                SEND_STRING("~");
            }
            return false;

        case KCODE_UP_COMMA:
            if (record->event.pressed) {
                SEND_STRING("`");
            }
            return false;

        case KCODE_PIPE:
            if (record->event.pressed) {
                SEND_STRING("|");
            }
            return false;

        case KCODE_SLASH:
            if (record->event.pressed) {
                SEND_STRING("/");
            }
            return false;
    }
    return true;
}
