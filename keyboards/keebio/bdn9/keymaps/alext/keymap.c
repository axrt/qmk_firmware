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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [0] = LAYOUT(
      KC_MUTE,               MO(1),               RGB_MODE_FORWARD, \
      KC_MEDIA_FAST_FORWARD, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_REWIND,  \
      KC_PGDOWN,             KC_HOME,             KC_PGUP           \
      ),
   [1] = LAYOUT(
      RGB_TOG,               KC_NO,               BL_TOGG, \
      RGB_HUI,               RGB_SAI,             BL_INC,  \
      RGB_HUD,               RGB_SAD,             BL_DEC   \
      ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
   if (index == 0) {
      if (clockwise) {
         tap_code(KC_VOLD);
      } else {
         tap_code(KC_VOLU);
      }
   }
   else if (index == 1) {
      if (clockwise) {
         tap_code(KC_BRIGHTNESS_DOWN);
      } else {
         tap_code(KC_BRIGHTNESS_UP);
      }
   }
}
