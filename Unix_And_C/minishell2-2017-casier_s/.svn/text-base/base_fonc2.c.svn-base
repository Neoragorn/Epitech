/*
** base_fonc2.c for base fonc in /home/casier_s/os-home/minishell
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Tue Dec 25 16:21:46 2012 sofian casier
** Last update Mon Feb 25 22:32:16 2013 sofian casier
*/

#include <stdlib.h>
#include "my.h"

void    putnbr(int nb)
{
  int   n;

  if (nb != 0)
    {
      n = nb % 10;
      putnbr(nb / 10);
      my_putchar('0' + n);
    }
}

void    my_put_nbr(int nb)
{
  if (nb < 0)
    my_putchar('-');
  if (nb == 0)
    my_putchar('0');
  putnbr(nb);
}

char    *path_dir(char *path, char *readfile)
{
  char *tmp;
  int   i;
  int   j;

  j = 0;
  i = 0;
  tmp  = malloc((my_strlen(path) + my_strlen(readfile) + 2) * sizeof(char));
  if (tmp == NULL)
    exit(1);
  while (path[i] != 0)
    {
      tmp[i] = path[i];
      i++;
    }
  tmp[i++] = '/';
  while (readfile[j] != 0)
    {
      tmp[i] = readfile[j];
      j++;
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
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
