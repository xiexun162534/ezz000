#include "timer_soft.h"

static timer_t timer_list[TIMER_MAX];

inline timer_t *timer_init ()
{
  int i;
  for (i = 0; i < TIMER_MAX; i++)
    {
      if (timer_list[i].available)
        break;
    }
  if (i < TIMER_MAX)
    {
      timer_list[i].available = 0;
      return &timer_list[i];
    }
  else
    return NULL;
}

inline void timer_set (timer_t *timer, unsigned long int milliseconds)
{
  timer->begin = millis ();
  timer->expected_end = timer->begin + milliseconds;
}

inline short int timer_check (timer_t *timer)
{
  unsigned long int current_time = millis ();
  if (current_time >= timer->expected_end)
    return 1;
  else if (current_time < timer->begin)
    return 1;
  else
    return 0;
}

inline void timer_destory (timer_t *timer)
{
  timer->available = 1;
}
