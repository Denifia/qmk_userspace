/*
Copyright 2015 Jun Wako <wakojun@gmail.com>

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

enum layers {
    _ALPHA_COLEMAK_DH_SPLIT = 0,
    _ALPHA_COLEMAK_DH,
    _SYM,
    _NAV,
    _NUM,
    _FUN,
    _FUN_DH
};

#define L_BA1   DF(_ALPHA_COLEMAK_DH_SPLIT)
#define L_NAV   MO(_NAV)
#define L_SYM   MO(_SYM)
#define L_NUM   MO(_NUM)
#define L_FN1   MO(_FUN)

#define L_BA2   DF(_ALPHA_COLEMAK_DH)
#define L_FN2   MO(_FUN_DH)

enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    CKC_A, // reads as C(ustom) + KC_A, but you may give any name here
    CKC_R,
    CKC_S,
    CKC_T,
    SMTD_KEYCODES_END,
};
#include "sm_td.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }
    // your code here

   return true;
}

void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
        SMTD_MT(CKC_A, KC_A, KC_LGUI)
        SMTD_MT(CKC_R, KC_R, KC_LALT)
        SMTD_MT(CKC_S, KC_S, KC_LCTL)
        SMTD_MT(CKC_T, KC_T, KC_LSFT)
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    
    /*
     * Colemak DH - Koy
     * 
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │   │   │   │   │   │   │   │   │   │   │   │   │   │   │   │Lay│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
     * │     │ Q │ W │ F │ P │ B │   │ J │ L │ U │ Y │ ; │   │     │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │      │ A │ R │ S │ T │ G │   │ M │ N │ E │ I │ O │        │   │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │      Z │ X │ C │ D │ V │   │   │ K │ H │ , │ . │ /    │   │   │
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
     * │    │ Esc│ Ent│         Space          │Bspc│ Tab│ │   │   │   │
     * └────┴────┴────┴────────────────────────┴────┴────┴─┴───┴───┴───┘
     */
     [_ALPHA_COLEMAK_DH_SPLIT] = LAYOUT_65_ansi_blocker_split_bs(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, L_BA2,
        XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    XXXXXXX, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,          XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, CKC_A,  CKC_R,    CKC_S,   CKC_T,   KC_G,    XXXXXXX, KC_M, RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),                      XXXXXXX, XXXXXXX,
        LT(_SYM,KC_Z),    KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX, XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,                   XXXXXXX, XXXXXXX,
        XXXXXXX, KC_ESC,  LT(_NUM,KC_ENT),                             LT(_NAV,KC_SPC),                    KC_BSPC, LT(_FUN,KC_TAB),                    XXXXXXX, XXXXXXX, XXXXXXX
    ),
    
    /*
     * Colemak DH - Base
     * 
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ BS│ ` │Lay│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┼───┤
     * │ Tab │ Q │ W │ F │ P │ B │ J │ L │ U │ Y │ ; │ [ │ ] │ \   │Del│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤
     * │ Caps │ A │ R │ S │ T │ G │ M │ N │ E │ I │ O │ ' │  Ent   │Hom│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
     * │ Shft   │ X │ C │ D │ V │ Z │ K │ H │ , │ . │ / │ Shift│ ↑ │End│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
     * │Ctrl│GUI │Alt │                        │Alt│ Fn│   │ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
*/
    [_ALPHA_COLEMAK_DH] = LAYOUT_65_ansi_blocker_split_bs(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRV,  L_BA1,
        KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_LBRC, KC_RBRC,          KC_BSLS, KC_DEL,
        KC_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,                   KC_ENT,  KC_HOME,
        KC_LSFT, KC_X,    KC_C,    KC_D,    KC_V,    KC_Z,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,                   KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    KC_RALT, L_FN2,                     KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /*
     * Colemak DH - Functions
     * 
     * ┌───┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┐───┬───┌───┐
     * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│   │   │   │
     * ├───└───┴───┴───┴───┴───┴───┴───┴───┴───┴─┬─┴─┬─┴─┬─┴─┐─┴───└───┘
     * │     │   │   │   │   │   │   │   │   │   │Psc│Slk│Pse│     │   │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──└───┴───┴───┘┬────┌───┐
     * │      │   │   │   │   │   │   │   │   │   │   │   │        │Vl+│
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┌───┼───┤
     * │        │   │   │   │   │   │   │   │   │   │   │      │PgU│Vl-│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┌───┼───┼───┤
     * │    │    │    │                        │   │   │   │Hom│PgD│End│
     * └────┴────┴────┴────────────────────────┴───┴───┴───└───┴───┴───┘
     */
    [_FUN_DH] = LAYOUT_65_ansi_blocker_split_bs(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_VOLD,
        _______, _______, _______,                            _______,                   _______, _______, KC_HOME, KC_PGDN, KC_END
    ),


    // [X] = LAYOUT_65_ansi_blocker_split_bs(
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, 
    //     _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, 
    //     _______, _______, _______,                            _______,                   _______, _______,                   _______, _______, _______
    // ),

    // Nav
    [_NAV] = LAYOUT_65_ansi_blocker_split_bs(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, _______,                   _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, 
        _______, _______, _______,                            _______,                   KC_BSPC,  KC_TAB,                   _______, _______, _______
    ),
    
    // Numbers
    [_NUM] = LAYOUT_65_ansi_blocker_split_bs(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_7, KC_8, KC_9, KC_RBRC, _______,          _______, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, KC_SCLN, KC_4, KC_5, KC_6, KC_EQL,                   _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, KC_GRV, KC_1, KC_2, KC_3, KC_BSLS,                _______, _______, 
        _______, _______, _______,                            _______,                   KC_0, KC_MINS,                   _______, _______, _______
    ),

    // Symbols
    [_SYM] = LAYOUT_65_ansi_blocker_split_bs(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, S(KC_LBRC), S(KC_7), S(KC_8), S(KC_9), S(KC_RBRC), _______,          _______, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, S(KC_SCLN), S(KC_4), S(KC_5), S(KC_6), S(KC_EQL),                   _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, S(KC_GRV), S(KC_1), S(KC_2), S(KC_3), S(KC_BSLS),                _______, _______, 
        _______, _______, _______,                            _______,                   S(KC_0), S(KC_MINS),                   _______, _______, _______
    ),

    // Functions
    [_FUN] = LAYOUT_65_ansi_blocker_split_bs(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_F12, KC_F7, KC_F8, KC_F9, _______, _______,          _______, _______,
        _______, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, _______, _______, KC_F11, KC_F4, KC_F5, KC_F6, _______,                   _______, _______, 
        _______, _______, _______, _______, _______, _______, _______, KC_F10, KC_F1, KC_F2, KC_F3,                   _______, _______, _______, 
        _______, _______, _______,                            _______,                   _______, _______,                   _______, _______, _______
    ),
    
};

