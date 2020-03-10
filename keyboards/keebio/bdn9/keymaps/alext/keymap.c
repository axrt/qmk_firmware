/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#define DEFAULT_TIMEOUT 300
void select_music(void);

enum custom_keycodes {
	MUSIC,
	MUSIC_DISLIKE,
	MUSIC_LIKE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT(
      KC_MUTE,         MO(1),               RGB_MODE_FORWARD,      \
      KC_MEDIA_REWIND, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_FAST_FORWARD, \
      MUSIC_LIKE,      MUSIC_DISLIKE,       MUSIC                  \
      ),
   [1] = LAYOUT(
      RGB_TOG,         KC_NO,               BL_TOGG, \
      RGB_HUI,         RGB_SAI,             BL_INC,  \
      RGB_HUD,         RGB_SAD,             BL_DEC   \
      ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
   if (index == 0) {
      if (clockwise) {
         tap_code(KC_VOLU);
      } else {
         tap_code(KC_VOLD);
      }
   }
   else if (index == 1) {
      if (clockwise) {
         tap_code(KC_BRIGHTNESS_UP);
      } else {
         tap_code(KC_BRIGHTNESS_DOWN);
      }
   }
}
void select_music(){
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_F) SS_UP(X_LGUI)));
         _delay_ms(DEFAULT_TIMEOUT);
         SEND_STRING("music");
         _delay_ms(DEFAULT_TIMEOUT);
         SEND_STRING(SS_TAP(X_ENTER));
}
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
   case MUSIC:
      if (record->event.pressed) {
	  select_music();
      }
      break;
   case MUSIC_LIKE:
      if (record->event.pressed) {
	 select_music();
         _delay_ms(DEFAULT_TIMEOUT);
	 SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_L) SS_UP(X_LGUI));
         _delay_ms(DEFAULT_TIMEOUT);
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_0) SS_UP(X_LGUI)));
         _delay_ms(100);
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_EQL) SS_UP(X_LGUI)));
      }
      break;
   case MUSIC_DISLIKE:
      if (record->event.pressed) {
	 select_music();
         _delay_ms(DEFAULT_TIMEOUT);
	 SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_L) SS_UP(X_LGUI));
         _delay_ms(DEFAULT_TIMEOUT);
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_MINS) SS_UP(X_LGUI)));
         _delay_ms(100);
         SEND_STRING(SS_LSFT(SS_DOWN(X_LGUI) SS_TAP(X_9) SS_UP(X_LGUI)));
      }
      break;
   }
   return true;
}
