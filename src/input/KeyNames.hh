#if KEYTEST //-->

// KeyNames.hh

/*
    DL_getScancodeName and SDL_getKeycodeName may return characters 
	that are difficult to recognize in label names and are unstable.
	As an alternative, here is a set of functions that return label names.
*/

namespace openmsx {

template <typename T>
struct KeyLabelName {
    T code;
    const char * name;
};

#define SCANCODE_LABEL_D( v ) KeyLabelName<SDL_Scancode>( v, #v )
#define KEYCODE_LABEL_D( v ) KeyLabelName<SDL_Keycode>( v, #v )

#include "SDL_scancode.h"

/** get Scancode label string list */
static constexpr auto getScanCodeLabelStringMap() {
	std::array mapping = {

	    SCANCODE_LABEL_D( SDL_SCANCODE_UNKNOWN ), 	/* 0 */ 

	    /**
	     *  \name Usage page 0x07
	     *
	     *  These values are from usage page 0x07 (USB keyboard page).
	     */
	    /* @{ */

	    SCANCODE_LABEL_D( SDL_SCANCODE_A ), 	/* 4 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_B ), 	/* 5 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_C ), 	/* 6 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_D ), 	/* 7 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_E ), 	/* 8 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F ), 	/* 9 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_G ), 	/* 10 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_H ), 	/* 11 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_I ), 	/* 12 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_J ), 	/* 13 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_K ), 	/* 14 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_L ), 	/* 15 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_M ), 	/* 16 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_N ), 	/* 17 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_O ), 	/* 18 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_P ), 	/* 19 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_Q ), 	/* 20 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_R ), 	/* 21 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_S ), 	/* 22 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_T ), 	/* 23 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_U ), 	/* 24 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_V ), 	/* 25 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_W ), 	/* 26 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_X ), 	/* 27 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_Y ), 	/* 28 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_Z ), 	/* 29 */ 

	    SCANCODE_LABEL_D( SDL_SCANCODE_1 ), 	/* 30 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_2 ), 	/* 31 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_3 ), 	/* 32 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_4 ), 	/* 33 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_5 ), 	/* 34 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_6 ), 	/* 35 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_7 ), 	/* 36 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_8 ), 	/* 37 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_9 ), 	/* 38 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_0 ), 	/* 39 */ 

	    SCANCODE_LABEL_D( SDL_SCANCODE_RETURN ), 	/* 40 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_ESCAPE ), 	/* 41 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_BACKSPACE ), 	/* 42 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_TAB ), 	/* 43 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_SPACE ), 	/* 44 */ 

	    SCANCODE_LABEL_D( SDL_SCANCODE_MINUS ), 	/* 45 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_EQUALS ), 	/* 46 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_LEFTBRACKET ), 	/* 47 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_RIGHTBRACKET ), 	/* 48 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_BACKSLASH ), 	/* 49 */  /**< Located at the lower left of the return
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
	    SCANCODE_LABEL_D( SDL_SCANCODE_NONUSHASH ), 	/* 50 */  /**< ISO USB keyboards actually use this code
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
	    SCANCODE_LABEL_D( SDL_SCANCODE_SEMICOLON ), 	/* 51 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_APOSTROPHE ), 	/* 52 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_GRAVE ), 	/* 53 */  /**< Located in the top left corner (on both ANSI
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
	    SCANCODE_LABEL_D( SDL_SCANCODE_COMMA ), 	/* 54 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_PERIOD ), 	/* 55 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_SLASH ), 	/* 56 */ 

	    SCANCODE_LABEL_D( SDL_SCANCODE_CAPSLOCK ), 	/* 57 */ 

	    SCANCODE_LABEL_D( SDL_SCANCODE_F1 ), 	/* 58 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F2 ), 	/* 59 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F3 ), 	/* 60 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F4 ), 	/* 61 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F5 ), 	/* 62 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F6 ), 	/* 63 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F7 ), 	/* 64 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F8 ), 	/* 65 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F9 ), 	/* 66 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F10 ), 	/* 67 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F11 ), 	/* 68 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F12 ), 	/* 69 */ 

	    SCANCODE_LABEL_D( SDL_SCANCODE_PRINTSCREEN ), 	/* 70 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_SCROLLLOCK ), 	/* 71 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_PAUSE ), 	/* 72 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_INSERT ), 	/* 73 */  /**< insert on PC, help on some Mac keyboards (but
	                                   does send code 73, not 117) */
	    SCANCODE_LABEL_D( SDL_SCANCODE_HOME ), 	/* 74 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_PAGEUP ), 	/* 75 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_DELETE ), 	/* 76 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_END ), 	/* 77 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_PAGEDOWN ), 	/* 78 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_RIGHT ), 	/* 79 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_LEFT ), 	/* 80 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_DOWN ), 	/* 81 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_UP ), 	/* 82 */ 

	    SCANCODE_LABEL_D( SDL_SCANCODE_NUMLOCKCLEAR ), 	/* 83 */  /**< num lock on PC, clear on Mac keyboards
	                                     */
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_DIVIDE ), 	/* 84 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_MULTIPLY ), 	/* 85 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_MINUS ), 	/* 86 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_PLUS ), 	/* 87 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_ENTER ), 	/* 88 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_1 ), 	/* 89 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_2 ), 	/* 90 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_3 ), 	/* 91 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_4 ), 	/* 92 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_5 ), 	/* 93 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_6 ), 	/* 94 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_7 ), 	/* 95 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_8 ), 	/* 96 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_9 ), 	/* 97 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_0 ), 	/* 98 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_PERIOD ), 	/* 99 */ 

	    SCANCODE_LABEL_D( SDL_SCANCODE_NONUSBACKSLASH ), 	/* 100 */  /**< This is the additional key that ISO
	                                        *   keyboards have over ANSI ones,
	                                        *   located between left shift and Y.
	                                        *   Produces GRAVE ACCENT and TILDE in a
	                                        *   US or UK Mac layout, REVERSE SOLIDUS
	                                        *   (backslash) and VERTICAL LINE in a
	                                        *   US or UK Windows layout, and
	                                        *   LESS-THAN SIGN and GREATER-THAN SIGN
	                                        *   in a Swiss German, German, or French
	                                        *   layout. */
	    SCANCODE_LABEL_D( SDL_SCANCODE_APPLICATION ), 	/* 101 */  /**< windows contextual menu, compose */
	    SCANCODE_LABEL_D( SDL_SCANCODE_POWER ), 	/* 102 */  /**< The USB document says this is a status flag,
	                               *   not a physical key - but some Mac keyboards
	                               *   do have a power key. */
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_EQUALS ), 	/* 103 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F13 ), 	/* 104 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F14 ), 	/* 105 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F15 ), 	/* 106 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F16 ), 	/* 107 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F17 ), 	/* 108 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F18 ), 	/* 109 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F19 ), 	/* 110 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F20 ), 	/* 111 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F21 ), 	/* 112 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F22 ), 	/* 113 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F23 ), 	/* 114 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_F24 ), 	/* 115 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_EXECUTE ), 	/* 116 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_HELP ), 	/* 117 */     /**< AL Integrated Help Center */
	    SCANCODE_LABEL_D( SDL_SCANCODE_MENU ), 	/* 118 */     /**< Menu (show menu) */
	    SCANCODE_LABEL_D( SDL_SCANCODE_SELECT ), 	/* 119 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_STOP ), 	/* 120 */     /**< AC Stop */
	    SCANCODE_LABEL_D( SDL_SCANCODE_AGAIN ), 	/* 121 */    /**< AC Redo/Repeat */
	    SCANCODE_LABEL_D( SDL_SCANCODE_UNDO ), 	/* 122 */     /**< AC Undo */
	    SCANCODE_LABEL_D( SDL_SCANCODE_CUT ), 	/* 123 */      /**< AC Cut */
	    SCANCODE_LABEL_D( SDL_SCANCODE_COPY ), 	/* 124 */     /**< AC Copy */
	    SCANCODE_LABEL_D( SDL_SCANCODE_PASTE ), 	/* 125 */    /**< AC Paste */
	    SCANCODE_LABEL_D( SDL_SCANCODE_FIND ), 	/* 126 */     /**< AC Find */
	    SCANCODE_LABEL_D( SDL_SCANCODE_MUTE ), 	/* 127 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_VOLUMEUP ), 	/* 128 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_VOLUMEDOWN ), 	/* 129 */ 
	/* not sure whether there's a reason to enable these */
	//     SCANCODE_LABEL_D( SDL_SCANCODE_LOCKINGCAPSLOCK ), 	/* 130 */   */
	//     SCANCODE_LABEL_D( SDL_SCANCODE_LOCKINGNUMLOCK ), 	/* 131 */  */
	//     SCANCODE_LABEL_D( SDL_SCANCODE_LOCKINGSCROLLLOCK ), 	/* 132 */  */
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_COMMA ), 	/* 133 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_EQUALSAS400 ), 	/* 134 */ 

	    SCANCODE_LABEL_D( SDL_SCANCODE_INTERNATIONAL1 ), 	/* 135 */  /**< used on Asian keyboards, see
	                                            footnotes in USB doc */
	    SCANCODE_LABEL_D( SDL_SCANCODE_INTERNATIONAL2 ), 	/* 136 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_INTERNATIONAL3 ), 	/* 137 */  /**< Yen */
	    SCANCODE_LABEL_D( SDL_SCANCODE_INTERNATIONAL4 ), 	/* 138 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_INTERNATIONAL5 ), 	/* 139 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_INTERNATIONAL6 ), 	/* 140 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_INTERNATIONAL7 ), 	/* 141 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_INTERNATIONAL8 ), 	/* 142 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_INTERNATIONAL9 ), 	/* 143 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_LANG1 ), 	/* 144 */  /**< Hangul/English toggle */
	    SCANCODE_LABEL_D( SDL_SCANCODE_LANG2 ), 	/* 145 */  /**< Hanja conversion */
	    SCANCODE_LABEL_D( SDL_SCANCODE_LANG3 ), 	/* 146 */  /**< Katakana */
	    SCANCODE_LABEL_D( SDL_SCANCODE_LANG4 ), 	/* 147 */  /**< Hiragana */
	    SCANCODE_LABEL_D( SDL_SCANCODE_LANG5 ), 	/* 148 */  /**< Zenkaku/Hankaku */
	    SCANCODE_LABEL_D( SDL_SCANCODE_LANG6 ), 	/* 149 */  /**< reserved */
	    SCANCODE_LABEL_D( SDL_SCANCODE_LANG7 ), 	/* 150 */  /**< reserved */
	    SCANCODE_LABEL_D( SDL_SCANCODE_LANG8 ), 	/* 151 */  /**< reserved */
	    SCANCODE_LABEL_D( SDL_SCANCODE_LANG9 ), 	/* 152 */  /**< reserved */

	    SCANCODE_LABEL_D( SDL_SCANCODE_ALTERASE ), 	/* 153 */     /**< Erase-Eaze */
	    SCANCODE_LABEL_D( SDL_SCANCODE_SYSREQ ), 	/* 154 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_CANCEL ), 	/* 155 */       /**< AC Cancel */
	    SCANCODE_LABEL_D( SDL_SCANCODE_CLEAR ), 	/* 156 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_PRIOR ), 	/* 157 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_RETURN2 ), 	/* 158 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_SEPARATOR ), 	/* 159 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_OUT ), 	/* 160 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_OPER ), 	/* 161 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_CLEARAGAIN ), 	/* 162 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_CRSEL ), 	/* 163 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_EXSEL ), 	/* 164 */ 

	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_00 ), 	/* 176 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_000 ), 	/* 177 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_THOUSANDSSEPARATOR ), 	/* 178 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_DECIMALSEPARATOR ), 	/* 179 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_CURRENCYUNIT ), 	/* 180 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_CURRENCYSUBUNIT ), 	/* 181 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_LEFTPAREN ), 	/* 182 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_RIGHTPAREN ), 	/* 183 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_LEFTBRACE ), 	/* 184 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_RIGHTBRACE ), 	/* 185 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_TAB ), 	/* 186 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_BACKSPACE ), 	/* 187 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_A ), 	/* 188 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_B ), 	/* 189 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_C ), 	/* 190 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_D ), 	/* 191 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_E ), 	/* 192 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_F ), 	/* 193 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_XOR ), 	/* 194 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_POWER ), 	/* 195 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_PERCENT ), 	/* 196 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_LESS ), 	/* 197 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_GREATER ), 	/* 198 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_AMPERSAND ), 	/* 199 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_DBLAMPERSAND ), 	/* 200 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_VERTICALBAR ), 	/* 201 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_DBLVERTICALBAR ), 	/* 202 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_COLON ), 	/* 203 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_HASH ), 	/* 204 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_SPACE ), 	/* 205 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_AT ), 	/* 206 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_EXCLAM ), 	/* 207 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_MEMSTORE ), 	/* 208 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_MEMRECALL ), 	/* 209 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_MEMCLEAR ), 	/* 210 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_MEMADD ), 	/* 211 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_MEMSUBTRACT ), 	/* 212 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_MEMMULTIPLY ), 	/* 213 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_MEMDIVIDE ), 	/* 214 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_PLUSMINUS ), 	/* 215 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_CLEAR ), 	/* 216 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_CLEARENTRY ), 	/* 217 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_BINARY ), 	/* 218 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_OCTAL ), 	/* 219 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_DECIMAL ), 	/* 220 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KP_HEXADECIMAL ), 	/* 221 */ 

	    SCANCODE_LABEL_D( SDL_SCANCODE_LCTRL ), 	/* 224 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_LSHIFT ), 	/* 225 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_LALT ), 	/* 226 */  /**< alt, option */
	    SCANCODE_LABEL_D( SDL_SCANCODE_LGUI ), 	/* 227 */  /**< windows, command (apple), meta */
	    SCANCODE_LABEL_D( SDL_SCANCODE_RCTRL ), 	/* 228 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_RSHIFT ), 	/* 229 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_RALT ), 	/* 230 */  /**< alt gr, option */
	    SCANCODE_LABEL_D( SDL_SCANCODE_RGUI ), 	/* 231 */  /**< windows, command (apple), meta */

	    SCANCODE_LABEL_D( SDL_SCANCODE_MODE ), 	/* 257 */     /**< I'm not sure if this is really not covered
	                                 *   by any of the above, but since there's a
	                                 *   special KMOD_MODE for it I'm adding it here
	                                 */

	    /* @} *//* Usage page 0x07 */

	    /**
	     *  \name Usage page 0x0C
	     *
	     *  These values are mapped from usage page 0x0C (USB consumer page).
	     *  See https://usb.org/sites/default/files/hut1_2.pdf
	     *
	     *  There are way more keys in the spec than we can represent in the
	     *  current scancode range, so pick the ones that commonly come up in
	     *  real world usage.
	     */
	    /* @{ */

	    SCANCODE_LABEL_D( SDL_SCANCODE_AUDIONEXT ), 	/* 258 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_AUDIOPREV ), 	/* 259 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_AUDIOSTOP ), 	/* 260 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_AUDIOPLAY ), 	/* 261 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_AUDIOMUTE ), 	/* 262 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_MEDIASELECT ), 	/* 263 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_WWW ), 	/* 264 */              /**< AL Internet Browser */
	    SCANCODE_LABEL_D( SDL_SCANCODE_MAIL ), 	/* 265 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_CALCULATOR ), 	/* 266 */       /**< AL Calculator */
	    SCANCODE_LABEL_D( SDL_SCANCODE_COMPUTER ), 	/* 267 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_AC_SEARCH ), 	/* 268 */        /**< AC Search */
	    SCANCODE_LABEL_D( SDL_SCANCODE_AC_HOME ), 	/* 269 */          /**< AC Home */
	    SCANCODE_LABEL_D( SDL_SCANCODE_AC_BACK ), 	/* 270 */          /**< AC Back */
	    SCANCODE_LABEL_D( SDL_SCANCODE_AC_FORWARD ), 	/* 271 */       /**< AC Forward */
	    SCANCODE_LABEL_D( SDL_SCANCODE_AC_STOP ), 	/* 272 */          /**< AC Stop */
	    SCANCODE_LABEL_D( SDL_SCANCODE_AC_REFRESH ), 	/* 273 */       /**< AC Refresh */
	    SCANCODE_LABEL_D( SDL_SCANCODE_AC_BOOKMARKS ), 	/* 274 */     /**< AC Bookmarks */

	    /* @} *//* Usage page 0x0C */

	    /**
	     *  \name Walther keys
	     *
	     *  These are values that Christian Walther added (for mac keyboard?).
	     */
	    /* @{ */

	    SCANCODE_LABEL_D( SDL_SCANCODE_BRIGHTNESSDOWN ), 	/* 275 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_BRIGHTNESSUP ), 	/* 276 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_DISPLAYSWITCH ), 	/* 277 */  /**< display mirroring/dual display
	                                           switch, video mode switch */
	    SCANCODE_LABEL_D( SDL_SCANCODE_KBDILLUMTOGGLE ), 	/* 278 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KBDILLUMDOWN ), 	/* 279 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_KBDILLUMUP ), 	/* 280 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_EJECT ), 	/* 281 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_SLEEP ), 	/* 282 */            /**< SC System Sleep */

	    SCANCODE_LABEL_D( SDL_SCANCODE_APP1 ), 	/* 283 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_APP2 ), 	/* 284 */ 

	    /* @} *//* Walther keys */

	    /**
	     *  \name Usage page 0x0C (additional media keys)
	     *
	     *  These values are mapped from usage page 0x0C (USB consumer page).
	     */
	    /* @{ */

	    SCANCODE_LABEL_D( SDL_SCANCODE_AUDIOREWIND ), 	/* 285 */ 
	    SCANCODE_LABEL_D( SDL_SCANCODE_AUDIOFASTFORWARD ), 	/* 286 */ 

	    /* @} *//* Usage page 0x0C (additional media keys) */

	    /**
	     *  \name Mobile keys
	     *
	     *  These are values that are often used on mobile phones.
	     */
	    /* @{ */

	    SCANCODE_LABEL_D( SDL_SCANCODE_SOFTLEFT ), 	/* 287 */  /**< Usually situated below the display on phones and
	                                      used as a multi-function feature key for selecting
	                                      a software defined function shown on the bottom left
	                                      of the display. */
	    SCANCODE_LABEL_D( SDL_SCANCODE_SOFTRIGHT ), 	/* 288 */  /**< Usually situated below the display on phones and
	                                       used as a multi-function feature key for selecting
	                                       a software defined function shown on the bottom right
	                                       of the display. */
	    SCANCODE_LABEL_D( SDL_SCANCODE_CALL ), 	/* 289 */  /**< Used for accepting phone calls. */
	    SCANCODE_LABEL_D( SDL_SCANCODE_ENDCALL ), 	/* 290 */  /**< Used for rejecting phone calls. */

	    /* @} *//* Mobile keys */

	    /* Add any other keys here. */

	    // SCANCODE_LABEL_D( SDL_NUM_SCANCODES ) /* 512 */ /**< not a key, just marks the number of scancodes
	    //                              for array bounds */
		};
    return mapping;
}

#include "SDL_keycode.h"

/** get Keycode label string list */
static constexpr auto getKeyCodeLabelStringMap() {
	std::array mapping = {
	    KEYCODE_LABEL_D( SDLK_UNKNOWN ), 	/* 0 */ 

	    KEYCODE_LABEL_D( SDLK_RETURN ), 	/* '\r' */ 
	    KEYCODE_LABEL_D( SDLK_ESCAPE ), 	/* '\x1B' */ 
	    KEYCODE_LABEL_D( SDLK_BACKSPACE ), 	/* '\b' */ 
	    KEYCODE_LABEL_D( SDLK_TAB ), 	/* '\t' */ 
	    KEYCODE_LABEL_D( SDLK_SPACE ), 	/* ' ' */ 
	    KEYCODE_LABEL_D( SDLK_EXCLAIM ), 	/* '!' */ 
	    KEYCODE_LABEL_D( SDLK_QUOTEDBL ), 	/* '"' */ 
	    KEYCODE_LABEL_D( SDLK_HASH ), 	/* '#' */ 
	    KEYCODE_LABEL_D( SDLK_PERCENT ), 	/* '%' */ 
	    KEYCODE_LABEL_D( SDLK_DOLLAR ), 	/* '$' */ 
	    KEYCODE_LABEL_D( SDLK_AMPERSAND ), 	/* '&' */ 
	    KEYCODE_LABEL_D( SDLK_QUOTE ), 	/* '\'' */ 
	    KEYCODE_LABEL_D( SDLK_LEFTPAREN ), 	/* '(' */ 
	    KEYCODE_LABEL_D( SDLK_RIGHTPAREN ), 	/* ')' */ 
	    KEYCODE_LABEL_D( SDLK_ASTERISK ), 	/* '*' */ 
	    KEYCODE_LABEL_D( SDLK_PLUS ), 	/* '+' */ 
	    KEYCODE_LABEL_D( SDLK_COMMA ), 	/* ',' */ 
	    KEYCODE_LABEL_D( SDLK_MINUS ), 	/* '-' */ 
	    KEYCODE_LABEL_D( SDLK_PERIOD ), 	/* '.' */ 
	    KEYCODE_LABEL_D( SDLK_SLASH ), /* '/' */
	    KEYCODE_LABEL_D( SDLK_0 ), 	/* '0' */ 
	    KEYCODE_LABEL_D( SDLK_1 ), 	/* '1' */ 
	    KEYCODE_LABEL_D( SDLK_2 ), 	/* '2' */ 
	    KEYCODE_LABEL_D( SDLK_3 ), 	/* '3' */ 
	    KEYCODE_LABEL_D( SDLK_4 ), 	/* '4' */ 
	    KEYCODE_LABEL_D( SDLK_5 ), 	/* '5' */ 
	    KEYCODE_LABEL_D( SDLK_6 ), 	/* '6' */ 
	    KEYCODE_LABEL_D( SDLK_7 ), 	/* '7' */ 
	    KEYCODE_LABEL_D( SDLK_8 ), 	/* '8' */ 
	    KEYCODE_LABEL_D( SDLK_9 ), 	/* '9' */ 
	    KEYCODE_LABEL_D( SDLK_COLON ), 	/* ':' */ 
	    KEYCODE_LABEL_D( SDLK_SEMICOLON ), 	/* ';' */ 
	    KEYCODE_LABEL_D( SDLK_LESS ), 	/* '<' */ 
	    KEYCODE_LABEL_D( SDLK_EQUALS ), /* '=' */ 
	    KEYCODE_LABEL_D( SDLK_GREATER ), 	/* '>' */ 
	    KEYCODE_LABEL_D( SDLK_QUESTION ), 	/* '?' */ 
	    KEYCODE_LABEL_D( SDLK_AT ), 	/* '@' */ 

	    /*
	       Skip uppercase letters
	     */

	    KEYCODE_LABEL_D( SDLK_LEFTBRACKET ), 	/* '[' */ 
	    KEYCODE_LABEL_D( SDLK_BACKSLASH ), 	/* '\\' */ 
	    KEYCODE_LABEL_D( SDLK_RIGHTBRACKET ), 	/* ']' */ 
	    KEYCODE_LABEL_D( SDLK_CARET ), 	/* '^' */ 
	    KEYCODE_LABEL_D( SDLK_UNDERSCORE ), 	/* '_' */ 
	    KEYCODE_LABEL_D( SDLK_BACKQUOTE ), 	/* '`' */ 
	    KEYCODE_LABEL_D( SDLK_a ), 	/* 'a' */ 
	    KEYCODE_LABEL_D( SDLK_b ), 	/* 'b' */ 
	    KEYCODE_LABEL_D( SDLK_c ), 	/* 'c' */ 
	    KEYCODE_LABEL_D( SDLK_d ), 	/* 'd' */ 
	    KEYCODE_LABEL_D( SDLK_e ), 	/* 'e' */ 
	    KEYCODE_LABEL_D( SDLK_f ), 	/* 'f' */ 
	    KEYCODE_LABEL_D( SDLK_g ), 	/* 'g' */ 
	    KEYCODE_LABEL_D( SDLK_h ), 	/* 'h' */ 
	    KEYCODE_LABEL_D( SDLK_i ), 	/* 'i' */ 
	    KEYCODE_LABEL_D( SDLK_j ), 	/* 'j' */ 
	    KEYCODE_LABEL_D( SDLK_k ), 	/* 'k' */ 
	    KEYCODE_LABEL_D( SDLK_l ), 	/* 'l' */ 
	    KEYCODE_LABEL_D( SDLK_m ), 	/* 'm' */ 
	    KEYCODE_LABEL_D( SDLK_n ), 	/* 'n' */ 
	    KEYCODE_LABEL_D( SDLK_o ), 	/* 'o' */ 
	    KEYCODE_LABEL_D( SDLK_p ), 	/* 'p' */ 
	    KEYCODE_LABEL_D( SDLK_q ), 	/* 'q' */ 
	    KEYCODE_LABEL_D( SDLK_r ), 	/* 'r' */ 
	    KEYCODE_LABEL_D( SDLK_s ), 	/* 's' */ 
	    KEYCODE_LABEL_D( SDLK_t ), 	/* 't' */ 
	    KEYCODE_LABEL_D( SDLK_u ), 	/* 'u' */ 
	    KEYCODE_LABEL_D( SDLK_v ), 	/* 'v' */ 
	    KEYCODE_LABEL_D( SDLK_w ), 	/* 'w' */ 
	    KEYCODE_LABEL_D( SDLK_x ), 	/* 'x' */ 
	    KEYCODE_LABEL_D( SDLK_y ), 	/* 'y' */ 
	    KEYCODE_LABEL_D( SDLK_z ), 	/* 'z' */ 

	    KEYCODE_LABEL_D( SDLK_CAPSLOCK ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CAPSLOCK) */ 

	    KEYCODE_LABEL_D( SDLK_F1 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F1) */ 
	    KEYCODE_LABEL_D( SDLK_F2 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F2) */ 
	    KEYCODE_LABEL_D( SDLK_F3 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F3) */ 
	    KEYCODE_LABEL_D( SDLK_F4 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F4) */ 
	    KEYCODE_LABEL_D( SDLK_F5 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F5) */ 
	    KEYCODE_LABEL_D( SDLK_F6 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F6) */ 
	    KEYCODE_LABEL_D( SDLK_F7 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F7) */ 
	    KEYCODE_LABEL_D( SDLK_F8 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F8) */ 
	    KEYCODE_LABEL_D( SDLK_F9 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F9) */ 
	    KEYCODE_LABEL_D( SDLK_F10 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F10) */ 
	    KEYCODE_LABEL_D( SDLK_F11 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F11) */ 
	    KEYCODE_LABEL_D( SDLK_F12 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F12) */ 

	    KEYCODE_LABEL_D( SDLK_PRINTSCREEN ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRINTSCREEN) */ 
	    KEYCODE_LABEL_D( SDLK_SCROLLLOCK ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SCROLLLOCK) */ 
	    KEYCODE_LABEL_D( SDLK_PAUSE ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAUSE) */ 
	    KEYCODE_LABEL_D( SDLK_INSERT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_INSERT) */ 
	    KEYCODE_LABEL_D( SDLK_HOME ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HOME) */ 
	    KEYCODE_LABEL_D( SDLK_PAGEUP ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEUP) */ 
	    KEYCODE_LABEL_D( SDLK_DELETE ), 	/* '\x7F' */ 
	    KEYCODE_LABEL_D( SDLK_END ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_END) */ 
	    KEYCODE_LABEL_D( SDLK_PAGEDOWN ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PAGEDOWN) */ 
	    KEYCODE_LABEL_D( SDLK_RIGHT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RIGHT) */ 
	    KEYCODE_LABEL_D( SDLK_LEFT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LEFT) */ 
	    KEYCODE_LABEL_D( SDLK_DOWN ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DOWN) */ 
	    KEYCODE_LABEL_D( SDLK_UP ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UP) */ 

	    KEYCODE_LABEL_D( SDLK_NUMLOCKCLEAR ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_NUMLOCKCLEAR) */ 
	    KEYCODE_LABEL_D( SDLK_KP_DIVIDE ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DIVIDE) */ 
	    KEYCODE_LABEL_D( SDLK_KP_MULTIPLY ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MULTIPLY) */ 
	    KEYCODE_LABEL_D( SDLK_KP_MINUS ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MINUS) */ 
	    KEYCODE_LABEL_D( SDLK_KP_PLUS ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUS) */ 
	    KEYCODE_LABEL_D( SDLK_KP_ENTER ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_ENTER) */ 
	    KEYCODE_LABEL_D( SDLK_KP_1 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_1) */ 
	    KEYCODE_LABEL_D( SDLK_KP_2 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_2) */ 
	    KEYCODE_LABEL_D( SDLK_KP_3 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_3) */ 
	    KEYCODE_LABEL_D( SDLK_KP_4 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_4) */ 
	    KEYCODE_LABEL_D( SDLK_KP_5 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_5) */ 
	    KEYCODE_LABEL_D( SDLK_KP_6 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_6) */ 
	    KEYCODE_LABEL_D( SDLK_KP_7 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_7) */ 
	    KEYCODE_LABEL_D( SDLK_KP_8 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_8) */ 
	    KEYCODE_LABEL_D( SDLK_KP_9 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_9) */ 
	    KEYCODE_LABEL_D( SDLK_KP_0 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_0) */ 
	    KEYCODE_LABEL_D( SDLK_KP_PERIOD ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERIOD) */ 

	    KEYCODE_LABEL_D( SDLK_APPLICATION ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APPLICATION) */ 
	    KEYCODE_LABEL_D( SDLK_POWER ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_POWER) */ 
	    KEYCODE_LABEL_D( SDLK_KP_EQUALS ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALS) */ 
	    KEYCODE_LABEL_D( SDLK_F13 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F13) */ 
	    KEYCODE_LABEL_D( SDLK_F14 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F14) */ 
	    KEYCODE_LABEL_D( SDLK_F15 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F15) */ 
	    KEYCODE_LABEL_D( SDLK_F16 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F16) */ 
	    KEYCODE_LABEL_D( SDLK_F17 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F17) */ 
	    KEYCODE_LABEL_D( SDLK_F18 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F18) */ 
	    KEYCODE_LABEL_D( SDLK_F19 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F19) */ 
	    KEYCODE_LABEL_D( SDLK_F20 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F20) */ 
	    KEYCODE_LABEL_D( SDLK_F21 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F21) */ 
	    KEYCODE_LABEL_D( SDLK_F22 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F22) */ 
	    KEYCODE_LABEL_D( SDLK_F23 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F23) */ 
	    KEYCODE_LABEL_D( SDLK_F24 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_F24) */ 
	    KEYCODE_LABEL_D( SDLK_EXECUTE ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXECUTE) */ 
	    KEYCODE_LABEL_D( SDLK_HELP ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_HELP) */ 
	    KEYCODE_LABEL_D( SDLK_MENU ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MENU) */ 
	    KEYCODE_LABEL_D( SDLK_SELECT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SELECT) */ 
	    KEYCODE_LABEL_D( SDLK_STOP ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_STOP) */ 
	    KEYCODE_LABEL_D( SDLK_AGAIN ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AGAIN) */ 
	    KEYCODE_LABEL_D( SDLK_UNDO ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_UNDO) */ 
	    KEYCODE_LABEL_D( SDLK_CUT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CUT) */ 
	    KEYCODE_LABEL_D( SDLK_COPY ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COPY) */ 
	    KEYCODE_LABEL_D( SDLK_PASTE ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PASTE) */ 
	    KEYCODE_LABEL_D( SDLK_FIND ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_FIND) */ 
	    KEYCODE_LABEL_D( SDLK_MUTE ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MUTE) */ 
	    KEYCODE_LABEL_D( SDLK_VOLUMEUP ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEUP) */ 
	    KEYCODE_LABEL_D( SDLK_VOLUMEDOWN ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_VOLUMEDOWN) */ 
	    KEYCODE_LABEL_D( SDLK_KP_COMMA ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COMMA) */ 
	    KEYCODE_LABEL_D( SDLK_KP_EQUALSAS400 ), 
	        /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EQUALSAS400) */ 

	    KEYCODE_LABEL_D( SDLK_ALTERASE ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ALTERASE) */ 
	    KEYCODE_LABEL_D( SDLK_SYSREQ ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SYSREQ) */ 
	    KEYCODE_LABEL_D( SDLK_CANCEL ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CANCEL) */ 
	    KEYCODE_LABEL_D( SDLK_CLEAR ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEAR) */ 
	    KEYCODE_LABEL_D( SDLK_PRIOR ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_PRIOR) */ 
	    KEYCODE_LABEL_D( SDLK_RETURN2 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RETURN2) */ 
	    KEYCODE_LABEL_D( SDLK_SEPARATOR ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SEPARATOR) */ 
	    KEYCODE_LABEL_D( SDLK_OUT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OUT) */ 
	    KEYCODE_LABEL_D( SDLK_OPER ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_OPER) */ 
	    KEYCODE_LABEL_D( SDLK_CLEARAGAIN ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CLEARAGAIN) */ 
	    KEYCODE_LABEL_D( SDLK_CRSEL ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CRSEL) */ 
	    KEYCODE_LABEL_D( SDLK_EXSEL ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EXSEL) */ 

	    KEYCODE_LABEL_D( SDLK_KP_00 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_00) */ 
	    KEYCODE_LABEL_D( SDLK_KP_000 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_000) */ 
	    KEYCODE_LABEL_D( SDLK_THOUSANDSSEPARATOR ), 
	        /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_THOUSANDSSEPARATOR) */ 
	    KEYCODE_LABEL_D( SDLK_DECIMALSEPARATOR ), 
	        /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DECIMALSEPARATOR) */ 
	    KEYCODE_LABEL_D( SDLK_CURRENCYUNIT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYUNIT) */ 
	    KEYCODE_LABEL_D( SDLK_CURRENCYSUBUNIT ), 
	        /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CURRENCYSUBUNIT) */ 
	    KEYCODE_LABEL_D( SDLK_KP_LEFTPAREN ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTPAREN) */ 
	    KEYCODE_LABEL_D( SDLK_KP_RIGHTPAREN ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTPAREN) */ 
	    KEYCODE_LABEL_D( SDLK_KP_LEFTBRACE ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LEFTBRACE) */ 
	    KEYCODE_LABEL_D( SDLK_KP_RIGHTBRACE ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_RIGHTBRACE) */ 
	    KEYCODE_LABEL_D( SDLK_KP_TAB ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_TAB) */ 
	    KEYCODE_LABEL_D( SDLK_KP_BACKSPACE ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BACKSPACE) */ 
	    KEYCODE_LABEL_D( SDLK_KP_A ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_A) */ 
	    KEYCODE_LABEL_D( SDLK_KP_B ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_B) */ 
	    KEYCODE_LABEL_D( SDLK_KP_C ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_C) */ 
	    KEYCODE_LABEL_D( SDLK_KP_D ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_D) */ 
	    KEYCODE_LABEL_D( SDLK_KP_E ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_E) */ 
	    KEYCODE_LABEL_D( SDLK_KP_F ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_F) */ 
	    KEYCODE_LABEL_D( SDLK_KP_XOR ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_XOR) */ 
	    KEYCODE_LABEL_D( SDLK_KP_POWER ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_POWER) */ 
	    KEYCODE_LABEL_D( SDLK_KP_PERCENT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PERCENT) */ 
	    KEYCODE_LABEL_D( SDLK_KP_LESS ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_LESS) */ 
	    KEYCODE_LABEL_D( SDLK_KP_GREATER ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_GREATER) */ 
	    KEYCODE_LABEL_D( SDLK_KP_AMPERSAND ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AMPERSAND) */ 
	    KEYCODE_LABEL_D( SDLK_KP_DBLAMPERSAND ), 
	        /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLAMPERSAND) */ 
	    KEYCODE_LABEL_D( SDLK_KP_VERTICALBAR ), 
	        /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_VERTICALBAR) */ 
	    KEYCODE_LABEL_D( SDLK_KP_DBLVERTICALBAR ), 
	        /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DBLVERTICALBAR) */ 
	    KEYCODE_LABEL_D( SDLK_KP_COLON ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_COLON) */ 
	    KEYCODE_LABEL_D( SDLK_KP_HASH ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HASH) */ 
	    KEYCODE_LABEL_D( SDLK_KP_SPACE ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_SPACE) */ 
	    KEYCODE_LABEL_D( SDLK_KP_AT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_AT) */ 
	    KEYCODE_LABEL_D( SDLK_KP_EXCLAM ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_EXCLAM) */ 
	    KEYCODE_LABEL_D( SDLK_KP_MEMSTORE ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSTORE) */ 
	    KEYCODE_LABEL_D( SDLK_KP_MEMRECALL ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMRECALL) */ 
	    KEYCODE_LABEL_D( SDLK_KP_MEMCLEAR ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMCLEAR) */ 
	    KEYCODE_LABEL_D( SDLK_KP_MEMADD ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMADD) */ 
	    KEYCODE_LABEL_D( SDLK_KP_MEMSUBTRACT ), 
	        /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMSUBTRACT) */ 
	    KEYCODE_LABEL_D( SDLK_KP_MEMMULTIPLY ), 
	        /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMMULTIPLY) */ 
	    KEYCODE_LABEL_D( SDLK_KP_MEMDIVIDE ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_MEMDIVIDE) */ 
	    KEYCODE_LABEL_D( SDLK_KP_PLUSMINUS ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_PLUSMINUS) */ 
	    KEYCODE_LABEL_D( SDLK_KP_CLEAR ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEAR) */ 
	    KEYCODE_LABEL_D( SDLK_KP_CLEARENTRY ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_CLEARENTRY) */ 
	    KEYCODE_LABEL_D( SDLK_KP_BINARY ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_BINARY) */ 
	    KEYCODE_LABEL_D( SDLK_KP_OCTAL ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_OCTAL) */ 
	    KEYCODE_LABEL_D( SDLK_KP_DECIMAL ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_DECIMAL) */ 
	    KEYCODE_LABEL_D( SDLK_KP_HEXADECIMAL ), 
	        /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KP_HEXADECIMAL) */ 

	    KEYCODE_LABEL_D( SDLK_LCTRL ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LCTRL) */ 
	    KEYCODE_LABEL_D( SDLK_LSHIFT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LSHIFT) */ 
	    KEYCODE_LABEL_D( SDLK_LALT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LALT) */ 
	    KEYCODE_LABEL_D( SDLK_LGUI ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_LGUI) */ 
	    KEYCODE_LABEL_D( SDLK_RCTRL ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RCTRL) */ 
	    KEYCODE_LABEL_D( SDLK_RSHIFT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RSHIFT) */ 
	    KEYCODE_LABEL_D( SDLK_RALT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RALT) */ 
	    KEYCODE_LABEL_D( SDLK_RGUI ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_RGUI) */ 

	    KEYCODE_LABEL_D( SDLK_MODE ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MODE) */ 

	    KEYCODE_LABEL_D( SDLK_AUDIONEXT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIONEXT) */ 
	    KEYCODE_LABEL_D( SDLK_AUDIOPREV ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOPREV) */ 
	    KEYCODE_LABEL_D( SDLK_AUDIOSTOP ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOSTOP) */ 
	    KEYCODE_LABEL_D( SDLK_AUDIOPLAY ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOPLAY) */ 
	    KEYCODE_LABEL_D( SDLK_AUDIOMUTE ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOMUTE) */ 
	    KEYCODE_LABEL_D( SDLK_MEDIASELECT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MEDIASELECT) */ 
	    KEYCODE_LABEL_D( SDLK_WWW ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_WWW) */ 
	    KEYCODE_LABEL_D( SDLK_MAIL ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_MAIL) */ 
	    KEYCODE_LABEL_D( SDLK_CALCULATOR ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALCULATOR) */ 
	    KEYCODE_LABEL_D( SDLK_COMPUTER ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_COMPUTER) */ 
	    KEYCODE_LABEL_D( SDLK_AC_SEARCH ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_SEARCH) */ 
	    KEYCODE_LABEL_D( SDLK_AC_HOME ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_HOME) */ 
	    KEYCODE_LABEL_D( SDLK_AC_BACK ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BACK) */ 
	    KEYCODE_LABEL_D( SDLK_AC_FORWARD ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_FORWARD) */ 
	    KEYCODE_LABEL_D( SDLK_AC_STOP ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_STOP) */ 
	    KEYCODE_LABEL_D( SDLK_AC_REFRESH ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_REFRESH) */ 
	    KEYCODE_LABEL_D( SDLK_AC_BOOKMARKS ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AC_BOOKMARKS) */ 

	    KEYCODE_LABEL_D( SDLK_BRIGHTNESSDOWN ), 
	        /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_BRIGHTNESSDOWN) */ 
	    KEYCODE_LABEL_D( SDLK_BRIGHTNESSUP ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_BRIGHTNESSUP) */ 
	    KEYCODE_LABEL_D( SDLK_DISPLAYSWITCH ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_DISPLAYSWITCH) */ 
	    KEYCODE_LABEL_D( SDLK_KBDILLUMTOGGLE ), 
	        /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMTOGGLE) */ 
	    KEYCODE_LABEL_D( SDLK_KBDILLUMDOWN ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMDOWN) */ 
	    KEYCODE_LABEL_D( SDLK_KBDILLUMUP ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_KBDILLUMUP) */ 
	    KEYCODE_LABEL_D( SDLK_EJECT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_EJECT) */ 
	    KEYCODE_LABEL_D( SDLK_SLEEP ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SLEEP) */ 
	    KEYCODE_LABEL_D( SDLK_APP1 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APP1) */ 
	    KEYCODE_LABEL_D( SDLK_APP2 ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_APP2) */ 

	    KEYCODE_LABEL_D( SDLK_AUDIOREWIND ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOREWIND) */ 
	    KEYCODE_LABEL_D( SDLK_AUDIOFASTFORWARD ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_AUDIOFASTFORWARD) */ 

	    KEYCODE_LABEL_D( SDLK_SOFTLEFT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTLEFT) */ 
	    KEYCODE_LABEL_D( SDLK_SOFTRIGHT ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_SOFTRIGHT) */ 
	    KEYCODE_LABEL_D( SDLK_CALL ), 	/* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_CALL) */ 
	    KEYCODE_LABEL_D( SDLK_ENDCALL ), /* SDL_SCANCODE_TO_KEYCODE(SDL_SCANCODE_ENDCALL) */
	};
    return mapping;
}

#undef SCANCODE_LABEL_D
#undef KEYCODE_LABEL_D

/** sort KeyLabelName list */
template<typename T, typename GetList>
static constexpr auto sortLabelNameList(GetList getList)
{
	auto list = getList();
	std::ranges::sort(list, {}, &KeyLabelName<T>::code);
	return list;
}

/** get Scancode Lbel string */
const char* getScanCodeLabelString(SDL_Scancode s) {
	static constexpr auto list = sortLabelNameList<SDL_Scancode>( [] { return getScanCodeLabelStringMap(); } );
    const auto* mapping = binary_find(list, s, {}, &KeyLabelName<SDL_Scancode>::code);
    if (mapping) {
        return mapping->name;
    }
    return "SDL_SCANCODE_UNKNOWN";
}

/** get Keycode Lbel string */
const char* getKeyCodeLabelString(SDL_Keycode s) {
	static constexpr auto list = sortLabelNameList<SDL_Keycode>([] { return getKeyCodeLabelStringMap(); });
	const auto* mapping = binary_find(list, s, {}, &KeyLabelName<SDL_Keycode>::code);
    if (mapping) {
        return mapping->name;
    }
    return "SDLK_UNKNOWN";
}

}
#endif //KEYTEST