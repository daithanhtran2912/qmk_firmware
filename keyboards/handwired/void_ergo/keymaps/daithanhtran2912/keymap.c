#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _RAISE,
    _LOWER,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
     * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
     * │Tab│ Q │ W │ E │ R │ T │            │ Y │ U │ I │ O │ P │Bsp│
     * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
     * │Ctl│ A │ S │ D │ F │ G │            │ H │ J │ K │ L │ ; │ ' │ RCTL_T(KC_QUOT)
     * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
     * │Sft│ Z │ X │ C │ V │ B │            │ N │ M │ , │ . │ / │Sft│ LSFT_T(KC_ESC)
     * └───┴───┴───┴───┴───┴───┘┌───┐  ┌───┐└───┴───┴───┴───┴───┴───┘
     *                      ┌───┤ ` │  │ \ ├───┐
     *          ┌───┬───┬───┤Spc├───┘  └───┤Ent├───┬───┬───┐
     *          │GUI│Alt│Lwr├───┘          └───┤Rse│Del│GUI│
     *          └───┴───┴───┘                  └───┴───┴───┘
     *
     */
    [_QWERTY] = LAYOUT_split_3x6_5(
        KC_TAB,         KC_Q,       KC_W,       KC_E,       KC_R,   KC_T,               KC_Y,       KC_U,     KC_I,       KC_O,     KC_P,     KC_BSPC,
        KC_LCTL,        KC_A,       KC_S,       KC_D,       KC_F,   KC_G,               KC_H,       KC_J,     KC_K,       KC_L,     KC_SCLN,  RCTL_T(KC_QUOT),
        LSFT_T(KC_ESC), KC_Z,       KC_X,       KC_C,       KC_V,   KC_B,               KC_N,       KC_M,     KC_COMM,    KC_DOT,   KC_SLSH,  KC_RSFT,
                        KC_LGUI,    KC_LALT,    MO(_LOWER), KC_SPC, KC_GRAVE,           KC_NUBS,    KC_ENT,   MO(_RAISE), KC_DEL,   KC_RGUI
    ),
    /* LOWER
     * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
     * │F1 │F2 │F3 │F4 │F5 │F6 │            │F7 │F8 │F9 │F10│F11│F12│
     * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
     * │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │            │ 7 │ 8 │ 9 │ 0 │ - │ = │
     * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
     * │Sft│   │ ← │ ↓ │ → │ ↑ │            │ ↑ │ ← │ ↓ │ → │   │Sft│ LSFT_T(KC_ESC) | SFT_T(KC_BSPC)
     * └───┴───┴───┴───┴───┴───┘┌───┐  ┌───┐└───┴───┴───┴───┴───┴───┘
     *                      ┌───┤   │  │   ├───┐
     *          ┌───┬───┬───┤Spc├───┘  └───┤Ent├───┬───┬───┐
     *          │GUI│Alt│Lwr├───┘          └───┤Rse│ [ │ ] │
     *          └───┴───┴───┘                  └───┴───┴───┘
     *
     */
    [_LOWER] = LAYOUT_split_3x6_5(
        KC_F1,      KC_F2,      KC_F3,      KC_F4,          KC_F5,      KC_F6,              KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
        KC_1,       KC_2,       KC_3,       KC_4,           KC_5,       KC_6,               KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,    KC_EQL,
        KC_TRNS,    KC_NO,      KC_LEFT,    KC_DOWN,        KC_RIGHT,   KC_UP,              KC_UP,      KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_NO,      SFT_T(KC_BSPC),
                    KC_LGUI,    KC_LALT,    MO(_LOWER),     KC_SPC,     KC_NO,              KC_NO,      KC_ENT,     MO(_RAISE), KC_LBRC,    KC_RBRC
    ),
    /* RAISE
     * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
     * │ / │ + │ 7 │ 8 │ 9 │Num│            │Pas│Hom│Ins│Pup│Psc│Vup│
     * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
     * │ * │ - │ 4 │ 5 │ 6 │ . │            │Cpy│End│ ↑ │Pdn│   │Vdn│ LCTL_T(KC_PAST)
     * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
     * │Sft│ 0 │ 1 │ 2 │ 3 │ = │            │Cut│ ← │ ↓ │ → │   │Mut│ LSFT_T(KC_PENT)
     * └───┴───┴───┴───┴───┴───┘┌───┐  ┌───┐└───┴───┴───┴───┴───┴───┘
     *                      ┌───┤ , │  │Und├───┐
     *          ┌───┬───┬───┤Spc├───┘  └───┤Ent├───┬───┬───┐
     *          │GUI│Alt│Lwr├───┘          └───┤Rse│   │   │
     *          └───┴───┴───┘                  └───┴───┴───┘
     *
     */
    [_RAISE] = LAYOUT_split_3x6_5(
        KC_PSLS,            KC_PPLS,    KC_P7,      KC_P8,      KC_P9,  KC_NUM,             KC_PASTE,   KC_HOME,    KC_INS,     KC_PGUP,    KC_PSCR,    KC_KB_VOLUME_UP,
        LCTL_T(KC_PAST),    KC_PMNS,    KC_P4,      KC_P5,      KC_P6,  KC_PDOT,            KC_COPY,    KC_END,     KC_UP,      KC_PGDN,    KC_NO,      KC_KB_VOLUME_DOWN,
        LSFT_T(KC_PENT),    KC_P0,      KC_P1,      KC_P2,      KC_P3,  KC_PEQL,            KC_CUT,     KC_LEFT,    KC_DOWN,    KC_RIGHT,   KC_NO,      KC_KB_MUTE,
                            KC_LGUI,    KC_LALT,    MO(_LOWER), KC_SPC, KC_PCMM,            KC_UNDO,    KC_ENT,     MO(_RAISE), KC_NO,      KC_NO
    ),
    /* ADJUST
     * ┌───┬───┬───┬───┬───┬───┐            ┌───┬───┬───┬───┬───┬───┐
     * │Mut│Stp│Prv│Ply│Nxt│Vup│            │Bn3│Bn1│ ↑ │Bn2│WHU│WHL│
     * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │Vdn│            │Bn4│ ← │ ↓ │ → │WHD│WHR│
     * ├───┼───┼───┼───┼───┼───┤            ├───┼───┼───┼───┼───┼───┤
     * │   │   │   │   │   │   │            │Bn5│   │   │   │Bn6│   │
     * └───┴───┴───┴───┴───┴───┘┌───┐  ┌───┐└───┴───┴───┴───┴───┴───┘
     *                      ┌───┤   │  │   ├───┐
     *          ┌───┬───┬───┤   ├───┘  └───┤   ├───┬───┬───┐
     *          │   │   │Lwr├───┘          └───┤Rse│   │   │
     *          └───┴───┴───┘                  └───┴───┴───┘
     *
     */
    [_ADJUST] = LAYOUT_split_3x6_5(
        KC_MUTE,    KC_MSTP,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_VOLU,                  KC_BTN3,  KC_BTN1,  KC_MS_U,      KC_BTN2,    KC_WH_U,    KC_WH_L,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_VOLD,                  KC_BTN4,  KC_MS_L,  KC_MS_D,      KC_MS_R,    KC_WH_D,    KC_WH_R,
        KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,                    KC_BTN5,  KC_NO,    KC_NO,        KC_NO,      KC_BTN6,    KC_NO,
                    KC_NO,      KC_NO,      MO(_LOWER), KC_NO,      KC_NO,                    KC_NO,    KC_TRNS,  MO(_RAISE),   KC_NO,      KC_NO
    )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

/*
 * ROTARY ENCODER
 */

// #if defined(ENCODER_MAP_ENABLE)
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//     [_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),             ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN)  },
//     [_LOWER] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
//     [_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
//     [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
// };
// #endif
