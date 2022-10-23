/*
 * Jasper van Thuijl <jaspervanthuijl@gmail.com>
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

enum layers {
    _QWERTY,
    _COLEMAK_DH,
    _SYM,
    _NAV,
    _EXTRA,
};

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

/* const uint16_t PROGMEM COMBO_QW_ESC[] = {KC_Q, KC_W, COMBO_END}; */
/* const uint16_t PROGMEM COMBO_WE_LBRC[] = {KC_W, KC_E, COMBO_END}; */
/* const uint16_t PROGMEM COMBO_IO_RBRC[] = {KC_I, KC_O, COMBO_END}; */
/* const uint16_t PROGMEM COMBO_XC_LPRN[] = {KC_X, KC_C, COMBO_END}; */
/* const uint16_t PROGMEM COMBO_COMM_DOT_RPRN[] = {KC_COMM, KC_DOT, COMBO_END}; */
/* const uint16_t PROGMEM COMBO_OP_BSLS[] = {KC_O, KC_P, COMBO_END}; */
/* const uint16_t PROGMEM COMBO_VOLU_VOLD_MUTE[] = {KC_VOLD, KC_VOLU, COMBO_END}; */

/* enum ferris_tap_dances { */
/*   TD_Q_ESC */
/* }; */

// Tap Dance Definitions
/* qk_tap_dance_action_t tap_dance_actions[] = { */
/*     // Tap once for Q, twice for ESC */
    /* [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC) */
/* }; */

/* #define TD_Q TD(TD_Q_ESC) */

/* combo_t key_combos[COMBO_COUNT] = { */
/*     /1* COMBO(COMBO_QW_ESC, KC_ESC), *1/ */
/*     /1* COMBO(COMBO_WE_LBRC, KC_LBRC), *1/ */
/*     /1* COMBO(COMBO_IO_RBRC, KC_RBRC), *1/ */
/*     /1* COMBO(COMBO_XC_LPRN, KC_LPRN), *1/ */
/*     /1* COMBO(COMBO_COMM_DOT_RPRN, KC_RPRN), *1/ */
/*     /1* COMBO(COMBO_OP_BSLS, KC_BSLS), *1/ */
/*     /1* COMBO(COMBO_VOLU_VOLD_MUTE, KC_MUTE), // keycodes with modifiers are possible too! *1/ */
/* }; */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_split_3x5_2(
    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,    KC_Y,    KC_U,       KC_I ,      KC_O,       KC_P,
    ALT_T(KC_A),GUI_T(KC_S),CTL_T(KC_D),SFT_T(KC_F),KC_G,    KC_H,    SFT_T(KC_J),CTL_T(KC_K),GUI_T(KC_L),ALT_T(KC_SCLN),
    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,    KC_N,    KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,
                              LT(_SYM,KC_ESC), KC_SFTENT,    KC_SPC,  LT(_NAV,KC_BSPC)
    ),                                                 
    [_COLEMAK_DH] = LAYOUT_split_3x5_2(
    KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,    KC_J,    KC_L,       KC_U,       KC_Y ,      KC_SCLN,
    ALT_T(KC_A),GUI_T(KC_R),CTL_T(KC_S),SFT_T(KC_T),KC_G,    KC_M,    SFT_T(KC_N),CTL_T(KC_E),GUI_T(KC_I),ALT_T(KC_O),
    KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,    KC_K,    KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,
                              LT(_SYM,KC_ESC), KC_SFTENT,    KC_SPC,  LT(_NAV,KC_BSPC)
    ),
    [_NAV] = LAYOUT_split_3x5_2(                       
    _______,  KC_1,    KC_2,    KC_3,       _______,         KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DQUO,
    KC_TAB,   KC_4,    KC_5,    KC_6,       _______,         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT,
    KC_PSCR,  KC_7,    KC_8,    KC_9,          KC_0,         _______, _______, _______, _______, _______,
                                MO(_EXTRA), _______,         _______, XXXXXXX
    ),                                                 
    [_SYM] = LAYOUT_split_3x5_2(                       
    KC_LEAD, KC_LBRC, KC_LCBR, KC_RCBR, _______,             KC_CIRC, KC_LPRN, KC_RPRN, KC_RBRC, KC_TILD,
    KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,             KC_AMPR, KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
    _______, _______, _______, _______, _______,             KC_ASTR, KC_UNDS, KC_PLUS, KC_PIPE, _______,
                               XXXXXXX, _______,             KC_DEL,  MO(_EXTRA)
    ),                                                       
    [_EXTRA] = LAYOUT_split_3x5_2(                                
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F10,              KC_VOLU, DT_PRNT,   DT_UP, DT_DOWN, RESET,
    _______, KC_F4,   KC_F5,   KC_F6,   KC_F11,              KC_VOLD, KC_CUT, KC_COPY, KC_PASTE, DF(_QWERTY), 
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F12,              KC_MUTE, KC_MPRV, KC_MPLY, KC_MNXT, DF(_COLEMAK_DH),
                               XXXXXXX, _______,             _______, XXXXXXX
    )

};

