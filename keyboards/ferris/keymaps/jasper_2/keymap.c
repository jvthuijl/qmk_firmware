/* Copyright 2021 @daliusd
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

#include "oneshot.h"
#include "custom_shift_keys.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layers {
    _QWERTY,
    _SYM,
    _NAV,
    _NUMB,
    _MOUSE,
    _MISC,
    _FUNC,
};

enum custom_keycodes {
  OS_CTRL = SAFE_RANGE,
  OS_ALT,
  OS_GUI,
  OS_MISC,
  OS_FUNC,
};

// Shortcut to make keymap more readable

#define L_SYM       MO(_SYM) //
#define L_NAV       MO(_NAV)
#define L_MOUSE     TG(_MOUSE)

//#define K_PRINT     (QK_LCTL | QK_LSFT | QK_LGUI | KC_4)


const custom_shift_key_t custom_shift_keys[] = {
  /* {KC_DOT , KC_EXLM}, // Shift . is ! */
  /* {KC_COMM, KC_EXLM}, // Shift , is ! */
  /* {KC_MINS, KC_EQL }, // Shift - is = */
  /* {KC_COLN, KC_SCLN}, // Shift : is ; */ 
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

enum ferris_tap_dances {
  TD_Q_ESC
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};


#define TD_Q TD(TD_Q_ESC)
/* TODO map KL to backspace, SD to control */ 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     TD_Q    ,KC_W    ,KC_E    ,KC_R    ,KC_T,                              KC_Y    ,KC_U    ,KC_I    ,KC_O    ,KC_P    ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_A    ,KC_S    ,KC_D    ,KC_F    ,KC_G    ,                          KC_H    ,KC_J    ,KC_K    ,KC_L    ,KC_SCLN ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_Z    ,KC_X    ,KC_C    ,KC_V    ,KC_B    ,                          KC_N    ,KC_M    ,KC_COMM ,KC_DOT  ,KC_SLSH,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     L_NAV   ,   KC_SFTENT,        KC_SPC  ,    L_SYM
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_SYM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_EXLM ,KC_AT   ,KC_HASH ,KC_DLR  ,KC_PERC ,                          KC_CIRC ,KC_AMPR ,KC_ASTR ,KC_LPRN ,KC_RPRN ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_GRV  ,KC_PLUS ,KC_LBRC ,KC_RBRC ,_______ ,                          KC_MINS ,OS_ALT  ,OS_CTRL ,OS_GUI  ,KC_PIPE ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EQL  ,KC_LCBR ,KC_RCBR ,_______ ,                          KC_UNDS ,KC_QUOT ,KC_DQT  ,_______ ,KC_BSLS ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______ ,    _______ ,        _______ ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_TILDE,L_MOUSE ,OS_FUNC ,OS_MISC ,KC_VOLU ,                          KC_HOME ,KC_PGDN ,KC_PGUP ,KC_END  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_TAB  ,OS_GUI  ,OS_CTRL ,OS_ALT  ,KC_VOLD ,                          KC_LEFT ,KC_DOWN ,KC_UP   ,KC_RIGHT,_______ ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_DELT ,KC_BSPC ,KC_ESC  ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    _______ ,        _______ ,    _______
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_NUMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                          KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,OS_ALT  ,OS_CTRL ,OS_GUI  ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     KC_DELT ,KC_BSPC ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     XXXXXXX ,    _______ ,        _______ ,    XXXXXXX
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     _______ ,L_MOUSE, KC_MS_U ,KC_BTN3 ,KC_WH_U ,                          _______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,                          _______ ,KC_LALT ,KC_LCTL ,KC_LGUI ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,KC_ESC  ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     KC_BTN1 ,    KC_BTN2 ,        _______ ,    _______
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_MISC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     RESET   ,_______ ,_______ ,_______ ,KC_VOLU ,                          KC_BRID ,KC_BRIU ,_______ ,KC_PSCR ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,DEBUG   ,_______ ,KC_VOLD ,                          _______ ,KC_MPRV ,KC_MPLY ,KC_MNXT ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______ ,    _______ ,        _______ ,    _______
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),

  [_FUNC] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┐                         ┌────────┬────────┬────────┬────────┬────────┐
     KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                          KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,KC_F11 ,                           KC_F12  ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,
  //└────────┴────────┴────────┴────┬───┴────┬───┼────────┐       ┌────────┼───┬────┴───┬────┴────────┴────────┴────────┘
                                     _______ ,    _______ ,        _______ ,    _______
  //                                └────────┘   └────────┘       └────────┘   └────────┘
  ),
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case L_SYM:
    case L_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_layer_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case L_SYM:
    case L_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case L_SYM:
    case L_NAV:
    case OS_CTRL:
    case OS_ALT:
    case OS_GUI:
    case OS_MISC:
    case KC_LSFT:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_mod_key(uint16_t keycode) {
    switch (keycode) {
    case OS_CTRL:
    case OS_ALT:
    case OS_GUI:
        return true;
    default:
        return false;
    }
}

oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;
oneshot_state os_misc_state = os_up_unqueued;
oneshot_state os_func_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_custom_shift_keys(keycode, record)) { return false; }

    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_cmd_state, KC_LGUI, OS_GUI,
        keycode, record
    );

    bool handled = true;

    handled = update_oneshot_layer(
        &os_misc_state, _MISC, OS_MISC,
        keycode, record
    ) & handled;

    handled = update_oneshot_layer(
        &os_func_state, _FUNC, OS_FUNC,
        keycode, record
    ) & handled;
    if (!handled) return false;

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUMB);
}
