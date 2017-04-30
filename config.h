#ifndef __CONFIG_H
#define __CONFIG_H


#define HEIGHT 5
#define WIDTH 4

#include <Arduino_xx.h>
#define PIN_CLK A1
#define PIN_TRIG A2
#define PIN_BUZZER A3
extern const short int PIN_ECHO[WIDTH];
extern const short int PIN_RED[WIDTH];
extern const short int PIN_BLUE[WIDTH];

#define TIMER_MAX 10

#define STANDARD_DISTANCE 0.30
#define ECHO_TIMEOUT 10000 /* microseconds */

#define NORMAL_FLASH 500 /* milliseconds */

#endif
