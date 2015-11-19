/*
** newton.c for my_newton.c in /home/liagre_c//Math/105
** 
** Made by clement liagre
** Login   <liagre_c@epitech.net>
** 
** Started on  Tue Jan 15 19:39:13 2013 clement liagre
** Last update Wed Jan 16 18:55:56 2013 clement liagre
*/

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

float   f_new(float x, float *tab)
{
  x = (tab[5] * powf(x,4)) + (tab[4] * powf(x,3)) + (tab[3] * powf(x,2)) + (tab[2] * powf(x,1)) + tab[1];
  return (x);
}

float f_prime(float x, float *tab)
{
  x = (tab[5] * (4 * powf(x, 3)) + (tab[4] * (3 * powf(x,2)) + (tab[3] * 2 * powf(x,1)) + tab[2]));
  return (x);
}

float newton(float *tab)
{
  int   i;
  float a;

  i = 1;
  a = 0.5;
  printf("point initial : %g\n", a);
  while (i < 4)
    {
      if (f_prime(a, tab) == 0)
	{
	  printf("f(x) = %.1e\n", f_new(a, tab));
	  return (0);
	}
      a = a - f_new(a, tab) / f_prime(a, tab);
      printf("itération %d   x =", i);
      printf("%.30g\n", a);
      i++;
    }
  printf("f(x) = %.1e\n", f_new(a, tab));
}
