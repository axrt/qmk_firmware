#include QMK_KEYBOARD_H

#define _BASE    0
#define _FN1     1
#define _FN2     2

enum custom_keycodes {
   NUMPAD = SAFE_RANGE,
   EMAIL,
   SSH_CONFIG_EDIT,
   NVIM_CONFIG_EDIT,
   ZSH_CONFIG_EDIT,
   HIST_GREP,
   SAFARI_BOOKS,
   TMUX_RENAME_PANE,
   TMUX_ONE,
   TMUX_TWO,
   TMUX_THREE,
   TMUX_FOUR
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [_BASE] = LAYOUT_ortho_4x4(
      EMAIL,     SSH_CONFIG_EDIT, NVIM_CONFIG_EDIT, ZSH_CONFIG_EDIT, \
      HIST_GREP, SAFARI_BOOKS,    TMUX_RENAME_PANE, _______,         \
      TMUX_ONE,  TMUX_TWO,        TMUX_THREE,       TMUX_FOUR,       \
      MO(_FN1),  MO(_FN2),        _______,          _______          \
      ),

   [_FN1] = LAYOUT_ortho_4x4(
      _______,   _______,         _______,          _______, \
      _______,   _______,         _______,          _______, \
      _______,   _______,         _______,          _______, \
      _______,   _______,         _______,          _______  \
      ),

   [_FN2] = LAYOUT_ortho_4x4(
      RGB_TOG,   RGB_HUI,         RGB_SAI,          RGB_VAI, \
      RGB_MOD,   RGB_HUD,         RGB_SAD,          RGB_VAD, \
      _______,   _______,         _______,          RESET,   \
      BL_STEP,   _______,         _______,          _______  \
      )
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
   }
   return(true);
};
