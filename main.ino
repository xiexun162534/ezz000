#include "main.h"


long int game1 (void)
{
  int i;
  long int score;
  timer_t *game1_timer;
  score = 0;

  game1_timer = timer_init ();

  randomSeed (micros ());
  for (i = 0; i < 35; i++)
    {
      short int no_judging;
      line_t line = {};
      unsigned long int real_duration;
      line[random (0, WIDTH)] = 1;
      judge_set (line);
      real_duration = test[i].duration * 1000;
      timer_set (game1_timer, real_duration);

      no_judging = 0;
      while (1)
        {
          short int judgement;

          if (no_judging)
            continue;
          
          judgement = judge ();
          if (judgement == -1)
            {
              score -= 100;
              no_judging = 1;
            }
          else if (judgement == 1)
            {
              play_note (&test[i]);
              score += 20;
            }


          if (timer_check (game1_timer))
            {
              break;
            }
        }
    }
  
  return score;
}

void setup (void)
{
  int i;
  Serial.begin (9600);
  Serial.flush ();
  pinMode (PIN_CLK, OUTPUT);
  pinMode (PIN_TRIG, OUTPUT);
  pinMode (PIN_BUZZER, OUTPUT);
  for (i = 0; i < WIDTH; i++)
    {
      pinMode (PIN_BLUE[i], OUTPUT);
      pinMode (PIN_RED[i], OUTPUT);
      pinMode (PIN_ECHO[i], INPUT);
    }
  display_image (e_img);
  delay (2000);
}

void loop (void)
{
  short int mode;
  timer_t *select_mode_timer;
  short int current_image;
  select_mode_timer = timer_init ();
  timer_set (select_mode_timer, NORMAL_FLASH);
  display_image (zero_img);
  current_image = 0;
  while (1)
    {
      int i;
      line_t input;
      judge_get (input);
      for (i = 0; i < WIDTH; i++)
        {
          if (input[i])
            break;
        }
      if (i < WIDTH)
        {
          mode = i;
          break;
        }

      if (timer_check (select_mode_timer))
        {
          if (current_image)
            {
              display_image (zero_img);
              current_image = 0;
            }
          else
            {
              display_image (e_img);
              current_image = 1;
            }
          timer_set (select_mode_timer, NORMAL_FLASH);
        }
    }
  timer_destory (select_mode_timer);

  game1 ();
}
