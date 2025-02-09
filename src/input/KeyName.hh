#if KEYTEST //-->
namespace openmsx {

struct KeyNameDef {
    const char * name;
    uint32_t code;
};

static constexpr auto getScanCodeNameMap() {
    // https://wiki.libsdl.org/SDL3/SDL_Scancode
    std::array mapping = {
        KeyNameDef( "SDL_SCANCODE_UNKNOWN", 0 ), 

        /**
         *  \name Usage page 0x07
         *
         *  These values are from usage page 0x07 (USB keyboard page).
         */
        /* @{ */

        KeyNameDef( "SDL_SCANCODE_A", 4 ), 
        KeyNameDef( "SDL_SCANCODE_B", 5 ), 
        KeyNameDef( "SDL_SCANCODE_C", 6 ), 
        KeyNameDef( "SDL_SCANCODE_D", 7 ), 
        KeyNameDef( "SDL_SCANCODE_E", 8 ), 
        KeyNameDef( "SDL_SCANCODE_F", 9 ), 
        KeyNameDef( "SDL_SCANCODE_G", 10 ), 
        KeyNameDef( "SDL_SCANCODE_H", 11 ), 
        KeyNameDef( "SDL_SCANCODE_I", 12 ), 
        KeyNameDef( "SDL_SCANCODE_J", 13 ), 
        KeyNameDef( "SDL_SCANCODE_K", 14 ), 
        KeyNameDef( "SDL_SCANCODE_L", 15 ), 
        KeyNameDef( "SDL_SCANCODE_M", 16 ), 
        KeyNameDef( "SDL_SCANCODE_N", 17 ), 
        KeyNameDef( "SDL_SCANCODE_O", 18 ), 
        KeyNameDef( "SDL_SCANCODE_P", 19 ), 
        KeyNameDef( "SDL_SCANCODE_Q", 20 ), 
        KeyNameDef( "SDL_SCANCODE_R", 21 ), 
        KeyNameDef( "SDL_SCANCODE_S", 22 ), 
        KeyNameDef( "SDL_SCANCODE_T", 23 ), 
        KeyNameDef( "SDL_SCANCODE_U", 24 ), 
        KeyNameDef( "SDL_SCANCODE_V", 25 ), 
        KeyNameDef( "SDL_SCANCODE_W", 26 ), 
        KeyNameDef( "SDL_SCANCODE_X", 27 ), 
        KeyNameDef( "SDL_SCANCODE_Y", 28 ), 
        KeyNameDef( "SDL_SCANCODE_Z", 29 ), 

        KeyNameDef( "SDL_SCANCODE_1", 30 ), 
        KeyNameDef( "SDL_SCANCODE_2", 31 ), 
        KeyNameDef( "SDL_SCANCODE_3", 32 ), 
        KeyNameDef( "SDL_SCANCODE_4", 33 ), 
        KeyNameDef( "SDL_SCANCODE_5", 34 ), 
        KeyNameDef( "SDL_SCANCODE_6", 35 ), 
        KeyNameDef( "SDL_SCANCODE_7", 36 ), 
        KeyNameDef( "SDL_SCANCODE_8", 37 ), 
        KeyNameDef( "SDL_SCANCODE_9", 38 ), 
        KeyNameDef( "SDL_SCANCODE_0", 39 ), 

        KeyNameDef( "SDL_SCANCODE_RETURN", 40 ), 
        KeyNameDef( "SDL_SCANCODE_ESCAPE", 41 ), 
        KeyNameDef( "SDL_SCANCODE_BACKSPACE", 42 ), 
        KeyNameDef( "SDL_SCANCODE_TAB", 43 ), 
        KeyNameDef( "SDL_SCANCODE_SPACE", 44 ), 

        KeyNameDef( "SDL_SCANCODE_MINUS", 45 ), 
        KeyNameDef( "SDL_SCANCODE_EQUALS", 46 ), 
        KeyNameDef( "SDL_SCANCODE_LEFTBRACKET", 47 ), 
        KeyNameDef( "SDL_SCANCODE_RIGHTBRACKET", 48 ), 
        KeyNameDef( "SDL_SCANCODE_BACKSLASH", 49 ),  /**< Located at the lower left of the return
                                      *   key on ISO keyboards and at the right end
                                      *   of the QWERTY row on ANSI keyboards.
                                      *   Produces REVERSE SOLIDUS (backslash) and
                                      *   VERTICAL LINE in a US layout, REVERSE
                                      *   SOLIDUS and VERTICAL LINE in a UK Mac
                                      *   layout, NUMBER SIGN and TILDE in a UK
                                      *   Windows layout, DOLLAR SIGN and POUND SIGN
                                      *   in a Swiss German layout, NUMBER SIGN and
                                      *   APOSTROPHE in a German layout, GRAVE
                                      *   ACCENT and POUND SIGN in a French Mac
                                      *   layout, and ASTERISK and MICRO SIGN in a
                                      *   French Windows layout.
                                      */
        KeyNameDef( "SDL_SCANCODE_NONUSHASH", 50 ),  /**< ISO USB keyboards actually use this code
                                      *   instead of 49 for the same key, but all
                                      *   OSes I've seen treat the two codes
                                      *   identically. So, as an implementor, unless
                                      *   your keyboard generates both of those
                                      *   codes and your OS treats them differently,
                                      *   you should generate SDL_SCANCODE_BACKSLASH
                                      *   instead of this code. As a user, you
                                      *   should not rely on this code because SDL
                                      *   will never generate it with most (all?)
                                      *   keyboards.
                                      */
        KeyNameDef( "SDL_SCANCODE_SEMICOLON", 51 ), 
        KeyNameDef( "SDL_SCANCODE_APOSTROPHE", 52 ), 
        KeyNameDef( "SDL_SCANCODE_GRAVE", 53 ),  /**< Located in the top left corner (on both ANSI
                                  *   and ISO keyboards). Produces GRAVE ACCENT and
                                  *   TILDE in a US Windows layout and in US and UK
                                  *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                                  *   and NOT SIGN in a UK Windows layout, SECTION
                                  *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                                  *   layouts on ISO keyboards, SECTION SIGN and
                                  *   DEGREE SIGN in a Swiss German layout (Mac:
                                  *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                                  *   DEGREE SIGN in a German layout (Mac: only on
                                  *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
                                  *   French Windows layout, COMMERCIAL AT and
                                  *   NUMBER SIGN in a French Mac layout on ISO
                                  *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                                  *   SIGN in a Swiss German, German, or French Mac
                                  *   layout on ANSI keyboards.
                                  */
        KeyNameDef( "SDL_SCANCODE_COMMA", 54 ), 
        KeyNameDef( "SDL_SCANCODE_PERIOD", 55 ), 
        KeyNameDef( "SDL_SCANCODE_SLASH", 56 ), 

        KeyNameDef( "SDL_SCANCODE_CAPSLOCK", 57 ), 

        KeyNameDef( "SDL_SCANCODE_F1", 58 ), 
        KeyNameDef( "SDL_SCANCODE_F2", 59 ), 
        KeyNameDef( "SDL_SCANCODE_F3", 60 ), 
        KeyNameDef( "SDL_SCANCODE_F4", 61 ), 
        KeyNameDef( "SDL_SCANCODE_F5", 62 ), 
        KeyNameDef( "SDL_SCANCODE_F6", 63 ), 
        KeyNameDef( "SDL_SCANCODE_F7", 64 ), 
        KeyNameDef( "SDL_SCANCODE_F8", 65 ), 
        KeyNameDef( "SDL_SCANCODE_F9", 66 ), 
        KeyNameDef( "SDL_SCANCODE_F10", 67 ), 
        KeyNameDef( "SDL_SCANCODE_F11", 68 ), 
        KeyNameDef( "SDL_SCANCODE_F12", 69 ), 

        KeyNameDef( "SDL_SCANCODE_PRINTSCREEN", 70 ), 
        KeyNameDef( "SDL_SCANCODE_SCROLLLOCK", 71 ), 
        KeyNameDef( "SDL_SCANCODE_PAUSE", 72 ), 
        KeyNameDef( "SDL_SCANCODE_INSERT", 73 ),  /**< insert on PC, help on some Mac keyboards (but
                                       does send code 73, not 117) */
        KeyNameDef( "SDL_SCANCODE_HOME", 74 ), 
        KeyNameDef( "SDL_SCANCODE_PAGEUP", 75 ), 
        KeyNameDef( "SDL_SCANCODE_DELETE", 76 ), 
        KeyNameDef( "SDL_SCANCODE_END", 77 ), 
        KeyNameDef( "SDL_SCANCODE_PAGEDOWN", 78 ), 
        KeyNameDef( "SDL_SCANCODE_RIGHT", 79 ), 
        KeyNameDef( "SDL_SCANCODE_LEFT", 80 ), 
        KeyNameDef( "SDL_SCANCODE_DOWN", 81 ), 
        KeyNameDef( "SDL_SCANCODE_UP", 82 ), 

        KeyNameDef( "SDL_SCANCODE_NUMLOCKCLEAR", 83 ),  /**< num lock on PC, clear on Mac keyboards
                                         */
        KeyNameDef( "SDL_SCANCODE_KP_DIVIDE", 84 ), 
        KeyNameDef( "SDL_SCANCODE_KP_MULTIPLY", 85 ), 
        KeyNameDef( "SDL_SCANCODE_KP_MINUS", 86 ), 
        KeyNameDef( "SDL_SCANCODE_KP_PLUS", 87 ), 
        KeyNameDef( "SDL_SCANCODE_KP_ENTER", 88 ), 
        KeyNameDef( "SDL_SCANCODE_KP_1", 89 ), 
        KeyNameDef( "SDL_SCANCODE_KP_2", 90 ), 
        KeyNameDef( "SDL_SCANCODE_KP_3", 91 ), 
        KeyNameDef( "SDL_SCANCODE_KP_4", 92 ), 
        KeyNameDef( "SDL_SCANCODE_KP_5", 93 ), 
        KeyNameDef( "SDL_SCANCODE_KP_6", 94 ), 
        KeyNameDef( "SDL_SCANCODE_KP_7", 95 ), 
        KeyNameDef( "SDL_SCANCODE_KP_8", 96 ), 
        KeyNameDef( "SDL_SCANCODE_KP_9", 97 ), 
        KeyNameDef( "SDL_SCANCODE_KP_0", 98 ), 
        KeyNameDef( "SDL_SCANCODE_KP_PERIOD", 99 ), 

        KeyNameDef( "SDL_SCANCODE_NONUSBACKSLASH", 100 ),  /**< This is the additional key that ISO
                                            *   keyboards have over ANSI ones,
                                            *   located between left shift and Y.
                                            *   Produces GRAVE ACCENT and TILDE in a
                                            *   US or UK Mac layout, REVERSE SOLIDUS
                                            *   (backslash) and VERTICAL LINE in a
                                            *   US or UK Windows layout, and
                                            *   LESS-THAN SIGN and GREATER-THAN SIGN
                                            *   in a Swiss German, German, or French
                                            *   layout. */
        KeyNameDef( "SDL_SCANCODE_APPLICATION", 101 ),  /**< windows contextual menu, compose */
        KeyNameDef( "SDL_SCANCODE_POWER", 102 ),  /**< The USB document says this is a status flag,
                                   *   not a physical key - but some Mac keyboards
                                   *   do have a power key. */
        KeyNameDef( "SDL_SCANCODE_KP_EQUALS", 103 ), 
        KeyNameDef( "SDL_SCANCODE_F13", 104 ), 
        KeyNameDef( "SDL_SCANCODE_F14", 105 ), 
        KeyNameDef( "SDL_SCANCODE_F15", 106 ), 
        KeyNameDef( "SDL_SCANCODE_F16", 107 ), 
        KeyNameDef( "SDL_SCANCODE_F17", 108 ), 
        KeyNameDef( "SDL_SCANCODE_F18", 109 ), 
        KeyNameDef( "SDL_SCANCODE_F19", 110 ), 
        KeyNameDef( "SDL_SCANCODE_F20", 111 ), 
        KeyNameDef( "SDL_SCANCODE_F21", 112 ), 
        KeyNameDef( "SDL_SCANCODE_F22", 113 ), 
        KeyNameDef( "SDL_SCANCODE_F23", 114 ), 
        KeyNameDef( "SDL_SCANCODE_F24", 115 ), 
        KeyNameDef( "SDL_SCANCODE_EXECUTE", 116 ), 
        KeyNameDef( "SDL_SCANCODE_HELP", 117 ),     /**< AL Integrated Help Center */
        KeyNameDef( "SDL_SCANCODE_MENU", 118 ),     /**< Menu (show menu) */
        KeyNameDef( "SDL_SCANCODE_SELECT", 119 ), 
        KeyNameDef( "SDL_SCANCODE_STOP", 120 ),     /**< AC Stop */
        KeyNameDef( "SDL_SCANCODE_AGAIN", 121 ),    /**< AC Redo/Repeat */
        KeyNameDef( "SDL_SCANCODE_UNDO", 122 ),     /**< AC Undo */
        KeyNameDef( "SDL_SCANCODE_CUT", 123 ),      /**< AC Cut */
        KeyNameDef( "SDL_SCANCODE_COPY", 124 ),     /**< AC Copy */
        KeyNameDef( "SDL_SCANCODE_PASTE", 125 ),    /**< AC Paste */
        KeyNameDef( "SDL_SCANCODE_FIND", 126 ),     /**< AC Find */
        KeyNameDef( "SDL_SCANCODE_MUTE", 127 ), 
        KeyNameDef( "SDL_SCANCODE_VOLUMEUP", 128 ), 
        KeyNameDef( "SDL_SCANCODE_VOLUMEDOWN", 129 ), 
    /* not sure whether there's a reason to enable these */
    /*     KeyNameDef( "SDL_SCANCODE_LOCKINGCAPSLOCK", 130 ),   */
    /*     KeyNameDef( "SDL_SCANCODE_LOCKINGNUMLOCK", 131 ),  */
    /*     KeyNameDef( "SDL_SCANCODE_LOCKINGSCROLLLOCK", 132 ),  */
        KeyNameDef( "SDL_SCANCODE_KP_COMMA", 133 ), 
        KeyNameDef( "SDL_SCANCODE_KP_EQUALSAS400", 134 ), 

        KeyNameDef( "SDL_SCANCODE_INTERNATIONAL1", 135 ),  /**< used on Asian keyboards, see
                                                footnotes in USB doc */
        KeyNameDef( "SDL_SCANCODE_INTERNATIONAL2", 136 ), 
        KeyNameDef( "SDL_SCANCODE_INTERNATIONAL3", 137 ),  /**< Yen */
        KeyNameDef( "SDL_SCANCODE_INTERNATIONAL4", 138 ), 
        KeyNameDef( "SDL_SCANCODE_INTERNATIONAL5", 139 ), 
        KeyNameDef( "SDL_SCANCODE_INTERNATIONAL6", 140 ), 
        KeyNameDef( "SDL_SCANCODE_INTERNATIONAL7", 141 ), 
        KeyNameDef( "SDL_SCANCODE_INTERNATIONAL8", 142 ), 
        KeyNameDef( "SDL_SCANCODE_INTERNATIONAL9", 143 ), 
        KeyNameDef( "SDL_SCANCODE_LANG1", 144 ),  /**< Hangul/English toggle */
        KeyNameDef( "SDL_SCANCODE_LANG2", 145 ),  /**< Hanja conversion */
        KeyNameDef( "SDL_SCANCODE_LANG3", 146 ),  /**< Katakana */
        KeyNameDef( "SDL_SCANCODE_LANG4", 147 ),  /**< Hiragana */
        KeyNameDef( "SDL_SCANCODE_LANG5", 148 ),  /**< Zenkaku/Hankaku */
        KeyNameDef( "SDL_SCANCODE_LANG6", 149 ),  /**< reserved */
        KeyNameDef( "SDL_SCANCODE_LANG7", 150 ),  /**< reserved */
        KeyNameDef( "SDL_SCANCODE_LANG8", 151 ),  /**< reserved */
        KeyNameDef( "SDL_SCANCODE_LANG9", 152 ),  /**< reserved */

        KeyNameDef( "SDL_SCANCODE_ALTERASE", 153 ),     /**< Erase-Eaze */
        KeyNameDef( "SDL_SCANCODE_SYSREQ", 154 ), 
        KeyNameDef( "SDL_SCANCODE_CANCEL", 155 ),       /**< AC Cancel */
        KeyNameDef( "SDL_SCANCODE_CLEAR", 156 ), 
        KeyNameDef( "SDL_SCANCODE_PRIOR", 157 ), 
        KeyNameDef( "SDL_SCANCODE_RETURN2", 158 ), 
        KeyNameDef( "SDL_SCANCODE_SEPARATOR", 159 ), 
        KeyNameDef( "SDL_SCANCODE_OUT", 160 ), 
        KeyNameDef( "SDL_SCANCODE_OPER", 161 ), 
        KeyNameDef( "SDL_SCANCODE_CLEARAGAIN", 162 ), 
        KeyNameDef( "SDL_SCANCODE_CRSEL", 163 ), 
        KeyNameDef( "SDL_SCANCODE_EXSEL", 164 ), 

        KeyNameDef( "SDL_SCANCODE_KP_00", 176 ), 
        KeyNameDef( "SDL_SCANCODE_KP_000", 177 ), 
        KeyNameDef( "SDL_SCANCODE_THOUSANDSSEPARATOR", 178 ), 
        KeyNameDef( "SDL_SCANCODE_DECIMALSEPARATOR", 179 ), 
        KeyNameDef( "SDL_SCANCODE_CURRENCYUNIT", 180 ), 
        KeyNameDef( "SDL_SCANCODE_CURRENCYSUBUNIT", 181 ), 
        KeyNameDef( "SDL_SCANCODE_KP_LEFTPAREN", 182 ), 
        KeyNameDef( "SDL_SCANCODE_KP_RIGHTPAREN", 183 ), 
        KeyNameDef( "SDL_SCANCODE_KP_LEFTBRACE", 184 ), 
        KeyNameDef( "SDL_SCANCODE_KP_RIGHTBRACE", 185 ), 
        KeyNameDef( "SDL_SCANCODE_KP_TAB", 186 ), 
        KeyNameDef( "SDL_SCANCODE_KP_BACKSPACE", 187 ), 
        KeyNameDef( "SDL_SCANCODE_KP_A", 188 ), 
        KeyNameDef( "SDL_SCANCODE_KP_B", 189 ), 
        KeyNameDef( "SDL_SCANCODE_KP_C", 190 ), 
        KeyNameDef( "SDL_SCANCODE_KP_D", 191 ), 
        KeyNameDef( "SDL_SCANCODE_KP_E", 192 ), 
        KeyNameDef( "SDL_SCANCODE_KP_F", 193 ), 
        KeyNameDef( "SDL_SCANCODE_KP_XOR", 194 ), 
        KeyNameDef( "SDL_SCANCODE_KP_POWER", 195 ), 
        KeyNameDef( "SDL_SCANCODE_KP_PERCENT", 196 ), 
        KeyNameDef( "SDL_SCANCODE_KP_LESS", 197 ), 
        KeyNameDef( "SDL_SCANCODE_KP_GREATER", 198 ), 
        KeyNameDef( "SDL_SCANCODE_KP_AMPERSAND", 199 ), 
        KeyNameDef( "SDL_SCANCODE_KP_DBLAMPERSAND", 200 ), 
        KeyNameDef( "SDL_SCANCODE_KP_VERTICALBAR", 201 ), 
        KeyNameDef( "SDL_SCANCODE_KP_DBLVERTICALBAR", 202 ), 
        KeyNameDef( "SDL_SCANCODE_KP_COLON", 203 ), 
        KeyNameDef( "SDL_SCANCODE_KP_HASH", 204 ), 
        KeyNameDef( "SDL_SCANCODE_KP_SPACE", 205 ), 
        KeyNameDef( "SDL_SCANCODE_KP_AT", 206 ), 
        KeyNameDef( "SDL_SCANCODE_KP_EXCLAM", 207 ), 
        KeyNameDef( "SDL_SCANCODE_KP_MEMSTORE", 208 ), 
        KeyNameDef( "SDL_SCANCODE_KP_MEMRECALL", 209 ), 
        KeyNameDef( "SDL_SCANCODE_KP_MEMCLEAR", 210 ), 
        KeyNameDef( "SDL_SCANCODE_KP_MEMADD", 211 ), 
        KeyNameDef( "SDL_SCANCODE_KP_MEMSUBTRACT", 212 ), 
        KeyNameDef( "SDL_SCANCODE_KP_MEMMULTIPLY", 213 ), 
        KeyNameDef( "SDL_SCANCODE_KP_MEMDIVIDE", 214 ), 
        KeyNameDef( "SDL_SCANCODE_KP_PLUSMINUS", 215 ), 
        KeyNameDef( "SDL_SCANCODE_KP_CLEAR", 216 ), 
        KeyNameDef( "SDL_SCANCODE_KP_CLEARENTRY", 217 ), 
        KeyNameDef( "SDL_SCANCODE_KP_BINARY", 218 ), 
        KeyNameDef( "SDL_SCANCODE_KP_OCTAL", 219 ), 
        KeyNameDef( "SDL_SCANCODE_KP_DECIMAL", 220 ), 
        KeyNameDef( "SDL_SCANCODE_KP_HEXADECIMAL", 221 ), 

        KeyNameDef( "SDL_SCANCODE_LCTRL", 224 ), 
        KeyNameDef( "SDL_SCANCODE_LSHIFT", 225 ), 
        KeyNameDef( "SDL_SCANCODE_LALT", 226 ),  /**< alt, option */
        KeyNameDef( "SDL_SCANCODE_LGUI", 227 ),  /**< windows, command (apple), meta */
        KeyNameDef( "SDL_SCANCODE_RCTRL", 228 ), 
        KeyNameDef( "SDL_SCANCODE_RSHIFT", 229 ), 
        KeyNameDef( "SDL_SCANCODE_RALT", 230 ),  /**< alt gr, option */
        KeyNameDef( "SDL_SCANCODE_RGUI", 231 ),  /**< windows, command (apple), meta */

        KeyNameDef( "SDL_SCANCODE_MODE", 257 ),     /**< I'm not sure if this is really not covered
                                     *   by any of the above, but since there's a
                                     *   special SDL_KMOD_MODE for it I'm adding it here
                                     */

        /* @} *//* Usage page 0x07 */

        /**
         *  \name Usage page 0x0C
         *
         *  These values are mapped from usage page 0x0C (USB consumer page).
         *
         *  There are way more keys in the spec than we can represent in the
         *  current scancode range, so pick the ones that commonly come up in
         *  real world usage.
         */
        /* @{ */

        KeyNameDef( "SDL_SCANCODE_SLEEP", 258 ),                    /**< Sleep */
        KeyNameDef( "SDL_SCANCODE_WAKE", 259 ),                     /**< Wake */

        KeyNameDef( "SDL_SCANCODE_CHANNEL_INCREMENT", 260 ),        /**< Channel Increment */
        KeyNameDef( "SDL_SCANCODE_CHANNEL_DECREMENT", 261 ),        /**< Channel Decrement */

        KeyNameDef( "SDL_SCANCODE_MEDIA_PLAY", 262 ),           /**< Play */
        KeyNameDef( "SDL_SCANCODE_MEDIA_PAUSE", 263 ),          /**< Pause */
        KeyNameDef( "SDL_SCANCODE_MEDIA_RECORD", 264 ),         /**< Record */
        KeyNameDef( "SDL_SCANCODE_MEDIA_FAST_FORWARD", 265 ),   /**< Fast Forward */
        KeyNameDef( "SDL_SCANCODE_MEDIA_REWIND", 266 ),         /**< Rewind */
        KeyNameDef( "SDL_SCANCODE_MEDIA_NEXT_TRACK", 267 ),     /**< Next Track */
        KeyNameDef( "SDL_SCANCODE_MEDIA_PREVIOUS_TRACK", 268 ),  /**< Previous Track */
        KeyNameDef( "SDL_SCANCODE_MEDIA_STOP", 269 ),           /**< Stop */
        KeyNameDef( "SDL_SCANCODE_MEDIA_EJECT", 270 ),          /**< Eject */
        KeyNameDef( "SDL_SCANCODE_MEDIA_PLAY_PAUSE", 271 ),     /**< Play / Pause */
        KeyNameDef( "SDL_SCANCODE_MEDIA_SELECT", 272 ),         /* Media Select */

        KeyNameDef( "SDL_SCANCODE_AC_NEW", 273 ),               /**< AC New */
        KeyNameDef( "SDL_SCANCODE_AC_OPEN", 274 ),              /**< AC Open */
        KeyNameDef( "SDL_SCANCODE_AC_CLOSE", 275 ),             /**< AC Close */
        KeyNameDef( "SDL_SCANCODE_AC_EXIT", 276 ),              /**< AC Exit */
        KeyNameDef( "SDL_SCANCODE_AC_SAVE", 277 ),              /**< AC Save */
        KeyNameDef( "SDL_SCANCODE_AC_PRINT", 278 ),             /**< AC Print */
        KeyNameDef( "SDL_SCANCODE_AC_PROPERTIES", 279 ),        /**< AC Properties */

        KeyNameDef( "SDL_SCANCODE_AC_SEARCH", 280 ),            /**< AC Search */
        KeyNameDef( "SDL_SCANCODE_AC_HOME", 281 ),              /**< AC Home */
        KeyNameDef( "SDL_SCANCODE_AC_BACK", 282 ),              /**< AC Back */
        KeyNameDef( "SDL_SCANCODE_AC_FORWARD", 283 ),           /**< AC Forward */
        KeyNameDef( "SDL_SCANCODE_AC_STOP", 284 ),              /**< AC Stop */
        KeyNameDef( "SDL_SCANCODE_AC_REFRESH", 285 ),           /**< AC Refresh */
        KeyNameDef( "SDL_SCANCODE_AC_BOOKMARKS", 286 ),         /**< AC Bookmarks */

        /* @} *//* Usage page 0x0C */


        /**
         *  \name Mobile keys
         *
         *  These are values that are often used on mobile phones.
         */
        /* @{ */

        KeyNameDef( "SDL_SCANCODE_SOFTLEFT", 287 ),  /**< Usually situated below the display on phones and
                                          used as a multi-function feature key for selecting
                                          a software defined function shown on the bottom left
                                          of the display. */
        KeyNameDef( "SDL_SCANCODE_SOFTRIGHT", 288 ),  /**< Usually situated below the display on phones and
                                           used as a multi-function feature key for selecting
                                           a software defined function shown on the bottom right
                                           of the display. */
        KeyNameDef( "SDL_SCANCODE_CALL", 289 ),  /**< Used for accepting phone calls. */
        KeyNameDef( "SDL_SCANCODE_ENDCALL", 290 ),  /**< Used for rejecting phone calls. */

        /* @} *//* Mobile keys */

        /* Add any other keys here. */

    //    SDL_SCANCODE_RESERVED = 400,     /**< 400-500 reserved for dynamic keycodes */

    //    SDL_SCANCODE_COUNT = 512 /**< not a key, just marks the number of scancodes for array bounds */

    };
    return mapping;
}

static constexpr auto getKeyCodeNameMap() {
    // https://wiki.libsdl.org/SDL3/SDL_Keycode
    std::array mapping = {
        KeyNameDef("SDLK_UNKNOWN",              0x00000000u), /**< 0 */
        KeyNameDef("SDLK_RETURN",               0x0000000du), /**< '\r' */
        KeyNameDef("SDLK_ESCAPE",               0x0000001bu), /**< '\x1B' */
        KeyNameDef("SDLK_BACKSPACE",            0x00000008u), /**< '\b' */
        KeyNameDef("SDLK_TAB",                  0x00000009u), /**< '\t' */
        KeyNameDef("SDLK_SPACE",                0x00000020u), /**< ' ' */
        KeyNameDef("SDLK_EXCLAIM",              0x00000021u), /**< '!' */
        KeyNameDef("SDLK_DBLAPOSTROPHE",        0x00000022u), /**< '"' */
        KeyNameDef("SDLK_HASH",                 0x00000023u), /**< '#' */
        KeyNameDef("SDLK_DOLLAR",               0x00000024u), /**< '$' */
        KeyNameDef("SDLK_PERCENT",              0x00000025u), /**< '%' */
        KeyNameDef("SDLK_AMPERSAND",            0x00000026u), /**< '&' */
        KeyNameDef("SDLK_APOSTROPHE",           0x00000027u), /**< '\'' */
        KeyNameDef("SDLK_LEFTPAREN",            0x00000028u), /**< '(' */
        KeyNameDef("SDLK_RIGHTPAREN",           0x00000029u), /**< ')' */
        KeyNameDef("SDLK_ASTERISK",             0x0000002au), /**< '*' */
        KeyNameDef("SDLK_PLUS",                 0x0000002bu), /**< '+' */
        KeyNameDef("SDLK_COMMA",                0x0000002cu), /**< ',' */
        KeyNameDef("SDLK_MINUS",                0x0000002du), /**< '-' */
        KeyNameDef("SDLK_PERIOD",               0x0000002eu), /**< '.' */
        KeyNameDef("SDLK_SLASH",                0x0000002fu), /**< '/' */
        KeyNameDef("SDLK_0",                    0x00000030u), /**< '0' */
        KeyNameDef("SDLK_1",                    0x00000031u), /**< '1' */
        KeyNameDef("SDLK_2",                    0x00000032u), /**< '2' */
        KeyNameDef("SDLK_3",                    0x00000033u), /**< '3' */
        KeyNameDef("SDLK_4",                    0x00000034u), /**< '4' */
        KeyNameDef("SDLK_5",                    0x00000035u), /**< '5' */
        KeyNameDef("SDLK_6",                    0x00000036u), /**< '6' */
        KeyNameDef("SDLK_7",                    0x00000037u), /**< '7' */
        KeyNameDef("SDLK_8",                    0x00000038u), /**< '8' */
        KeyNameDef("SDLK_9",                    0x00000039u), /**< '9' */
        KeyNameDef("SDLK_COLON",                0x0000003au), /**< ':' */
        KeyNameDef("SDLK_SEMICOLON",            0x0000003bu), /**< ';' */
        KeyNameDef("SDLK_LESS",                 0x0000003cu), /**< '<' */
        KeyNameDef("SDLK_EQUALS",               0x0000003du), /**< '=' */
        KeyNameDef("SDLK_GREATER",              0x0000003eu), /**< '>' */
        KeyNameDef("SDLK_QUESTION",             0x0000003fu), /**< '?' */
        KeyNameDef("SDLK_AT",                   0x00000040u), /**< '@' */
        KeyNameDef("SDLK_LEFTBRACKET",          0x0000005bu), /**< '[' */
        KeyNameDef("SDLK_BACKSLASH",            0x0000005cu), /**< '\\' */
        KeyNameDef("SDLK_RIGHTBRACKET",         0x0000005du), /**< ']' */
        KeyNameDef("SDLK_CARET",                0x0000005eu), /**< '^' */
        KeyNameDef("SDLK_UNDERSCORE",           0x0000005fu), /**< '_' */
        KeyNameDef("SDLK_GRAVE",                0x00000060u), /**< '`' */
        KeyNameDef("SDLK_A",                    0x00000061u), /**< 'a' */
        KeyNameDef("SDLK_B",                    0x00000062u), /**< 'b' */
        KeyNameDef("SDLK_C",                    0x00000063u), /**< 'c' */
        KeyNameDef("SDLK_D",                    0x00000064u), /**< 'd' */
        KeyNameDef("SDLK_E",                    0x00000065u), /**< 'e' */
        KeyNameDef("SDLK_F",                    0x00000066u), /**< 'f' */
        KeyNameDef("SDLK_G",                    0x00000067u), /**< 'g' */
        KeyNameDef("SDLK_H",                    0x00000068u), /**< 'h' */
        KeyNameDef("SDLK_I",                    0x00000069u), /**< 'i' */
        KeyNameDef("SDLK_J",                    0x0000006au), /**< 'j' */
        KeyNameDef("SDLK_K",                    0x0000006bu), /**< 'k' */
        KeyNameDef("SDLK_L",                    0x0000006cu), /**< 'l' */
        KeyNameDef("SDLK_M",                    0x0000006du), /**< 'm' */
        KeyNameDef("SDLK_N",                    0x0000006eu), /**< 'n' */
        KeyNameDef("SDLK_O",                    0x0000006fu), /**< 'o' */
        KeyNameDef("SDLK_P",                    0x00000070u), /**< 'p' */
        KeyNameDef("SDLK_Q",                    0x00000071u), /**< 'q' */
        KeyNameDef("SDLK_R",                    0x00000072u), /**< 'r' */
        KeyNameDef("SDLK_S",                    0x00000073u), /**< 's' */
        KeyNameDef("SDLK_T",                    0x00000074u), /**< 't' */
        KeyNameDef("SDLK_U",                    0x00000075u), /**< 'u' */
        KeyNameDef("SDLK_V",                    0x00000076u), /**< 'v' */
        KeyNameDef("SDLK_W",                    0x00000077u), /**< 'w' */
        KeyNameDef("SDLK_X",                    0x00000078u), /**< 'x' */
        KeyNameDef("SDLK_Y",                    0x00000079u), /**< 'y' */
        KeyNameDef("SDLK_Z",                    0x0000007au), /**< 'z' */
        KeyNameDef("SDLK_LEFTBRACE",            0x0000007bu), /**< '{' */
        KeyNameDef("SDLK_PIPE",                 0x0000007cu), /**< '|' */
        KeyNameDef("SDLK_RIGHTBRACE",           0x0000007du), /**< '}' */
        KeyNameDef("SDLK_TILDE",                0x0000007eu), /**< '~' */
        KeyNameDef("SDLK_DELETE",               0x0000007fu), /**< '\x7F' */
        KeyNameDef("SDLK_PLUSMINUS",            0x000000b1u), /**< '\xB1' */
        KeyNameDef("SDLK_CAPSLOCK",             0x40000039u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CAPSLOCK) */
        KeyNameDef("SDLK_F1",                   0x4000003au), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F1) */
        KeyNameDef("SDLK_F2",                   0x4000003bu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F2) */
        KeyNameDef("SDLK_F3",                   0x4000003cu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F3) */
        KeyNameDef("SDLK_F4",                   0x4000003du), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F4) */
        KeyNameDef("SDLK_F5",                   0x4000003eu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F5) */
        KeyNameDef("SDLK_F6",                   0x4000003fu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F6) */
        KeyNameDef("SDLK_F7",                   0x40000040u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F7) */
        KeyNameDef("SDLK_F8",                   0x40000041u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F8) */
        KeyNameDef("SDLK_F9",                   0x40000042u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F9) */
        KeyNameDef("SDLK_F10",                  0x40000043u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F10) */
        KeyNameDef("SDLK_F11",                  0x40000044u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F11) */
        KeyNameDef("SDLK_F12",                  0x40000045u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F12) */
        KeyNameDef("SDLK_PRINTSCREEN",          0x40000046u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRINTSCREEN) */
        KeyNameDef("SDLK_SCROLLLOCK",           0x40000047u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SCROLLLOCK) */
        KeyNameDef("SDLK_PAUSE",                0x40000048u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAUSE) */
        KeyNameDef("SDLK_INSERT",               0x40000049u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_INSERT) */
        KeyNameDef("SDLK_HOME",                 0x4000004au), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HOME) */
        KeyNameDef("SDLK_PAGEUP",               0x4000004bu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEUP) */
        KeyNameDef("SDLK_END",                  0x4000004du), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_END) */
        KeyNameDef("SDLK_PAGEDOWN",             0x4000004eu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEDOWN) */
        KeyNameDef("SDLK_RIGHT",                0x4000004fu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RIGHT) */
        KeyNameDef("SDLK_LEFT",                 0x40000050u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LEFT) */
        KeyNameDef("SDLK_DOWN",                 0x40000051u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DOWN) */
        KeyNameDef("SDLK_UP",                   0x40000052u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UP) */
        KeyNameDef("SDLK_NUMLOCKCLEAR",         0x40000053u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_NUMLOCKCLEAR) */
        KeyNameDef("SDLK_KP_DIVIDE",            0x40000054u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DIVIDE) */
        KeyNameDef("SDLK_KP_MULTIPLY",          0x40000055u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MULTIPLY) */
        KeyNameDef("SDLK_KP_MINUS",             0x40000056u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MINUS) */
        KeyNameDef("SDLK_KP_PLUS",              0x40000057u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUS) */
        KeyNameDef("SDLK_KP_ENTER",             0x40000058u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_ENTER) */
        KeyNameDef("SDLK_KP_1",                 0x40000059u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_1) */
        KeyNameDef("SDLK_KP_2",                 0x4000005au), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_2) */
        KeyNameDef("SDLK_KP_3",                 0x4000005bu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_3) */
        KeyNameDef("SDLK_KP_4",                 0x4000005cu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_4) */
        KeyNameDef("SDLK_KP_5",                 0x4000005du), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_5) */
        KeyNameDef("SDLK_KP_6",                 0x4000005eu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_6) */
        KeyNameDef("SDLK_KP_7",                 0x4000005fu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_7) */
        KeyNameDef("SDLK_KP_8",                 0x40000060u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_8) */
        KeyNameDef("SDLK_KP_9",                 0x40000061u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_9) */
        KeyNameDef("SDLK_KP_0",                 0x40000062u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_0) */
        KeyNameDef("SDLK_KP_PERIOD",            0x40000063u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERIOD) */
        KeyNameDef("SDLK_APPLICATION",          0x40000065u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APPLICATION) */
        KeyNameDef("SDLK_POWER",                0x40000066u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_POWER) */
        KeyNameDef("SDLK_KP_EQUALS",            0x40000067u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALS) */
        KeyNameDef("SDLK_F13",                  0x40000068u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F13) */
        KeyNameDef("SDLK_F14",                  0x40000069u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F14) */
        KeyNameDef("SDLK_F15",                  0x4000006au), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F15) */
        KeyNameDef("SDLK_F16",                  0x4000006bu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F16) */
        KeyNameDef("SDLK_F17",                  0x4000006cu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F17) */
        KeyNameDef("SDLK_F18",                  0x4000006du), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F18) */
        KeyNameDef("SDLK_F19",                  0x4000006eu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F19) */
        KeyNameDef("SDLK_F20",                  0x4000006fu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F20) */
        KeyNameDef("SDLK_F21",                  0x40000070u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F21) */
        KeyNameDef("SDLK_F22",                  0x40000071u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F22) */
        KeyNameDef("SDLK_F23",                  0x40000072u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F23) */
        KeyNameDef("SDLK_F24",                  0x40000073u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F24) */
        KeyNameDef("SDLK_EXECUTE",              0x40000074u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXECUTE) */
        KeyNameDef("SDLK_HELP",                 0x40000075u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HELP) */
        KeyNameDef("SDLK_MENU",                 0x40000076u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MENU) */
        KeyNameDef("SDLK_SELECT",               0x40000077u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SELECT) */
        KeyNameDef("SDLK_STOP",                 0x40000078u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_STOP) */
        KeyNameDef("SDLK_AGAIN",                0x40000079u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AGAIN) */
        KeyNameDef("SDLK_UNDO",                 0x4000007au), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UNDO) */
        KeyNameDef("SDLK_CUT",                  0x4000007bu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CUT) */
        KeyNameDef("SDLK_COPY",                 0x4000007cu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COPY) */
        KeyNameDef("SDLK_PASTE",                0x4000007du), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PASTE) */
        KeyNameDef("SDLK_FIND",                 0x4000007eu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_FIND) */
        KeyNameDef("SDLK_MUTE",                 0x4000007fu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MUTE) */
        KeyNameDef("SDLK_VOLUMEUP",             0x40000080u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEUP) */
        KeyNameDef("SDLK_VOLUMEDOWN",           0x40000081u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEDOWN) */
        KeyNameDef("SDLK_KP_COMMA",             0x40000085u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COMMA) */
        KeyNameDef("SDLK_KP_EQUALSAS400",       0x40000086u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALSAS400) */
        KeyNameDef("SDLK_ALTERASE",             0x40000099u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ALTERASE) */
        KeyNameDef("SDLK_SYSREQ",               0x4000009au), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SYSREQ) */
        KeyNameDef("SDLK_CANCEL",               0x4000009bu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CANCEL) */
        KeyNameDef("SDLK_CLEAR",                0x4000009cu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEAR) */
        KeyNameDef("SDLK_PRIOR",                0x4000009du), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRIOR) */
        KeyNameDef("SDLK_RETURN2",              0x4000009eu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RETURN2) */
        KeyNameDef("SDLK_SEPARATOR",            0x4000009fu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SEPARATOR) */
        KeyNameDef("SDLK_OUT",                  0x400000a0u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OUT) */
        KeyNameDef("SDLK_OPER",                 0x400000a1u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OPER) */
        KeyNameDef("SDLK_CLEARAGAIN",           0x400000a2u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEARAGAIN) */
        KeyNameDef("SDLK_CRSEL",                0x400000a3u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CRSEL) */
        KeyNameDef("SDLK_EXSEL",                0x400000a4u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXSEL) */
        KeyNameDef("SDLK_KP_00",                0x400000b0u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_00) */
        KeyNameDef("SDLK_KP_000",               0x400000b1u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_000) */
        KeyNameDef("SDLK_THOUSANDSSEPARATOR",   0x400000b2u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_THOUSANDSSEPARATOR) */
        KeyNameDef("SDLK_DECIMALSEPARATOR",     0x400000b3u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DECIMALSEPARATOR) */
        KeyNameDef("SDLK_CURRENCYUNIT",         0x400000b4u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYUNIT) */
        KeyNameDef("SDLK_CURRENCYSUBUNIT",      0x400000b5u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYSUBUNIT) */
        KeyNameDef("SDLK_KP_LEFTPAREN",         0x400000b6u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTPAREN) */
        KeyNameDef("SDLK_KP_RIGHTPAREN",        0x400000b7u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTPAREN) */
        KeyNameDef("SDLK_KP_LEFTBRACE",         0x400000b8u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTBRACE) */
        KeyNameDef("SDLK_KP_RIGHTBRACE",        0x400000b9u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTBRACE) */
        KeyNameDef("SDLK_KP_TAB",               0x400000bau), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_TAB) */
        KeyNameDef("SDLK_KP_BACKSPACE",         0x400000bbu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BACKSPACE) */
        KeyNameDef("SDLK_KP_A",                 0x400000bcu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_A) */
        KeyNameDef("SDLK_KP_B",                 0x400000bdu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_B) */
        KeyNameDef("SDLK_KP_C",                 0x400000beu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_C) */
        KeyNameDef("SDLK_KP_D",                 0x400000bfu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_D) */
        KeyNameDef("SDLK_KP_E",                 0x400000c0u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_E) */
        KeyNameDef("SDLK_KP_F",                 0x400000c1u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_F) */
        KeyNameDef("SDLK_KP_XOR",               0x400000c2u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_XOR) */
        KeyNameDef("SDLK_KP_POWER",             0x400000c3u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_POWER) */
        KeyNameDef("SDLK_KP_PERCENT",           0x400000c4u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERCENT) */
        KeyNameDef("SDLK_KP_LESS",              0x400000c5u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LESS) */
        KeyNameDef("SDLK_KP_GREATER",           0x400000c6u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_GREATER) */
        KeyNameDef("SDLK_KP_AMPERSAND",         0x400000c7u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AMPERSAND) */
        KeyNameDef("SDLK_KP_DBLAMPERSAND",      0x400000c8u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLAMPERSAND) */
        KeyNameDef("SDLK_KP_VERTICALBAR",       0x400000c9u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_VERTICALBAR) */
        KeyNameDef("SDLK_KP_DBLVERTICALBAR",    0x400000cau), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLVERTICALBAR) */
        KeyNameDef("SDLK_KP_COLON",             0x400000cbu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COLON) */
        KeyNameDef("SDLK_KP_HASH",              0x400000ccu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HASH) */
        KeyNameDef("SDLK_KP_SPACE",             0x400000cdu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_SPACE) */
        KeyNameDef("SDLK_KP_AT",                0x400000ceu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AT) */
        KeyNameDef("SDLK_KP_EXCLAM",            0x400000cfu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EXCLAM) */
        KeyNameDef("SDLK_KP_MEMSTORE",          0x400000d0u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSTORE) */
        KeyNameDef("SDLK_KP_MEMRECALL",         0x400000d1u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMRECALL) */
        KeyNameDef("SDLK_KP_MEMCLEAR",          0x400000d2u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMCLEAR) */
        KeyNameDef("SDLK_KP_MEMADD",            0x400000d3u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMADD) */
        KeyNameDef("SDLK_KP_MEMSUBTRACT",       0x400000d4u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSUBTRACT) */
        KeyNameDef("SDLK_KP_MEMMULTIPLY",       0x400000d5u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMMULTIPLY) */
        KeyNameDef("SDLK_KP_MEMDIVIDE",         0x400000d6u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMDIVIDE) */
        KeyNameDef("SDLK_KP_PLUSMINUS",         0x400000d7u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUSMINUS) */
        KeyNameDef("SDLK_KP_CLEAR",             0x400000d8u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEAR) */
        KeyNameDef("SDLK_KP_CLEARENTRY",        0x400000d9u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEARENTRY) */
        KeyNameDef("SDLK_KP_BINARY",            0x400000dau), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BINARY) */
        KeyNameDef("SDLK_KP_OCTAL",             0x400000dbu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_OCTAL) */
        KeyNameDef("SDLK_KP_DECIMAL",           0x400000dcu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DECIMAL) */
        KeyNameDef("SDLK_KP_HEXADECIMAL",       0x400000ddu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HEXADECIMAL) */
        KeyNameDef("SDLK_LCTRL",                0x400000e0u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LCTRL) */
        KeyNameDef("SDLK_LSHIFT",               0x400000e1u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LSHIFT) */
        KeyNameDef("SDLK_LALT",                 0x400000e2u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LALT) */
        KeyNameDef("SDLK_LGUI",                 0x400000e3u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LGUI) */
        KeyNameDef("SDLK_RCTRL",                0x400000e4u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RCTRL) */
        KeyNameDef("SDLK_RSHIFT",               0x400000e5u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RSHIFT) */
        KeyNameDef("SDLK_RALT",                 0x400000e6u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RALT) */
        KeyNameDef("SDLK_RGUI",                 0x400000e7u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RGUI) */
        KeyNameDef("SDLK_MODE",                 0x40000101u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MODE) */
        KeyNameDef("SDLK_SLEEP",                0x40000102u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SLEEP) */
        KeyNameDef("SDLK_WAKE",                 0x40000103u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_WAKE) */
        KeyNameDef("SDLK_CHANNEL_INCREMENT",    0x40000104u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CHANNEL_INCREMENT) */
        KeyNameDef("SDLK_CHANNEL_DECREMENT",    0x40000105u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CHANNEL_DECREMENT) */
        KeyNameDef("SDLK_MEDIA_PLAY",           0x40000106u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PLAY) */
        KeyNameDef("SDLK_MEDIA_PAUSE",          0x40000107u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PAUSE) */
        KeyNameDef("SDLK_MEDIA_RECORD",         0x40000108u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_RECORD) */
        KeyNameDef("SDLK_MEDIA_FAST_FORWARD",   0x40000109u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_FAST_FORWARD) */
        KeyNameDef("SDLK_MEDIA_REWIND",         0x4000010au), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_REWIND) */
        KeyNameDef("SDLK_MEDIA_NEXT_TRACK",     0x4000010bu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_NEXT_TRACK) */
        KeyNameDef("SDLK_MEDIA_PREVIOUS_TRACK", 0x4000010cu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PREVIOUS_TRACK) */
        KeyNameDef("SDLK_MEDIA_STOP",           0x4000010du), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_STOP) */
        KeyNameDef("SDLK_MEDIA_EJECT",          0x4000010eu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_EJECT) */
        KeyNameDef("SDLK_MEDIA_PLAY_PAUSE",     0x4000010fu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_PLAY_PAUSE) */
        KeyNameDef("SDLK_MEDIA_SELECT",         0x40000110u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIA_SELECT) */
        KeyNameDef("SDLK_AC_NEW",               0x40000111u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_NEW) */
        KeyNameDef("SDLK_AC_OPEN",              0x40000112u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_OPEN) */
        KeyNameDef("SDLK_AC_CLOSE",             0x40000113u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_CLOSE) */
        KeyNameDef("SDLK_AC_EXIT",              0x40000114u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_EXIT) */
        KeyNameDef("SDLK_AC_SAVE",              0x40000115u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SAVE) */
        KeyNameDef("SDLK_AC_PRINT",             0x40000116u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_PRINT) */
        KeyNameDef("SDLK_AC_PROPERTIES",        0x40000117u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_PROPERTIES) */
        KeyNameDef("SDLK_AC_SEARCH",            0x40000118u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SEARCH) */
        KeyNameDef("SDLK_AC_HOME",              0x40000119u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_HOME) */
        KeyNameDef("SDLK_AC_BACK",              0x4000011au), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BACK) */
        KeyNameDef("SDLK_AC_FORWARD",           0x4000011bu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_FORWARD) */
        KeyNameDef("SDLK_AC_STOP",              0x4000011cu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_STOP) */
        KeyNameDef("SDLK_AC_REFRESH",           0x4000011du), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_REFRESH) */
        KeyNameDef("SDLK_AC_BOOKMARKS",         0x4000011eu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BOOKMARKS) */
        KeyNameDef("SDLK_SOFTLEFT",             0x4000011fu), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTLEFT) */
        KeyNameDef("SDLK_SOFTRIGHT",            0x40000120u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTRIGHT) */
        KeyNameDef("SDLK_CALL",                 0x40000121u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALL) */
        KeyNameDef("SDLK_ENDCALL",              0x40000122u), /**< SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ENDCALL) */
        KeyNameDef("SDLK_LEFT_TAB",             0x20000001u), /**< Extended key Left Tab */
        KeyNameDef("SDLK_LEVEL5_SHIFT",         0x20000002u), /**< Extended key Level 5 Shift */
        KeyNameDef("SDLK_MULTI_KEY_COMPOSE",    0x20000003u), /**< Extended key Multi-key Compose */
        KeyNameDef("SDLK_LMETA",                0x20000004u), /**< Extended key Left Meta */
        KeyNameDef("SDLK_RMETA",                0x20000005u), /**< Extended key Right Meta */
        KeyNameDef("SDLK_LHYPER",               0x20000006u), /**< Extended key Left Hyper */
        KeyNameDef("SDLK_RHYPER",               0x20000007u), /**< Extended key Right Hyper */
    };
    return mapping;
}

const char* getScanCodeName(SDL_Scancode s) {
    const auto* mapping = binary_find(getScanCodeNameMap(), uint32_t(s), {}, &KeyNameDef::code);
    if (mapping) {
        return mapping->name;
    }
    return "SDL_SCANCODE_UNKNOWN";
}

const char* getKeyCodeName(SDL_Keycode s) {
    const auto* mapping = binary_find(getKeyCodeNameMap(), uint32_t(s), {}, &KeyNameDef::code);
    if (mapping) {
        return mapping->name;
    }
    return "SDLK_UNKNOWN";
}

}
#endif //KEYTEST