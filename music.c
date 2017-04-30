#include "music.h"
#include <math.h>


const music_t music_list[TOTAL_MUSIC] =
  {
    /* Music 0: test */
    {35, 60.0,
     {
       {s1, C, 1.0},{s1, D, 1.0},{s1, E, 1.0},{s1, F, 1.0},{s1, G, 1.0},
       {s1, C, 1.0},{s1, D, 1.0},{s1, E, 1.0},{s1, F, 1.0},{s1, G, 1.0},
       {s1, C, 1.0},{s1, D, 1.0},{s1, E, 1.0},{s1, F, 1.0},{s1, G, 1.0},
       {s1, C, 1.0},{s1, D, 1.0},{s1, E, 1.0},{s1, F, 1.0},{s1, G, 1.0},
       {s1, C, 1.0},{s1, D, 1.0},{s1, E, 1.0},{s1, F, 1.0},{s1, G, 1.0},
       {s1, C, 1.0},{s1, D, 1.0},{s1, E, 1.0},{s1, F, 1.0},{s1, G, 1.0},
       {s1, C, 1.0},{s1, D, 1.0},{s1, E, 1.0},{s1, F, 1.0},{s1, G, 1.0}
     }
    }
  };

const note_t rest_note = {s1, REST, 1.0};

inline void play_note (const note_t *note)
{
  if (note->step == REST)
    noTone_c (PIN_BUZZER);
  unsigned int frequency = (unsigned int) (a1 * pow (2, note->octave + note->step / 12.0f));
  tone_c (PIN_BUZZER, frequency);
}

inline note_t *noise_note (void)
{
  return &rest_note;
}
