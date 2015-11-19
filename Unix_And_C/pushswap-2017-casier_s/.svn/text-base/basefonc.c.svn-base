/*
** basefonc.c for basefonc in /home/casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Wed Jan  2 18:47:46 2013 sofian casier
** Last update Sun Jan  6 20:19:00 2013 sofian casier
*/

#include <stdlib.h>
#include "my.h"

void    my_putchar(char c)
{
  write(1, &c, 1);
}

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int     my_conststrlen(const char *str)
{
  int   i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int     my_getnbr(char *str)
{
  int   i;
  int   n;
  int   compteur;
  int	j;
  
  compteur = 0;
  n = 0;
  i = my_strlen(str);
  while (str[n] == '+' || str[n] == '-')
    {
      if (str[n] == '-')
        {
          compteur++;
	}
      n++;
      i--;
    }
  j = my_getnbr2(str, i, n, compteur);
}

int     my_getnbr2(char *str, int i, int n, int compteur)
{
  int   nb;

  nb = 0;
  if (compteur % 2 == 1)
    {
      my_putchar('-');
    }
  while (i > 0 && str[n] >= '0' && str[n] <= '9')
    {
      nb = (nb * 10) + (str[n] - '0');
      i--;
      n++;
    }
  return (nb);
}
