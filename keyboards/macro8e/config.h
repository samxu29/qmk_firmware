#pragma once

#define MATRIX_ROWS 2
#define MATRIX_COLS 4

// Matrix pins
#define MATRIX_ROW_PINS { B5, B4 }
#define MATRIX_COL_PINS { F4, F5, F6, F7 }

#define DIODE_DIRECTION COL2ROW

// Encoder pins
#define ENCODER_A_PINS { D6 }  // DT pin
#define ENCODER_B_PINS { D7 }  // CLK pin
#define ENCODER_RESOLUTION 4

#ifdef OLED_ENABLE
    #define OLED_DISPLAY_128X64
    #define OLED_TIMEOUT 60000
    #define OLED_TRANSPORT_DRIVER i2c
#endif