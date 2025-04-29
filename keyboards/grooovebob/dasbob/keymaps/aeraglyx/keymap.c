#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "keymap_us.h"
#include "quantum_keycodes.h"

#include "unicode.c"


enum layers {
    _BAS,
    _NAV,
    _SYM,
    _NUM,
    _FUN,
    _CZE,
    _REF
};


#define LT_SYM_REP LT(_SYM, KC_0)


bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
    if (keycode == LT_SYM_REP) { return false; }
    return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case LT_SYM_REP:
            if (record->tap.count) {
                repeat_key_invoke(&record->event);
                return false;
            }
            break;
    }
    return true;
}


uint8_t combo_ref_from_layer(uint8_t layer){
    switch (get_highest_layer(layer_state)){
        case _BAS: return _REF;
    }
    return layer;
}


const uint16_t PROGMEM combo_escape[] = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM combo_enter_l[] = {KC_D, KC_W, COMBO_END};
const uint16_t PROGMEM combo_copy[] = {KC_SPC, KC_T, COMBO_END};
const uint16_t PROGMEM combo_paste[] = {KC_SPC, KC_S, COMBO_END};
const uint16_t PROGMEM combo_left[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo_right[] = {KC_T, KC_S, COMBO_END};
const uint16_t PROGMEM combo_mouse_middle[] = {KC_M, KC_C, COMBO_END};

const uint16_t PROGMEM combo_backspace[] = {KC_H, KC_E, COMBO_END};
const uint16_t PROGMEM combo_delete[] = {KC_E, KC_A, COMBO_END};
const uint16_t PROGMEM combo_enter[] = {KC_V, KC_COMM, COMBO_END};

const uint16_t PROGMEM combo_capslock[] = {KC_T, KC_E, COMBO_END};
const uint16_t PROGMEM combo_windows[] = {KC_W, KC_P, COMBO_END};


combo_t key_combos[] = {
    COMBO(combo_escape, KC_ESC),
    COMBO(combo_enter_l, KC_ENT),
    COMBO(combo_copy, LCTL(KC_C)),
    COMBO(combo_paste, LCTL(KC_V)),
    COMBO(combo_left, KC_LEFT),
    COMBO(combo_right, KC_RIGHT),
    COMBO(combo_mouse_middle, MS_BTN3),

    COMBO(combo_backspace, KC_BSPC),
    COMBO(combo_delete, KC_DEL),
    COMBO(combo_enter, KC_ENT),

    COMBO(combo_capslock, CW_TOGG),
    COMBO(combo_windows, KC_LGUI),
};


const keypos_t PROGMEM hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    {{4, 4}, {3, 4}, {2, 4}, {1, 4}, {0, 4}},
    {{4, 5}, {3, 5}, {2, 5}, {1, 5}, {0, 5}},
    {{4, 6}, {3, 6}, {2, 6}, {1, 6}, {0, 6}},
    {{2, 7}, {1, 7}, {0, 7}, {0, 0}, {0, 0}},

    {{4, 0}, {3, 0}, {2, 0}, {1, 0}, {0, 0}},
    {{4, 1}, {3, 1}, {2, 1}, {1, 1}, {0, 1}},
    {{4, 2}, {3, 2}, {2, 2}, {1, 2}, {0, 2}},
    {{2, 3}, {1, 3}, {0, 3}, {0, 0}, {0, 0}},
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BAS] = LAYOUT_split_3x5_3(

        KC_B,               KC_L,               LT(_FUN, KC_D),     KC_W,               KC_X,               KC_K,               KC_P,               KC_U,               KC_O,               KC_Y,
        LCTL_T(KC_N),       LALT_T(KC_R),       LSFT_T(KC_T),       LCTL_T(KC_S),       KC_G,               KC_F,               LCTL_T(KC_H),       LSFT_T(KC_E),       LALT_T(KC_A),       KC_I,
        KC_Q,               KC_J,               LT(_FUN, KC_M),     KC_C,               KC_Z,               KC_QUOT,            KC_V,               LT(_FUN, KC_COMM),  KC_DOT,             KC_QUES,
                                                LT(_NUM, QK_REP),   LT(_NAV, KC_SPC),   SH_T(KC_TAB),       LT(_CZE, KC_ESC),   LT_SYM_REP,         QK_AREP
    ),

    [_NAV] = LAYOUT_split_3x5_3(

        XXXXXXX,            KC_PSCR,            KC_GRAVE,           XXXXXXX,            QK_BOOT,            QK_BOOT,            KC_HOME,            KC_UP,              KC_END,             XXXXXXX,
        OSM(MOD_LGUI),      OSM(MOD_RALT),      OSM(MOD_LSFT),      OSM(MOD_LCTL),      XXXXXXX,            XXXXXXX,            KC_LEFT,            KC_DOWN,            KC_RIGHT,           XXXXXXX,
        XXXXXXX,            XXXXXXX,            MS_BTN3,            OSM(MOD_MEH),       KC_SLEP,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
                                                XXXXXXX,            XXXXXXX,            XXXXXXX,            KC_ENT,             KC_SPC,             XXXXXXX
    ),

    [_SYM] = LAYOUT_split_3x5_3(

        XXXXXXX,            KC_LBRC,            KC_RBRC,            KC_DOLLAR,          XXXXXXX,            XXXXXXX,            KC_PERC,            KC_PIPE,            KC_AT,              XXXXXXX,
        KC_EXLM,            KC_LPRN,            KC_RPRN,            KC_EQL,             KC_SCLN,            KC_AMPR,            KC_PLUS,            KC_MINS,            KC_COLON,           KC_BSLS,
        KC_GRV,             KC_LCBR,            KC_RCBR,            KC_HASH,            XXXXXXX,            KC_CIRC,            KC_ASTR,            KC_SLSH,            KC_TILDE,           XXXXXXX,
                                                XXXXXXX,            KC_UNDS,            KC_GRV,             KC_LEFT,            XXXXXXX,            KC_RIGHT
    ),

    [_NUM] = LAYOUT_split_3x5_3(

        XXXXXXX,            KC_9,               KC_8,               KC_7,               XXXXXXX,            KC_KP_SLASH,        KC_KP_7,            KC_KP_8,            KC_KP_9,            KC_KP_PLUS,
        KC_0,               KC_6,               KC_5,               KC_4,               XXXXXXX,            KC_KP_ASTERISK,     KC_KP_4,            KC_KP_5,            KC_KP_6,            KC_KP_DOT,
        XXXXXXX,            KC_3,               KC_2,               KC_1,               XXXXXXX,            XXXXXXX,            KC_KP_1,            KC_KP_2,            KC_KP_3,            KC_KP_MINUS,
                                                XXXXXXX,            XXXXXXX,            XXXXXXX,            KC_DOWN,            KC_KP_0,            KC_UP
    ),

    [_FUN] = LAYOUT_split_3x5_3(

        XXXXXXX,            KC_F1,              XXXXXXX,            KC_F3,              XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
        XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
        XXXXXXX,            KC_VOLD,            XXXXXXX,            KC_VOLU,            XXXXXXX,            XXXXXXX,            KC_VOLU,            XXXXXXX,            KC_VOLD,            XXXXXXX,
                                                KC_MPRV,            KC_MPLY,            KC_MNXT,            KC_MNXT,            KC_MPLY,            KC_MPRV
    ),

    [_CZE] = LAYOUT_split_3x5_3(

        XXXXXXX,            XXXXXXX,            CZ_DCAR,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            CZ_URNG,            CZ_OACU,            CZ_YACU,
        CZ_NCAR,            CZ_RCAR,            CZ_TCAR,            CZ_SCAR,            XXXXXXX,            XXXXXXX,            CZ_UACU,            CZ_ECAR,            CZ_AACU,            CZ_IACU,
        XXXXXXX,            XXXXXXX,            XXXXXXX,            CZ_CCAR,            CZ_ZCAR,            XXXXXXX,            XXXXXXX,            CZ_EACU,            XXXXXXX,            XXXXXXX,
                                                XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX
    ),

    [_REF] = LAYOUT_split_3x5_3(

        KC_B,               KC_L,               KC_D,               KC_W,               KC_X,               KC_K,               KC_P,               KC_U,               KC_O,               KC_Y,
        KC_N,               KC_R,               KC_T,               KC_S,               KC_G,               KC_F,               KC_H,               KC_E,               KC_A,               KC_I,
        KC_Q,               KC_J,               KC_M,               KC_C,               KC_Z,               KC_QUOT,            KC_V,               KC_COMM,            KC_DOT,             KC_SLSH,
                                                QK_REP,             KC_SPC,             KC_TAB,             KC_ESC,             QK_REP,             KC_ESC
    ),

    // [_TMP] = LAYOUT_split_3x5_3(
    //
    //     XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
    //     XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
    //     XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
    //                                             XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX
    // ),

};
