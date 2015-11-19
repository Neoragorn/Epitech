/*
** main.c for my_105tore in /home/liagre_c//Math/105
** 
** Made by clement liagre
** Login   <liagre_c@epitech.net>
** 
** Started on  Mon Jan 14 12:59:00 2013 clement liagre
<<<<<<< .mine
** Last update Tue Jan 15 14:49:09 2013 sofian casier
=======
** Last update Wed Jan 16 18:39:57 2013 clement liagre
>>>>>>> .r13
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

<<<<<<< .mine

float	f_bis(float x, float *tab)
{
  x = (tab[5] * powf(x,4)) + (tab[4] * powf(x,3)) + (tab[3] * powf(x,2)) + (tab[2] * powf(x,1)) + tab[1];  
  return (x);
}

float f_prime(float x, float *tab)
{
  x = (tab[5] * (4 * powf(x, 3)) + (tab[4] * (3 * powf(x,2)) + (tab[3] * powef(x,1)) + (tab[2] * x)));
}

float	newton(float *tab, char **argv)
{
  float init;
  float end;
  int	stop;
  float	x;

  init = 0;
  end = 1;
  stop = 20;
  x = 0;
  x = x - (f_bis(x, tab) / 
}

float	 bissection(float *tab, char **argv)
{
  float	init;
  float	end;
  float	xm;
  int	stop;
  int	i;

  i = 0;
  init = 0;
  end = 1;
  stop = 20;
  while (i < stop)
    {
      if (init > end)
	my_swap(init, end);
      xm = (init + end) / 2;
      if ((f_bis(init, tab) * f_bis(xm, tab)) > 0)
	{
	  printf("%.10f\n", xm);
	  init = xm;
	}
      else
	{
	  printf("%.10f\n", xm);
	  end = xm;
	}
      i++;
    }
}

=======
>>>>>>> .r13
int	chooser(float *tab, int argc, char **argv)
{ 
  printf("%g x^4 + %g x^3 + %g x^2 + %g x + %g\n", 
	 tab[5], tab[4], tab[3], tab[2], tab[1]);
  if (tab[0] == 1 || tab[0] == 4)
    {
      printf("You choose: bissection case.\n");
      bissection(tab);
    }
  if (tab[0] == 2 || tab[0] == 4)
    {
      printf("You choose: Newton case.\n");
      newton(tab);
    }
  if (tab[0] == 3 || tab[0] == 4)
    {
      printf("You choose: secante case.\n");
      secante(tab);
    }
  return (0);
}

void	check(char *str, int argc)
{
  int	a;
  
  a = 0;
  if (str[0] == '-')
    a++;
  while (str[a] != '\0')
    {
      if (str[a] >= 48 && str[a] <= 57)
	a++;
      else
	{
	  printf("Error in arguments.\n");
	  exit(0);
	}
    }
}



void	next_step(char **argv, int argc, float *tab)
{
  int	a;
  int	j;
  
  a = 1;
  j = 0;
  while (a < argc)
    {
      check(argv[a], argc);
      a++;
    }
  a = 1;
  while (j < argc - 2)
    {
      tab[j] = atoi(argv[a]);
      a++;
      j++;
    }
  chooser(tab, argc, argv);
}

int	main(int argc, char **argv)
{
  float	*tab;
  
  tab = malloc(argc * sizeof(float) + 1);
  if (argc <= 7)
    {
      printf("not enough arguments.\nThis is bull shit.\n");
      return (0);
    }
  else if (argc == 8)
    next_step(argv, argc, tab);
  else  
    printf("Come on, give me a REAL problem kid.\n");
  free(tab);
  return (0);
}
