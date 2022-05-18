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
    _SYM,
    _NAV,
    _NUM,
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
    /* [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC) */
};

/* #define TD_Q TD(TD_Q_ESC) */

combo_t key_combos[COMBO_COUNT] = {
    COMBO(COMBO_QW_ESC, KC_ESC),
    COMBO(COMBO_WE_LBRC, KC_LBRC),
    COMBO(COMBO_IO_RBRC, KC_RBRC),
    COMBO(COMBO_XC_LPRN, KC_LPRN),
    COMBO(COMBO_COMM_DOT_RPRN, KC_RPRN),
    COMBO(COMBO_OP_BSLS, KC_BSLS),
    COMBO(COMBO_VOLU_VOLD_MUTE, KC_MUTE), // keycodes with modifiers are possible too!
};

#define ALT_A    ALT_T(KC_A)
#define GUI_S    GUI_T(KC_S)
#define CTL_D    CTL_T(KC_D)
#define CTL_K    CTL_T(KC_K)
#define GUI_L    GUI_T(KC_L)
#define ALT_SCL  ALT_T(KC_SCLN)

#define L_SYMESC   LT(_SYM,KC_ESC),
#define L_NUMSPC   LT(_NUM,KC_SPC),
#define L_NAVBSPC  LT(_NAV,KC_BSPC)
#define L_EXTRA    MO(_EXTRA)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(

  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_Q    , KC_W   , KC_E   , KC_R   , KC_T   ,                          KC_Y    , KC_U   , KC_I   , KC_O   , KC_P   ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     ALT_A   , GUI_S  , CTL_D  , KC_F   , KC_G   ,                          KC_H    , KC_J   , CTL_K  , GUI_L  , ALT_SCL,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_Z    , KC_X   , KC_C   , KC_V   , KC_B   ,                          KC_N    , KC_M   , KC_COMM, KC_DOT , KC_SLSH,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     L_SYMESC,   KC_SFTENT,       L_NUMSPC ,   L_NAVBSPC
  //                                └────────┘   └────────┘       └────────┘   └────────┘
    ),                                                 

    [_SYM] = LAYOUT(                       
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,                          KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,KC_PIPE ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    _______ ,        _______ ,    _______ 
  //                                └────────┘   └────────┘       └────────┘   └────────┘
    ),                              

    [_NUM] = LAYOUT(                       
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_1    , KC_2   , KC_3   , KC_4   , KC_5   ,                          KC_6    , KC_7   , KC_8   , KC_9   , KC_0   ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______ ,    _______,         XXXXXXX ,    _______  
  //                                └────────┘   └────────┘       └────────┘   └────────┘
    ),                                                 

    [_NAV] = LAYOUT(                       
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,KC_PIPE ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______ ,    _______,         ________,    XXXXXXX 
  //                                └────────┘   └────────┘       └────────┘   └────────┘
    )
};

