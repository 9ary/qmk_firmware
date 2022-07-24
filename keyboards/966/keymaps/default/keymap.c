#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_default(
        KC_MENU, KC_GRAVE, KC_1, KC_2, KC_3, KC_4, KC_5, KC_LEFT_GUI,
        KC_RIGHT_GUI, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINUS, KC_EQUAL,

        KC_BACKSLASH, KC_SLASH, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_DELETE, KC_DELETE,
        KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LEFT_BRACKET, KC_RIGHT_BRACKET,

        KC_LEFT_SHIFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_TAB,
        KC_TAB, KC_H, KC_J, KC_K, KC_L, KC_SEMICOLON, KC_RIGHT_SHIFT,

        KC_LEFT_CTRL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_BACKSPACE,
        KC_BACKSPACE, KC_N, KC_M, KC_COMMA, KC_DOT, KC_QUOTE, KC_RIGHT_CTRL,

        KC_LEFT_GUI, KC_SPACE, KC_ENTER,
        KC_ENTER, KC_ESCAPE, KC_RIGHT_GUI
    )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
