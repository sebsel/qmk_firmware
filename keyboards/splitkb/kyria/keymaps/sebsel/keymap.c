/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    _BASE = 0,
    _RAISE,
    _NAV,
};


// Aliases for readability
#define RAISE    MO(_RAISE)
#define NAV      MO(_NAV)
#define ____     _______
#define XXXX     XXXXXXX

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTY
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |  ` ~ |   Q  |   L  |   U  |   W  |   V  |                              |   F  |   P  |   O  |   D  |  - _ |  = + |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |  ' " |   H  |   R  |   E  |   S  |   G  |                              |   B  |   N  |   A  |   T  |   I  |  ; : |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |  / ? |   K  |   J  |  Ent |   M  |   X  |  Nav | Meh  |  |      | Tab  |   Z  |   C  | Bksp |   Y  |  , < |  . > |
 * `--------------------+------+------+------+------+------|  |------+------+------+------+------+--------------------'
 *                      | LAlt | LCtl | LSft | Raise| Cmd  |  |      | Esc  | Space|   [  |   ]  |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_BASE] = LAYOUT(
     KC_GRV,  KC_Q, KC_L, KC_U,    KC_W,    KC_V,                                   KC_F,   KC_P,   KC_O,    KC_D, KC_MINS, KC_EQL,
     KC_QUOT, KC_H, KC_R, KC_E,    KC_S,    KC_G,                                   KC_B,   KC_N,   KC_A,    KC_T, KC_I,    KC_SCLN,
     KC_SLSH, KC_K, KC_J, KC_ENT,  KC_M,    KC_X,    NAV,   KC_MEH,   XXXX, KC_TAB, KC_Z,   KC_C,   KC_BSPC, KC_Y, KC_COMM, KC_DOT,
                          KC_LALT, KC_LCTL, KC_LSFT, RAISE, KC_LGUI,  XXXX, KC_ESC, KC_SPC, KC_LBRC,KC_RBRC
    ),

/*
 * Raised Layer: Numbers and symbols
 *
 * ,-----------------------------------------.                              ,-----------------------------------------.
 * |   =  |   -  |   <  |   /  |   >  |   |  |                              |   \  |   {  |   }  |   %  |   _  |   +  |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
 * |   "  |   1  |   2  |   3  |   4  |   5  |                              |   6  |   7  |   8  |   9  |   0  |   :  |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
 * |   ?  |   !  |   @  |   #  |   $  |   %  |  --  |      |  |      |      |   ^  |   &  |   *  |   (  |   )  |   ~  |
 * `--------------------+------+------+------+------+------|  |------+------+------+------+------+--------------------'
 *                      |      |      |      |  --  |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      XXXX,    XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,XXXXXXX,                       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      KC_DQUO, KC_1,    KC_2,  KC_3,    KC_4,   KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
      KC_QUES, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,____,____,   ____,____,KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, XXXXXXX,
                               _______, ____,   _______,____,____,   ____,____,_______, XXXXXXX, XXXXXXX
    ),

/*
 * Nav Layer: Arrows and controls
 *
 * ,-----------------------------------------.                              ,------------------------------------------.
 * | Prev | Play | Next | Mute | VolDn| VolUp|                              |      |      |      |      |      |       |
 * |------+------+------+------+------+------|                              |------+------+------+------+------+-------|
 * |      |      |      |      |      |      |                              |  Ent |   ←  |   ↓  |   ↑  |   →  |       |
 * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+-------|
 * |      |      |      |      |      |      |  --  |      |  |      |      |      |      |      |      |      |       |
 * `--------------------+------+------+------+------+------|  |------+------+------+------+------+---------------------'
 *                      |      |      |      |  --  |      |  |      |      |      |      |      |
 *                      `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      KC_MPRV, KC_MPLY,KC_MNXT,KC_MUTE, KC_VOLU,KC_VOLD,                       XXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXX,    XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,XXXXXXX,                       KC_ENT,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
      XXXX,    XXXXXXX,XXXXXXX,XXXXXXX, XXXXXXX,XXXXXXX,____,____,   ____,____,XXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               _______, ____,   _______,____,____,   ____,____,_______, XXXXXXX, XXXXXXX
    ),

// /*
//  * Layer template
//  *
//  * ,-----------------------------------------.                              ,-----------------------------------------.
//  * |      |      |      |      |      |      |                              |      |      |      |      |      |      |
//  * |------+------+------+------+------+------|                              |------+------+------+------+------+------|
//  * |      |      |      |      |      |      |                              |      |      |      |      |      |      |
//  * |------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+------|
//  * |      |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |      |
//  * `--------------------+------+------+------+------+------|  |------+------+------+------+------+--------------------'
//  *                      |      |      |      |      |      |  |      |      |      |      |      |
//  *                      `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       ____, ____, ____, ____, ____, ____,                                        ____, ____, ____, ____, ____, ____,
//       ____, ____, ____, ____, ____, ____,                                        ____, ____, ____, ____, ____, ____,
//       ____, ____, ____, ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____, ____,
//                               ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____
//     ),
};

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_F) {
      // Anything you can do in a macro.
      SEND_STRING("QMK is awesome.");
    }
  }
}

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

// clang-format off
static const char PROGMEM logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0xf0, 0x78, 0x18, 0x1c, 0x1c, 0x0c, 0x0c, 0x1c,
    0x1c, 0x38, 0x78, 0xf0, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xfc, 0xf8, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0xf8, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0f, 0x1e, 0x1c, 0x1c, 0x18, 0x38, 0x38, 0x38,
    0x30, 0x70, 0x70, 0xe0, 0xe0, 0x80, 0x00, 0x00, 0x00, 0xf0, 0xfc, 0xde, 0xc6, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc6, 0xfe, 0xfc, 0xf0, 0x00, 0x00, 0x00, 0xff, 0xff, 0x7f, 0x0e, 0x07, 0x03, 0x03,
    0x03, 0x03, 0x07, 0x1e, 0xfc, 0xf8, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xf0,
    0xfc, 0x7e, 0x0e, 0x07, 0x03, 0x03, 0x03, 0x03, 0x07, 0x0e, 0xfe, 0xf8, 0xc0, 0x00, 0x00, 0xf0,
    0xfc, 0x3e, 0x0e, 0x07, 0x03, 0x03, 0x03, 0x07, 0x06, 0x3c, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x0c, 0x06, 0x03, 0x03, 0x03, 0x03,
    0x07, 0xfe, 0xfc, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x1f, 0x3e, 0x38, 0x70, 0x60, 0x60, 0x60, 0x60, 0x60,
    0x60, 0x60, 0x70, 0x3f, 0x1f, 0x0f, 0x00, 0x00, 0x00, 0x0f, 0x1f, 0x3c, 0x70, 0x60, 0x60, 0x60,
    0x60, 0x60, 0x70, 0x38, 0x1c, 0x04, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x3f, 0x30, 0x60, 0x60, 0x60,
    0x60, 0x60, 0x70, 0x3c, 0x1f, 0x07, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x07,
    0x1f, 0x3e, 0x70, 0x60, 0x60, 0x60, 0x60, 0x60, 0x70, 0x38, 0x3f, 0x0f, 0x01, 0x00, 0x00, 0x07,
    0x1f, 0x3e, 0x70, 0x60, 0x60, 0x60, 0x60, 0x70, 0x38, 0xbf, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x70, 0x70, 0x70, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x7f, 0x7f, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x06, 0x0e, 0x1c, 0x18, 0x18, 0x18, 0x18, 0x18, 0x1c, 0x0f, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00
};
// clang-format on

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_write_P(PSTR("\n\n\n\n\n\n"), false);

        if (get_mods() & MOD_MASK_ALT)   { oled_write_P(PSTR("A"), false); } else { oled_write_P(PSTR(" "), false); }
        if (get_mods() & MOD_MASK_CTRL)  { oled_write_P(PSTR("C"), false); } else { oled_write_P(PSTR(" "), false); }
        if (get_mods() & MOD_MASK_SHIFT) { oled_write_P(PSTR("S"), false); } else { oled_write_P(PSTR(" "), false); }
        if (get_mods() & MOD_MASK_GUI)   { oled_write_P(PSTR("G"), false); } else { oled_write_P(PSTR(" "), false); }

        oled_write_P(PSTR("\n"), false);

        // Host Keyboard Layer Status
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _BASE:
                oled_write_P(PSTR("-- NORMAL --"), false);
                break;
            case _RAISE:
                oled_write_P(PSTR("-- RAISED --"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined   "), false);
        }
        if (leading) {
          oled_write_P(PSTR("        \\"), false);
        } else {
          oled_write_P(PSTR("         "), false);
        }
    } else {
        oled_write_raw_P(logo, sizeof(logo));
    }
    return false;
}
#endif
