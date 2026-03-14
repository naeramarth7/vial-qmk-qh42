/* Copyright 2021 beanaccle
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

enum layer_number {
    _GRAPHITE = 0,
    _SYMBOLS,
    _NAV,
    _NUM,
    _MOUSE,
    _5,
    _LIGHT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_GRAPHITE] = LAYOUT_3x6(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_B,    KC_L,    KC_D,    KC_W,    KC_Z,                      KC_QUOT,    KC_F,    KC_O,    KC_U,    KC_J, KC_SCLN,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       KC_ESC, LGUI_T(KC_N), LALT_T(KC_R), LSFT_T(KC_T), LCTL_T(KC_S), KC_G,       KC_Y, RCTL_T(KC_H), RSFT_T(KC_A), RALT_T(KC_E), RGUI_T(KC_I), KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_Q,    KC_X,    KC_M,    KC_C,    KC_V,                         KC_K,    KC_P,  KC_DOT, KC_MINS, KC_SLSH,  KC_EQL,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                          MO(5), LT(_SYMBOLS, KC_SPC), LT(_NAV, KC_BSPC),    LT(_NUM, KC_ENT), LT(_MOUSE, KC_SPC), MO(6)
  ),

  [_SYMBOLS] = LAYOUT_3x6(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_TILD, KC_EXLM,   KC_AT, KC_LBRC, KC_RBRC,   KC_LT,                        KC_NO,   KC_LT,   KC_GT,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_HASH,  KC_DLR, KC_PERC, KC_LPRN, KC_RPRN,   KC_GT,                       KC_DOT, KC_COMM, KC_QUOT, KC_DQUO, KC_BSLS, KC_PIPE,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_CIRC, KC_AMPR, KC_ASTR, KC_LCBR, KC_RCBR, KC_PIPE,                      KC_COLN, KC_SCLN, KC_EXLM, KC_QUES, KC_SLSH, KC_UNDS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   KC_NO, KC_NO,    KC_NO,   KC_NO,   KC_NO
  ),

  [_NAV] = LAYOUT_3x6(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                       KC_INS, KC_HOME,   KC_UP,  KC_END,  KC_DEL,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGUP,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,   KC_NO, KC_NO,    KC_NO,   KC_NO,   KC_NO
  ),

  [_NUM] = LAYOUT_3x6(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_MINS,    KC_7,    KC_8,    KC_9, KC_SLSH,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                      KC_PLUS,    KC_4,    KC_5,    KC_6, KC_ASTR,  KC_DOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                         KC_0,    KC_1,    KC_2,    KC_3,  KC_EQL, KC_COMM,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   KC_NO, KC_NO,    KC_NO,   KC_NO, KC_NO
  ),

  [_MOUSE] = LAYOUT_3x6(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO, KC_BTN1, KC_MS_U, KC_BTN2,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO, KC_MS_L, KC_MS_D, KC_MS_R,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO
  ),

  [_5] = LAYOUT_3x6(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO
  ),

  [_LIGHT] = LAYOUT_3x6(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        BL_UP, RM_VALU,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      BL_TOGG, RM_TOGG,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      BL_DOWN, RM_VALD,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO
  )
};

// Graphite non-standard shifted pairs: ' → _, - → ", / → <
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const uint8_t mods = get_mods() | get_oneshot_mods();
    if (mods & MOD_MASK_SHIFT) {
        uint16_t replacement = 0;
        switch (keycode) {
            case KC_QUOT: replacement = KC_MINS; break;  // ' → _
            case KC_MINS: replacement = KC_QUOT; break;  // - → "
            case KC_SLSH: replacement = KC_COMM; break;  // / → <
        }
        if (replacement && record->event.pressed) {
            register_code16(S(replacement));
            return false;
        } else if (replacement) {
            unregister_code16(S(replacement));
            return false;
        }
    }
    return true;
}
