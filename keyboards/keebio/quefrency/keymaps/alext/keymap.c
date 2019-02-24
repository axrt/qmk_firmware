#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE    0
#define _FN1     1
#define _FN2     2

enum custom_keycodes {
   QWERTY = SAFE_RANGE,
   FIRE,
   KITTY,
   NVIM
};

#define _______    KC_TRNS
#define XXXXXXX    KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT(
      KC_GESC,  KC_1,               KC_2,             KC_3,    KC_4,       KC_5,       KC_6,         KC_7,          KC_8,         KC_9,        KC_0,    KC_MINS, KC_EQL,  KC_BSPC,  \
      KC_TAB,   KC_Q,               KC_W,             KC_E,    KC_R,       KC_T,       KC_Y,         KC_U,          KC_I,         KC_O,        KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,  \
      KC_CAPS,  KC_A,               KC_S,             KC_D,    KC_F,       KC_G,       KC_H,         KC_J,          KC_K,         KC_L,        KC_SCLN, KC_QUOT, KC_ENT,            \
      KC_LSFT,  KC_Z,               KC_X,             KC_C,    KC_V,       KC_B,       KC_N,         KC_M,          KC_COMM,      KC_DOT,      _______, KC_SLSH, KC_GRV,  MO(_FN2), \
      MO(_FN1), KC_LCTL,            KC_LALT,          KC_LCMD, KC_SPC,     KC_SPC,     _______,      _______,       KC_LEFT,      KC_RIGHT,    _______, KC_DOWN, KC_UP
      ),

   [_FN1] = LAYOUT(
      KC_GESC,  KC_F1,              KC_F2,            KC_F3,   KC_F4,      KC_F5,      KC_F6,        KC_F7,         KC_F8,        KC_F9,       KC_F10,  KC_F11,  KC_F12,  KC_BSPC, \
      _______,  _______,            _______,          _______, _______,    _______,    _______,      KC_MS_WH_DOWN, KC_MS_WH_UP,  _______,     _______, _______, _______, _______, \
      _______,  _______,            _______,          _______, KC_MS_BTN1, KC_MS_BTN2, KC_MS_LEFT,   KC_MS_DOWN,    KC_MS_UP,     KC_MS_RIGHT, _______, _______, _______,          \
      _______,  _______,            _______,          _______, _______,    _______,    KC_MS_ACCEL0, KC_MS_ACCEL1,  KC_MS_ACCEL2, _______,     _______, _______, _______, _______, \
      _______,  _______,            _______,          _______, _______,    _______,    _______,      _______,       _______,      _______,     _______, _______, _______
      ),

   [_FN2] = LAYOUT(
      KC_GESC,  KC_BRIGHTNESS_DOWN, KC_BRIGHTNESS_UP, _______, _______,    _______,    _______,      _______,       _______,      _______,     _______, _______, _______, _______, \
      _______,  _______,            _______,          _______, _______,    _______,    _______,      _______,       _______,      _______,     _______, _______, _______, _______, \
      _______,  _______,            _______,          _______, FIRE,       _______,    _______,      _______,       KITTY,        _______,     _______, _______, _______,          \
      _______,  _______,            _______,          _______, _______,    _______,    NVIM,         _______,       _______,      _______,     _______, _______, _______, _______, \
      _______,  _______,            _______,          _______, _______,    _______,    _______,      _______,       _______,      _______,     _______, _______, _______
      )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
   case FIRE :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)) "Firefox"SS_TAP (X_ENTER));
      }
      break;
   case KITTY :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)) "Kitty"SS_TAP (X_ENTER));
      }
      break;
   case NVIM :
      if (record->event.pressed) {
         SEND_STRING("nvim" SS_TAP(X_ENTER));
      }
      break;
   }
   return(true);
}
