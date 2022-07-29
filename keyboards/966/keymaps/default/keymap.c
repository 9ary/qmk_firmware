#include QMK_KEYBOARD_H

enum layers {
    LAYER_DEFAULT,
    LAYER_NAV,
    LAYER_MEDIA,
};

const uint16_t PROGMEM combo_nav_left[] = {KC_LGUI, KC_SPACE, COMBO_END};
const uint16_t PROGMEM combo_nav_right[] = {KC_RSFT, KC_RAPC, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_nav_left, MO(LAYER_NAV)),
    COMBO(combo_nav_right, MO(LAYER_NAV)),
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(combo_t);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_DEFAULT] = LAYOUT_default(
        // Left hand
        KC_APP,  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_INS,
        KC_BSLS, KC_SLSH, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_DEL,
                 KC_LSPO, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TAB,
                 KC_LCPO, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_LALT,
                                                     KC_LGUI, KC_SPC,  KC_ENT,

        // Right hand
        XXXXXXX,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        XXXXXXX,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        MO(LAYER_MEDIA), KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_RSPC,
        KC_RALT,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT, KC_RCPC,
        KC_BSPC,         KC_RSFT, KC_RAPC
    ),

    [LAYER_NAV] = LAYOUT_default(
        // Left hand
        _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
        _______, _______, _______, _______, _______, _______, _______, _______,
                 _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
                 _______, _______, _______, _______, _______, _______, _______,
                                                     _______, _______, _______,

        // Right hand
        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______
    ),

    [LAYER_MEDIA] = LAYOUT_default(
        // Left hand
        _______, _______, _______, _______, _______, _______, _______, KC_MSEL,
        _______, _______, _______, _______, _______, KC_VOLU, KC_BRIU, _______,
                 _______, _______, _______, _______, KC_VOLD, KC_BRID, _______,
                 _______, _______, _______, _______, KC_MUTE, _______, _______,
                                                     KC_MPRV, KC_MPLY, KC_MNXT,

        // Right hand
        KC_MSEL, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______,
        _______, KC_BRIU, KC_VOLU, _______, _______, _______, _______, _______,
        _______, KC_BRID, KC_VOLD, _______, _______, _______, _______,
        _______, _______, KC_MUTE, _______, _______, _______, _______,
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
