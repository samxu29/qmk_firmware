#pragma once

#define MATRIX_ROWS 2
#define MATRIX_COLS 4
#define MATRIX_ROW_PINS { B5, B4 }
#define MATRIX_COL_PINS { F4, F5, F6, F7 }
#define DIP_SWITCH_PINS { D4 }  // Independent encoder switch

#define DIODE_DIRECTION COL2ROW

// Encoder pins
#define ENCODER_A_PINS { C6 } // DT pin
#define ENCODER_B_PINS { D7 } // CLK pin
#define ENCODER_RESOLUTION 4

// LED pins
#define LED_1_PIN B6
#define LED_2_PIN B2
#define LED_3_PIN B3
#define LED_4_PIN B1

// Set all LEDs as output and low by default
#define LED_PIN_INIT { setPinOutput(LED_1_PIN); setPinOutput(LED_2_PIN); setPinOutput(LED_3_PIN); setPinOutput(LED_4_PIN);}

#ifdef OLED_ENABLE
    #define OLED_DISPLAY_128X64
    #define OLED_TIMEOUT 60000
    #define OLED_TRANSPORT_DRIVER i2c

#endif