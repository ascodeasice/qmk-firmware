/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

enum charybdis_keymap_layers {
    LAYER_BASE = 0,
    LAYER_NUM,
    LAYER_SYM,
    LAYER_NAV,
    LAYER_SHORTCUT,
    LAYER_FUNCTION,
};

// SECTION tap dance

enum tap_dances {
    UP_PGUP=0,
    DOWN_PGDN,
    LEFT_HOME,
    RIGHT_END,
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

tap_dance_action_t tap_dance_actions[] = {
    [UP_PGUP] = ACTION_TAP_DANCE_TAP_HOLD(KC_UP, KC_PGUP),
    [DOWN_PGDN] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOWN, KC_PGDN),
    [LEFT_HOME] = ACTION_TAP_DANCE_TAP_HOLD(KC_LEFT, KC_HOME),
    [RIGHT_END] = ACTION_TAP_DANCE_TAP_HOLD(KC_RIGHT, KC_END),
};



// SECTION macro

enum macros {
    TMUX_PREFIX = SAFE_RANGE, // USING SAFE_RANGE IS REQUIRED TO PREVENT CLASHING WITH OTHER KEYCODE
    LAN_SWITCH,
    OR,
    KEY,
    L_DIR,
    HOME_DIR,
    CONST,
    FUNCTION,
    RETURN,
    EXPORT,
    IMPORT,
    CONTINUE,
    STU_ID,
    INDEX_I,
    INDEX_J,
    INDEX_K,
    INDEX0,
    INDEX1,
    INDEX2,
    LENGTH,
    LOCALHOST_URL,
    VIM_REPLACE,
    VIM_EXIT,
    SQL_SELECT_ALL,
    DEFAULT,
};

// Macro Definitions
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        case TMUX_PREFIX:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL(" "));
            } else {
                // when keycode QMKBEST is released
            }
            break;

        case LAN_SWITCH:
            if (record->event.pressed) {
                SEND_STRING(SS_LGUI(" "));
            } else {
                // when keycode QMKURL is released
            }
            break;

        case OR:
            if (record->event.pressed) {
                SEND_STRING("||");
            } else {
                // when keycode QMKURL is released
            }
            break;

        case KEY:
            if (record->event.pressed) {
                SEND_STRING("key");
            } else {
                // when keycode QMKURL is released
            }
            break;

        case L_DIR:
            if (record->event.pressed) {
                SEND_STRING("../");
            } else {
                // when keycode QMKURL is released
            }
            break;

        case HOME_DIR:
            if (record->event.pressed) {
                SEND_STRING("~/");
            } else {
                // when keycode QMKURL is released
            }
            break;


        case CONST:
            if(record->event.pressed){
                SEND_STRING("const ");
            }else{

            }
            break;

        case FUNCTION:
            if(record->event.pressed){
                SEND_STRING("function ");
            }else{

            }
            break;

        case RETURN:
            if(record->event.pressed){
                SEND_STRING("return ");
            }else{

            }
            break;

        case EXPORT:
            if(record->event.pressed){
                SEND_STRING("export ");
            }else{

            }
            break;

        case IMPORT:
            if(record->event.pressed){
                SEND_STRING("import ");
            }else{

            }
            break;

        case CONTINUE:
            if(record->event.pressed){
                SEND_STRING("continue");
            }else{

            }
            break;

        case STU_ID:
            if(record->event.pressed){
                SEND_STRING("E24106254");
            }else{

            }
            break;

        case INDEX_I:
            if(record->event.pressed){
                SEND_STRING("[i]");
            }else{

            }
            break;

        case INDEX_J:
            if(record->event.pressed){
                SEND_STRING("[j]");
            }else{

            }
            break;

        case INDEX_K:
            if(record->event.pressed){
                SEND_STRING("[k]");
            }else{

            }
            break;

        case INDEX0:
            if(record->event.pressed){
                SEND_STRING("[0]");
            }else{

            }
            break;

        case INDEX1:
            if(record->event.pressed){
                SEND_STRING("[1]");
            }else{

            }
            break;

        case INDEX2:
            if(record->event.pressed){
                SEND_STRING("[2]");
            }else{

            }
            break;

        case LENGTH:
            if(record->event.pressed){
                SEND_STRING("length");
            }else{

            }
            break;

        case LOCALHOST_URL:
            if(record->event.pressed){
                SEND_STRING("http://localhost:");
            }else{

            }
            break;

        case VIM_REPLACE:
            if(record->event.pressed){
                SEND_STRING(SS_TAP(X_ESC)":%s/");
            }else{

            }
            break;

        case VIM_EXIT:
            if(record->event.pressed){
                SEND_STRING(SS_TAP(X_ESC)":wq");
            }else{

            }
            break;

        case SQL_SELECT_ALL:
            if(record->event.pressed){
                SEND_STRING("SELECT * FROM ");
            }else{

            }
            break;

        case DEFAULT:
            if(record->event.pressed){
                SEND_STRING("default ");
            }else{

            }
            break;

        // list all tap dance keycodes with tap-hold configurations
        case TD(UP_PGUP):
        case TD(DOWN_PGDN):
        case TD(LEFT_HOME):
        case TD(RIGHT_END):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }


    }
    return true;
}

// SECTION combos

enum combos {
    S_D_X,
    P_F_V,
    R_S_Q,
    F_T_Z,
    R_T_ESC,
    W_F_TAB,
    K_C_0,
    C_D_1,
    K_D_2,
    COMM_DOT_SLASH,
    M_COMM_MINUS,
    E_I_QUOTE,
    N_E_EQUAL,
    M_DOT_ASTR,
    A_R_DEL,
    T_G_LALT_F4,
    N_M_CIRC,
    E_COMM_DOLLAR,
    I_DOT_EXCLAIM,
    U_Y_LAN_SWITCH,
    OR_COMBO,
    KEY_COMBO,
    L_DIR_COMBO,
    HOME_DIR_COMBO,
};

const uint16_t PROGMEM s_d_x[]          = {C_S_T(KC_S), LGUI_T(KC_D), COMBO_END};
const uint16_t PROGMEM p_f_v[]          = {LSG_T(KC_P), KC_F, COMBO_END};
const uint16_t PROGMEM r_s_q[]          = {MT(MOD_LCTL | MOD_LGUI, KC_R), C_S_T(KC_S), COMBO_END};
const uint16_t PROGMEM f_t_z[]          = {KC_F, LCA_T(KC_T), COMBO_END};
const uint16_t PROGMEM r_t_esc[]        = {MT(MOD_LCTL | MOD_LGUI, KC_R), LCA_T(KC_T), COMBO_END};
const uint16_t PROGMEM w_f_tab[]        = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM k_c_0[]          = {LCTL_T(KC_K), LALT_T(KC_C), COMBO_END};
const uint16_t PROGMEM c_d_1[]          = {LALT_T(KC_C), LGUI_T(KC_D), COMBO_END};
const uint16_t PROGMEM k_d_2[]          = {LCTL_T(KC_K), LGUI_T(KC_D), COMBO_END};
const uint16_t PROGMEM comm_dot_slash[] = {LALT_T(KC_COMM), LCTL_T(KC_DOT), COMBO_END};
const uint16_t PROGMEM m_comm_minus[]   = {LGUI_T(KC_H), LALT_T(KC_COMM), COMBO_END};
const uint16_t PROGMEM e_i_quote[]      = {C_S_T(KC_E), MT(MOD_LCTL | MOD_LGUI, KC_I), COMBO_END};
const uint16_t PROGMEM n_e_equal[]      = {LCA_T(KC_N), C_S_T(KC_E), COMBO_END};
const uint16_t PROGMEM m_dot_astr[]     = {LGUI_T(KC_H), LCTL_T(KC_DOT), COMBO_END};
const uint16_t PROGMEM a_r_del[]        = {KC_A, MT(MOD_LCTL | MOD_LGUI, KC_R), COMBO_END};
const uint16_t PROGMEM t_g_lalt_f4[]    = {LCA_T(KC_T), KC_G, COMBO_END};
const uint16_t PROGMEM n_m_circ[]       = {LCA_T(KC_N), LGUI_T(KC_H), COMBO_END};
const uint16_t PROGMEM e_comm_dollar[]  = {C_S_T(KC_E), LALT_T(KC_COMM), COMBO_END};
const uint16_t PROGMEM i_dot_exclaim[]  = {MT(MOD_LCTL | MOD_LGUI, KC_I), LCTL_T(KC_DOT), COMBO_END};
const uint16_t PROGMEM u_y_lan_switch[]  = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM or_combo[]  = { KC_RCBR, KC_BSLS , COMBO_END};
const uint16_t PROGMEM key_combo[]  = { LSG_T(KC_P), LCA_T(KC_T), COMBO_END};
const uint16_t PROGMEM l_dir_combo[]  = { MT(MOD_LCTL|MOD_LGUI,KC_R), KC_W, COMBO_END};
const uint16_t PROGMEM home_dir_combo[]  = {KC_W,LSG_T(KC_P), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [S_D_X] = COMBO(s_d_x, KC_X),
  [P_F_V] = COMBO(p_f_v, KC_V),
  [R_S_Q] = COMBO(r_s_q, KC_Q),
  [F_T_Z] = COMBO(f_t_z, KC_Z),
  [R_T_ESC] = COMBO(r_t_esc, KC_ESC),
  [W_F_TAB] = COMBO(w_f_tab, KC_TAB),
  [K_C_0] = COMBO(k_c_0, KC_0),
  [C_D_1] = COMBO(c_d_1, KC_1),
  [K_D_2] = COMBO(k_d_2, KC_2),
  [COMM_DOT_SLASH] = COMBO(comm_dot_slash, KC_SLASH),
  [M_COMM_MINUS] = COMBO(m_comm_minus, KC_MINUS),
  [E_I_QUOTE] = COMBO(e_i_quote, KC_QUOTE),
  [N_E_EQUAL] = COMBO(n_e_equal, KC_EQUAL),
  [M_DOT_ASTR] = COMBO(m_dot_astr, KC_ASTR),
  [A_R_DEL] = COMBO(a_r_del, KC_DEL),
  [T_G_LALT_F4] = COMBO(t_g_lalt_f4, LALT(KC_F4)),
  [N_M_CIRC] = COMBO(n_m_circ, KC_CIRC),
  [E_COMM_DOLLAR] = COMBO(e_comm_dollar, KC_DOLLAR),
  [I_DOT_EXCLAIM] = COMBO(i_dot_exclaim, KC_EXCLAIM),
  [U_Y_LAN_SWITCH] = COMBO(u_y_lan_switch, LAN_SWITCH),
  [OR_COMBO] = COMBO(or_combo, OR),
  [KEY_COMBO] = COMBO(key_combo, KEY),
  [L_DIR_COMBO] = COMBO(l_dir_combo, L_DIR),
  [HOME_DIR_COMBO] = COMBO(home_dir_combo, HOME_DIR),
};

// SECTION keymap

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          TMUX_PREFIX,    KC_W,    KC_F,    LSG_T(KC_P),    KC_B,       LSG_T(KC_J),    KC_L,    KC_U,    KC_Y,    KC_SCLN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          LT(4,KC_A),MT(MOD_LCTL | MOD_LGUI,KC_R),C_S_T(KC_S),LCA_T(KC_T),KC_G, /*||*/KC_M,LCA_T(KC_N),C_S_T(KC_E),MT(MOD_LCTL | MOD_LGUI,KC_I), LT(5,KC_O),
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
    SNP_TOG, LCTL_T(KC_K), LALT_T(KC_C), LGUI_T(KC_D),KC_BTN3,     KC_BTN2,    LGUI_T(KC_H), LALT_T(KC_COMM),  LCTL_T(KC_DOT), DRG_TOG,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_BTN1,KC_LSFT, LT(2,KC_BSPC),      LT(1,KC_ENTER), LT(3,KC_SPACE)
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_NUM] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX,    XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_1, KC_2, KC_3, KC_4, KC_5,                    KC_6,    KC_7,    KC_8,    KC_9, KC_0,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, KC_UP, KC_DOWN,  XXXXXXX,    XXXXXXX,    KC_BSPC,    KC_COMM,    KC_DOT, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         XXXXXXX, KC_SPACE, KC_ENTER,    XXXXXXX, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_SYM] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, KC_ASTR, KC_COMM, KC_DOT, XXXXXXX,    XXXXXXX, KC_LCBR, KC_RCBR, KC_BSLS, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_EXCLAIM,   KC_GRAVE, KC_SCLN, KC_EQUAL, KC_PERCENT,    KC_BSPC, KC_LPRN, KC_RPRN, KC_AMPR, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_NO, KC_AT, KC_HASH,  KC_DOLLAR, XXXXXXX,    XXXXXXX, KC_LBRC,  KC_RBRC, KC_CIRC, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, XXXXXXX,    KC_ENTER, LSFT_T(KC_SPACE)
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
  [LAYER_NAV] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, LALT(KC_F4), KC_MS_UP, LALT(KC_TAB), XXXXXXX,    XXXXXXX, KC_APP, TD(UP_PGUP), XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_ESC,   KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,KC_NO, KC_ENTER,    TD(LEFT_HOME), TD(DOWN_PGDN), TD(RIGHT_END), XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_NO, KC_LCTL, KC_NO,  KC_CAPS, XXXXXXX,    XXXXXXX, KC_LBRC,  KC_RBRC, KC_CIRC, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, XXXXXXX,    KC_ENTER, KC_SPACE
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_SHORTCUT] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, CONST, INDEX_J, INDEX1, XXXXXXX,    XXXXXXX, SQL_SELECT_ALL, XXXXXXX, LENGTH, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_NO,   STU_ID, INDEX_I, INDEX0, KC_NO,          XXXXXXX, EXPORT,    DEFAULT, FUNCTION, RETURN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_NO, VIM_REPLACE, VIM_EXIT, LOCALHOST_URL, XXXXXXX,    XXXXXXX, IMPORT,  CONTINUE, KC_CIRC, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, XXXXXXX,    KC_ENTER, KC_SPACE
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [LAYER_FUNCTION] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_F7, KC_F8, KC_F9, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LSFT,LCTL(KC_LGUI), LCTL(KC_LSFT), LCTL(KC_LALT), KC_NO, /*||*/ KC_F10, KC_F4, KC_F5, KC_F6, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_NO, KC_NO, KC_LALT, KC_LGUI, XXXXXXX,        KC_NO, KC_F1, KC_F2,  KC_F3,  XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, XXXXXXX,    KC_F11, KC_F12
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on
