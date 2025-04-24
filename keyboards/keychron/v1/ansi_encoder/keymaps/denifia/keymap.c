/* Copyright 2021 @ Keychron (https://www.keychron.com)
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

// clang-format off

enum layers{
    MAC_BASE,
    _FUN,
    WIN_BASE,
    _SYM,
    _NAV,
    _NUM,
    WIN_FN
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

#define L_BA1   DF(_ALPHA_COLEMAK_DH_SPLIT)
#define L_NAV   MO(_NAV)
#define L_SYM   MO(_SYM)
#define L_NUM   MO(_NUM)
#define L_FN1   MO(_FUN)

#define L_BA2   DF(_ALPHA_COLEMAK_DH)
#define L_FN2   MO(_FUN_DH)

enum custom_keycodes {
    SMTD_KEYCODES_BEGIN = SAFE_RANGE,
    
    CKC_A, // left hand
    CKC_R,
    CKC_S,
    CKC_T,

    CKC_N, // right hand
    CKC_E,
    CKC_I,
    CKC_O,

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

        SMTD_MT(CKC_N, KC_N, KC_RSFT)
        SMTD_MT(CKC_E, KC_E, KC_RCTL)
        SMTD_MT(CKC_I, KC_I, KC_RALT)
        SMTD_MT(CKC_O, KC_O, KC_RGUI)
    }
}

enum combos {
  TN_CAPS_WORD,
};

const uint16_t PROGMEM tn_combo[] = {LSFT_T(KC_T), RSFT_T(KC_N), COMBO_END};

combo_t key_combos[] = {
  [TN_CAPS_WORD] = COMBO(tn_combo, QK_CAPS_WORD_TOGGLE),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // [MAC_BASE] = LAYOUT_ansi_82(
    //     XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,             XXXXXXX,
    //     XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,             XXXXXXX,
    //     XXXXXXX,      KC_Q,     KC_W,     KC_F,     KC_P,    KC_B,  XXXXXXX,     KC_J,     KC_L,     KC_U,     KC_Y,  KC_SCLN,    XXXXXXX,  XXXXXXX,             XXXXXXX,
    //     XXXXXXX,     CKC_A,    CKC_R,    CKC_S,    CKC_T,    KC_G,  XXXXXXX,     KC_M,    CKC_N,    CKC_E,    CKC_I,    CKC_O,    XXXXXXX,  XXXXXXX,
    //     LT(_SYM,KC_Z),          KC_X,     KC_C,     KC_D,    KC_V,  XXXXXXX,  XXXXXXX,     KC_K,     KC_H,  KC_COMM,   KC_DOT,              KC_SLSH,  XXXXXXX,
    //     XXXXXXX,  KC_ESC,  LT(_NUM,KC_ENT),                             LT(_NAV,KC_SPC),                KC_BSPC, LT(_FUN,KC_TAB), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),

    [MAC_BASE] = LAYOUT_ansi_82(
        XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,             XXXXXXX,
        XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,             XXXXXXX,
        XXXXXXX,      KC_Q,     KC_W,     KC_F,     KC_P,    KC_B,  XXXXXXX,     KC_J,     KC_L,     KC_U,     KC_Y,  KC_SCLN,    XXXXXXX,  XXXXXXX,             XXXXXXX,
        XXXXXXX,    LGUI_T(KC_A), LALT_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T),    KC_G,  XXXXXXX,     KC_M,    RSFT_T(KC_N), RCTL_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O),    XXXXXXX,  XXXXXXX,
        LT(_SYM,KC_Z),          KC_X,     KC_C,     KC_D,    KC_V,  XXXXXXX,  XXXXXXX,     KC_K,     KC_H,  KC_COMM,   KC_DOT,              KC_SLSH,  XXXXXXX,
        XXXXXXX,  KC_ESC,  LT(_NUM,KC_ENT),                             LT(_NAV,KC_SPC),                KC_BSPC, LT(_FUN,KC_TAB), XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX),


    [_NAV] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  _______,  _______,  KC_LEFT,  KC_DOWN,    KC_UP, KC_RIGHT,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                KC_BSPC,   KC_TAB,    _______,  _______,  _______,  _______),

    [_NUM] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  KC_LBRC,     KC_7,     KC_8,     KC_9,  KC_RBRC,    _______,  _______,            _______,
        _______,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  _______,  _______,  KC_SCLN,     KC_4,     KC_5,     KC_6,   KC_EQL,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,   KC_GRV,     KC_1,     KC_2,     KC_3,              KC_BSLS,  _______,
        _______,  _______,  _______,                                _______,                                   KC_0,  KC_MINS,    _______,  _______,  _______,  _______),

    [_SYM] = LAYOUT_ansi_82(
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  S(KC_LBRC), S(KC_7), S(KC_8),S(KC_9),S(KC_RBRC),    _______,  _______,            _______,
        _______,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  _______,  _______,  S(KC_SCLN), S(KC_4), S(KC_5),S(KC_6), S(KC_EQL),              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,S(KC_GRV),  S(KC_1),  S(KC_2),  S(KC_3),           S(KC_BSLS),            _______,
        _______,  _______,  _______,                                _______,                              S(KC_0), S(KC_MINS),    _______,  _______,  _______,  _______),

    [_FUN] = LAYOUT_ansi_82(
        QK_BOOT,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   KC_F12,    KC_F7,    KC_F8,    KC_F9,  _______,    _______,  _______,            _______,
        _______,  KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  _______,  _______,   KC_F11,    KC_F4,    KC_F5,    KC_F6,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  _______,   KC_F10,    KC_F1,    KC_F2,    KC_F3,              _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_ansi_82(
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_DEL,             KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                                KC_SPC,                                 KC_RALT,  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_ansi_82(
        _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RM_VALD,  RM_VALU,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  _______,            _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        RM_TOGG,  RM_NEXT,  RM_VALU,  RM_HUEU,  RM_SATU,  RM_SPDU,  _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RM_PREV,  RM_VALD,  RM_HUED,  RM_SATD,  RM_SPDD,  _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,            _______,  _______,  _______,  _______,  _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,    _______,  _______,  _______,  _______),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FUN]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [WIN_FN]   = { ENCODER_CCW_CW(RM_VALD, RM_VALU)}
};
#endif // ENCODER_MAP_ENABLE
