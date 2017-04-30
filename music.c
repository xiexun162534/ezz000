#include "music.h"
#include <math.h>


const note_t test[35] = {{s1, C, 1.0},
                         {s1, D, 1.0},
                         {s1, E, 1.0},
                         {s1, F, 1.0},
                         {s1, G, 1.0},
                         {s1, C, 1.0},
                         {s1, D, 1.0},
                         {s1, E, 1.0},
                         {s1, F, 1.0},
                         {s1, G, 1.0},
                         {s1, C, 1.0},
                         {s1, D, 1.0},
                         {s1, E, 1.0},
                         {s1, F, 1.0},
                         {s1, G, 1.0},
                         {s1, C, 1.0},
                         {s1, D, 1.0},
                         {s1, E, 1.0},
                         {s1, F, 1.0},
                         {s1, G, 1.0},
                         {s1, C, 1.0},
                         {s1, D, 1.0},
                         {s1, E, 1.0},
                         {s1, F, 1.0},
                         {s1, G, 1.0},
                         {s1, C, 1.0},
                         {s1, D, 1.0},
                         {s1, E, 1.0},
                         {s1, F, 1.0},
                         {s1, G, 1.0},
                         {s1, C, 1.0},
                         {s1, D, 1.0},
                         {s1, E, 1.0},
                         {s1, F, 1.0},
                         {s1, G, 1.0}};

inline void play_note (const note_t *note)
{
  unsigned int frequency = (unsigned int) (a1 * pow (2, note->octave + note->step / 12.0f));
  /*tone (PIN_BUZZER, frequency);*/
}

inline void play_note_with_duration (const note_t *note, unsigned long int duration)
{
  unsigned int frequency = (unsigned int) (a1 * pow (2, note->octave + note->step / 12.0f));
  /*tone (PIN_BUZZER, frequency, duration);*/
}
