// this is the style you want to emulate.  // This is the canonical layout file for the Quantum project. If you want to add another keyboard, 
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _SP 1
#define _NB 2
#define _LW 4
#define _SH 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    MT(MOD_HYPR, KC_ESC), KC_TAB, KC_LALT,  KC_LSFT, KC_LCTL,  KC_BSPC, KC_LGUI, KC_SPC,  MO(_SP), MO(_NB), KC_NO, MT(MOD_MEH, KC_ENT)
  ),

  [_SP] = LAYOUT(
    KC_LCBR, KC_RCBR,   KC_LT,   KC_GT, KC_NO,                     KC_AT,   KC_DLR,  KC_AMPR, KC_PIPE, KC_UNDS,
    KC_LPRN, KC_RPRN, KC_SLSH, KC_BSLS, KC_NO,                     KC_ASTR, KC_CIRC, KC_GRV,  KC_QUOT, KC_DQUO,
    KC_LBRC, KC_RBRC, KC_PLUS, KC_MINS, KC_NO,                     KC_HASH, KC_EXLM, KC_PERC, KC_TILD, KC_QUES,
    TG(_LW), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS,   KC_NO,   KC_TRNS, KC_TRNS,  KC_NO,  KC_EQL  ),

  [_NB] = LAYOUT(
    KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO,                   KC_PGUP, KC_7,    KC_8,    KC_9,  KC_NO,
    KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,                   KC_PGDN, KC_4,    KC_5,    KC_6,  KC_0,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                   KC_NO,    KC_1,    KC_2,    KC_3,  KC_NO ,
    TG(_LW), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_NO, KC_NO  ),

  [_LW] = LAYOUT(
    KC_NO,  KC_NO, KC_NO,   KC_NO,  KC_NO,                       KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_NO, KC_NO, KC_NO, KC_NO,     KC_NO,                       KC_NO, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_NO,   KC_NO, KC_NO,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    TG(_QW), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_NO,   KC_TRNS, KC_TRNS, KC_NO, KC_NO  ),

  [_SH] = LAYOUT(
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  HYPR(KC_C),
    KC_ESC, KC_TAB, KC_LALT,  KC_LSFT, KC_LCTL,  KC_BSPC, KC_LGUI, KC_SPC,  MO(_SP), MO(_NB), KC_NO, KC_ENT
  ),
};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
    break;
  }
  return MACRO_NONE;
};
