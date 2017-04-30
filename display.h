#ifndef __DISPLAY_H
#define __DISPLAY_H

#include "config.h"

typedef short int line_t[WIDTH];
typedef short int image_t[HEIGHT][WIDTH];

             
extern const image_t e_img;

extern const image_t zero_img;

#ifdef __cplusplus
extern "C" {
#endif

inline void display_flush (void);

inline void display_line (const line_t line);

inline void display_image (const image_t image);

inline void get_last_line (line_t output);

#ifdef __cplusplus
}
#endif

#endif
