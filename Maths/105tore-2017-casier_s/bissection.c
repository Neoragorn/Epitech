/*
** bissection.c for my_bissection_105 in /home/liagre_c//Math/105
** 
** Made by clement liagre
** Login   <liagre_c@epitech.net>
** 
** Started on  Mon Jan 14 13:46:41 2013 clement liagre
** Last update Tue Jan 15 21:11:19 2013 clement liagre
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float   f_bis(float x, float *tab)
{
  x = (tab[5] * powf(x,4)) + (tab[4] * powf(x,3)) + (tab[3] * powf(x,2))
    + (tab[2] * powf(x,1)) + tab[1];
  return (x);
}

float    bissection(float *tab)
{
  float init;
  float end;
  float xm;
  float a;
  int   stop;
  int   i;

  i = 1;
  init = 0;
  end = 1;
  stop = 19;
  printf("point initial 1 : %g\n", init);
  printf("point initial 2 : %g\n", end);
  while (i < stop)
    {
      if (init > end)
        my_swap(init, end);
      xm = (init + end) / 2;
      printf("itération %d ", i);
      if (i < 10)
        printf(" ");
      if ((f_bis(init, tab) * f_bis(xm, tab)) > 0)
        {
          printf("   x = %.30g\n", xm);
          init = xm;
        }
      else
        {
          printf("   x = %.30g\n", xm);
          end = xm;
        }
      i++;
    }
  printf("f(x) = %.1e\n", f_bis(xm, tab));
}
