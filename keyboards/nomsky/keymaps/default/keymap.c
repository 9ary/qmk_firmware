#include QMK_KEYBOARD_H

enum layers {
    L_BASE,
    L_DEF,
    L_LMODS,
    L_RMODS,
    L_LSYM,
    L_RSYM,
    L_NAV,
    L_MEDIA,
    L_FN,
};

const uint16_t PROGMEM combo_escape[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM compo_delete[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM combo_caps_word[] = {KC_F, KC_J, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_escape, KC_ESCAPE),
    COMBO(compo_delete, KC_DELETE),
    COMBO(combo_caps_word, CAPS_WORD),
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(combo_t);

struct {
    uint8_t upper;
    uint8_t lower;
} PROGMEM tt_sublayers[] = {
    {L_FN, L_RMODS},
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_BASE] = LAYOUT_default(
        // Left hand
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                                   KC_SPC,  KC_LSFT,

        // Right hand
        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
        KC_RSFT, KC_BSPC
    ),

    [L_DEF] = LAYOUT_default(
        // Left hand
        KC_Q,    KC_W,         KC_F,         KC_P,         KC_B,
        KC_A,    LGUI_T(KC_R), LCTL_T(KC_S), LSFT_T(KC_T), LALT_T(KC_G),
        KC_Z,    KC_X,         KC_C,         KC_D,         KC_V,
                                       LT(L_RSYM, KC_SPC), LT(L_NAV, KC_ENT),

        // Right hand
        KC_J,         KC_L,         KC_U,         KC_Y,         KC_SCLN,
        RALT_T(KC_M), RSFT_T(KC_N), RCTL_T(KC_E), RGUI_T(KC_I), KC_O,
        KC_K,         KC_H,         _______,      _______,      _______,
        KC_BSPC,      LT(L_LSYM, KC_TAB)
    ),

    [L_LMODS] = LAYOUT_default(
        // Left hand
        XXXXXXX, XXXXXXX, MO(L_MEDIA), XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LGUI, KC_LCTL,     KC_LSFT, KC_LALT,
        XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,
                                       _______, _______,

        // Right hand
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______
    ),

    [L_RMODS] = LAYOUT_default(
        // Left hand
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______,

        // Right hand
        XXXXXXX, TT(L_FN), XXXXXXX, XXXXXXX, XXXXXXX,
        KC_RALT, KC_RSFT,  KC_RCTL, KC_RGUI, XXXXXXX,
        XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______
    ),

    [L_LSYM] = LAYOUT_default(
        // Left hand
        KC_GRV,  KC_TILD, KC_LCBR, KC_LBRC, XXXXXXX,
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,
        XXXXXXX, KC_BSLS, KC_SLSH, KC_PIPE, KC_QUES,
                                   _______, _______,

        // Right hand
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______
    ),

    [L_RSYM] = LAYOUT_default(
        // Left hand
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                   _______, _______,

        // Right hand
        XXXXXXX, KC_RBRC, KC_RCBR, XXXXXXX, XXXXXXX,
        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        KC_UNDS, KC_PLUS, KC_MINS, KC_EQL,  XXXXXXX,
        _______, _______
    ),

    [L_NAV] = LAYOUT_default(
        // Left hand
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                   _______, _______,

        // Right hand
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
        _______, _______
    ),

    [L_MEDIA] = LAYOUT_default(
        // Left hand
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
                                   _______, _______,

        // Right hand
        XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_BRIU, KC_VOLU, KC_MNXT, XXXXXXX,
        XXXXXXX, KC_BRID, KC_VOLD, KC_MPRV, XXXXXXX,
        KC_MPLY, KC_MSEL
    ),

    [L_FN] = LAYOUT_default(
        // Left hand
        XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,
        XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,
        XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,
                                   _______, _______,

        // Right hand
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,
        _______, _______
    ),
};

void keyboard_post_init_kb(void) {
    default_layer_set(1 << L_DEF);

    //debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;
    //debug_mouse=true;

    keyboard_post_init_user();
}

#define LAYER_MASK(LAYER) ((layer_state_t)1 << LAYER)
layer_state_t held_tt_layers = 0;

layer_state_t layer_state_set_kb(layer_state_t state) {
    state &= ~(LAYER_MASK(L_LMODS) | LAYER_MASK(L_RMODS));
    if (IS_LAYER_ON_STATE(state, L_LSYM)) {
        state |= LAYER_MASK(L_RMODS);
    }
    if (IS_LAYER_ON_STATE(state, L_RSYM) || IS_LAYER_ON_STATE(state, L_NAV)) {
        state |= LAYER_MASK(L_LMODS);
    }

    for (uint32_t i = 0; i < sizeof(tt_sublayers) / sizeof(tt_sublayers[0]); i++) {
        if (IS_LAYER_OFF_STATE(state, tt_sublayers[i].lower)) {
            state &= ~LAYER_MASK(tt_sublayers[i].upper);
        }
    }
    state |= held_tt_layers;

    return default_layer_state_set_user(state);
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
        {
            layer_state_t mask = (layer_state_t)1 << (keycode & 0xFF);
            if (record->event.pressed) {
                held_tt_layers |= mask;
            } else {
                held_tt_layers &= ~mask;
            }
            break;
        }
    }

    return process_record_user(keycode, record);
}
