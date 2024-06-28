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
};

// combos

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

};

const uint16_t PROGMEM s_d_x[] = { C_S_T(KC_S), LGUI_T(KC_D), COMBO_END};
const uint16_t PROGMEM p_f_v[] = { LSG_T(KC_P), KC_F, COMBO_END};
const uint16_t PROGMEM r_s_q[] = { MT(MOD_LCTL | MOD_LGUI,KC_R), C_S_T(KC_S), COMBO_END};
const uint16_t PROGMEM f_t_z[] = { KC_F, LCA_T(KC_T), COMBO_END};
const uint16_t PROGMEM r_t_esc[] = { MT(MOD_LCTL | MOD_LGUI,KC_R), LCA_T(KC_T), COMBO_END};
const uint16_t PROGMEM w_f_tab[] = { KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM k_c_0[] = { LCTL_T(KC_K), LALT_T(KC_C), COMBO_END};
const uint16_t PROGMEM c_d_1[] = { LALT_T(KC_C), LGUI_T(KC_D), COMBO_END};
const uint16_t PROGMEM k_d_2[] = { LCTL_T(KC_K), LGUI_T(KC_D), COMBO_END};
const uint16_t PROGMEM comm_dot_slash[] = { LALT_T(KC_COMM), LCTL_T(KC_DOT), COMBO_END};
const uint16_t PROGMEM m_comm_minus[] = { LGUI_T(KC_H), LALT_T(KC_COMM), COMBO_END};
const uint16_t PROGMEM e_i_quote[] = { C_S_T(KC_E), MT(MOD_LCTL | MOD_LGUI,KC_I), COMBO_END};
const uint16_t PROGMEM n_e_equal[] = { LCA_T(KC_N), C_S_T(KC_E), COMBO_END};
const uint16_t PROGMEM m_dot_astr[] = { LGUI_T(KC_H), LCTL_T(KC_DOT), COMBO_END};
const uint16_t PROGMEM a_r_del[] = { KC_A, MT(MOD_LCTL | MOD_LGUI,KC_R), COMBO_END};
const uint16_t PROGMEM t_g_lalt_f4[] = { LCA_T(KC_T), KC_G, COMBO_END};
const uint16_t PROGMEM n_m_circ[] = { LCA_T(KC_N), LGUI_T(KC_H), COMBO_END};
const uint16_t PROGMEM e_comm_dollar[] = { C_S_T(KC_E), LALT_T(KC_COMM), COMBO_END};
const uint16_t PROGMEM i_dot_exclaim[] = { MT(MOD_LCTL | MOD_LGUI,KC_I), LCTL_T(KC_DOT), COMBO_END};

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

};
// combo end

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LAYER_BASE] = LAYOUT(
        // TODO: macro for tmux prefix on left top
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
          KC_Q,    KC_W,    KC_F,    LSG_T(KC_P),    KC_B,       LSG_T(KC_J),    KC_L,    KC_U,    KC_Y,    KC_SCLN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    MT(MOD_LCTL | MOD_LGUI,KC_R),    C_S_T(KC_S),    LCA_T(KC_T),    KC_G,       KC_M,    LCA_T(KC_N),    C_S_T(KC_E),    MT(MOD_LCTL | MOD_LGUI,KC_I), KC_O,
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
       XXXXXXX, KC_ASTR, KC_COMM, KC_DOT, XXXXXXX,    XXXXXXX, KC_LCBR, KC_RCBR, KC_SLASH, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_EXCLAIM,   KC_GRAVE, KC_SCLN, KC_EQUAL, KC_PERCENT,    KC_BSPC, KC_LPRN, KC_RPRN, KC_AMPR, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_NO, KC_AT, KC_HASH,  KC_DOLLAR, XXXXXXX,    XXXXXXX, KC_LBRC,  KC_RBRC, KC_CIRC, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, XXXXXXX,    KC_ENTER, LSFT_T(KC_SPACE)
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
    // TOOD: implement the tap dance here for direction
  [LAYER_NAV] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, LALT(KC_F4), KC_MS_UP, LALT(KC_TAB), XXXXXXX,    XXXXXXX, KC_APP, KC_UP, XXXXXXX, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_ESC,   KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT,KC_NO, KC_ENTER,    KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_NO, KC_NO, KC_NO,  KC_CAPS, XXXXXXX,    XXXXXXX, KC_LBRC,  KC_RBRC, KC_CIRC, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, XXXXXXX,    KC_ENTER, KC_SPACE
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on
