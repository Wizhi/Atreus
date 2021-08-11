#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif

#include "Kaleidoscope.h"
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"
#include "Kaleidoscope-FocusSerial.h"
#include "Kaleidoscope-Macros.h"
#include "Kaleidoscope-MouseKeys.h"
#include "Kaleidoscope-OneShot.h"
#include "Kaleidoscope-Qukeys.h"
#include "Kaleidoscope-SpaceCadet.h"

enum {
	MACRO_QWERTY,
	MACRO_VERSION_INFO
};

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

KALEIDOSCOPE_INIT_PLUGINS(
	EEPROMSettings,
	EEPROMKeymap,
	Focus,
	FocusEEPROMCommand,
	FocusSettingsCommand,
	Qukeys,
	SpaceCadet,
	OneShot,
	Macros,
	MouseKeys
);

const macro_t *macroAction(uint8_t macro_id, KeyEvent &event) {
	if (keyToggledOn(event.state)) {
		switch (macro_id) {
		case MACRO_QWERTY:
			// This macro is currently unused, but is kept around for compatibility
			// reasons. We used to use it in place of `MoveToLayer(QWERTY)`, but no
			// longer do. We keep it so that if someone still has the old layout with
			// the macro in EEPROM, it will keep working after a firmware update.
			Layer.move(QWERTY);
			break;
		case MACRO_VERSION_INFO:
			Macros.type(PSTR("Keyboardio Atreus - Kaleidoscope "));
			Macros.type(PSTR(BUILD_INFORMATION));
			break;
		default:
			break;
		}
	}
	return MACRO_NONE;
}

void setup() {
	Kaleidoscope.setup();
	SpaceCadet.disable();
	EEPROMKeymap.setup(10);
}

void loop() {
	Kaleidoscope.loop();
}
