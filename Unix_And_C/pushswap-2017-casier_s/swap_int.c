/*
** swap_int.c for swap int in /home/casier_s/os-home/pushswap
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sat Jan  5 18:35:44 2013 sofian casier
** Last update Sun Jan  6 19:25:32 2013 sofian casier
*/

#include <stdlib.h>
#include "my.h"

int     *s_b(int *l_b)
{
  my_swap(&l_b[0], &l_b[1]);
  my_putstr("s_b ");
}

int     *s_a(int *l_a)
{
  my_swap(&l_a[0], &l_a[1]);
  my_putstr("s_a ");
}

int     p_b(int *l_a, int *l_b, int argc)
{
  int   i;

  i = argc - 1;
  if (l_b == NULL)
    return (0);
  my_swap(&l_a[0], &l_b[i]);
  while (i > 0)
    {
      my_swap(&l_b[i - 1], &l_b[i]);
      i--;
    }
  my_putstr("p_b ");
}

int     p_a(int *l_a, int *l_b, int argc)
{
  int   i;

  i = argc - 1;
  if (l_b == NULL)
    return (0);
  my_swap(&l_b[0], &l_a[i]);
  while (i > 0)
    {
      my_swap(&l_a[i - 1], &l_a[i]);
      i--;
    }
  my_putstr("p_a ");
}
