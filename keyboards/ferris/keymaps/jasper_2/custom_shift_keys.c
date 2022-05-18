// Copyright 2021-2022 Google LLC.
// SPDX-License-Identifier: Apache-2.0

#include "custom_shift_keys.h"

bool process_custom_shift_keys(uint16_t keycode, keyrecord_t *record) {
  static uint16_t registered_keycode = KC_NO;

  // If a custom shift key is registered, then this event is either
  // releasing it or manipulating another key at the same time. Either way,
  // we release the currently registered key.
  if (registered_keycode != KC_NO) {
    unregister_code16(registered_keycode);
    registered_keycode = KC_NO;
  }

  if (record->event.pressed) {  // Press event.
    const uint8_t mods = get_mods();
#ifndef NO_ACTION_ONESHOT
    if ((mods | get_weak_mods() | get_oneshot_mods()) & MOD_MASK_SHIFT) {
#else
    if ((mods | get_weak_mods()) & MOD_MASK_SHIFT) {  // Shift is held.
#endif  // NO_ACTION_ONESHOT
      // Search for a custom key with keycode equal to `keycode`.
      for (int i = 0; i < NUM_CUSTOM_SHIFT_KEYS; ++i) {
        if (keycode == custom_shift_keys[i].keycode) {
#ifndef NO_ACTION_ONESHOT
          del_oneshot_mods(MOD_MASK_SHIFT);
#endif  // NO_ACTION_ONESHOT
          del_mods(MOD_MASK_SHIFT);
          del_weak_mods(MOD_MASK_SHIFT);
          send_keyboard_report();
          registered_keycode = custom_shift_keys[i].shifted_keycode;
          register_code16(registered_keycode);
          set_mods(mods);  // Restore the mods.
          return false;
        }
      }
    }
  }

  return true;  // Continue with default handling.
}
