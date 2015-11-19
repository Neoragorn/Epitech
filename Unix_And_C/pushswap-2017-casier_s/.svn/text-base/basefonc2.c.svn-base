/*
** basefonc2.c for base fonc é in /home/casier_s/os-home/pushswap
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Wed Jan  2 19:04:55 2013 sofian casier
** Last update Sun Jan  6 19:21:45 2013 sofian casier
*/

#include "my.h"

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

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}

int     my_strcmp(char *str, char *dest)
{
  int   i;

  i = 0;
  while (str[i] == dest[i])
    {
      if (str[i] == dest[i] && str[i] == '\0')
        return (0);
      i++;
    }
  if (str[i] != dest[i])
    return (str[i] - dest[i]);
}

int     my_swap(int *a, int *b)
{
  int   c;

  c = *a;
  *a = *b;
  *b = c;
}
