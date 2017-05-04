#include "main.h"


long int music_first (const music_t * music)
{
  int i;
  long int score;
  timer_t *music_timer;
  score = 0;

  music_timer = timer_init ();

  randomSeed (micros ());
  display_image (zero_img);
  for (i = -HEIGHT; i < music->length; i++)
    {
      short int no_judging;
      line_t line = {};
      line_t judge_line;
      if (i < 0)
        /* preparation */
        {
          line[random (0, WIDTH)] = 1;
          display_line (line);
          timer_set (music_timer, (unsigned long int) (music->tempo * 1000 / 60));
          no_judging = 1;
        }
      else if (i < music->length - HEIGHT)
        {
          line[random (0, WIDTH)] = 1;
          display_line (line);
          get_last_line (judge_line);
          judge_set (judge_line);
          timer_set (music_timer, (unsigned long int) (music->notes[i].duration * music->tempo * 1000 / 60));
          no_judging = 0;
        }
      else
        {
          display_line (line);
          get_last_line (judge_line);
          judge_set (judge_line);
          timer_set (music_timer, (unsigned long int) (music->notes[i].duration * music->tempo * 1000 / 60));
          no_judging = 0;
        }
      #ifdef __DEBUG
      Serial.println ("random");
      do
        {
          int k;
          for (k = 0; k < WIDTH; k++)
            {
              Serial.print (line[k]);
              Serial.print (' ');
              Serial.print (k);
              Serial.print (' ');
            }
        } while (0);
      Serial.println ("");
      Serial.print ("length");
      Serial.print (music->length);
      Serial.println ("");
      Serial.print ("no");
      Serial.print (i);
      Serial.println ("");
      Serial.println ("");
      #endif


      while (1)
        {
          short int judgement;
          
          if (!no_judging)
            {
              judgement = judge ();
              if (judgement == -1)
                {
                  play_note (noise_note ());
                  score -= 100;
                  no_judging = 1;
                }
              else if (judgement == 1)
                {
                  play_note (&music->notes[i]);
                  score += 20;
                  no_judging = 1;
                }
            }


          if (timer_check (music_timer))
            {
              if (!no_judging)
                {
                  play_note (&rest_note);
                  #ifdef __DEBUG
                  play_note (&music->notes[i]);
                  #endif
                  score -= 100;
                }
              break;
            }
        }
    }

  timer_destory (music_timer);
  return score;
}


long int step_first (const music_t * music, unsigned long int time_limit)
{
  int i;
  long int score;
  timer_t *limit_timer;
  short int end;
  end = 0;
  score = 0;

  limit_timer = timer_init ();
  timer_set (limit_timer, time_limit);

  randomSeed (micros ());
  for (i = 0; i < music->length && !end; i++)
    {
      short int no_judging;
      line_t line = {};
      line_t judge_line;

      line[random (0, WIDTH)] = 1;
      display_line (line);
      if (i < HEIGHT)
        /* preparation */
        continue;

      get_last_line (judge_line);
      judge_set (judge_line);

 
      while (!end)
        {
          short int judgement;

          judgement = judge ();
          if (judgement == -1)
            {
              play_note (noise_note ());
              score -= 100;
            }
          else if (judgement == 1)
            {
              play_note (&music->notes[i]);
              score += 20;
            }


          if (timer_check (limit_timer))
            {
              break;
            }
        }
    }

  timer_destory (limit_timer);
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
  Serial.println ("welcome");
  display_image (e_img);
  delay (2000);
}

void loop (void)
{
  long int score;
  short int mode;
  short int found_mode;
  timer_t *select_mode_timer;
  short int current_image;
  select_mode_timer = timer_init ();
  timer_set (select_mode_timer, NORMAL_FLASH_PERIOD);
  display_image (zero_img);
  current_image = 0;
  found_mode = 0;
  while (1)
    {
      #ifdef __DEBUG
      mode = 0;
      break;
      #endif
      int i;
      line_t input;
      judge_get (input);
      if (!found_mode)
        {
          for (i = 0; i < WIDTH; i++)
            {
              if (input[i])
                break;
            }
          if (i < WIDTH)
            {
              mode = i;
              found_mode = 1;
            }
        }
      else
        {
          if (!input[i])
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
          timer_set (select_mode_timer, NORMAL_FLASH_PERIOD);
        }
    }
  timer_destory (select_mode_timer);

  switch (mode)
    {
    case 0:
      score = music_first (&music_list[MUSIC_TEST]);
      break;
    case 1:
      score = step_first (&music_list[MUSIC_TEST], TIME_LIMIT);
      break;
    default:
      break;
    }

  Serial.println ("score");
  Serial.println (score);
  display_image (e_img);
  delay (2000);
}
