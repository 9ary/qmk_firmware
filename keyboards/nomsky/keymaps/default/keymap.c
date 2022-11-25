#include QMK_KEYBOARD_H

enum layers {
    LAYER_DEFAULT,
};

enum tap_dance {
    DANCE_LGUI,
};

void dance_lgui_tap(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code16(KC_LGUI);
    } else if (state->count == 2) {
        register_code16(KC_ENTER);
        state->finished = true;
    }
}

void dance_lgui_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (state->count == 2) {
        unregister_code16(KC_ENTER);
    }
    unregister_code16(KC_LGUI);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [DANCE_LGUI] = ACTION_TAP_DANCE_FN_ADVANCED(dance_lgui_tap, NULL, dance_lgui_reset),
};

const uint16_t PROGMEM combo_function[] = {TD(DANCE_LGUI), KC_SFTENT, COMBO_END};
combo_t key_combos[] = {
    //COMBO(combo_function, MO(LAYER_FUNCTION)),
};
uint16_t COMBO_LEN = sizeof(key_combos) / sizeof(combo_t);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_DEFAULT] = LAYOUT_default(
        // Left hand
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,
                                   KC_SFTENT,  OSM(MOD_LSFT),

        // Right hand
        KC_Y,          KC_U,      KC_I,    KC_O,    KC_P,
        KC_H,          KC_J,      KC_K,    KC_L,    KC_SCLN,
        KC_N,          KC_M,      KC_COMM, KC_DOT,  KC_QUOT,
        KC_BSPC, KC_ENTER
    ),
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
}
