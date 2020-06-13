/* Good on you for modifying your layout! if you don't have
 * time to read the QMK docs, a list of keycodes can be found at
 *
 * https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md
 *
 * There's also a template for adding new layers at the bottom of this file!
 */

#include QMK_KEYBOARD_H
#include "keymap_german.h"

#define _QWERTZ 0
#define _DVORAK 1
#define _SYMB 2
#define _FUNC 3
#define _DEAD 4
#define _MOUSE 5
#define _ADJUST 16

enum customKeycodes {
    QWERTZ = SAFE_RANGE,
    DVORAK
    SYMB
    FUNC
    DEAD
    MOUSE
    ADJUST
};

#define ESC_C MT(MOD_LCTL, KC_ESC)
#define TAB_A MT(MOD_LALT, KC_TAB)
#define SPC_G MT(MOD_LGUI, KC_SPC)
#define


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Qwertz
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |   BS   |   Q  |   W  |   E  |   R  |   T  |                         |   Z  |   U  |   I  |   O  |   P  |   BS   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |Ctrl/ESC|   A  |   S  |  D   |   F  |   G  |      |           |      |   H  |   J  |   K  |   L  | + *  | Ctrl/#'|
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | LShift |   Y  |   X  |   C  |   V  |   B  | MOUSE|           |      |   N  |   M  | ,  ; | . :  | -  _ | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .-------.                                 .------.   .----------.
 *                    | ALT/TAB  |   |GUI/SPC|                                 | SPC  |   | DEAD/TAB |
 *                    '----------'   '-------'                                 `------.   '----------'
 *                                        ,-------.                      ,-------.
 *                                        | PGDWN |                      | DEL   |
 *                                 ,------|-------|                      |-------|------.
 *                                 | SYMB | NUMB  |                      | NUMB  | SYMB |
 *                                 | ENT  | Escape|                      | INS   | ENT  |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[_QWERTZ] = LAYOUT_gergo(
    KC_BSPC,  KC_Q,  KC_W,      KC_E,     KC_R, KC_T,                                          DE_Z,    KC_U, KC_I,     KC_O,   KC_P,    KC_BSPC,
    ESC_C,    KC_A,  KC_S,      KC_D,     KC_F, KC_G, _______,                       _______,  KC_H,    KC_J, KC_K,     KC_L,   DE_PLUS, MT(MOD_RCTL, DE_HASH),
    KC_LSFT,  DE_Y,  KC_X,      KC_C,     KC_V, KC_B, MO(MOUSE), KC_PGDN,   KC_DEL,  _______,  KC_N,    KC_M, DE_COMM,  DE_DOT, DE_MINS, KC_RSFT,
                     TAB_A,     SPC_G, LT(SYMB, KC_ENT), LT(NUMB, KC_ESC),    LT(NUMB, KC_INS),  LT(SYMB, KC_ENT), KC_SPC, LT(DEAD, KC_TAB)
    ),
/* Dvorak
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |   BS   |   Q  |   W  |   E  |   R  |   T  |                         |   Z  |   U  |   I  |   O  |   P  |   BS   |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |Ctrl/ESC|   A  |   S  |  D   |   F  |   G  |      |           |      |   H  |   J  |   K  |   L  | + *  | Ctrl/#'|
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * | LShift |   Y  |   X  |   C  |   V  |   B  | MOUSE|           |      |   N  |   M  | ,  ; | . :  | -  _ | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                    .----------.   .-------.                                 .------.   .----------.
 *                    | ALT/TAB  |   |GUI/SPC|                                 | SPC  |   | DEAD/TAB |
 *                    '----------'   '-------'                                 `------.   '----------'
 *                                        ,-------.                      ,-------.
 *                                        | PGDWN |                      | DEL   |
 *                                 ,------|-------|                      |-------|------.
 *                                 | SYMB | NUMB  |                      | NUMB  | SYMB |
 *                                 | ENT  | Escape|                      | INS   | ENT  |
 *                                 |      |       |                      |       |      |
 *                                 `--------------'                      `--------------'
 */
[_QWERTZ] = LAYOUT_gergo(
    KC_BSPC,                KC_Q,  KC_W,   KC_E,   KC_R, KC_T,                                          DE_Z,    KC_U, KC_I,     KC_O,   KC_P,    KC_BSPC,
    MT(MOD_LCTL, KC_ESC),   KC_A,  KC_S,   KC_D,   KC_F, KC_G, _______,                       _______,  KC_H,    KC_J, KC_K,     KC_L,   DE_PLUS, MT(MOD_RCTL, DE_HASH),
    KC_LSFT,                DE_Y,  KC_X,   KC_C,   KC_V, KC_B, MO(MOUSE), KC_PGDN,   KC_DEL,  _______,  KC_N,    KC_M, DE_COMM,  DE_DOT, DE_MINS, KC_RSFT,
  MT(MOD_LALT, KC_TAB), MT(MOD_LGUI, KC_SPC), LT(SYMB, KC_ENT), LT(NUMB, KC_ESC),    LT(NUMB, KC_INS),  LT(SYMB, KC_ENT), KC_SPC, LT(DEAD, KC_TAB)
    ),
/* Symbol
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |  !   |  "   |  €   |  {   |  }   |                         |   `  |  7   |  8   |  9   |  ?   |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  @   |  $   |  %   |  (   |  )   |      |           |      |   /  |  4   |  5   |  6   |  =   |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |  |   |  ^   |  &   |  [   |  ]   |      |           |      |   \  |  1   |  2   |  3   |  ~   |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |  0  |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     | PgUp  |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |   <  |   >   |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[_] = LAYOUT_gergo(
    _______, DE_EXLM, DE_DQUO, DE_EURO, DE_LCBR, DE_RCBR,                                             DE_GRV,  DE_7, DE_8, DE_9,  DE_QUES, _______,
    _______, DE_AT,   DE_DLR,  DE_PERC, DE_LPRN, DE_RPRN,  _______,                          _______, DE_SLSH, DE_4, DE_5, DE_6,  DE_EQL,  _______,
    _______, DE_PIPE, DE_CIRC, DE_AMPR, DE_LBRC, DE_RBRC,  _______, _______,        _______, _______, DE_BSLS, DE_1, DE_2, DE_3,  DE_TILD, _______,
                                         _______, _______, DE_LABK, DE_RABK,        _______, _______, _______,    DE_0
    ),
/* Function
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |  F1    | F2   | F3   | F4   | F5   | F6   |                         | F7   | F8   |  F9   | F10 | F11  | F12    |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * | CAPS   |      |      |      |      |      |      |           |      | LEFT | DOWN |  UP  | RIGHT| Pause| BriUp  |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      | MPrev| VolD | VolU | MNext| Mute | BriDwn |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.                     ,-------.
 *                                        |       |                     |       |
 *                                 ,------|-------|                     |-------|------.
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 |      |       |                     |       |      |
 *                                 `--------------'                     `--------------'
 */
[NUMB] = LAYOUT_gergo(
    KC_F1,	 KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                                                 KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_CAPS, _______, _______, _______, _______, _______, _______,                            _______,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_MPLY, KC_BRIU,
    _______, _______, _______, _______, _______, _______, _______, _______,         _______,  _______,  KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MUTE, KC_BRID,
                                        _______, _______, _______, _______,         _______,  _______,  _______, _______
    ),
/* dead
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |   Ü  |      |   Ö  |      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |  Ä   |   ß  |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |      |   |     |
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       | RESET |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 */
[DEAD] = LAYOUT_gergo(
    _______, _______, _______, _______, _______, _______,                                             _______, DE_UDIA, _______, DE_ODIA, _______, _______,
    _______, DE_ADIA, DE_SS,   _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,         RESET,   _______, _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______, _______,         _______, _______, _______, _______
    ),

/* mouse
 *
 * ,-------------------------------------------.                         ,-------------------------------------------.
 * |        |      |      |      |      |      |                         |      |      | WHUP | WHDWN|      |        |
 * |--------+------+------+------+------+------|------.           .------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      | MLEFT| MDOWN| MUP  |MRIGHT|        |
 * |--------+------+------+------+------+------|------|           |------|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *                        .------.   .------.                                 .------.   .-----.
 *                        |      |   |      |                                 |BTN 1 |   |BTN 2|
 *                        '------'   '------'                                 `------.   '-----'
 *                                        ,-------.       ,-------.
 *                                        |       |       |       |
 *                                 ,------|-------|       |-------|------.
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 |      |       |       |       |      |
 *                                 `--------------'       `--------------'
 */
[MOUSE] = LAYOUT_gergo(
    _______, _______, _______, _______, _______, _______,                                             _______, KC_WH_D, KC_WH_U, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                           _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______, _______,
                                        _______, _______, _______, _______,         _______, _______, KC_BTN1, KC_BTN2
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTZ:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_QWERTZ);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
                persistent_default_layer_set(1UL<<_DVORAK);
            }
            return false;
            break;
    }
    return true
}
