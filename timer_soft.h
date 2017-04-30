#ifndef __TIMER_SOFT_H
#define __TIMER_SOFT_H

#include "config.h"

typedef struct __timer_t
{
  short int available;
  unsigned long int begin;
  unsigned long int expected_end;
} timer_t;

#ifdef __cplusplus
extern "C" {
#endif

inline timer_t *timer_init (void);

inline void timer_set (timer_t *timer, unsigned long int milliseconds);

inline short int timer_check (timer_t *timer);

inline void timer_destory (timer_t *timer);


#ifdef __cplusplus
}
#endif

#endif
