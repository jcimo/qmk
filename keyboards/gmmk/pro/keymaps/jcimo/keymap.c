// my gmmk/pro custom keymap

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // The Fn key maps to a momentary toggle to layer 1

    // To put the keyboard in bootloader mode, use Fn+Esc
    // If you accidentally put it into bootloader, you can just unplug the USB cable and it'll be back to normal when you plug it back in


    // BASE lAYER

    //      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12      Play/Pause      Rotary(Mute)
    //      ~        1        2        3        4        5        6        7        8        9        0        -        (=)      BackSpc         Home
    //      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \               PgUp
    //      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter           PgDn
    //      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up     End
    //      Ct_L     LGUI     Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down   Right

    [0] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_MPLY,          KC_MUTE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_HOME,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                             KC_RALT, MO(1),   KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),


    // LAYER 1 [while holding Fn]

    //      RESET    F13      F14      F15      F16      F17      F18      F19      F20      F21      F22      F23      F24      _               _
    //      _        _        _        _        _        _        _        _        _        _        _         _       _        Delete          PrntScrn
    //      _        _        _        _        _        _        _        _        _        _        _         _       _        _               _
    //      _        _        _        _        _        _        _        _        _        _        _         _                _               _
    //      _        _        _        _        _        _        _        _        _        _        _         _                _               PgDn
    //      _        _        _        _        _        _        _        _        _        _        _         _                _        VolU   _
    //      _        _        _                                   _                          _        _         _       _        Prev     VolD   Next

    [1] = LAYOUT(
        RESET,   KC_F13,   KC_F14, KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,  KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,  _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL,           KC_PSCREEN,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, KC_VOLU, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, KC_MPRV, KC_VOLD, KC_MNXT
    ),

};


// rotary encoder, use for volume
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      tap_code(KC_VOLU);
    } else {
      tap_code(KC_VOLD);
    }
    return true;
}
