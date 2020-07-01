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

enum custom_keycodes {
    QWERTZ = SAFE_RANGE,
    DVORAK,
    SYMB,
    FUNC,
    DEAD,
    MOUSE,
    ADJUST
};

#define ESC_CTL MT(MOD_LCTL, KC_ESC)
#define ESC_FUN LT(_FUNC, KC_ESC)

#define TAB_ALT MT(MOD_LALT, KC_TAB)
#define TAB_GUI MT(MOD_LGUI, KC_TAB)

#define SPC_GUI MT(MOD_LGUI, KC_SPC)
#define HASH_CTL MT(MOD_RCTL, DE_HASH)
#define ENT_SYM LT(_SYMB, KC_ENT)

#define A_FUN LT(_FUNC, KC_A)
#define S_SYM LT(_SYMB, KC_S)
#define L_SYM LT(_SYMB, KC_L)
#define PLUS_FUN LT(_FUNC, DE_PLUS)
#define O_SYM LT(_SYMB, KC_O)
#define N_SYM LT(_SYMB, KC_N)
#define S_FUN LT(_FUNC, KC_S)

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
    KC_BSPC,  KC_Q,  KC_W,     KC_E,    KC_R,     KC_T,                                              DE_Z,    KC_U,  KC_I,     KC_O,   KC_P,     KC_BSPC,
    ESC_CTL,  A_FUN, S_SYM,    KC_D,    KC_F,     KC_G,    _______,                       _______,   KC_H,    KC_J,  KC_K,     L_SYM,  PLUS_FUN, HASH_CTL,
    KC_LSFT,  DE_Y,  KC_X,     KC_C,    KC_V,     KC_B,    MOUSE,   KC_PGDN,     KC_DEL,  ADJUST,    KC_N,    KC_M,  DE_COMM,  DE_DOT, DE_MINS,  KC_RSFT,
                                        TAB_ALT,  TAB_GUI, ENT_SYM, ESC_FUN,     ESC_FUN, ENT_SYM,   SPC_GUI, ESC_CTL
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
[_DVORAK] = LAYOUT_gergo(
    KC_BSPC,  DE_PLUS,  DE_COMM,  DE_DOT,  KC_P,     KC_Y,                                              DE_F,    KC_G,  KC_C,  KC_R,   KC_L,   KC_BSPC,
    ESC_CTL,  A_FUN,    O_SYM,    KC_E,    KC_U,     KC_I,    _______,                       _______,   KC_D,    KC_H,  KC_T,  N_SYM,  S_FUN,  HASH_CTL,
    KC_LSFT,  DE_MINS,  KC_Q,     KC_J,    KC_K,     KC_X,    MOUSE,   KC_PGDN,     KC_DEL,  ADJUST,    KC_B,    KC_M,  KC_W,  KC_V,   KC_Z,   KC_RSFT,
                                           TAB_ALT,  SPC_GUI, ENT_SYM, ESC_FUN,     ESC_FUN, ENT_SYM,   TAB_GUI, ESC_CTL
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
[_SYMB] = LAYOUT_gergo(
    _______, DE_EXLM, DE_DQUO, DE_EURO, DE_LCBR, DE_RCBR,                                             DE_GRV,  DE_7, DE_8, DE_9,  DE_QUES, _______,
    _______, DE_AT,   DE_DLR,  DE_PERC, DE_LPRN, DE_RPRN,  _______,                          _______, DE_SLSH, DE_4, DE_5, DE_6,  DE_EQL,  _______,
    _______, DE_PIPE, DE_CIRC, DE_AMPR, DE_LBRC, DE_RBRC,  _______, _______,        _______, _______, DE_BSLS, DE_1, DE_2, DE_3,  DE_TILD, _______,
                                         _______, _______, DE_LABK, DE_RABK,        _______, _______, _______, DE_0
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
[_FUNC] = LAYOUT_gergo(
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
[_DEAD] = LAYOUT_gergo(
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
[_MOUSE] = LAYOUT_gergo(
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
                default_layer_set(1UL<<_QWERTZ);
            }
            return false;
            break;
        case DVORAK:
            if (record->event.pressed) {
                default_layer_set(1UL<<_DVORAK);
            }
            return false;
            break;
        case SYMB:
            if (record->event.pressed) {
                layer_on(_SYMB);
                update_tri_layer(_SYMB, _FUNC, _ADJUST);
            } else {
                layer_off(_SYMB);
                update_tri_layer(_SYMB, _FUNC, _ADJUST);

            }
            return false;
            break;

        case FUNC:
            if (record->event.pressed) {
                layer_on(_FUNC);
                update_tri_layer(_SYMB, _FUNC, _ADJUST);
            } else {
                layer_off(_FUNC);
                update_tri_layer(_SYMB, _FUNC, _ADJUST);
            }
            return false;
            break;

        case MOUSE:
            if (record->event.pressed) {
                layer_on(_MOUSE);
            } else {
                layer_off(_MOUSE);
            }
            return false;
            break;
    };
    return true;
}
