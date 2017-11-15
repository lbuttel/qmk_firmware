#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _NAVPAD 2
#define _NAVF 3
#define _LOWER 4
#define _RAISE 5
#define _ADJUST 6
#define _ONEHAND 7
#define _OTHERSIDE 8
#define _ONEHANDSYM 9
#define _OTHERSIDESYM 10
#define _ONEHANDNAV 11
#define _ONEHANDPAD 12
#define _ONEHANDF 13
#define _GAME 15


#define DANCINGLAYERS 0
#define OH 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  ONEHAND,
  OTHERSIDE,
  ONEHANDSYM,
  OTHERSIDESYM,
  OHOFF,
  LOWER,
  RAISE,
  ADJUST,
  GAME
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------|-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |Lower |Shift |Space |Enter |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------|-----------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_ESC       ,  KC_Q  ,    KC_W,    KC_E,  KC_R,                         KC_T,              KC_Y,  KC_U,    KC_I,    KC_O,    KC_P,       KC_BSPC, \
  KC_TAB       ,  KC_A  ,    KC_S,    KC_D,  KC_F,                         KC_G,              KC_H,  KC_J,    KC_K,    KC_L, KC_SCLN,       KC_QUOT, \
  OSM(MOD_LSFT), KC_Z   ,    KC_X,    KC_C,  KC_V,                         KC_B,              KC_N,  KC_M, KC_COMM,  KC_DOT, KC_SLSH, OSM(MOD_RSFT), \
  KC_LCTL      , KC_LGUI, KC_LALT,   LOWER,  OSM(MOD_LSFT), LT(_NAVPAD, KC_SPC), LT(_NAVF, KC_ENT), RAISE, KC_LEFT, KC_DOWN,   KC_UP,       KC_RGHT \
),

/* Nav
 * ,-----------------------------------------|-----------------------------------------.
 * |      |      |MCLeft|  MUp |MCRigh|      |      | PgUp |  Up  | PgDn |      |  ü   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Del  | MCMid| MLeft| MDown|MRight|      | Home | Left | Down | Right|  ö   |  ä   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |  End | Mute | Vol+ | Vol- |  ß   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------|-----------------------------------------'
 *
[_NAV] = KEYMAP( \
  _______, _______  ,KC_MS_BTN1,KC_MS_UP  ,KC_MS_BTN2 , _______, _______, KC_PGUP,  KC_UP , KC_PGDN, _______  ,RALT(KC_Y), \
  KC_DEL ,KC_MS_BTN3,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT, _______, KC_HOME, KC_LEFT, KC_DOWN,KC_RIGHT,RALT(KC_P),RALT(KC_Q), \
  _______, _______  , _______  , _______  , _______   , _______, KC_END , KC_MUTE, KC_VOLD, KC_VOLU,RALT(KC_S), _______, \
  _______, _______  , _______  , _______  , _______   , _______, _______, _______, _______, _______, _______, _______  \
),
*/

/* NavPad
 * ,-----------------------------------------|-----------------------------------------.
 * |      |      |MCRigh|  MUp |MCLeft|      |      |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Del  | MCMid| MLeft| MDown|MRight|      |      |   4  |   5  |   6  |   -  |   /  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |   1  |   2  |   3  |   +  |   *  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | 1Hand|      |      |      |      |      |      |   0  |   .  |   ,  |   ^  |   %  |
 * `-----------------------------------------|-----------------------------------------'
 */
[_NAVPAD] = KEYMAP( \
  _______, _______  ,KC_MS_BTN2,KC_MS_UP  ,KC_MS_BTN1 , _______, _______, KC_7, KC_8   , KC_9   , _______, _______, \
  KC_DEL ,KC_MS_BTN3,KC_MS_LEFT,KC_MS_DOWN,KC_MS_RIGHT, _______, _______, KC_4, KC_5   , KC_6   , KC_MINS, KC_SLSH, \
  _______, _______  , _______  , _______  , _______   , _______, _______, KC_1, KC_2   , KC_3   , KC_PPLS, KC_PAST, \
  ONEHAND, _______  , _______  , _______  , _______   , _______, _______, KC_0,  KC_DOT, KC_COMM, KC_CIRC, KC_PERC  \
),

/* NavF
 * ,-----------------------------------------|-----------------------------------------.
 * |      |  F10 |  F9  |  F8  |  F7  |      |      | PgUp |  Up  | PgDn |  ü   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Del  |  F11 |  F6  |  F5  |  F4  |      | Home | Left | Down | Right|  ö   |  ä   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F12 |  F3  |  F2  |  F1  |      |  End | Mute | Vol+ | Vol- |  ß   |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | 1Hand|
 * `-----------------------------------------|-----------------------------------------'
 */
[_NAVF] = KEYMAP( \
  _______,    KC_F10,   KC_F9,   KC_F8,   KC_F7, _______, _______, KC_PGUP,  KC_UP , KC_PGDN,RALT(KC_Y), _______  , \
  KC_DEL ,    KC_F11,   KC_F6,   KC_F5,   KC_F4, _______, KC_HOME, KC_LEFT, KC_DOWN,KC_RIGHT,RALT(KC_P),RALT(KC_Q), \
  _______,    KC_F12,   KC_F3,   KC_F2,   KC_F1, _______, KC_END , KC_MUTE, KC_VOLD, KC_VOLU,RALT(KC_S), _______  , \
  _______, _______  , _______, _______, _______, _______, _______, _______, _______, _______, _______  , ONEHAND  \
),

/* Lower
 * ,-----------------------------------------|-----------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |      |   \  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------|-----------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC, \
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, _______, KC_BSLS, KC_PIPE, \
  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY \
),

/* Raise
 * ,-----------------------------------------|-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Del  |   -  |   <  |   [  |   {  |   (  |   )  |   }  |   ]  |   >  |   =  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------|-----------------------------------------'
 */
[_RAISE] = KEYMAP( \
   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC, \
   KC_DEL, KC_MINS, KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK,  KC_EQL, KC_BSLS, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------|-----------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      | 1Hand|      |  Del |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff| Game |AGswap|Qwerty|      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |AGnorm|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------|-----------------------------------------'
 */
[_ADJUST] =  KEYMAP( \
  _______, RESET,   _______, _______, _______, _______, _______, _______, _______, ONEHAND, _______,  KC_DEL, \
  _______, _______, _______,   AU_ON,  AU_OFF,    GAME, AG_SWAP,  QWERTY, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, AG_NORM, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

/* Onehand
 * ,-----------------------------------------|-----------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | TDL  |OHSYM |Space |Space |OHSYM | Left | Down |  Up  |Right |
 * `-----------------------------------------|-----------------------------------------'
 */
[_ONEHAND] = KEYMAP( \
  KC_ESC       ,  KC_Q  ,    KC_W,              KC_E,       KC_R,                   KC_T,                   KC_Y,       KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC, \
  KC_TAB       ,  KC_A  ,    KC_S,              KC_D,       KC_F,                   KC_G,                   KC_H,       KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, \
  OSM(MOD_LSFT), KC_Z   ,    KC_X,              KC_C,       KC_V,                   KC_B,                   KC_N,       KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT, \
  KC_LCTL      , KC_LGUI, KC_LALT, TD(DANCINGLAYERS), ONEHANDSYM, LT(_OTHERSIDE, KC_SPC), LT(_OTHERSIDE, KC_SPC), ONEHANDSYM, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT  \
),

/* Otherside
 * ,-----------------------------------------|-----------------------------------------.
 * | Bksp |   P  |   O  |   I  |   U  |   Y  |   T  |   R  |   E  |   W  |   Q  | Esc  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   "  |   ;  |   L  |   K  |   J  |   H  |   G  |   F  |   D  |   S  |   A  | Tab  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Enter|   /  |   .  |   ,  |   M  |   N  |   B  |   V  |   C  |   X  |   Z  |Shift |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Right|  Up  | Down | Left |OSSYM |      |      |OSSYM |  TDL | Alt  | GUI  | Ctrl |
 * `-----------------------------------------|-----------------------------------------'
 */

[_OTHERSIDE] = KEYMAP( \
  KC_BSPC , KC_P   ,   KC_O ,    KC_I,         KC_U,    KC_U,    KC_T,         KC_R,              KC_E,    KC_W,    KC_Q,        KC_ESC, \
  KC_QUOT , KC_SCLN,   KC_L ,    KC_K,         KC_J,    KC_H,    KC_G,         KC_F,              KC_D,    KC_S,    KC_A,        KC_TAB, \
  KC_ENT  , KC_SLSH,  KC_DOT, KC_COMM,         KC_M,    KC_N,    KC_B,         KC_V,              KC_C,    KC_X,    KC_Z, OSM(MOD_LSFT), \
  KC_RIGHT, KC_UP  , KC_DOWN, KC_LEFT, OTHERSIDESYM, _______, _______, OTHERSIDESYM, TD(DANCINGLAYERS), KC_LALT, KC_LGUI,       KC_LCTL  \
),

/* OnehandSym
 * ,-----------------------------------------|-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   O  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   -  |   <  |   [  |   {  |  (   |  )   |   }  |   ]  |   >  |   =  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   _  |      |      |      |Space |Space |      |      |      |   +  |  |   |
 * `-----------------------------------------|-----------------------------------------'
 */
[_ONEHANDSYM] = KEYMAP( \
   KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,         KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC, \
  KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR,      KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX, \
  XXXXXXX, KC_MINS, KC_LABK, KC_LBRC, KC_LCBR,      KC_LPRN,      KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK,  KC_EQL, KC_BSLS, \
  XXXXXXX, KC_UNDS, XXXXXXX, XXXXXXX, _______, OTHERSIDESYM, OTHERSIDESYM, _______, XXXXXXX, XXXXXXX, KC_PLUS, KC_PIPE  \
),

/* OthersideSym
 * ,-----------------------------------------|-----------------------------------------.
 * | Bksp |   0  |   9  |   8  |   7  |   6  |   5  |   4  |   3  |   2  |   1  |  `   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   )  |   (  |   *  |   &  |   ^  |   %  |   $  |   #  |   @  |   !  |  ~   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   \  |   =  |   >  |   ]  |   }  |   )  |   (  |   {  |   [  |   <  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   |  |   +  |      | Back |      |      |      |      | Back |      |      |      |
 * `-----------------------------------------|-----------------------------------------'
 */

[_OTHERSIDESYM] = KEYMAP( \
  KC_BSPC,    KC_0,   KC_9 ,    KC_8,    KC_7,    KC_6,    KC_5,    KC_4,    KC_3,    KC_2,    KC_1,  KC_GRV, \
  XXXXXXX, KC_RPRN, KC_LPRN, KC_ASTR, KC_AMPR, KC_CIRC, KC_PERC,  KC_DLR, KC_HASH,   KC_AT, KC_EXLM, KC_TILD, \
  KC_BSLS,  KC_EQL, KC_RABK, KC_RBRC, KC_RCBR, KC_RPRN, KC_LPRN, KC_LCBR, KC_LBRC, KC_LABK, KC_MINS, XXXXXXX, \
  KC_PIPE, KC_PLUS, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, KC_UNDS, XXXXXXX  \
),

/* OnehandNumpad
 * ,-----------------------------------------|-----------------------------------------.
 * |      |      |   9  |   8  |   7  |      |      |   7  |   8  |   9  |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   /  |   -  |   6  |   5  |   4  |      |      |   4  |   5  |   6  |   -  |   /  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   *  |   +  |   3  |   2  |   1  |      |      |   1  |   2  |   3  |   +  |   *  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   ^  |   %  |      | Back |   .  |  0   |   0  |   .  | Back |      |   ^  |   %  |
 * `-----------------------------------------|-----------------------------------------'
 */
[_ONEHANDPAD] = KEYMAP( \
  XXXXXXX, XXXXXXX,    KC_9,         KC_8,   KC_7, XXXXXXX, XXXXXXX,   KC_7,         KC_8,    KC_9, XXXXXXX, XXXXXXX, \
  KC_SLSH, KC_MINS,    KC_6,         KC_5,   KC_4, XXXXXXX, XXXXXXX,   KC_4,         KC_5,    KC_6, KC_MINS, KC_SLSH, \
  KC_PAST, KC_PLUS,    KC_3,         KC_2,   KC_1, XXXXXXX, XXXXXXX,   KC_1,         KC_2,    KC_3, KC_PPLS, KC_PAST, \
  KC_PERC, KC_CIRC, XXXXXXX, TO(_ONEHAND), KC_DOT,    KC_0,    KC_0, KC_DOT, TO(_ONEHAND), XXXXXXX, KC_CIRC, KC_PERC  \
),

/* OnehandNav
 * ,-----------------------------------------|-----------------------------------------.
 * |      |  ü   | PgDn |  Up  | PgUp |      |      | PgUp |  Up  | PgDn |   ü  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  ä   |  ö   | Left | Down | Right| Home | Home | Left | Down | Right|   ö  |   ä  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  ß   | Vol- | Vol+ | Mute | End  |  End | Mute | Vol+ | Vol- |   ß  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      | Back |      |      |      |      | Back |      |      |      |
 * `-----------------------------------------|-----------------------------------------'
 */
[_ONEHANDNAV] = KEYMAP( \
     XXXXXXX, RALT(KC_Y), KC_PGDN,        KC_UP,  KC_PGUP, XXXXXXX, XXXXXXX, KC_PGUP,        KC_UP,  KC_PGDN, RALT(KC_Y),    XXXXXXX, \
  RALT(KC_Q), RALT(KC_P), KC_LEFT,      KC_DOWN, KC_RIGHT, KC_HOME, KC_HOME, KC_LEFT,      KC_DOWN, KC_RIGHT, RALT(KC_P), RALT(KC_Q), \
     XXXXXXX, RALT(KC_S), KC_VOLU,      KC_VOLD,  KC_MUTE,  KC_END, KC_END , KC_MUTE,      KC_VOLD,  KC_VOLU, RALT(KC_S),    XXXXXXX, \
     XXXXXXX,    XXXXXXX, XXXXXXX, TO(_ONEHAND),  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_ONEHAND),  XXXXXXX,    XXXXXXX,    XXXXXXX  \
),

/* OnehandF
 * ,-----------------------------------------|-----------------------------------------.
 * | OHOFF|  F10 |  F9  |  F8  |  F7  |      |      |  F7  |  F8  |  F9  | F10  | OHOFF|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F11 |  F6  |  F5  |  F4  |      |      |  F4  |  F5  |  F6  | F11  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F12 |  F3  |  F2  |  F1  |      |      |  F1  |  F2  |  F3  | F12  |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      | Back |      |      |      |      | Back |      |      |      |
 * `-----------------------------------------|-----------------------------------------'
 */
[_ONEHANDF] = KEYMAP( \
    OHOFF,  KC_F10,   KC_F9,        KC_F8,   KC_F7, XXXXXXX, XXXXXXX,   KC_F7,        KC_F8,   KC_F9,   KC_F10,   OHOFF, \
  XXXXXXX,  KC_F11,   KC_F6,        KC_F5,   KC_F4, XXXXXXX, XXXXXXX,   KC_F4,        KC_F5,   KC_F6,   KC_F11, XXXXXXX, \
  XXXXXXX,  KC_F12,   KC_F3,        KC_F2,   KC_F1, XXXXXXX, XXXXXXX,   KC_F1,        KC_F2,   KC_F3,   KC_F12, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, TO(_ONEHAND), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(_ONEHAND), XXXXXXX, XXXXXXX , XXXXXXX  \
),

/* Game
 * ,-----------------------------------------|-----------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |   N  |   M  |   ,  |   .  |   /  | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  |   C  |Space |Space |Space |QWERTY| Left | Down |  Up  |Right |
 * `-----------------------------------------|-----------------------------------------'
 */
[_GAME] = KEYMAP( \
  KC_ESC ,    KC_1,    KC_2, KC_3,   KC_4,   KC_5,   KC_Y,   KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC, \
  KC_TAB ,    KC_Q,    KC_W, KC_E,   KC_R,   KC_T,   KC_H,   KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT, \
  KC_LSFT,    KC_A,    KC_S, KC_D,   KC_F,   KC_G,   KC_N,   KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ENT, \
  KC_LCTL, KC_LGUI, KC_LALT, KC_C, KC_SPC, KC_SPC, KC_SPC, QWERTY, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT  \
),

/* empty layout template

 * Nav
 * ,-----------------------------------------|-----------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------|-----------------------------------------'
 *

[_] = KEYMAP( \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),
*/
};


void dance_layers(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
    case 1:
      layer_move(_ONEHANDNAV);
      break;
    case 2:
      layer_move(_ONEHANDPAD);
      break;
    case 3:
      layer_move(_ONEHANDF);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [DANCINGLAYERS] = ACTION_TAP_DANCE_FN(dance_layers)
};


#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case GAME:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_GAME);
        layer_move(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
    case ONEHAND:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_ONEHAND);
      }
      return false;
      break;
    case OTHERSIDE:
      if (record->event.pressed) {
        layer_on(_OTHERSIDE);
        update_tri_layer(_OTHERSIDE, _ONEHANDSYM, _OTHERSIDESYM);
      } else {
        layer_off(_OTHERSIDE);
        update_tri_layer(_OTHERSIDE, _ONEHANDSYM, _OTHERSIDESYM);
      }
      return false;
      break;
    case ONEHANDSYM:
      if (record->event.pressed) {
        layer_on(_ONEHANDSYM);
        update_tri_layer(_OTHERSIDE, _ONEHANDSYM, _OTHERSIDESYM);
      } else {
        layer_off(_ONEHANDSYM);
        update_tri_layer(_OTHERSIDE, _ONEHANDSYM, _OTHERSIDESYM);
      }
      return false;
      break;
    case OTHERSIDESYM:
      if (record->event.pressed) {
        layer_on(_OTHERSIDESYM);
      } else {
        layer_off(_OTHERSIDESYM);
      }
      return false;
      break;
    case OHOFF:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
        layer_move(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}
