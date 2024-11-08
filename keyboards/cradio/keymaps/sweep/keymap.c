/* ENDO Katsuhiro <ka2hiro@curlybracket.co.jp> David Philip Barr <@davidphilipbarr>
 * Pierre Chevalier <pierrechevalier83@gmail.com>
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

/* Base layer 0 layout uses home row mods. See the following guide for details:
 * https://precondition.github.io/home-row-mods
 */

//// Tap Dance declarations
//enum {
//    TD_ENT_ESC,
//};
//
//// Tap Dance definitions
//qk_tap_dance_action_t tap_dance_actions[] = {
//    // Tap once for tab, twice for escape
//    [TD_ENT_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_ENT, KC_ESC),
//};
LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_TWO_KEYS(KC_AT, KC_AT) {
      SEND_STRING("jaspervanthuijl@gmail.com");
    }
    SEQ_TWO_KEYS(KC_AT, KC_HASH) {
      SEND_STRING("j.m.van.thuijl@student.rug.nl");
    }
  }
}

const uint16_t PROGMEM COMBO_QW_ESC[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM COMBO_WE_LBRC[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM COMBO_IO_RBRC[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM COMBO_XC_LPRN[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM COMBO_COMM_DOT_RPRN[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM COMBO_OP_BSLS[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM COMBO_VOLU_VOLD_MUTE[] = {KC_VOLD, KC_VOLU, COMBO_END};

enum ferris_tap_dances {
  TD_Q_ESC
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};

#define TD_Q TD(TD_Q_ESC)

combo_t key_combos[COMBO_COUNT] = {
    COMBO(COMBO_QW_ESC, KC_ESC),
    COMBO(COMBO_WE_LBRC, KC_LBRC),
    COMBO(COMBO_IO_RBRC, KC_RBRC),
    COMBO(COMBO_XC_LPRN, KC_LPRN),
    COMBO(COMBO_COMM_DOT_RPRN, KC_RPRN),
    COMBO(COMBO_OP_BSLS, KC_BSLS),
    COMBO(COMBO_VOLU_VOLD_MUTE, KC_MUTE), // keycodes with modifiers are possible too!
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x5_2(
    TD_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    ALT_T(KC_A),GUI_T(KC_S),CTL_T(KC_D),SFT_T(KC_F), KC_G,    KC_H, SFT_T(KC_J),CTL_T(KC_K),GUI_T(KC_L),ALT_T(KC_SCLN),
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                          LT(2,KC_TAB), KC_SFTENT,   KC_SPC,  LT(1,KC_BSPC)
    ),
    [1] = LAYOUT_split_3x5_2(
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_VOLU,     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DQUO,
    KC_PSCR, KC_4,    KC_5,    KC_6,    KC_VOLD,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT,
    KC_CAPS, KC_7,    KC_8,    KC_9,    KC_0,        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______,
                               MO(3),   KC_ESC,      _______, _______
    ),
    [2] = LAYOUT_split_3x5_2(
    KC_LEAD, KC_LBRC, KC_LCBR, KC_RCBR, _______,     KC_CIRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_TILD,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_AMPR, KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
    _______, _______, _______, _______, _______,     KC_ASTR, KC_UNDS, KC_PLUS, KC_PIPE, _______,
                               _______, _______,     KC_DEL,  MO(3)
    ),
    [3] = LAYOUT_split_3x5_2(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F10,      _______, _______, _______, _______, RESET,
    _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,      _______, KC_CUT, KC_COPY, KC_PASTE, _______, 
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F12,      _______, _______, _______, _______, _______,
                               _______, _______,     _______, _______
    )
};

