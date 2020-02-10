#include QMK_KEYBOARD_H
#include "tada68.h"
#include "keymap_german.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL1 1
#define _FL2 2
#define _FL3 3
#define _GAME 4
#define _GFN 5
#define _MIDI 6

#define _______ KC_TRNS
#define xxxxxxx KC_NO

// tap dance
#define TD_DOT_COM 0
#define TD_NP_SPC 1

// custom functions
#define NPAD 0
#define BLDN 1
#define BLUP 2

//led mode
uint8_t led_mode = 0;

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_DOT_COM] = ACTION_TAP_DANCE_DOUBLE(KC_PDOT, KC_PCMM),
  [TD_NP_SPC] = ACTION_TAP_DANCE_DOUBLE(KC_KP_0, KC_SPC)
};

const uint16_t PROGMEM fn_actions[] = {
  [NPAD] = ACTION_FUNCTION(NPAD),  // Calls action_function()
  [BLDN] = ACTION_FUNCTION(BLDN),
  [BLUP] = ACTION_FUNCTION(BLUP),
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
   * |Ctrl|Win |Alt |       SpaceFn1        |Alt|Fn3|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = LAYOUT_ansi(
  KC_ESC  ,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,   KC_BSPC, KC_GRV, \
  KC_TAB   ,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
  LT(_FL2,KC_DEL),KC_A,KC_S, KC_D,   KC_F,   KC_G,   KC_H ,  KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,       KC_ENT,  KC_PGUP, \
  OSM(MOD_LSFT),KC_Z, KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH, OSM(MOD_RSFT), KC_UP, KC_PGDN, \
  KC_LCTL, KC_LGUI, KC_LALT,             LT(_FL1, KC_SPC)             , KC_RALT, F(NPAD), KC_RCTRL, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Keymap _FL1: Function Layer
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |   |McL|MsU|McR|   |   |PgU| Up|PgD|   | Ü |   |     |    |
   * |----------------------------------------------------------------|
   * |      |McM|MsL|MsD|MsR|   |Hme|Lef|Dow|Rig| Ö | Ä |        |MIDI|
   * |----------------------------------------------------------------|
   * |        |   |   |Bl-|BL |BL+|End|MUT|VU-|VU+| ß |      |   |GAME|
   * |----------------------------------------------------------------|
   * |    |    |    |                        |   |   |   |   |   |    |
   * `----------------------------------------------------------------'
   */
[_FL1] = LAYOUT_ansi(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_DEL,  KC_INS, \
  _______  , _______, KC_MS_BTN1,KC_MS_UP,KC_MS_BTN2,_______,_______, KC_PGUP, KC_UP, KC_PGDN, _______,RALT(KC_Y),_______, _______,_______, \
  _______    , KC_MS_BTN3, KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT,_______,KC_HOME,KC_LEFT,KC_DOWN,KC_RIGHT,RALT(KC_P),RALT(KC_Q),_______,TO(_MIDI), \
  _______      , _______, _______, F(BLDN),  BL_TOGG, F(BLUP), KC_END ,  KC_MUTE, KC_VOLD,  KC_VOLU,RALT(KC_S), _______, _______,TO(_GAME), \
  _______, _______, _______,                 _______                                , _______, _______, _______, _______, _______, _______),


  /* Keymap _FL2: Programming Layer
   * ,----------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |Dbg|Cpl|   |   |       |    |
   * |----------------------------------------------------------------|
   * |     |   | % | / | - | | | & | + | * | ^ | ! | ? |   |     |    |
   * |----------------------------------------------------------------|
   * |      |   | < | [ | { | ( | ) | } | ] | > | = |   |        |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |                        |   |   |   |   |   |    |
   * `----------------------------------------------------------------'
   */
[_FL2] = LAYOUT_ansi(
  _______,_______,_______,_______,_______,_______,_______,_______,_______,LSFT(KC_F9),LSFT(KC_F10), _______, _______,     _______, _______, \
  _______  , _______, KC_PERC, KC_SLSH, KC_MINS, KC_PIPE, KC_AMPR, KC_PLUS, KC_ASTR, KC_CIRC, KC_EXLM, KC_QUES, _______,  _______, _______, \
  _______    , _______, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK,  KC_EQL, _______,         _______, _______, \
  _______      , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, \
  _______ , _______, _______,                 _______                               , _______, _______, _______, _______, _______, _______),


  /* Keymap _FL3: Numpad Layer
   * ,----------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |    |
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   | 7 | 8 | 9 |   | / |   |     |    |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   | 4 | 5 | 6 | - | * | Enter  |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   | 1 | 2 | 3 | + |      |   |    |
   * |----------------------------------------------------------------|
   * |    |    |    |            0           | . |   |   |   |   |    |
   * `----------------------------------------------------------------'
   */
[_FL3] = LAYOUT_ansi(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______, _______, \
  _______  , _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, _______, KC_PSLS, _______,  _______, _______, \
  _______    , _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_PMNS, KC_PAST,     KC_KP_ENTER, _______, \
  _______      , _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_PPLS,       _______, _______, _______, \
  _______ , _______, _______,                 TD(TD_NP_SPC)                        ,TD(TD_DOT_COM),_______,_______,_______,_______,_______),


  /* Keymap _GAME: Game Layer
   * ,----------------------------------------------------------------.
   * |Esc | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |~ ` |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |Caps   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgUp|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|PgDn|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |         Space         |Alt|GFN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_GAME] = LAYOUT_ansi(
  KC_ESC  ,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,   KC_BSPC, KC_GRV, \
  KC_TAB   ,KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
  KC_CAPS        ,KC_A,KC_S, KC_D,   KC_F,   KC_G,   KC_H ,  KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,       KC_ENT,  KC_PGUP, \
  KC_LSFT      ,KC_Z, KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,       KC_RSFT, KC_UP, KC_PGDN, \
  KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC               , KC_RALT, TT(_GFN), KC_RCTRL, KC_LEFT, KC_DOWN, KC_RGHT),


  /* Keymap _GFN: Game Function Layer
   * ,----------------------------------------------------------------.
   * |   | F1|F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |   |   |     |Hme |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |   |   |   |   |   |   |   |        |End |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |      |   |_BL |
   * |----------------------------------------------------------------|
   * |    |    |    |                        |   |   |   |   |   |    |
   * `----------------------------------------------------------------'
   */
[_GFN] = LAYOUT_ansi(
  _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12, KC_DEL,  KC_INS, \
  _______  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, \
  _______    , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,        _______,  KC_END, \
  _______      , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______, _______,  TO(_BL), \
  _______, _______, _______,                 _______                                , _______, _______, _______, _______, _______, _______),


  /* Keymap _MIDI: MIDI Layer
   * ,----------------------------------------------------------------.
   * |   |   |   |   |   |   |   |   |   |   |   |   |   |       |    |
   * |----------------------------------------------------------------|
   * |     |   |   | C#| D#|   | F#| G#| A#|   |   |   |   |     |    |
   * |----------------------------------------------------------------|
   * |      |   | C | D | E | F | G | A | B | C |   |   |        |_BL |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |   |   |   |     |OctU|    |
   * |----------------------------------------------------------------|
   * |    |    |    |       Sustain          |   |   |   |  |OctD|    |
   * `----------------------------------------------------------------'
   */
[_MIDI] = LAYOUT_ansi(
  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,    xxxxxxx, xxxxxxx, \
  xxxxxxx  , xxxxxxx, xxxxxxx, MI_Cs_3, MI_Ds_3, xxxxxxx, MI_Fs_3, MI_Gs_3, MI_As_3, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,  xxxxxxx, xxxxxxx, \
  xxxxxxx    , xxxxxxx, MI_C_3 , MI_D_3 , MI_E_3 , MI_F_3 , MI_G_3 , MI_A_3 , MI_B_3 , MI_C_4 , xxxxxxx, xxxxxxx,         xxxxxxx, TO(_BL), \
  xxxxxxx      , xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,       xxxxxxx, MI_OCTU, xxxxxxx, \
  xxxxxxx , xxxxxxx, xxxxxxx,                       MI_SUS                          , xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, MI_OCTD, xxxxxxx),
};


void tap(uint16_t keycode){
  register_code(keycode);
  unregister_code(keycode);
}

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {

  switch (id) {
    case NPAD:
      if (record->event.pressed) {
        layer_invert(_FL3);
        tap(KC_NLCK);
      }
    break;
    case BLDN:
      if (record->event.pressed) {
        if (led_mode < 5) {
          led_mode == 0 ? backlight_set(0) : backlight_set(--led_mode);
        } else if (led_mode == 5) {
          breathing_disable();
          backlight_set(--led_mode);
        } else {
          breathing_period_dec();
          led_mode--;
        }
      }
    break;
    case BLUP:
      if (record->event.pressed) {
        if (led_mode < 4) {
          backlight_set(++led_mode);
        } else if (led_mode == 4) {
          breathing_period_set(1);
          breathing_enable();
	  led_mode++;
        } else if (led_mode > 4) {
          breathing_period_inc();
          led_mode++;
        }
      }
    break;
  }
};

void led_set_user(uint8_t usb_led) {
  if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
    // Turn capslock on
    PORTB |= (1<<6);
  } else {
    // Turn capslock off
    PORTB &= ~(1<<6);
  }
}
