#ifndef __CONFIG_H
#define __CONFIG_H

#define __DEBUG

#define HEIGHT 5
#define WIDTH 4

#include <Arduino.h>
#define PIN_CLK A2
#define PIN_TRIG A3
#define PIN_BUZZER 11
extern const short int PIN_ECHO[WIDTH];
extern const short int PIN_RED[WIDTH];
extern const short int PIN_BLUE[WIDTH];

#define TIMER_MAX 2

#define STANDARD_DISTANCE 0.30
#define ECHO_TIMEOUT 10000 /* microseconds */

#define NORMAL_FLASH_PERIOD 500 /* milliseconds */

#define MAX_MUSIC_LENGTH 100
#define TOTAL_MUSIC 1

#define TIME_LIMIT 20000 /* milliseconds */

#ifndef __cplusplus
/* Default value of duration is 0. */
void tone_c (unsigned char pin, unsigned int frequency);

void noTone_c (unsigned char pin);
#endif

#endif
