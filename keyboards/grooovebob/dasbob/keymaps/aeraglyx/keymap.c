#include QMK_KEYBOARD_H

enum layers {
    _BAS,
    _NAV,
    _SYM,
    _NUM,
    _FUN,
    _INT
};


// #define BC_B KC_B
// #define BC_L KC_L
// #define BC_D KC_D
// #define BC_W KC_W
// #define BC_X KC_X
//
// #define BC_K KC_K
// #define BC_P KC_P
// #define BC_U KC_U
// #define BC_O KC_O
// #define BC_Y KC_Y
//
// #define BC_B KC_B
// #define BC_L KC_L
// #define BC_D KC_D
// #define BC_W KC_W
// #define BC_X KC_X
//
// #define BC_B KC_B
// #define BC_L KC_L
// #define BC_D KC_D
// #define BC_W KC_W
// #define BC_X KC_X
//
// #define BC_B KC_B
// #define BC_L KC_L
// #define BC_D KC_D
// #define BC_W KC_W
// #define BC_X KC_X
//
// #define BC_B KC_B
// #define BC_L KC_L
// #define BC_D KC_D
// #define BC_W KC_W
// #define BC_X KC_X


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BAS] = LAYOUT_split_3x5_3(

        KC_B,               KC_L,               LT(_FUN, KC_D),     KC_W,               KC_X,               KC_K,               KC_P,               KC_U,               KC_O,               KC_Y,
        KC_N,               RALT_T(KC_R),       LSFT_T(KC_T),       LCTL_T(KC_S),       KC_G,               KC_F,               RSFT_T(KC_H),       RCTL_T(KC_K),       RALT_T(KC_L),       KC_I,
        KC_Q,               KC_J,               LT(_FUN, KC_M),     KC_C,               KC_Z,               KC_N,               KC_V,               KC_COMM,            KC_DOT,             LCTL(KC_SLSH),
                                                LT(_NUM, QK_REP),   LT(_NAV, KC_SPC),   SH_T(KC_TAB),       KC_ESC,             LT(_SYM, QK_REP),   KC_ESC
    ),

    [_NAV] = LAYOUT_split_3x5_3(

        KC_SLEP,            KC_PSCR,            KC_GRAVE,           XXXXXXX,            QK_REBOOT,          QK_REBOOT,          KC_HOME,            KC_UP,              KC_END,             XXXXXXX,
        OSM(MOD_LGUI),      OSM(MOD_RALT),      OSM(MOD_LCTL),      OSM(MOD_LSFT),      XXXXXXX,            XXXXXXX,            KC_LEFT,            KC_DOWN,            KC_RIGHT,           XXXXXXX,
        XXXXXXX,            XXXXXXX,            MS_BTN3,            OSM(MOD_MEH),       XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
                                                KC_TRNS,            KC_TRNS,            KC_TAB,             KC_ENT,             KC_TRNS,            KC_TRNS
    ),

    [_SYM] = LAYOUT_split_3x5_3(

        KC_ESC,             KC_UP,              XXXXXXX,            XXXXXXX,            CK_TOGG,            KC_NUM_LOCK,        KC_KP_7,            KC_KP_8,            KC_KP_9,            KC_KP_MINUS,
        KC_LEFT,            RALT_T(KC_DOWN),    LCTL_T(KC_RGHT),    LSFT_T(XXXXXXX),    KC_LGUI,            XXXXXXX,            LSFT_T(KC_KP_4),    LCTL_T(KC_KP_5),    RALT_T(KC_KP_6),    KC_KP_PLUS,
        KC_MPRV,            KC_MSTP,            KC_MPLY,            KC_MNXT,            KC_PSCR,            XXXXXXX,            KC_KP_1,            KC_KP_2,            KC_KP_3,            KC_KP_0,
                                                KC_TRNS,            KC_TRNS,            KC_TAB,             KC_ENT,             KC_TRNS,            KC_TRNS
    ),

    [_NUM] = LAYOUT_split_3x5_3(

        KC_ESC,             KC_UP,              XXXXXXX,            XXXXXXX,            CK_TOGG,            KC_KP_SLASH,        KC_KP_7,            KC_KP_8,            KC_KP_9,            KC_KP_PLUS,
        KC_LEFT,            RALT_T(KC_DOWN),    LCTL_T(KC_RGHT),    LSFT_T(XXXXXXX),    KC_LGUI,            KC_KP_ASTERISK,     KC_KP_4,            KC_KP_5,            KC_KP_6,            KC_KP_DOT,
        KC_MPRV,            KC_MSTP,            KC_MPLY,            KC_MNXT,            KC_PSCR,            XXXXXXX,            KC_KP_1,            KC_KP_2,            KC_KP_3,            KC_KP_MINUS,
                                                KC_TRNS,            KC_TRNS,            KC_TAB,             KC_J,               KC_KP_0,            KC_K
    ),

    [_FUN] = LAYOUT_split_3x5_3(

        XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
        XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
        XXXXXXX,            KC_VOLD,            XXXXXXX,            KC_VOLU,            XXXXXXX,            XXXXXXX,            KC_VOLU,            XXXXXXX,            KC_VOLD,            XXXXXXX,
                                                KC_MPRV,            KC_MPLY,            KC_MNXT,            KC_MNXT,            KC_MPLY,            KC_MPRV
    ),

    // [_TMP] = LAYOUT_split_3x5_3(
    //
    //     XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
    //     XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
    //     XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
    //                                             XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX
    // ),

};

// const uint16_t PROGMEM combo_backspace[] = {KC_H, KC_E, COMBO_END};
// const uint16_t PROGMEM combo_delete[] = {KC_E, KC_A, COMBO_END};
// const uint16_t PROGMEM combo_enter[] = {KC_V, KC_COMM, COMBO_END};
// const uint16_t PROGMEM combo_capslock[] = {KC_T, KC_E, COMBO_END};
//
// combo_t key_combos[] = {
//     COMBO(combo_backspace, KC_BSPC),
//     COMBO(combo_delete, KC_DEL),
//     COMBO(combo_enter, KC_ENT),
//     COMBO(combo_capslock, KC_CAPS),
// };
//
// // TODO:
// const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
//     {{9, 0}, {8, 0}, {7, 0}, {6, 0}, {5, 0}, {4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
//     {{9, 1}, {8, 1}, {7, 1}, {6, 1}, {5, 1}, {4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
//     {{9, 2}, {8, 2}, {7, 2}, {6, 2}, {5, 2}, {4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
//     {                {5, 3}, {4, 3}, {3, 3}, {2, 3}, {1, 3}, {0, 3}                },
// };

