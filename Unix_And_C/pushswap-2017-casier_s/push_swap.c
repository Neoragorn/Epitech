/*
** push_swap.c for push swap in /home/casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Wed Jan  2 18:35:06 2013 sofian casier
** Last update Sun Jan  6 23:19:10 2013 sofian casier
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int	*ss(int	*l_a, int *l_b)
{
  s_a(l_a);
  s_b(l_b);
  my_putstr("ss ");
  return (1);
}

int	*rrr(int *l_a, int *l_b, int argc)
{
  rra(l_a, l_b, argc);
  rrb(l_a, l_b, argc);
  my_putstr("rrr ");
  return (1);
}

int	check_swap(int	*l_a, int argc)
{
  int	i;

  i = 0;
  while (l_a[i + 1] != 0)
    {
      if (l_a[i] > l_a[i + 1])
	return (0);
      i++;
    }
  return (1);
}

int	push_swap(int *l_a, int *l_b, int argc)
{
  int	i;
  int	check;

  check = check_swap(l_a, argc);
  i = 0;
  if (check == 0)
    {
      if (l_a[0] > l_a[1] && l_a[argc - 2] > l_a[1] && l_a[0] > l_a[argc - 2])
	r_a(l_a, argc);
      else if (l_a[0] > l_a[1])
	s_a(l_a);
      else
	r_a(l_a, argc);
    }
  else if (check == 1)
    return (0);
  push_swap(l_a, l_b, argc);
}

int	main(int argc, char **argv)
{
  int	*l_a;
  int	*l_b;

  if (l_a == NULL)
    return (1);
  l_a = malloc(argc * sizeof(int) + 1);
  l_b = malloc(argc * sizeof(int) + 1);
    if (argc == 1)
    {
      my_putstr("Add more arguments\n");
      return (1);
    }
  if (argc > 6)
    {
      my_putstr("Sorry, i can't use so many arguments.\n");
      return (1);
    }
  my_intdup(argv, l_a, argc);
  push_swap(l_a, l_b, argc);
  check_swap(l_a, argc);
  free(l_a);
  free(l_b);
  my_putchar('\n');
}
