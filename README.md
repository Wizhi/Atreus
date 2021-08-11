# Building & Flashing

To keep things as simple as possible, I'm just utilizing the existing tools from the Kaleidoscope firmware.

First up, we need to setup Kaleidoscope:

```bash
export KALEIDOSCOPE_DIR="$KALEIDOSCOPE_DIR"

git clone 'https://github.com/keyboardio/Kaleidoscope' "$KALEIDOSCOPE_DIR"
make -C "$KALEIDOSCOPE_DIR" setup
```

Now it's just a matter of using this repository's Makefile:

```bash
export KALEIDOSCOPE_DIR="$KALEIDOSCOPE_DIR"

make compile
make flash
```

For alternative setups, see the `Makefile` - it's blatantly stolen from Kaleidoscope's own examples.
