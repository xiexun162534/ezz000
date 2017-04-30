#include "judge.h"

static line_t standard;
static line_t result;

inline void judge_set (line_t draft_standard)
{
  int i;
  for (i = 0; i < WIDTH; i++)
    {
      standard[i] = draft_standard[i];
    }
}

inline void judge_get (line_t output)
{
  int i;
  unsigned long input[WIDTH];
  digitalWrite (PIN_TRIG, HIGH);
  delay (1);
  digitalWrite (PIN_TRIG, LOW);
  for (i = 0; i < WIDTH; i++)
    {
      input[i] = pulseIn (PIN_ECHO[i], HIGH, ECHO_TIMEOUT);
    }
  for (i = 0; i < WIDTH; i++)
    {
      if (input[i] / 5800.0 < 0.30)
        output[i] = 1;
      else
        output[i] = 0;
    }
}

inline short int judge (void)
{
  line_t input;
  int i;
  short int is_right;
  judge_get (input);
  is_right = 1;
  for (i = 0; i < WIDTH; i++)
    {
      if (input[i])
        result[i] = 1;
      if (result[i] != standard[i])
        is_right = 0;
      else if (result[i] && !standard[i])
        return -1;
    }
  if (is_right)
    return 1;
  else
    return 0;
}

inline short int judge_end (void)
{
  int i;
  for (i = 0; i < WIDTH; i++)
    {
      if (result[i] != standard[i])
        return 0;
    }

  return 1;
}
