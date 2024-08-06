VIA_ENABLE          = yes
VIAL_ENABLE         = yes
LTO_ENABLE          = yes

RGBLIGHT_ENABLE     = no
RGB_MATRIX_ENABLE   = yes # Can't have RGBLIGHT and RGB_MATRIX at the same time.
MOUSEKEY_ENABLE     = no
OLED_ENABLE         = yes
OLED_DRIVER         = ssd1306
EXTRAKEY_ENABLE     = no
COMBO_ENABLE        = no
QMK_SETTINGS        = no
WPM_ENABLE = no

RGB_MATRIX_KEYPRESSES = yes  // Enables keypress effects
RGB_MATRIX_KEYRELEASES = yes // Enables keyrelease effects
RGB_MATRIX_FRAMEBUFFER_EFFECTS = yes // Enables framebuffer effects
RGB_MATRIX_LED_PROCESS_LIMIT = 10 // Limits the number of LEDs processed in a cycle
RGB_MATRIX_LED_FLUSH_LIMIT = 26 // Limits in ms how quickly an LED can be flushed
RGB_MATRIX_MAXIMUM_BRIGHTNESS = 120 // Limits maximum brightness
RGB_MATRIX_HUE_STEP = 10
RGB_MATRIX_SAT_STEP = 17
RGB_MATRIX_VAL_STEP = 17
RGB_MATRIX_SPD_STEP = 10
