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
#define _MOUSE 6
#define _MULTI_TOOL 8
#define _SHORTCUT_SWITCHER 9
#define _L_CHROME 10
#define _CHROME 11
#define _TMUX 12
#define _ITERM 13
#define _DESKTOP 14

enum custom_keycodes {
    MY_CUSTOM = SAFE_RANGE,
    TMUX_SPLIT_HORIZONTAL,
    TMUX_SPLIT_VERTICAL,
    TMUX_NEW_TAB,
    TMUX_MOVE_UP,
    TMUX_MOVE_DOWN,
    TMUX_MOVE_LEFT,
    TMUX_MOVE_RIGHT,
    TMUX_NEXT_WINDOW,
    TMUX_PREVIOUS_WINDOW,
    TMUX_CLOSE_WINDOW,
    LINUX_AS_DEFAULT,
    MAC_AS_DEFAULT,
    TMUX_RENAME_TAB,
    TMUX_SCROLL,
    TMUX_ZOOM,
    TMUX_BREAK_PANE,
    TMUX_CHOOSE_TREE,
    TMUX_SWITCH_SESSION
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch(keycode) {
      case MY_CUSTOM:
        SEND_STRING("QMK is the best thing ever!");
        return false;
      case TMUX_NEW_TAB:
        SEND_STRING(SS_LCTRL("s")"c");
        return false;
      case TMUX_MOVE_UP:
        SEND_STRING(SS_LCTRL("s")SS_TAP(X_UP));
        return false;
      case TMUX_MOVE_DOWN:
        SEND_STRING(SS_LCTRL("s")SS_TAP(X_DOWN));
        return false;
      case TMUX_MOVE_RIGHT:
        SEND_STRING(SS_LCTRL("s")SS_TAP(X_RIGHT));
        return false;
      case TMUX_MOVE_LEFT:
        SEND_STRING(SS_LCTRL("s")SS_TAP(X_LEFT));
        return false;
      case TMUX_SPLIT_HORIZONTAL:
        SEND_STRING(SS_LCTRL("s")"\"");
        return false;
      case TMUX_SPLIT_VERTICAL:
        SEND_STRING(SS_LCTRL("s")SS_LSFT("5"));
        return false;
      case TMUX_NEXT_WINDOW:
        SEND_STRING(SS_LCTRL("s")"n");
        return false;
      case TMUX_PREVIOUS_WINDOW:
        SEND_STRING(SS_LCTRL("s")"p");
        return false;
      case TMUX_CLOSE_WINDOW:
        SEND_STRING(SS_LCTRL("s")"x""y");
        return false;
      case TMUX_RENAME_TAB:
        SEND_STRING(SS_LCTRL("s")","SS_LCTRL("u"));
        return false;
      case TMUX_SCROLL:
        SEND_STRING(SS_LCTRL("s")"[");
        return false;
      case TMUX_ZOOM:
        SEND_STRING(SS_LCTRL("s")"z");
        return false;
      case TMUX_SWITCH_SESSION:
        SEND_STRING(SS_LCTRL("s")"s");
        return false;
      case TMUX_CHOOSE_TREE:
        SEND_STRING(SS_LCTRL("s")"t");
        return false;
      case TMUX_BREAK_PANE:
        SEND_STRING(SS_LCTRL("s")"b");
        return false;
      case LINUX_AS_DEFAULT:
        set_single_persistent_default_layer(_MAIN_LINUX);
        return false;
      case MAC_AS_DEFAULT:
        set_single_persistent_default_layer(_MAIN_MAC);
        return false;
    }
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_MAIN_MAC] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    LT(_MULTI_TOOL, KC_SCLN),
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_ESC, KC_TAB, MO(_MOUSE),  KC_LSFT, MT(MOD_LGUI, KC_BSPC),   KC_LCTL, KC_LALT,       KC_SPC,  MO(_RS), KC_MINS, KC_QUOT, KC_ENT
  ),

  [_MAIN_LINUX] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    LT(_MOUSE, KC_ESC), KC_TRNS, KC_TRNS,  KC_TRNS, MT(MOD_LCTL, KC_BSPC),      KC_TRNS, KC_TRNS,    KC_SPC,  MO(_RS), KC_MINS, KC_QUOT, KC_ENT
  ),

  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                   KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR ,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DLR,                    KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS ,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                   KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS ,
    TG(_LW), KC_TRNS/*TG(_SHORTCUT_SWITCHER)*/,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_DOT, KC_0, KC_EQL  ),

  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_DOWN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    TO(_MAIN_MAC),   KC_VOLD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  TO(_MAIN_MAC), KC_PSCR, KC_SLCK, KC_PAUS ),

  [_MULTI_TOOL] = LAYOUT(
    KC_NO, KC_NO, LGUI(LSFT(KC_E)), LGUI(LSFT(KC_R)), LGUI(LSFT(KC_T)),                         KC_NO, KC_NO, LALT(LGUI(KC_I)), KC_NO, LGUI(LSFT(KC_O)),
    LGUI(LSFT(KC_A)), LGUI(LSFT(LALT(KC_S))), KC_NO, LGUI(LSFT(KC_F)), LGUI(LSFT(KC_G)),                         KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
    KC_NO, KC_NO, LGUI(LSFT(LALT(KC_C))), LGUI(LSFT(KC_V)), LGUI(LSFT(KC_B)),                         KC_NO, LGUI(LSFT(KC_M)), KC_NO, KC_NO, KC_NO,
    LCTL(LSFT(KC_TAB)), LCTL(KC_TAB), KC_NO, KC_NO, KC_NO,   KC_NO, KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
  ),

  [_SHORTCUT_SWITCHER] = LAYOUT(
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, LINUX_AS_DEFAULT, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                         KC_TRNS, MAC_AS_DEFAULT, KC_TRNS, KC_TRNS, KC_TRNS,
    DF(_MAIN_MAC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_CHROME] = LAYOUT(
    KC_Q,    LGUI(KC_W),    KC_E,    KC_R,    KC_NO,                            KC_Y,    LGUI(KC_L),    LGUI(LSFT(KC_N)),    KC_O,    KC_P    ,
    KC_A,    KC_S,    LGUI(LALT(KC_I)),    KC_F,    KC_G,                      LCTL(LSFT(KC_TAB)),    KC_TAB,    LSFT(KC_TAB),    LCTL(KC_TAB),    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    LGUI(LALT(KC_B)),                      KC_N,    KC_M,    KC_COMM, LGUI(KC_MINS),  LGUI(KC_PLUS) ,
    KC_TRNS, KC_NO, KC_NO,  KC_NO, KC_NO,         KC_NO, KC_NO,              KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO
  ),

  [_TMUX] = LAYOUT(
    KC_Q,    TMUX_CLOSE_WINDOW,    KC_E,    TMUX_RENAME_TAB,    TMUX_CHOOSE_TREE,                            TMUX_NEW_TAB,    TMUX_SPLIT_HORIZONTAL,    TMUX_SPLIT_VERTICAL,    TMUX_NEW_TAB,    TMUX_NEXT_WINDOW    ,
    TMUX_SCROLL, TMUX_SWITCH_SESSION, LGUI(LSFT(KC_TAB)),    LGUI(KC_TAB),    KC_G,                      TMUX_MOVE_LEFT,    TMUX_MOVE_DOWN,    TMUX_MOVE_UP,    TMUX_MOVE_RIGHT,    TMUX_PREVIOUS_WINDOW ,
    TMUX_ZOOM,    KC_X,    KC_C,    KC_V,    TMUX_BREAK_PANE,                      KC_TRNS,    LCTL(KC_LEFT),    LCTL(KC_DOWN), LCTL(KC_UP),  LCTL(KC_RIGHT) ,
    KC_TRNS, KC_NO, KC_NO,  KC_NO, KC_NO,         KC_NO, KC_NO,              KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO
  ),

  [_L_CHROME] = LAYOUT(
    KC_Q,    LGUI(KC_W),    KC_E,    KC_R,    KC_NO,                            KC_Y,    LGUI(KC_L),    LGUI(LSFT(KC_N)),    KC_O,    KC_P    ,
    KC_A,    KC_S,    LGUI(LALT(KC_I)),    KC_F,    KC_G,                      LCTL(LSFT(KC_TAB)),    KC_TAB,    LSFT(KC_TAB),    LCTL(KC_TAB),    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    LGUI(LALT(KC_B)),                      KC_N,    KC_M,    KC_COMM, LGUI(KC_MINS),  LGUI(KC_PLUS) ,
    KC_TRNS, KC_NO, KC_NO,  KC_NO, KC_NO,         KC_NO, KC_NO,              KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO
  ),

  [_ITERM] = LAYOUT(
    KC_TRNS, LGUI(KC_W), KC_TRNS, KC_TRNS, LGUI(KC_PGUP),                                       LGUI(KC_T), LGUI(LSFT(KC_D)), LGUI(KC_D), LGUI(KC_T), LCTL(KC_TAB),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LGUI(KC_PGDN),                                       LGUI(LSFT(KC_H)), LGUI(LSFT(KC_J)), LGUI(LSFT(KC_K)), LGUI(LSFT(KC_L)), LCTL(LSFT(KC_TAB)),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_DESKTOP] = LAYOUT(
    LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), LGUI(KC_4), LGUI(KC_5),        LGUI(KC_6), LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), LGUI(KC_0),
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_MOUSE] = LAYOUT(
    KC_NO, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U,                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_NO, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,                         MOD_LCTL, MOD_LGUI, KC_NO, KC_NO, KC_TRNS,
    KC_NO, KC_NO, LGUI(KC_C), LGUI(KC_V), KC_ACL0,                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
    KC_ESC, KC_NO, KC_NO, KC_NO, KC_NO,     LCTL(KC_C), LCTL(KC_V),   KC_BTN1, KC_BTN2, KC_BTN3, KC_NO, KC_NO
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
