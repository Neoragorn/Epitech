/*
** base_fonc3.c for base fonc in /home/casier_s/os-home/minishell
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sun Dec 30 15:03:42 2012 sofian casier
** Last update Mon Mar 18 18:48:21 2013 sofian casier
*/

#include <unistd.h>
#include "my.h"

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    i++;
  return (i);
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
