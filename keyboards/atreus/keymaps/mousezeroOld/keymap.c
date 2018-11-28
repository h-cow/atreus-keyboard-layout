// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _EM 1
#define _AR 2
#define _SP 3
#define _PR 4
#define _RS 8
#define _LW 9
#define _DK 10

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT(
    KC_Q,                 KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,                 KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    LT(_PR, KC_SCLN) ,
    KC_Z,                 KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,    KC_M,    KC_COMM, KC_DOT,  LT(_SP, KC_SLSH),
    MT(MOD_LCTL, KC_ESC), KC_TAB,  KC_LGUI,  KC_LSFT, KC_BSPC,  MOD_LALT, MOB_HYPR,   KC_SPC,  MO(_RS), KC_MINS, KC_QUOT, MT(MOD_LGUI, KC_ENT)
  ),

  [_EM] = LAYOUT( 
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,                    KC_NO,  KC_NO, KC_NO, KC_NO, KC_TRNS, 
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,                    KC_NO,  KC_NO, KC_NO, KC_NO, KC_TRNS, 
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,                    KC_NO,  KC_NO, KC_NO, KC_NO, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_AR] = LAYOUT( 
    KC_TRNS, KC_NO,   KC_UP,   KC_NO,   KC_PGUP,                     KC_NO,  KC_7,    KC_8,   KC_9, KC_TRNS, 
    KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDOWN,                     KC_NO,  KC_4,    KC_5,   KC_6, KC_TRNS, 
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,  KC_1,    KC_2,   KC_3, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_MINS, KC_PLUS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS, KC_0, KC_TRNS
  ),

  [_PR] = LAYOUT( 
    KC_TRNS, KC_LBRC,   KC_RBRC,   KC_LT,   KC_GT,                    KC_NO,  KC_NO, KC_NO, KC_NO, KC_TRNS, 
    KC_TRNS, KC_LPRN,   KC_RPRN,   KC_LCBR,   KC_RCBR,                    KC_NO,  KC_NO, KC_NO, KC_NO, KC_TRNS, 
    KC_TRNS, KC_NO,   KC_NO,   KC_MINS,   KC_PLUS,                    KC_NO,  KC_NO, KC_NO, KC_NO, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_SP] = LAYOUT( 
    KC_TRNS, KC_NO,   KC_CIRC,   KC_HASH,   KC_NO,                  KC_NO,  KC_EXLM, KC_NO, KC_NO, KC_TRNS, 
    KC_TRNS, KC_NO,   KC_PERC,   KC_DLR,   KC_NO,                   KC_NO,  KC_AT,   KC_NO, KC_NO, KC_TRNS, 
    KC_TRNS, KC_NO,   KC_NO,   KC_AMPR,   KC_NO,                    KC_NO,  KC_ASTR, KC_NO, KC_NO, KC_TRNS, 
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   fn    .     0    =
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                   KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                    KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                   KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS ,
    TG(_LW), KC_INS,  KC_TRNS, KC_TRNS, KC_TRNS, TG(_DK), KC_TRNS, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL  ),
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_DOWN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_MEDIA_FAST_FORWARD,   KC__VOLUP, KC__MUTE,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_MEDIA_REWIND,   KC__VOLDOWN, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC,  TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS ),


  [_DK] = LAYOUT(
    KC_Q,                 KC_W,    KC_E,    KC_R,    KC_T,                           KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,                 KC_S,    KC_D,    KC_F,    KC_G,                           KC_H,    KC_J,    KC_K,    KC_L,    LT(_PR, KC_SCLN) ,
    KC_Z,                 KC_X,    KC_C,    KC_V,    KC_B,                           KC_N,    KC_M,    KC_COMM, KC_DOT,  LT(_SP, KC_SLSH),
    MT(MOD_LCTL, KC_ESC), KC_TAB,  KC_LGUI,  KC_LSFT, KC_BSPC,  MOD_LALT, MO(_DK),   KC_SPC,  MO(_RS), KC_MINS, KC_QUOT, MT(MOD_LGUI, KC_ENT)
  )

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
