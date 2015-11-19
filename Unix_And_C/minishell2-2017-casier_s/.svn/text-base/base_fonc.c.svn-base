/*
** base_fonc.c for base fonc in /home/casier_s/os-home/minishell
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Fri Dec 14 15:40:27 2012 sofian casier
** Last update Sun Mar 10 17:39:53 2013 sofian casier
*/

#include <stdlib.h>
#include "my.h"

int     my_tab_strlen(char **str)
{
  int   i;

  i = 0;
  while (str[i] != NULL)
    i++;
  return (i);
}

int     word(char *str)
{
  int   i;
  int   j;

  i = 0;
  j = 0;
  while (str[i])
    {
      if (str[j] != ' ' || str[j] != '\t')
        j++;
      i++;
    }
  return (j);
}

int     my_strncmp(char *s1, char *s2, int nb)
{
  int   x;
  int   i;

  i = 0;
  x = 0;
  while (x < nb)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      i++;
      x++;
    }
  return (0);
}

int     countchar(char *str)
{
  int   c;

  c = 0;
  while ((str[c] != ' ') && (str[c] != '\0') && (str[c] != '\n'))
    c++;
  c += 1;
  return (c);
}
