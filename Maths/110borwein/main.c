/*
** main.c for main in /home/casier_s//110borwein
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Tue Apr  9 16:01:10 2013 sofian casier
** Last update Tue Apr 16 15:31:33 2013 sofian casier
*/

#include <string.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

float	function(int nb, float x)
{
  float	resultat;
  int	k;
  float	calc;

  k = 0;
  resultat = 1;
  while (k <= nb)
    {
      calc = (2 * k) + 1;
      resultat *= (sin(x / calc) / (x / calc));
      k++;
    }
  return (resultat);
}

void	simpson(int kmax)
{
  float	a;
  float	b;
  int	nmax;
  int	i;
  float x2;
  float h2;
  float	x;
  float	h;
  float	resultat;
  float	integr;
  float	diff;
  float integr2;

  i = 1;
  a = 0.000000000001;
  b = 5000;
  integr = 0;
  nmax = 10000;
  h = (b - a) / (6 * nmax);
  h2 = (b - a) / nmax;
  while (i <= (nmax - 1))
    {
      x = a + (h2 * i);
      integr += (function(kmax, x));
      i++;
    }
  i = 0;
  while (i <= (nmax - 1))
    {
      x = a + (h2 * i) + (h2 / 2);
      integr2 += (function(kmax, x));
      i++;
    }
  resultat = (h * ((function(kmax, a) + function(kmax, b) + 2 * integr) + 4 * integr2));
  printf("      La méthode de Simpson :\n\t|%d = %.13f\n", kmax, resultat);
  resultat -= (M_PI / 2);
  printf("\tdiff = %.13f\n", resultat);
}

void	trap(int kmax)
{
  float	a;
  float	b;
  int	nmax;
  int	i;
  float x2;
  float h2;
  float	x;
  float	h;
  float	resultat;
  float	integr;
  float	diff;

  i = 1;
  a = 0.000000000001;
  b = 5000;
  integr = 0;
  nmax = 10000;
  h = (b - a) / (2 * nmax);
  h2 = (b - a) / nmax;
  while (i <= (nmax - 1))
    {
      x = a + (h2 * i);
      integr += (function(kmax, x));
      i++;
    }
  resultat = (h * ((function(kmax, a) + function(kmax, b) + 2 * integr)));
  printf("      La méthode des trapezes :\n\t|%d = %.13f\n", kmax, resultat);
  resultat -= (M_PI / 2);
  printf("\tdiff = %.13f\n", resultat);
}

void	rect(int kmax)
{
  float	a;
  float	b;
  int	nmax;
  int	i;
  float	x;
  float	h;
  float	resultat;
  float	integr;

  i = 0;
  a = 0.000000000001;
  b = 5000;
  integr = 0;
  nmax = 10000;
  h = (b - a) / nmax;
  while (i <= (nmax - 1))
    {
      x = a + (h * i);
      integr += function(kmax, x);
      i++;
    }
  resultat = ((b - a) / nmax) * integr;
  printf("      La méthode des rectangles :\n\t|%d = %.10f\n", kmax, resultat);
  printf("\tdiff = %.10f\n", resultat - (M_PI / 2));
}

void	borwein(int argv)
{
  rect(argv);
  trap(argv);
  simpson(argv);
}

int	main(int argc, char **argv)
{
  int	i;

  i = 0;
  if (argc != 2)
    {
      printf("Put one argument\n");
      return (1);
    }
  while (argv[1][i])
    {
      if (argv[1][i] < '0' || argv[1][i] > '9')
	{
	  printf("You must put numbers only!\n");
	  return (1);
	}
      i++;
    }
  if (strlen(argv[1]) > 14)
    {
      printf("This number is too high! \n");
      return (1);
    }
  borwein(atoi(argv[1]));
  return (1);
}
