#include "display.h"

const image_t e_img = {{0,1,1,0},
                       {1,0,0,1},
                       {1,1,1,1},
                       {1,0,0,0},
                       {0,1,1,0}};

const image_t S_img = {{0,1,1,1},
                       {1,0,0,0},
                       {1,1,1,0},
                       {0,0,0,1},
                       {1,1,1,0}};

const image_t B_img = {{1,1,1,0},
                       {1,0,0,1},
                       {1,1,1,0},
                       {1,0,0,1},
                       {1,1,1,0}};

const image_t A_img = {{0,1,1,0},
                       {1,0,0,1},
                       {1,1,1,1},
                       {1,0,0,1},
                       {1,0,0,1}};

const image_t zero_img = {{0,0,0,0},
                          {0,0,0,0},
                          {0,0,0,0},
                          {0,0,0,0},
                          {0,0,0,0}};
static image_t current_image;
static short int image_end;

inline void display_flush (void)
{
  digitalWrite (PIN_CLK, HIGH);
  digitalWrite (PIN_CLK, LOW);
}

inline void display_line (const line_t line)
{
  int i;
  for (i = 0; i < WIDTH; i++)
    {
      current_image[image_end][i] = line[i];
      if (line[i])
        {
          digitalWrite (PIN_RED[i], HIGH);
          digitalWrite (PIN_BLUE[i], LOW);
        }
      else
        {
          digitalWrite (PIN_RED[i], LOW);
          digitalWrite (PIN_BLUE[i], HIGH);
        }
    }
  image_end = (image_end - 1) % HEIGHT;
  display_flush ();
}

inline void display_image (const image_t image)
{
  int i;
  for (i = HEIGHT - 1; i >= 0; i--)
    {
      display_line (image[i]);
    }
}

inline void get_last_line (line_t output)
{
  int i;
  for (i = 0; i < WIDTH; i++)
    {
      output[i] = current_image[image_end][i];
    }
}
