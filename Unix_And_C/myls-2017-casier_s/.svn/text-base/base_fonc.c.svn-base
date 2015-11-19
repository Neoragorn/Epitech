/*
** base_fonc.c for base fonc in /home/casier_s/os-home/tpmyls
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Nov 29 19:09:45 2012 sofian casier
** Last update Sun Dec  2 02:25:12 2012 sofian casier
*/

#include <stdlib.h>
#include <unistd.h>

void    my_putchar(char c)
{
  write(1, &c, 1);
}

int    my_putstr(char *str)
{
  int   i;

  i = 0;
  if (str == NULL)
    exit (0);
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
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

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
      i++;
  return (i);
}
