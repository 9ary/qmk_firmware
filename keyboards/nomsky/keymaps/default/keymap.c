#include QMK_KEYBOARD_H

enum layers {
    L_BASE,
    L_DEF,
    L_NUM,
    L_SYM,
    L_NAV,
    L_MEDIA,
};

// Left hand
const uint16_t PROGMEM combo_tab[] = {KC_D, KC_F, COMBO_END};

// Right hand
const uint16_t PROGMEM combo_enter[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_escape[] = {KC_K, KC_L, COMBO_END};

// Both hands
const uint16_t PROGMEM combo_caps_word[] = {KC_LSFT, KC_RSFT, COMBO_END};
combo_t key_combos[] = {
    // Left hand
    COMBO(combo_tab, KC_TAB),

    // Right hand
    COMBO(combo_enter, KC_ENTER),
    COMBO(combo_escape, KC_ESCAPE),

    // Both hands
    COMBO(combo_caps_word, CAPS_WORD),
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(combo_t);

layer_state_t layer_state_set_kb(layer_state_t state) {
    state = IS_LAYER_OFF_STATE(state, L_SYM) ? (state & ~((layer_state_t) 1 << L_NAV)) : state;
    return state;
}

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
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,
        KC_A,    MT(MOD_LALT, KC_R), MT(MOD_LGUI, KC_S), MT(MOD_LCTL, KC_T),    KC_G,
        KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,
                                   LT(L_SYM, KC_SPC), OSM(MOD_LSFT),

        // Right hand
        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        KC_M,    MT(MOD_RCTL, KC_N), MT(MOD_RGUI, KC_E), MT(MOD_RALT, KC_I),    KC_O,
        KC_K,    KC_H,    _______, _______, _______,
        OSM(MOD_RSFT), LT(L_NUM, KC_BSPC)
    ),

    [L_NUM] = LAYOUT_default(
        // Left hand
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_MINS,
        XXXXXXX, KC_4,    KC_5,    KC_6,    KC_EQL,
        XXXXXXX, KC_7,    KC_8,    KC_9,    KC_0,
                                   _______, _______,

        // Right hand
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_RCTL, KC_RGUI, KC_RALT, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______
    ),

    [L_SYM] = LAYOUT_default(
        // Left hand
        XXXXXXX, XXXXXXX, MO(L_MEDIA), TT(L_NAV), XXXXXXX,
        XXXXXXX, KC_LALT, KC_LGUI, KC_LCTL, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______,

        // Right hand
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_DEL,  KC_GRV,  KC_SLSH, KC_BSLS, XXXXXXX,
        XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX, XXXXXXX,
        _______, _______
    ),

    [L_NAV] = LAYOUT_default(
        // Left hand
        XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,
        XXXXXXX, _______, _______, _______, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______,

        // Right hand
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
        KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX,
        _______, _______
    ),

    [L_MEDIA] = LAYOUT_default(
        // Left hand
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, _______, _______, _______, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______,

        // Right hand
        XXXXXXX, XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_BRIU, KC_VOLU, KC_MNXT, XXXXXXX,
        XXXXXXX, KC_BRID, KC_VOLD, KC_MPRV, XXXXXXX,
        KC_MPLY, KC_MSEL
    ),
};

void keyboard_post_init_user(void) {
    default_layer_set(1 << L_DEF);
    //debug_enable=true;
    //debug_matrix=true;
    //debug_keyboard=true;
    //debug_mouse=true;
}
