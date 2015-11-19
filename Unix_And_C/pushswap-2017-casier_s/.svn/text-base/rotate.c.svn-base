/*
** rotate.c for rotate in /home/casier_s/os-home/pushswap
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sat Jan  5 18:32:50 2013 sofian casier
** Last update Sun Jan  6 19:22:48 2013 sofian casier
*/

#include "my.h"

int     rrb(int *l_a, int *l_b, int argc)
{
  int   i;

  i = argc - 2;
  while (i > 0)
    {
      my_swap(&l_b[i - 1], &l_b[i]);
      i--;
    }
  my_putstr("rrb ");
  return (1);
}

int     rra(int *l_a, int *l_b, int argc)
{
  int   i;

  i = argc - 2;
  while (i > 0)
    {
      my_swap(&l_a[i - 1], &l_a[i]);
      i--;
    }
  my_putstr("rra ");
  return (1);
}

int     *r_b(int *l_b, int argc)
{
  int   i;

  i = argc - 2;
  while (i > 0)
    {
      my_swap(&l_b[0], &l_b[i]);
      i--;
    }
  my_putstr("r_b ");
  return (1);
}

int     *r_a(int *l_a, int argc)
{
  int   i;

  i = argc - 2;
  while (i > 0)
    {
      my_swap(&l_a[0], &l_a[i]);
      i--;
    }
   my_putstr("r_a ");
   return (1);
}

int     *rr(int *l_a, int *l_b, int argc)
{
  r_a(l_a, argc);
  r_b(l_b, argc);
  my_putstr("rr ");
  return (1);
}
