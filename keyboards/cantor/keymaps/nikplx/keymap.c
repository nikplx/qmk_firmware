// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H

#define LT1(kc) LT(_FN1, kc)
#define LT2(kc) LT(_FN2, kc)
#define LT3(kc) LT(_FN3, kc)

enum layers {
  _QWERTZ,
  _FN1,
  _FN2,
  _FN3
};

#define KC_EURO RALT(KC_5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTZ] = LAYOUT_split_3x6_3(
        KC_BSPC,        KC_Q,      KC_W,      KC_E,  KC_R, KC_T,                KC_Z,  KC_U,  KC_I,    KC_O,       KC_P,         KC_BSPC,
        LCTL_T(KC_ESC), LT2(KC_A), LT1(KC_S), KC_D,  KC_F, KC_G,                KC_H,  KC_J,  KC_K,    LT2(KC_L),  LT1(KC_SCLN), RCTL_T(KC_QUOT),
		KC_LSFT,        KC_Y,      KC_X,      KC_C,  KC_V, KC_B,                KC_N,  KC_M,  KC_COMM, KC_DOT,     KC_SLSH,      KC_RSFT,
                LALT_T(KC_TILD), LGUI_T(KC_TAB), LT3(KC_ENT),        LT3(KC_ENT), LGUI_T(KC_SPC), RALT_T(KC_MINS)
	),

    [_FN1] = LAYOUT_split_3x6_3(
		KC_DEL,  KC_EXLM,  KC_ASTR, KC_EURO,  KC_LCBR, KC_RCBR,              _______, _______, _______, KC_HASH, KC_PLUS, _______, 
		_______, KC_AT,    KC_DLR,  KC_PERC,  KC_LPRN, KC_RPRN,              KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSLS, KC_GRV, 
		_______, KC_PIPE,  KC_CIRC, KC_AMPR,  KC_LBRC, KC_RBRC,              _______, _______, _______, KC_TILD, KC_UNDS, _______, 
									KC_LABK,  KC_RABK, _______,               _______, _______, _______
	),

	[_FN2] = LAYOUT_split_3x6_3(
		 _______,   _______,    KC_MPRV,  KC_MPLY, KC_MNXT, KC_VOLU,         KC_ASTR, KC_7, KC_8, KC_9, KC_PLUS, _______, 
		 _______,   _______,    _______,  _______, _______, KC_VOLD,         KC_SLSH, KC_4, KC_5, KC_6, KC_EQL,  KC_GRV, 
		 _______,   _______,    _______,  _______, _______, _______,         KC_BSLS, KC_1, KC_2, KC_3, KC_MINS,  _______, 
								_______, _______, _______,                   _______, KC_0, KC_DOT 

	),


	[_FN3] = LAYOUT_split_3x6_3(
		 _______,   _______,    _______,    RALT(KC_5), _______,   _______,    _______, RALT(KC_Y), _______, RALT(KC_P), _______, _______, 
		 _______,   RALT(KC_Q), RALT(KC_S), _______,    _______,   _______,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   
		 _______,   _______,    _______,    _______,    _______,   _______,    KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  
											RESET, _______, _______,                   _______, _______, _______

	)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LALT_T(KC_TILD):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_TILD); // Send KC_DQUO on tap
                return false;        // Return false to ignore further processing of key
            }
            break;
    }
    return true;
}
