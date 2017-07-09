#include "tada68.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL1 1
#define _FL2 2
#define _FL3 3 

#define _______ KC_TRNS

enum {
  TD_DOT_COM = 0
};

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_DOT_COM] = ACTION_TAP_DANCE_DOUBLE(KC_PDOT, KC_PCMM)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |DelFn2 |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        SpaceFn        |Alt|Fn1|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = KEYMAP_ANSI(
  KC_ESC  ,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,   KC_BSPC, KC_GRV, \
  KC_TAB   ,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
  LT(_FL2,KC_DEL),KC_A,KC_S, KC_D,   KC_F,   KC_G,   KC_H ,  KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,       KC_ENT,  KC_PGUP, \
  OSM(MOD_LSFT),KC_Z, KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RSFT), KC_UP, KC_PGDN, \
  KC_LCTL, KC_LGUI, KC_LALT,            LT(_FL1, KC_SPC)             , KC_RALT, TG(_FL3), KC_RCTRL, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _FL1: Function Layer
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Mcl|MsU|Mcr|   |   |PgU| Up|PgD|   |   |   |     |Hme |
   * |----------------------------------------------------------------|
   * |      |Mcm|MsL|MsD|MsR|   |Hme|Lef|Dow|Rig|   |   |        |End |
   * |----------------------------------------------------------------|
   * |        |   |   |Bl-|BL |BL+|End|MUT|VU-|VU+|   |   McL|MsU|McR |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |MsL|MsD|MsR |
   * `----------------------------------------------------------------'
   */
[_FL1] = KEYMAP_ANSI(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_DEL,  KC_INS, \
  _______  , _______, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2,_______,_______, KC_PGUP, KC_UP, KC_PGDN, _______, _______,_______, _______,KC_HOME, \
  _______    , KC_MS_BTN3, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,_______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,_______,_______,_______,KC_END, \
  _______      , _______, _______,  BL_DEC,  BL_TOGG,  BL_INC, KC_UP ,   KC_MUTE,   KC_VOLD,  KC_VOLU, _______, KC_BTN1, KC_MS_U, KC_BTN2, \
  _______, _______, _______,                 _______                                  , _______, _______, _______,KC_MS_L,KC_MS_D, KC_MS_R),


  /* Keymap _FL2: Programming Layer
   * ,----------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |Dbg|Cpl|   |   |       |    |
   * |----------------------------------------------------------------|
   * |     |   | ^ | / | - | | | ? | + | * | = | ! |   |   |     |    |
   * |----------------------------------------------------------------|
   * |      |   | < | [ | { | ( | ) | } | ] | > |   |   |        |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |                        |   |   |   |   |   |    |
   * `----------------------------------------------------------------'
   */
[_FL2] = KEYMAP_ANSI(
  _______,_______,_______,_______,_______,_______,_______,_______,_______,LSFT(KC_F9),LSFT(KC_F10), _______, _______,     _______, _______, \
  _______  , _______, KC_CIRC, KC_SLSH, KC_MINS, KC_PIPE, KC_QUES, KC_PLUS, KC_ASTR,  KC_EQL, KC_EXLM, _______, _______,  _______, _______, \
  _______    , _______, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, _______, _______,         _______, _______, \
  _______      , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, \
  _______ , _______, _______,                 _______                               , _______, _______, _______, _______, _______, _______),


  /* Keymap _FL3: Numpad Layer
   * ,----------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |    |
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   | 7 | 8 | 9 |  | / |   |     |    |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   | 4 | 5 | 6 | - | * | Enter  |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   | 1 | 2 | 3 | + |      |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |            0           | . |   |   |   |   |    |
   * `----------------------------------------------------------------'
   */
[_FL3] = KEYMAP_ANSI(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, \
  _______  , _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, KC_PSLS, _______,  _______, _______, \
  _______    , _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, KC_PAST,     KC_KP_ENTER, _______, \
  _______      , _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS,       _______, _______, _______, \
  _______ , _______, _______,                 KC_KP_0                              ,TD(TD_DOT_COM),_______,_______,_______,_______,_______),
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {

  switch (id) {
    case 0:
      if (record->event.pressed) {
        layer_invert(_FL3);
	add_key(KC_NLCK);
	del_key(KC_NLCK);
//	breathing_speed_set(3);
		breathing_pulse();
      }
  }
};
