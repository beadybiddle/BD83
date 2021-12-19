# bd83

![bd83](imgur.com image replace me!)

83 Key Keeb.
Adafruit Feather 32u4 BLE dev board, MCP23017 I2C expander to make enough GPIO, two IS31FL3733Bs for driving per-key RGB.

* Keyboard Maintainer: [beadybiddle](https://github.com/beadybiddle)
* Hardware Supported: Custom PCB (see BD83 repo)
* Hardware Availability: TODO fetch links to components

Make example for this keyboard (after setting up your build environment):

    make bd83:default

Flashing example for this keyboard:

    make bd83:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down `ESC` and plug in the keyboard
* **Physical reset button**: Briefly press the button on the Feather Dev Board
* **Keycode in layout**: Press `FN+RESET`
