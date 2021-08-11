#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-Qukeys.h"

#define Key_Star LSHIFT(Key_8)
#define Key_Plus LSHIFT(Key_Equals)

enum {
	QWERTY,
	NUMPAD
};

KEYMAPS(
	[QWERTY] = KEYMAP_STACKED
	(
		Key_Q,    Key_W, Key_E, Key_R,         Key_T,
		Key_A,    Key_S, Key_D, LT(NUMPAD, F), Key_G,
		SFT_T(Z), Key_X, Key_C, Key_V,         Key_B,     ___,
		___,      ___,   ___,   Key_LeftGui,   Key_Space, Key_Enter,

		         Key_Y,         Key_U, Key_I,     Key_O,      Key_P,
		         Key_H,         Key_J, Key_K,     Key_L,      Key_Semicolon,
		___,     Key_N,         Key_M, Key_Comma, Key_Period, SFT_T(Slash),
		Key_Tab, Key_Backspace,  ___,  ___,       ___,        ___
	),
	[NUMPAD] = KEYMAP_STACKED
	(
		___, ___, ___, ___, ___,
		___, ___, ___, ___, ___,
		___, ___, ___, ___, ___, ___,
		___, ___, ___, ___, ___, ___,

		     Key_Period, Key_1,     Key_2, Key_3, Key_Equals,
		     Key_0,      Key_4,     Key_5, Key_6, Key_Plus,
		___, Key_Star,   Key_7,     Key_8, Key_9, Key_Minus,
		___, ___,        Key_Slash, ___,   ___,   ___
	)
)

KALEIDOSCOPE_INIT_PLUGINS(Qukeys);

void setup() {
	Kaleidoscope.setup();
}

void loop() {
	Kaleidoscope.loop();
}
