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
    LAYER_RAISE,
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

const uint16_t PROGMEM s_d_x[] = { KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM p_f_v[] = { KC_P, KC_F, COMBO_END};
const uint16_t PROGMEM r_s_q[] = { KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM f_t_z[] = { KC_F, KC_T, COMBO_END};
const uint16_t PROGMEM r_t_esc[] = { KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM w_f_tab[] = { KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM k_c_0[] = { KC_K, KC_C, COMBO_END};
const uint16_t PROGMEM c_d_1[] = { KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM k_d_2[] = { KC_K, KC_D, COMBO_END};
const uint16_t PROGMEM comm_dot_slash[] = { KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM m_comm_minus[] = { KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM e_i_quote[] = { KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM n_e_equal[] = { KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM m_dot_astr[] = { KC_M, KC_DOT, COMBO_END};
const uint16_t PROGMEM a_r_del[] = { KC_A, KC_R, COMBO_END};
const uint16_t PROGMEM t_g_lalt_f4[] = { KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM n_m_circ[] = { KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM e_comm_dollar[] = { KC_E, KC_COMM, COMBO_END};
const uint16_t PROGMEM i_dot_exclaim[] = { KC_I, KC_DOT, COMBO_END};

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
          KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_A,    KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,    KC_E,    KC_I, KC_O,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
          KC_NO,    KC_K,    KC_C,    KC_D,    KC_NO,       KC_NO,    KC_M, KC_COMM,  KC_DOT, KC_NO,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         KC_BTN1	, KC_LSFT,   KC_BSPC,      LT(1,KC_ENTER), KC_SPACE
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

  [LAYER_RAISE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, KC_VOLU, KC_MUTE, KC_VOLD, XXXXXXX,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    QK_BOOT, EE_CLR,  XXXXXXX, XXXXXXX, XXXXXXX,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, XXXXXXX,    _______, XXXXXXX
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on
