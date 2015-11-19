/*
** exo.c for exo in /home/casier_s/
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sat Mar  9 16:53:59 2013 sofian casier
** Last update Sat Mar  9 18:13:45 2013 sofian casier
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int	factor(float *fact, int size)
{
  int	n;
  float	x;
  float	resultat;
  int	power;
  int	count;

  count = 0;
  x = 0;
  power = 1;
  n = 0;
  resultat = 0;
  while (x <= 1000)
    {
      resultat = 0;
      count = 0;
      n = 0;
      power = 1;
      while (n <= size)
    	{
    	  if (count == 0)
    	    resultat = fact[n] + x * (powf(fact[n + 1], power)) + resultat;
    	  else
    	    resultat = fact[n + 1] * (powf(x, power)) + resultat;
    	  n++;
    	  power++;
    	  count++;
    	}
      x = x + 0.001;
    }
  printf("%f\n", resultat);
}
  /*
    6x^5 + 5x^4 + 4x^3 + 3x^2 + 2x + 1

    (1 + x(2 + x(3 + x(4 + x(5 + x(6))))))

    argv[0]x^5 + argv[1]x^4 + argv[2]x^3...
  */

int	main(int argc, char **argv)
{
  int	i;
  float	*fact;

  fact = malloc(10000 * sizeof(float));
  i = 0;
  while (i < argc - 1)
    {
      fact[i] = atof(argv[i + 1]);
      i++;
      //      argc--;
    }
  factor(fact, 6);
}
