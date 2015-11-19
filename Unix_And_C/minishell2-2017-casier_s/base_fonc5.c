/*
** base_fonc5.c for base in /home/casier_s//minishell2-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Feb 28 16:20:58 2013 sofian casier
** Last update Mon Jan  2 10:05:41 2012 sofian casier
*/

#include <stdlib.h>
#include "my.h"

char	*my_strcat(char *src, char *dest)
{
  int   a;
  int   b;
  char  c;

  a = 0;
  b = 0;
  c = 0;
  while (src[b] != c)
    {
      dest[a] = src[b];
      a++;
      b++;
    }
  dest[a] = c;
  return (dest);
}

int	error_env()
{
  my_putstr("Some important parts of the environnement are missing\n");
  exit (1);
}
