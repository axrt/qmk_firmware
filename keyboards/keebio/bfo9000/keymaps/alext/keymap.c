#include QMK_KEYBOARD_H

#define _BASE    0
enum custom_keycodes {
   QWERTY = SAFE_RANGE,
   ACTIVITY_MONITOR,
   ASYNC_TASK,
   ASYNC_TASK_EDIT,
   CALIBRE,
   CHROME,
   COC_CONFIG,
   DOCUMENTS,
   DOUBLE_ZERO,
   DOWNLOADS,
   FANTASTICAL,
   FINDER,
   GIT_KRAKEN,
   GIT_PUSH_BB,
   GIT_PUSH_BB_MASTER,
   GIT_PUSH_GH,
   GIT_PUSH_GH_MASTER,
   G_STATUS,
   MARGIN_NOTE,
   OMNIFOCUS,
   OPEN_HEADER,
   OPEN_SOURCE,
   POMODORO,
   PREFERENCES,
   PRINT_SCREEN,
   SPARK,
   TEST_NEAREST,
   TRIPLE_ZERO,
   ULTISNIPS_EDIT,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT(                                                                                                                  \
      OPEN_HEADER,  OPEN_SOURCE, G_STATUS,       GIT_PUSH_GH, GIT_PUSH_GH_MASTER, ASYNC_TASK,       KC_NO, KC_NO,       PREFERENCES,  \
      TEST_NEAREST, KC_NO,       ULTISNIPS_EDIT, GIT_PUSH_BB, GIT_PUSH_BB_MASTER, ASYNC_TASK_EDIT,  KC_NO, KC_NO,       PRINT_SCREEN, \
      COC_CONFIG,   KC_NO,       KC_NO,          KC_NO,       KC_NO,              KC_NO,            KC_7,  KC_8,        KC_9,         \
      KC_NO,        KC_NO,       KC_NO,          KC_NO,       KC_NO,              KC_NO,            KC_4,  KC_5,        KC_6,         \
      CHROME,       POMODORO,    CALIBRE,        FINDER,      DOWNLOADS,          DOCUMENTS,        KC_1,  KC_2,        KC_3,         \
      SPARK,        FANTASTICAL, GIT_KRAKEN,     MARGIN_NOTE, OMNIFOCUS,          ACTIVITY_MONITOR, KC_0,  DOUBLE_ZERO, TRIPLE_ZERO   \
      )
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
   case OPEN_HEADER :
      if (record->event.pressed) {
         SEND_STRING(SS_TAP(X_ESC));
         _delay_ms(100);
         SEND_STRING(":call OpenHeader()");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case OPEN_SOURCE :
      if (record->event.pressed) {
         SEND_STRING(SS_TAP(X_ESC));
         _delay_ms(100);
         SEND_STRING(":call OpenCPPSource()");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case G_STATUS :
      if (record->event.pressed) {
         SEND_STRING(SS_TAP(X_ESC));
         _delay_ms(100);
         SEND_STRING(":Gstatus");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case GIT_PUSH_GH :
      if (record->event.pressed) {
         SEND_STRING(SS_TAP(X_ESC));
         _delay_ms(100);
         SEND_STRING(":Gpush gh ");
      }
      break;
   case GIT_PUSH_GH_MASTER :
      if (record->event.pressed) {
         SEND_STRING(SS_TAP(X_ESC));
         _delay_ms(100);
         SEND_STRING(":Gpush gh master");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case GIT_PUSH_BB :
      if (record->event.pressed) {
         SEND_STRING(SS_TAP(X_ESC));
         _delay_ms(100);
         SEND_STRING(":Gpush bb ");
      }
      break;
   case GIT_PUSH_BB_MASTER :
      if (record->event.pressed) {
         SEND_STRING(SS_TAP(X_ESC));
         _delay_ms(100);
         SEND_STRING(":Gpush bb master");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case TEST_NEAREST :
      if (record->event.pressed) {
         SEND_STRING(SS_TAP(X_ESC));
         _delay_ms(100);
         SEND_STRING(":TestNearest");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case ULTISNIPS_EDIT :
      if (record->event.pressed) {
         SEND_STRING(SS_TAP(X_ESC));
         _delay_ms(100);
         SEND_STRING(":UltiSnipsEdit");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case ASYNC_TASK :
      if (record->event.pressed) {
         SEND_STRING(SS_TAP(X_ESC));
         _delay_ms(100);
         SEND_STRING(":AsyncTask ");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_TAB));
      }
      break;
   case ASYNC_TASK_EDIT :
      if (record->event.pressed) {
         SEND_STRING(SS_TAP(X_ESC));
         _delay_ms(100);
         SEND_STRING(":AsyncTaskEdit");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case COC_CONFIG :
      if (record->event.pressed) {
         SEND_STRING(SS_TAP(X_ESC));
         _delay_ms(100);
         SEND_STRING(":CocConfig");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case DOUBLE_ZERO :
      if (record->event.pressed) {
         SEND_STRING("00");
      }
      break;
   case TRIPLE_ZERO :
      if (record->event.pressed) {
         SEND_STRING("000");
      }
      break;
   case PRINT_SCREEN :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_4) SS_UP(X_LGUI)));
      }
      break;
   case SPARK :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)) "Spark");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case CALIBRE :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)) "Calibre");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case FINDER :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)) "Finder");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case DOWNLOADS :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)) "Downloads");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case DOCUMENTS :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)) "Documents");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case CHROME :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)) "Chrome");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case FANTASTICAL :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)) "Fantastical");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case GIT_KRAKEN :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)) "Gitkraken");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case MARGIN_NOTE :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)) "Marginnote");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case OMNIFOCUS :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)) "Omnifocus");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case ACTIVITY_MONITOR :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)) "Activity Monitor");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case PREFERENCES :
      if (record->event.pressed) {
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)) "System Preferences");
         _delay_ms(300);
         SEND_STRING(SS_TAP(X_ENTER));
      }
      break;
   case POMODORO :
      if (record->event.pressed) {
         SEND_STRING("noti --title \"Pomodoro done\" --message \"You did it!\" pomodoro start \"");
      }
      break;
   }
   return(true);
}
