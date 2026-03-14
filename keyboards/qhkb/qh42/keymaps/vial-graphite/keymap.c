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
    _EDIT,
    _DATA,
    _ADJUST,
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
                              KC_LCTL,  KC_SPC, LT(_EDIT, KC_BSPC),    LT(_DATA, KC_ENT),  KC_SPC, KC_RCTL
                                      //`--------------------------'  `--------------------------'
  ),

  [_EDIT] = LAYOUT_3x6(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______, _______,   KC_UP, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
  ),

  [_DATA] = LAYOUT_3x6(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,                      _______,    KC_7,    KC_8,    KC_9, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                      _______,    KC_4,    KC_5,    KC_6, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                         KC_0,    KC_1,    KC_2,    KC_3, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
  ),

  [_ADJUST] = LAYOUT_3x6(
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
                                          _______, _______, _______,    _______, _______, _______
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
