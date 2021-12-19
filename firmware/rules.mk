# MCU name
MCU = atmega32u4
F_CPU = 8000000

# Bootloader selection
BOOTLOADER = caterina

# Build Options
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output
LTO_ENABLE = yes

RBG_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = IS31FL3733
BLUETOOTH_ENABLE = yes
BLUETOOTH_DRIVER = AdafruitBLE
CUSTOM_MATRIX = lite
SRC += matrix.c
QUANTUM_LIB_SRC += i2c_master.c