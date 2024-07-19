#include QMK_KEYBOARD_H

enum layers {
    L_DEF,
    L_FN,
    L_MEDIA,
};

#define HOME_R LGUI_T(KC_R)
#define HOME_S LCTL_T(KC_S)
#define HOME_T LSFT_T(KC_T)
#define HOME_G LALT_T(KC_G)
#define HOME_M RALT_T(KC_M)
#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_I RGUI_T(KC_I)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_DEF] = LAYOUT_default(
        // Left hand
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX,
        XXXXXXX, KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    XXXXXXX,
        XXXXXXX, KC_A,    HOME_R,  HOME_S,  HOME_T,  HOME_G,  XXXXXXX,
        XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    XXXXXXX,
        XXXXXXX, KC_HOME, KC_PGUP, KC_END,  KC_TAB,  KC_SPC,  KC_ENT,
                          KC_PGDN,

        // Right hand
        XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        XXXXXXX, KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_EQL,
        XXXXXXX, HOME_M,  HOME_N,  HOME_E,  HOME_I,  KC_O,    KC_QUOT,
        XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
        KC_BSPC, KC_ESC,  KC_DEL,  KC_LEFT, KC_UP,   KC_RGHT, XXXXXXX,
                                            KC_DOWN
    ),

    [L_FN] = LAYOUT_default(
        // Left hand
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                          _______,

        // Right hand
        _______, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, _______, _______, KC_F12,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                                            _______
    ),

    [L_MEDIA] = LAYOUT_default(
        // Left hand
        _______, _______, _______, _______, _______, _______, KC_MSEL,
        _______, _______, _______, _______, KC_VOLU, KC_BRIU, _______,
        _______, _______, _______, _______, KC_VOLD, KC_BRID, _______,
        _______, _______, _______, _______, KC_MUTE, _______, _______,
        _______, _______, _______, _______, KC_MPRV, KC_MPLY, KC_MNXT,
                          _______,

        // Right hand
        KC_MSEL, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______,
        _______, KC_BRIU, KC_VOLU, _______, _______, _______, _______,
        _______, KC_BRID, KC_VOLD, _______, _______, _______, _______,
        _______, _______, KC_MUTE, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,
                                            _______
    ),
};

void keyboard_post_init_kb(void) {
    //debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;
    //debug_mouse=true;

    keyboard_post_init_user();
}
