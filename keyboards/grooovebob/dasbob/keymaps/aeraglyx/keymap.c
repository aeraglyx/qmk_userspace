#include QMK_KEYBOARD_H
#include <stdint.h>

#include "keycodes.h"
#include "keymap_us.h"
#include "quantum_keycodes.h"
#include "action.h"

#include "unicode.c"


enum layers {
    _BAS,
    _NAV,
    _SYM,
    _NUM,
    _CTL,
    _MIR,
    _CZE,
    _REF,
    _FUN
};


#define LT_SYM_REP LT(_SYM, KC_0)
#define LT_NUM_REP LT(_NUM, KC_0)
#define LT_NUM_ALT LT(_FUN, KC_1)

// enum custom_keycodes {
//     // CC_01 = SAFE_RANGE,
//     // CC_02,
//     // CC_03,
//     // CC_04,
//     // CC_05,
//     // CC_06,
//     // CC_07,
//     // CC_08,
//     // CC_09,
//     // CC_10,
//     CC_10 = SAFE_RANGE,
//     CC_11,
//     CC_12
// };


bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
    if (keycode == LT_SYM_REP) { return false; }
    if (keycode == LT_NUM_REP) { return false; }
    if (keycode == LT_NUM_ALT) { return false; }
    return true;
}

bool custom_hold(keyrecord_t* record, uint16_t keycode_hold) {
    if (!record->tap.count && record->event.pressed) {
        tap_code16(keycode_hold);
        return false;
    }
    return true;
};

// bool custom_tap_hold(keyrecord_t* record, uint16_t keycode_tap, uint16_t keycode_hold) {
//     if (record->tap.count && record->event.pressed) {
//         tap_code(keycode_tap);
//     } else if (record->event.pressed) {
//         tap_code(keycode_hold);
//     }
//     return false;
// };


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {

        case LT_SYM_REP:
        case LT_NUM_REP:
            if (record->tap.count) {
                repeat_key_invoke(&record->event);
                return false;
            }
            break;

        case LT_NUM_ALT:
            if (record->tap.count) {
                alt_repeat_key_invoke(&record->event);
                return false;
            }
            break;

        case LT(0, KC_1):
            return custom_hold(record, KC_F1);
        case LT(0, KC_2):
            return custom_hold(record, KC_F2);
        case LT(0, KC_3):
            return custom_hold(record, KC_F3);
        case LT(0, KC_4):
            return custom_hold(record, KC_F4);
        case LT(0, KC_5):
            return custom_hold(record, KC_F5);
        case LT(0, KC_6):
            return custom_hold(record, KC_F6);
        case LT(0, KC_7):
            return custom_hold(record, KC_F7);
        case LT(0, KC_8):
            return custom_hold(record, KC_F8);
        case LT(0, KC_9):
            return custom_hold(record, KC_F9);
        case LT(0, KC_TAB):
            return custom_hold(record, KC_F10);
        case LT(0, KC_DOT):
            return custom_hold(record, KC_F11);
        case LT(0, KC_0):
            return custom_hold(record, KC_F12);
    }
    return true;
}


uint8_t combo_ref_from_layer(uint8_t layer) {
    switch (get_highest_layer(layer_state)) {
        case _BAS: return _REF;
    }
    return layer;
}


// left hand
const uint16_t PROGMEM combo_escape[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM combo_enter_l[] = {KC_M, KC_C, COMBO_END};
const uint16_t PROGMEM combo_copy[] = {KC_SPC, KC_T, COMBO_END};
const uint16_t PROGMEM combo_paste[] = {KC_SPC, KC_S, COMBO_END};
const uint16_t PROGMEM combo_undo[] = {KC_SPC, KC_D, COMBO_END};
// const uint16_t PROGMEM combo_save[] = {KC_SPC, KC_R, COMBO_END};
const uint16_t PROGMEM combo_shift_d[] = {KC_D, KC_S, COMBO_END};
const uint16_t PROGMEM combo_shift_a[] = {KC_D, KC_R, COMBO_END};
const uint16_t PROGMEM combo_left_l[] = {KC_L, KC_D, COMBO_END};
const uint16_t PROGMEM combo_right_l[] = {KC_D, KC_W, COMBO_END};
// const uint16_t PROGMEM combo_mouse_middle[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM combo_lgui[] = {KC_W, KC_G, COMBO_END};

// right hand
const uint16_t PROGMEM combo_backspace[] = {KC_H, KC_E, COMBO_END};
const uint16_t PROGMEM combo_delete[] = {KC_E, KC_A, COMBO_END};
const uint16_t PROGMEM combo_enter_r[] = {KC_V, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_left_r[] = {KC_U, KC_P, COMBO_END};
const uint16_t PROGMEM combo_right_r[] = {KC_O, KC_U, COMBO_END};

// both hands
const uint16_t PROGMEM combo_capslock[] = {KC_T, KC_E, COMBO_END};


combo_t key_combos[] = {
    COMBO(combo_escape, KC_ESC),
    COMBO(combo_enter_l, KC_ENT),
    COMBO(combo_copy, LCTL(KC_C)),
    COMBO(combo_paste, LCTL(KC_V)),
    COMBO(combo_undo, LCTL(KC_Z)),
    // COMBO(combo_save, LCTL(KC_S)),
    COMBO(combo_shift_d, LSFT(KC_D)),
    COMBO(combo_shift_a, LSFT(KC_A)),
    COMBO(combo_left_l, KC_LEFT),
    COMBO(combo_right_l, KC_RIGHT),
    // COMBO(combo_mouse_middle, MS_BTN3),

    COMBO(combo_backspace, KC_BSPC),
    COMBO(combo_delete, KC_DEL),
    COMBO(combo_enter_r, KC_ENT),
    COMBO(combo_left_r, KC_LEFT),
    COMBO(combo_right_r, KC_RIGHT),

    COMBO(combo_capslock, CW_TOGG),
    COMBO(combo_lgui, KC_LGUI),
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

        KC_B,               KC_L,               LT(_CTL, KC_D),     KC_W,               KC_X,               KC_K,               KC_P,               KC_U,               KC_O,               KC_Y,
        LCTL_T(KC_N),       LALT_T(KC_R),       LSFT_T(KC_T),       LCTL_T(KC_S),       KC_G,               KC_F,               LCTL_T(KC_H),       LSFT_T(KC_E),       LALT_T(KC_A),       KC_I,
        KC_Q,               KC_J,               LT(_CTL, KC_M),     LGUI_T(KC_C),       KC_Z,               KC_QUOT,            LGUI_T(KC_V),       LT(_CTL, KC_COMM),  KC_DOT,             KC_QUES,
                                                LT_NUM_REP,         LT(_NAV, KC_SPC),   LT(_MIR, KC_TAB),   LT(_CZE, KC_ESC),   LT_SYM_REP,         LT_NUM_ALT
    ),

    [_NAV] = LAYOUT_split_3x5_3(

        XXXXXXX,            KC_PSCR,            KC_GRAVE,           XXXXXXX,            QK_BOOT,            QK_BOOT,            KC_HOME,            KC_UP,              KC_END,             XXXXXXX,
        OSM(MOD_LGUI),      OSM(MOD_RALT),      OSM(MOD_LSFT),      OSM(MOD_LCTL),      QK_MAKE,            QK_MAKE,            KC_LEFT,            KC_DOWN,            KC_RIGHT,           XXXXXXX,
        XXXXXXX,            XXXXXXX,            MS_BTN3,            OSM(MOD_MEH),       KC_SLEP,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
                                                XXXXXXX,            XXXXXXX,            XXXXXXX,            KC_ENT,             KC_SPC,             XXXXXXX
    ),

    [_SYM] = LAYOUT_split_3x5_3(

        KC_GRV,             KC_LBRC,            KC_RBRC,            KC_DOLLAR,          XXXXXXX,            XXXXXXX,            KC_PERC,            KC_PIPE,            KC_AT,              XXXXXXX,
        KC_EXLM,            KC_LPRN,            KC_RPRN,            KC_EQL,             KC_SCLN,            KC_AMPR,            KC_PLUS,            KC_MINS,            KC_COLON,           KC_BSLS,
        KC_GRV,             KC_LCBR,            KC_RCBR,            KC_HASH,            XXXXXXX,            KC_CIRC,            KC_ASTR,            KC_SLSH,            KC_TILDE,           XXXXXXX,
                                                XXXXXXX,            KC_UNDS,            KC_GRV,             KC_LEFT,            XXXXXXX,            KC_RIGHT
    ),

    [_NUM] = LAYOUT_split_3x5_3(

        XXXXXXX,            LT(0, KC_9),        LT(0, KC_8),        LT(0, KC_7),        LT(0, KC_0),        KC_KP_ASTERISK,     KC_KP_7,            KC_KP_8,            KC_KP_9,            KC_KP_PLUS,
        KC_0,               LT(0, KC_6),        LT(0, KC_5),        LT(0, KC_4),        LT(0, KC_DOT),      KC_TAB,             KC_KP_4,            KC_KP_5,            KC_KP_6,            KC_KP_DOT,
        XXXXXXX,            LT(0, KC_3),        LT(0, KC_2),        LT(0, KC_1),        LT(0, KC_TAB),      KC_KP_SLASH,        KC_KP_1,            KC_KP_2,            KC_KP_3,            KC_KP_MINUS,
                                                XXXXXXX,            XXXXXXX,            XXXXXXX,            KC_DOWN,            KC_KP_0,            KC_UP
    ),

    [_CTL] = LAYOUT_split_3x5_3(

        XXXXXXX,            KC_F1,              XXXXXXX,            KC_F3,              XXXXXXX,            XXXXXXX,            MS_BTN1,            MS_UP,              MS_BTN2,            XXXXXXX,
        XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            MS_LEFT,            MS_DOWN,            MS_RGHT,            MS_BTN3,
        XXXXXXX,            KC_VOLD,            XXXXXXX,            KC_VOLU,            XXXXXXX,            XXXXXXX,            KC_VOLU,            XXXXXXX,            KC_VOLD,            XXXXXXX,
                                                KC_MPRV,            KC_MPLY,            KC_MNXT,            KC_MNXT,            KC_MPLY,            KC_MPRV
    ),

    [_MIR] = LAYOUT_split_3x5_3(

        KC_Y,               KC_O,               KC_U,               KC_P,               KC_K,               XXXXXXX,            MS_WHLU,            MS_UP,              MS_WHLD,            XXXXXXX,
        KC_I,               KC_A,               KC_E,               KC_H,               KC_F,               XXXXXXX,            MS_LEFT,            MS_DOWN,            MS_RGHT,            MS_BTN2,
        KC_QUES,            KC_DOT,             KC_COMM,            KC_V,               KC_QUOT,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
                                                XXXXXXX,            XXXXXXX,            XXXXXXX,            MS_BTN3,            MS_BTN1,            MS_BTN2
    ),

    [_CZE] = LAYOUT_split_3x5_3(

        XXXXXXX,            UC_LINX,            CZ_DCAR,            UC_WINC,            XXXXXXX,            XXXXXXX,            XXXXXXX,            CZ_URNG,            CZ_OACU,            CZ_YACU,
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

    [_FUN] = LAYOUT_split_3x5_3(

        XXXXXXX,            KC_F9,              KC_F8,              KC_F7,              KC_F12,             XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
        XXXXXXX,            KC_F6,              KC_F5,              KC_F4,              KC_F11,             XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
        XXXXXXX,            KC_F3,              KC_F2,              KC_F1,              KC_F10,             XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
                                                KC_F10,             KC_F11,             KC_F12,             XXXXXXX,            XXXXXXX,            XXXXXXX
    ),

    // [_TMP] = LAYOUT_split_3x5_3(
    //
    //     XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
    //     XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
    //     XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,
    //                                             XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX,            XXXXXXX
    // ),

};
