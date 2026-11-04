// Copyright 2026 Jack Hu (@jh242)
// Boardsource Unicorne — port of jh242/zmk-config Totem Corne layout.
//
// Thumbs: NAV · Ent · Bspc | Spc · Esc · SYM   (plain MO — not LT/mod-tap)
// HRM:    A Gui · S Alt · D Ctrl · F Sft / J Sft · K Ctrl · L Alt · ; Gui
// Combos: J+K → Esc, Z+X → Caps Word
// NUM:    NAV + SYM tri-layer

#include QMK_KEYBOARD_H

enum layers {
    LAYER_BASE = 0,
    LAYER_NAV,
    LAYER_SYM,
    LAYER_NUM,
};

#define HRM_A    LGUI_T(KC_A)
#define HRM_S    LALT_T(KC_S)
#define HRM_D    LCTL_T(KC_D)
#define HRM_F    LSFT_T(KC_F)
#define HRM_J    RSFT_T(KC_J)
#define HRM_K    RCTL_T(KC_K)
#define HRM_L    RALT_T(KC_L)
#define HRM_SCLN RGUI_T(KC_SCLN)

#define NAV MO(LAYER_NAV)
#define SYM MO(LAYER_SYM)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT_split_3x6_3(
       KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
       KC_GRV,  HRM_A,   HRM_S,   HRM_D,   HRM_F,   KC_G,        KC_H,    HRM_J,   HRM_K,   HRM_L,   HRM_SCLN,KC_QUOT,
       KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                  NAV,     KC_ENT,  KC_BSPC,     KC_SPC,  KC_ESC,  SYM
  ),

  [LAYER_NAV] = LAYOUT_split_3x6_3(
       _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
       _______, _______, _______, _______, _______, _______,     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
       _______, _______, _______,C(KC_BSPC),_______, _______,    KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_GRV,  _______,
                                  _______, _______, _______,     _______, _______, _______
  ),

  [LAYER_SYM] = LAYOUT_split_3x6_3(
       _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______,
       _______, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_TILD,     KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, _______,
       _______, KC_LCBR, KC_RCBR, KC_LT,   KC_GT,   _______,     KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_GRV,
                                  _______, _______, _______,     _______, _______, _______
  ),

  [LAYER_NUM] = LAYOUT_split_3x6_3(
       _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_PAST, KC_7,    KC_8,    KC_9,    KC_PMNS, _______,
       _______, RM_TOGG, RM_NEXT, RM_PREV, RM_HUEU, RM_SATU,     KC_PSLS, KC_4,    KC_5,    KC_6,    KC_PPLS, _______,
       QK_BOOT, EE_CLR,  _______, _______, KC_F11,  KC_F12,      KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  KC_BSPC,
                                  _______, _______, _______,     _______, _______, _______
  ),
};
// clang-format on

/*
 * Opposite-hands map. Thumbs '*' so HRM + thumb still holds (shift-click etc.).
 * Same-hand HRM+plain-key → tap; same-hand HRM+HRM still chords.
 */
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT_split_3x6_3(
    'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',  'R', 'R', 'R', 'R', 'R', 'R',
                   '*', '*', '*',  '*', '*', '*'
);

/*
 * ZMK require-prior-idle-ms stand-in: any recent prior key forces HRM tap.
 * Stock Flow Tap only watches alphas+Space — widen to all mod-taps.
 */
uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t *record,
                           uint16_t prev_keycode) {
    if (IS_QK_MOD_TAP(keycode) && prev_keycode != KC_NO) {
        return FLOW_TAP_TERM;
    }
    return 0;
}

const uint16_t PROGMEM combo_jk_esc[]  = {HRM_J, HRM_K, COMBO_END};
const uint16_t PROGMEM combo_zx_caps[] = {KC_Z, KC_X, COMBO_END};

combo_t key_combos[] = {
    COMBO(combo_jk_esc, KC_ESC),
    COMBO(combo_zx_caps, QK_CAPS_WORD_TOGGLE),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, LAYER_NAV, LAYER_SYM, LAYER_NUM);
}
