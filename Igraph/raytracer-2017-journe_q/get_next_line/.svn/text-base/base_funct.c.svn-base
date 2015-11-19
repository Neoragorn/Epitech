/*
** base_funct.c for funct in /home/journe_q//projet/raytracer
** 
** Made by quentin journet
** Login   <journe_q@epitech.net>
** 
** Started on  Tue Apr  9 15:32:03 2013 quentin journet
** Last update Thu Apr 25 14:46:29 2013 quentin journet
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"../point_h/fonction.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		m;

  m = 0;
  while (str[m])
    {
      my_putchar(str[m]);
      m++;
    }
}

int		my_memcmp(void *b, void *c, int len)
{
  char		*t;
  char		*t1;

  t = b;
  t1 = c;
  while (len--)
    if (*t != *t1)
      return (*t - *t1);
    else
      {
        t++;
        t1++;
      }
  return (0);
}

int		my_strlen(char *str)
{
  int		m;

  m = 0;
  while (str[m] && str)
    m++;
  return (m);
}

int		my_len_coma(char *str)
{
  int		m;
  int		k;

  m = 0;
  k = 0;
  while (str[m] && str)
    {
      if (str[m] == ';')
	k++;
      m++;
    }
  return (k);
}
