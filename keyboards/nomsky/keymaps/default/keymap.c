#include QMK_KEYBOARD_H

enum layers {
    L_DEF,
    L_NUM,
    L_SYM,
    L_NAV,
    L_MEDIA,
};

// Left hand
const uint16_t PROGMEM combo_layer_media[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM combo_layer_nav[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM combo_backspace[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_layer_symbols[] = {KC_C, KC_V, COMBO_END};

// Right hand
const uint16_t PROGMEM combo_enter[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_escape[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_layer_numbers[] = {KC_M, KC_COMMA, COMBO_END};

// Both hands
const uint16_t PROGMEM combo_caps_word[] = {KC_F, KC_J, COMBO_END};
combo_t key_combos[] = {
    // Left hand
    COMBO(combo_layer_media, MO(L_MEDIA)),
    COMBO(combo_layer_nav, MO(L_NAV)),
    COMBO(combo_tab, KC_TAB),
    COMBO(combo_backspace, KC_BACKSPACE),
    COMBO(combo_layer_symbols, MO(L_SYM)),

    // Right hand
    COMBO(combo_enter, KC_ENTER),
    COMBO(combo_escape, KC_ESCAPE),
    COMBO(combo_layer_numbers, MO(L_NUM)),

    // Both hands
    COMBO(combo_caps_word, CAPS_WORD),
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(combo_t);

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (combo->keycode) {
    case MO(L_MEDIA):
    case MO(L_NAV):
        return 25;
    default:
        return COMBO_TERM;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_DEF] = LAYOUT_default(
        // Left hand
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                                   MT(MOD_LGUI, KC_SPC), OSM(MOD_LSFT),

        // Right hand
        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_QUOT,
        KC_LCTL, KC_LALT
    ),

    [L_NUM] = LAYOUT_default(
        // Left hand
        XXXXXXX, KC_1,    KC_2,    KC_3,    KC_MINS,
        XXXXXXX, KC_4,    KC_5,    KC_6,    KC_EQL,
        XXXXXXX, KC_7,    KC_8,    KC_9,    KC_0,
                                   _______, _______,

        // Right hand
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, _______
    ),

    [L_SYM] = LAYOUT_default(
        // Left hand
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______,

        // Right hand
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_DEL,  KC_GRV,  KC_SLSH, KC_BSLS, XXXXXXX,
        KC_LCBR, KC_LBRC, KC_RBRC, KC_RCBR, XXXXXXX,
        _______, _______
    ),

    [L_NAV] = LAYOUT_default(
        // Left hand
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
