// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"

#define BASE               0 // default layer
#define MOTI               1 // motion layer
#define SYMB               2 // symbols
#define MDIA               3 // media keys
#define _______            KC_TRNS
#define XXXXXXX            KC_NO
#define MISSION_CONTROL    LCTL(KC_UP)
#define EXPOSE             LCTL(KC_DOWN)

enum custom_keycodes {
   QWERTY = SAFE_RANGE,
   EMAIL,
   NVIM,
   SSH_CONFIG_EDIT,
   NVIM_CONFIG_EDIT,
   ZSH_CONFIG_EDIT,
   HIST_GREP,
   SAFARI_BOOKS,
   TMUX_RENAME_PANE,
   TMUX_ONE,
   TMUX_TWO,
   TMUX_THREE,
   TMUX_FOUR,
   TMUX_LEFT_WINDOW,
   TMUX_RIGHT_WINDOW,
   TMUX_UPPER_SESSION,
   TMUX_LOWER_SESSION,
   RSYNC,
   SEARCH,
   FIREFOX,
   ITERM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   6  |           |   7  |   8  |   9  |   0  |   -  |   +  | Bckspc |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  | Left |           |  Up  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Ctrl  |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |  "     |
 * |--------+------+------+------+------+------| Right|           | Down |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * |--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * |MO(MOTI)| Ctrl | Alt  | CMD  | Lang |                                       | Space|   `  |   [  |   ]  | Neovim |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Home | End  |       |TLWind|TRWind|
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      | PgUp |       |TUSess|       |      |
 *                                 | Enter| ITERM|------|       |------|FIREFOX|SEARCH|
 *                                 |      |      | PgDn |       |TLSess|       |      |
 *                                 `--------------------'       `---------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
   [BASE] = LAYOUT_ergodox( // layer 0 : default
      // left hand
      KC_GESC,            KC_1,              KC_2,        KC_3,          KC_4,          KC_5,       KC_6,
      KC_TAB,             KC_Q,              KC_W,        KC_E,          KC_R,          KC_T,       KC_LEFT,
      KC_LCTRL,           KC_A,              KC_S,        KC_D,          KC_F,          KC_G,
      KC_LSFT,            KC_Z,              KC_X,        KC_C,          KC_V,          KC_B,       KC_RIGHT,
      MO(MOTI),           KC_LCTRL,          KC_LALT,     KC_LCMD,       LCMD(KC_SPC),
      KC_HOME,            KC_END,
      KC_PGUP,
      KC_ENT,             ITERM,             KC_PGDN,
      // right hand
      KC_7,               KC_8,              KC_9,        KC_0,          KC_MINS,       KC_EQL,     KC_BSPC,
      KC_UP,              KC_Y,              KC_U,        KC_I,          KC_O,          KC_P,       KC_BSLS,
      KC_H,               KC_J,              KC_K,        KC_L,          KC_SCLN,       KC_QUOT,
      KC_DOWN,            KC_N,              KC_M,        KC_COMM,       KC_DOT,        KC_SLSH,    KC_RSFT,
      KC_SPC,             KC_GRV,            KC_LBRC,     KC_RBRC,       NVIM,
      TMUX_LEFT_WINDOW,   TMUX_RIGHT_WINDOW,
      TMUX_UPPER_SESSION,
      TMUX_LOWER_SESSION, FIREFOX,           SEARCH
      ),

/* Keymap 1: Motion layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |           |  F7  |  F8  |  F9  | F10  | F11  | F12  |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           | MISN |MsSrLt|MsSrDn|MsSrUp|MsSrRt|      |        |
 * |--------+------+------+------+------+------|      |           | CTRL |------+------+------+------+------+--------|
 * |        |      |      |      |MsLtBn|MsRtBn|------|           |------|MsLeft|MsDown| MsUp |MsRght|      |        |
 * |--------+------+------+------+------+------|      |           |EXPOSE|------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 * |        |      |      |      |      |                                       |      |      |      |      |        |
 * `------------------------------------'                                       `------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+-------+------.
 *                                 |      |      |      |       |      |       |      |
 *                                 |      |      |------|       |------|       |      |
 *                                 |      |      |      |       |      |       |      |
 *                                 `--------------------'       `---------------------'
 */
   [MOTI] = LAYOUT_ergodox( // layer 1 : motion
      // left hand
      KC_TRNS,            KC_F1,             KC_F2,       KC_F3,         KC_F4,         KC_F5,      KC_F6,
      KC_NO,              KC_NO,             KC_NO,       KC_NO,         KC_NO,         KC_NO,      KC_NO,
      KC_NO,              KC_NO,             KC_NO,       KC_NO,         KC_MS_BTN1,    KC_MS_BTN2,
      KC_LSFT,            KC_NO,             KC_NO,       KC_NO,         KC_NO,         KC_NO,      KC_NO,
      KC_NO,              KC_NO,             KC_NO,       KC_LCMD,       KC_NO,
      KC_NO,              KC_NO,
      KC_NO,
      KC_NO,              KC_NO,             KC_NO,
      // right hand
      KC_F7,              KC_F8,             KC_F9,       KC_F10,        KC_F11,        KC_F12,     KC_NO,
      MISSION_CONTROL,    KC_MS_WH_RIGHT,    KC_MS_WH_UP, KC_MS_WH_DOWN, KC_MS_WH_LEFT, KC_NO,      KC_NO,
      KC_MS_LEFT,         KC_MS_DOWN,        KC_MS_UP,    KC_MS_RIGHT,   KC_NO,         KC_NO,
      EXPOSE,             KC_NO,             KC_NO,       KC_NO,         KC_NO,         KC_NO,      KC_NO,
      KC_NO,              KC_NO,             KC_NO,       KC_NO,         KC_NO,
      KC_NO,              KC_NO,
      KC_NO,
      KC_NO,              KC_NO,             KC_NO
      ),


/* Keymap 2: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
   [SYMB] = LAYOUT_ergodox(
      // left hand
      KC_TRNS,            KC_F1,             KC_F2,       KC_F3,         KC_F4,         KC_F5,      KC_TRNS,
      KC_TRNS,            KC_EXLM,           KC_AT,       KC_LCBR,       KC_RCBR,       KC_PIPE,    KC_TRNS,
      KC_TRNS,            KC_HASH,           KC_DLR,      KC_LPRN,       KC_RPRN,       KC_GRV,
      KC_TRNS,            KC_PERC,           KC_CIRC,     KC_LBRC,       KC_RBRC,       KC_TILD,    KC_TRNS,
      KC_TRNS,            KC_TRNS,           KC_TRNS,     KC_TRNS,       KC_TRNS,
      KC_TRNS,            KC_TRNS,
      KC_TRNS,
      KC_TRNS,            KC_TRNS,           KC_TRNS,
      // right hand
      KC_TRNS,            KC_F6,             KC_F7,       KC_F8,         KC_F9,         KC_F10,     KC_F11,
      KC_TRNS,            KC_UP,             KC_7,        KC_8,          KC_9,          KC_ASTR,    KC_F12,
      KC_DOWN,            KC_4,              KC_5,        KC_6,          KC_PLUS,       KC_TRNS,
      KC_TRNS,            KC_AMPR,           KC_1,        KC_2,          KC_3,          KC_BSLS,    KC_TRNS,
      KC_TRNS,            KC_DOT,            KC_0,        KC_EQL,        KC_TRNS,
      KC_TRNS,            KC_TRNS,
      KC_TRNS,
      KC_TRNS,            KC_TRNS,           KC_TRNS
      ),

/* Keymap 3: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
   [MDIA] = LAYOUT_ergodox(
      KC_TRNS,            KC_TRNS,           KC_TRNS,     KC_TRNS,       KC_TRNS,       KC_TRNS,    KC_TRNS,
      KC_TRNS,            KC_TRNS,           KC_TRNS,     KC_MS_U,       KC_TRNS,       KC_TRNS,    KC_TRNS,
      KC_TRNS,            KC_TRNS,           KC_MS_L,     KC_MS_D,       KC_MS_R,       KC_TRNS,
      KC_TRNS,            KC_TRNS,           KC_TRNS,     KC_TRNS,       KC_TRNS,       KC_TRNS,    KC_TRNS,
      KC_TRNS,            KC_TRNS,           KC_TRNS,     KC_BTN1,       KC_BTN2,
      KC_TRNS,            KC_TRNS,
      KC_TRNS,
      KC_TRNS,            KC_TRNS,           KC_TRNS,
      // right hand
      KC_TRNS,            KC_TRNS,           KC_TRNS,     KC_TRNS,       KC_TRNS,       KC_TRNS,    KC_TRNS,
      KC_TRNS,            KC_TRNS,           KC_TRNS,     KC_TRNS,       KC_TRNS,       KC_TRNS,    KC_TRNS,
      KC_TRNS,            KC_TRNS,           KC_TRNS,     KC_TRNS,       KC_TRNS,       KC_MPLY,
      KC_TRNS,            KC_TRNS,           KC_TRNS,     KC_MPRV,       KC_MNXT,       KC_TRNS,    KC_TRNS,
      KC_VOLU,            KC_VOLD,           KC_MUTE,     KC_TRNS,       KC_TRNS,
      KC_TRNS,            KC_TRNS,
      KC_TRNS,
      KC_TRNS,            KC_TRNS,           KC_WBAK
      ),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
   // MACRODOWN only works in this function
   switch (id) {
   case 0 :
      if (record->event.pressed) {
         register_code(KC_RSFT);
      } else {
         unregister_code(KC_RSFT);
      }
      break;
   }
   return(MACRO_NONE);
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
   uint8_t layer = biton32(layer_state);

   ergodox_board_led_off();
   ergodox_right_led_1_off();
   ergodox_right_led_2_off();
   ergodox_right_led_3_off();
   switch (layer) {
   // TODO: Make this relevant to the ErgoDox EZ.
   case MOTI :
      ergodox_right_led_1_on();
      break;
   case SYMB :
      ergodox_right_led_2_on();
      break;
   case MDIA :
      ergodox_right_led_3_on();
      break;
   default :
      // none
      break;
   }
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
   case EMAIL :
      if (record->event.pressed) {
         SEND_STRING("alexander.tuzhikov@gmail.com");
      }
      break;
   case SSH_CONFIG_EDIT :
      if (record->event.pressed) {
         SEND_STRING("nvim ~/.ssh/config" SS_TAP(X_ENTER));
      }
      break;
   case NVIM :
      if (record->event.pressed) {
         SEND_STRING("nvim" SS_TAP(X_ENTER));
      }
      break;
   case NVIM_CONFIG_EDIT :
      if (record->event.pressed) {
         SEND_STRING("nvim ~/.vim_cfg/.vimrc" SS_TAP(X_ENTER));
      }
      break;
   case ZSH_CONFIG_EDIT :
      if (record->event.pressed) {
         SEND_STRING("nvim ~/.zshrc" SS_TAP(X_ENTER));
      }
      break;
   case HIST_GREP :
      if (record->event.pressed) {
         SEND_STRING("history | grep ");
      }
      break;
   case SAFARI_BOOKS :
      if (record->event.pressed) {
         SEND_STRING(
            "python3 safaribooks.py --cred 'atuzhikov@illumina.com:0B7iYmD67BHg' ");
      }
      break;
   case TMUX_RENAME_PANE :
      if (record->event.pressed) {
         SEND_STRING(SS_LCTRL("a") ":" "select-pane -T '");
      }
      break;
   case TMUX_ONE :
      if (record->event.pressed) {
         SEND_STRING(SS_LCTRL("a") "s" "0");
      }
      break;
   case TMUX_TWO :
      if (record->event.pressed) {
         SEND_STRING(SS_LCTRL("a") "s" "1");
      }
      break;
   case TMUX_THREE :
      if (record->event.pressed) {
         SEND_STRING(SS_LCTRL("a") "s" "2");
      }
      break;
   case TMUX_FOUR :
      if (record->event.pressed) {
         SEND_STRING(SS_LCTRL("a") "s" "3");
      }
      break;
   case TMUX_LEFT_WINDOW :
      if (record->event.pressed) {
         SEND_STRING(SS_LCTRL("a") "[");
      }
      break;
   case TMUX_RIGHT_WINDOW :
      if (record->event.pressed) {
         SEND_STRING(SS_LCTRL("a") "]");
      }
      break;
   case TMUX_UPPER_SESSION :
      if (record->event.pressed) {
         SEND_STRING(SS_LCTRL("a") "(");
      }
      break;
   case TMUX_LOWER_SESSION :
      if (record->event.pressed) {
         SEND_STRING(SS_LCTRL("a") ")");
      }
      break;
   case RSYNC :
      if (record->event.pressed) {
         SEND_STRING("rsync -avhP ");
      }
      break;
   case SEARCH :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)));
      }
      break;
   case FIREFOX :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)));
         _delay_ms(300);
         SEND_STRING("fire");
         _delay_ms(200);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case ITERM :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)));
         _delay_ms(300);
         SEND_STRING("iterm");
         _delay_ms(200);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   }
   return(true);
};
