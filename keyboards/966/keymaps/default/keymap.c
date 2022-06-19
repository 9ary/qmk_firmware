#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_left_hand(
        KC_TAB, KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_F1,
        KC_BACKSLASH, KC_SLASH, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_F2,
        KC_LEFT_SHIFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_F3,
        KC_LEFT_CTRL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_F4,
        KC_LEFT_GUI, KC_SPACE, KC_ENTER
    )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
