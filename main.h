#ifndef __MAIN_H
#define __MAIN_H


#include "config.h"
#include "display.h"
#include "timer_soft.h"
#include "judge.h"
#include "music.h"

/* Default value of duration is 0. */
extern "C" void tone_c (unsigned char pin, unsigned int frequency)
{
  tone (pin, frequency, 0);
}

extern "C" void noTone_c (unsigned char pin)
{
  noTone (pin);
}

const short int PIN_ECHO[WIDTH] = {11, 12, 13, A0};
const short int PIN_RED[WIDTH] = {3, 4, 5, 6};
const short int PIN_BLUE[WIDTH] = {7, 8, 9, 10};

#endif
