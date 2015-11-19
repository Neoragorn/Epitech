/*
** secante.c for my_secante in /home/liagre_c/
** 
** Made by clement liagre
** Login   <liagre_c@epitech.net>
** 
** Started on  Tue Jan 15 21:39:02 2013 clement liagre
** Last update Wed Jan 16 21:39:11 2013 clement liagre
*/

#include <stdlib.h>
#include <math.h>
#include <stdio.h>

float   f_sec(float x, float *tab)
{
  x = (tab[5] * powf(x,4)) + (tab[4] * powf(x,3)) + (tab[3] * powf(x,2)) + 
    (tab[2] * powf(x,1)) + tab[1];
  return (x);
}


float secante(float *tab)
{
  int i;
  float b;
  float a;
  float fa;
  float fb;
  float c;

  i = 0;
  a = 0.4;
  b = 0.8;
  printf("point initial 1 : %g\npoint initial 2 : %g\n", a, b);
  while (i < 6)
    {
      fa = f_sec(a, tab);
      fb = f_sec(b, tab);
      c = (f_sec(b, tab) - f_sec(a, tab)) / (b - a);
      if (c == 0)
	{
	  printf("f(x) = %.1e\n", f_sec(a, tab));
	  exit (0);
	}
      a = b;
      b = a - f_sec(a, tab) / c;
      if (i > 0)
	printf("itération %d   x = %.30g\n", i, a);
      i++;
    }
  printf("f(x) = %.1e\n", f_sec(a, tab));
  return (a);
}
