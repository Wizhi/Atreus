#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"

enum {
	QWERTY
};

KEYMAPS(
	[QWERTY] = KEYMAP_STACKED
	(
		Key_Q, Key_W, Key_E, Key_R, Key_T,
		Key_A, Key_S, Key_D, Key_F, Key_G,
		Key_Z, Key_X, Key_C, Key_V, Key_B, ___,
		___,   ___,   ___,   ___,   ___,   ___,

		     Key_Y, Key_U, Key_I,     Key_O,      Key_P,
		     Key_H, Key_J, Key_K,     Key_L,      Key_Semicolon,
		___, Key_N, Key_M, Key_Comma, Key_Period, Key_Slash,
		___, ___,   ___,   ___,       ___,        ___
	)
)

void setup() {
	Kaleidoscope.setup();
}

void loop() {
	Kaleidoscope.loop();
}
