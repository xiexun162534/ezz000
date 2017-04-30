#ifndef __MUSIC_H
#define __MUSIC_H

#include "config.h"

#define a1 440.0

typedef enum __octave_t {g2 = -4, g1 = -3, g0 = -2, s0 = -1, s1 = 0, s2 = 1, s3 = 2, s4 = 3, s5 = 4} octave_t;
typedef enum __step_t {C = 0, sC = 1, fD = 1, D = 2, sD = 3, fE = 3, E = 4, F = 5, sF = 6, fG = 6, G = 7, sG = 8, fA = 8, A = 9, sA = 10, fB = 10, B = 11} step_t;

typedef struct __note_t
{
  octave_t octave;
  step_t step;
  float duration;
} note_t;

extern const note_t test[35];

#ifdef __cplusplus
extern "C" {
#endif

inline void play_note (const note_t *note);

inline void play_note_with_duration (const note_t *note, unsigned long int duration);

#ifdef __cplusplus
}
#endif

#endif
