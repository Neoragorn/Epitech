/*
** alph_func.c for alph func in /home/casier_s//102chiffrement-2017-duques_a
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Tue Nov 27 14:36:35 2012 sofian casier
** Last update Sun Dec  2 20:43:26 2012 sofian casier
*/


#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "chiffre.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
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

char	*alpha_pos(char *str, s_mat *matrice)
{  
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (str[i] != 0)
    {
      if (str[i] == ' ')
	{
	  matrice->elements[j] = 0;
	}
      else if (str[i] >= 'a' && str[i] <= 'z')
	{
	  matrice->elements[j] = str[i] - 96;
	}
      else if (str[i] >= 'A' && str[i] <= 'Z')
	{
	  matrice->elements[j] = str[i] - 64;
	}
      i++;
      j++;
    }
  return (str);
}
