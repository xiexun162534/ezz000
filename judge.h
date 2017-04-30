#ifndef __JUDGE_H
#define __JUDGE_H

#include "config.h"
#include "display.h"

#ifdef __cplusplus
extern "C" {
#endif

inline void judge_set (line_t standard);

inline void judge_get (line_t output);

inline short int judge (void);

#ifdef __cplusplus
}
#endif

#endif
