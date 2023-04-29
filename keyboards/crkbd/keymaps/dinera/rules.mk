### Mouse
MOUSEKEY_ENABLE     = yes      # Mouse keys

SRC += globalvar.c

### RGB LEDs
RGB_MATRIX_CUSTOM_USER = yes
RGB_MATRIX_ENABLE   = yes		  # Enable RGB matrix
RGB_MATRIX_DRIVER   = WS2812    # Enable WS2812 for RGB Matrix
#RGBLIGHT_ENABLE     = yes     # Enable WS2812 RGB underlight.

### Vial settings
VIALRGB_ENABLE      = yes
VIA_ENABLE          = yes     # Enable VIA
VIAL_ENABLE         = yes     # Enable VIAL
VIAL_INSECURE 		= yes     # Enables insecure mode !!! remove in production 	!!!

### MIDI
MIDI_ENABLE = yes

### USB HID
RAW_ENABLE          = yes 	  # Enable RAW HID

### OLED
OLED_ENABLE         = yes
OLED_DRIVER         = SSD1306

### Rotary Encoder
ENCODER_ENABLE 		= yes        # Activate Encoder
ENCODER_MAP_ENABLE 	= yes

### Misc
EXTRAKEY_ENABLE     = yes
LTO_ENABLE          = yes
QMK_SETTINGS        = no
COMBO_ENABLE        = no

### KB2040
PIN_COMPATIBLE 		= promicro
CONVERT_TO			= kb2040 # Convert Code to Adafruit KB2040
