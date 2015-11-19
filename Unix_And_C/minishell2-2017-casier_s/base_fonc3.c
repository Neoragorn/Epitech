/*
** base_fonc3.c for base fonc in /home/casier_s/os-home/minishell
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sun Dec 30 15:03:42 2012 sofian casier
** Last update Sun Feb 24 17:51:24 2013 sofian casier
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char    *my_strncpy(char *dest, char *src, int nb)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      while (i < nb)
        {
          dest[i] = src[i];
          i++;
        }
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

int     count_space(char *str, char c)
{
  int nb;
  int i;

  nb = 1;
  i = 0;
  while (str[i])
    {
      if (str[i] == c)
        {
          nb++;
          while (str[i] == ' ' && str[i] != '\0')
            i++;
        }
      else
        i++;
    }
  return (nb);
}

void    my_putchar(char c)
{
  write(1, &c, 1);
}

void    my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i++;
    }
}
