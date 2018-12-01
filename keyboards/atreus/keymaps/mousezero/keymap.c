// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _MAIN_MAC 0
#define _MAIN_LINUX 1
#define _RS 3
#define _LW 4
#define _SHORTCUT_SWITCH 5
#define _CH 6
#define _DK 7
#define _WINDOW_MANAGER 8
#define _VSCODE 9
#define _KEYBOARD_SETTINGS 10

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN_MAC] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  LT(_DK, KC_SLSH) ,
    LT(_WINDOW_MANAGER, KC_ESC), KC_TAB, KC_LGUI,  KC_LSFT, MT(MOD_LGUI, KC_BSPC),      KC_LALT, KC_LCTL,        LT(_SHORTCUT_SWITCH, KC_SPC),  MO(_RS), KC_MINS, KC_QUOT, KC_ENT
  ),

  [_MAIN_LINUX] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  LT(_DK, KC_SLSH) ,
    LT(_WINDOW_MANAGER, KC_ESC), KC_TAB, KC_LGUI,  KC_LSFT, MT(MOD_LCTL, KC_BSPC),      KC_LALT, KC_LCTL,        LT(_SHORTCUT_SWITCH, KC_SPC),  MO(_RS), KC_MINS, KC_QUOT, KC_ENT
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
    TG(_LW), KC_NO,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL  ),
  /*
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_DOWN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(_MAIN_MAC), KC_PSCR, KC_SLCK, KC_PAUS ),

  [_SHORTCUT_SWITCH] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    TG(_KEYBOARD_SETTINGS),    KC_X,    TG(_CH),    TG(_VSCODE),    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    TO(_MAIN_MAC), KC_NO, KC_NO,  KC_NO, KC_NO,  KC_NO, KC_LCTL | KC_LALT, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO
  ),

  [_CH] = LAYOUT( /* Qwerty */
    KC_Q,    LGUI(KC_W),    KC_E,    KC_R,    KC_T,                            KC_Y,    LGUI(KC_L),    LGUI(LSFT(KC_N)),    KC_O,    KC_P    ,
    KC_A,    KC_S,    LGUI(LALT(KC_I)),    KC_F,    KC_G,                      LCTL(LSFT(KC_TAB)),    KC_TAB,    LSFT(KC_TAB),    LCTL(KC_TAB),    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    LGUI(LALT(KC_B)),                      KC_N,    KC_M,    KC_COMM, LGUI(KC_MINS),  LGUI(KC_PLUS) ,
    TO(_MAIN_MAC), KC_NO, KC_NO,  KC_NO, KC_NO,         KC_NO, KC_NO,              KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO
  ),

  [_DK] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, LGUI(LSFT(KC_7)),    LGUI(LSFT(KC_8)),   LGUI(LSFT(KC_9)), KC_RCBR,                   KC_PGUP, LGUI(KC_7),    LGUI(KC_8),   LGUI(KC_9), KC_ASTR ,
    KC_HASH, LGUI(LSFT(KC_4)),    LGUI(LSFT(KC_5)),   LGUI(LSFT(KC_6)), LGUI(LSFT(KC_0)),                    LGUI(KC_0), LGUI(KC_4),    LGUI(KC_5),   LGUI(KC_6), KC_PLUS ,
    KC_LBRC, LGUI(LSFT(KC_1)),    LGUI(LSFT(KC_2)),   LGUI(LSFT(KC_3)), KC_AMPR,                   KC_GRV,  LGUI(KC_1),    LGUI(KC_2),   LGUI(KC_3), KC_BSLS ,
    TO(_LW), KC_NO,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL  ),

  [_WINDOW_MANAGER] = LAYOUT( /* Qwerty */
    HYPR(KC_Q),    LGUI(KC_W),    HYPR(KC_E),    HYPR(KC_R),    HYPR(KC_T),                      HYPR(KC_Y),    HYPR(KC_U),    HYPR(KC_I),    HYPR(KC_O),    HYPR(KC_P    ),
    HYPR(KC_A),    HYPR(KC_S),    HYPR(KC_D),    HYPR(KC_F),    HYPR(KC_G),                      HYPR(KC_H),    HYPR(KC_J),    HYPR(KC_K),    HYPR(KC_L),    HYPR(KC_SCLN ),
    HYPR(KC_Z),    HYPR(KC_X),    HYPR(KC_C),    HYPR(KC_V),    HYPR(KC_B),                      HYPR(KC_N),    HYPR(KC_M),    HYPR(KC_COMM), HYPR(KC_DOT),  HYPR(KC_SLSH),
    KC_TRNS,       KC_NO,        KC_NO,          KC_NO,         KC_LCTL,       KC_TAB, KC_LGUI,       KC_TAB,  KC_NO, KC_NO, KC_NO, KC_NO
  ),

  [_VSCODE] = LAYOUT(
    LGUI(LALT(LSFT(KC_1))), LGUI(LSFT(KC_E)), LGUI(LSFT(KC_E)), LGUI(LALT(KC_F)), LGUI(LCTL(LSFT(KC_R))), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(KC_P),
    LGUI(LALT(KC_K)), LGUI(LSFT(KC_F)), KC_TRNS, LGUI(KC_F), LGUI(LCTL(LSFT(KC_F))), LCTL(LSFT(KC_TAB)), KC_TRNS, KC_TRNS, LCTL(KC_TAB), KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(LALT(KC_B)), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    TO(_MAIN_MAC), KC_TRNS, KC_TRNS, KC_TRNS, KC_LCTL, KC_TRNS, KC_TRNS, KC_TAB, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_KEYBOARD_SETTINGS] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DF(_MAIN_LINUX), KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DF(_MAIN_MAC), KC_TRNS, KC_TRNS, KC_TRNS,
    TO(_MAIN_MAC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
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
