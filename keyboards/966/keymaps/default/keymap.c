#include QMK_KEYBOARD_H

enum layers {
    DEFAULT,
    NAV,
};

const uint16_t PROGMEM combo_nav[] = {KC_LGUI, KC_SPACE, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_nav, MO(NAV)),
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(combo_t);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEFAULT] = LAYOUT_default(
        // Left hand
        KC_APP,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,
        KC_BSLS, KC_SLSH, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,
                 KC_LSPO, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,
                 KC_LCPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT,
                                                     KC_LGUI, KC_SPC,  KC_ENT,

        // Right hand
        XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSPC,
        KC_RALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, KC_RCPC,
        KC_ESC,  KC_RSFT, KC_BSPC
    ),

    [NAV] = LAYOUT_default(
        // Left hand
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                 _______, _______, _______, _______, _______, _______, _______,
                                                     _______, _______, _______,

        // Right hand
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
         _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______
    ),
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
