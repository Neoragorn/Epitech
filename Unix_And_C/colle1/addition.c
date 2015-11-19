/*
** addition.c for addition in /home/casier_s//colle1
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Tue Apr 23 10:29:22 2013 sofian casier
** Last update Tue Apr 23 13:00:46 2013 sofian casier
*/

#include <stdlib.h>
#include "my.h"

void	error()
{
  my_putstr("Error on the addition argument\n");
  exit(1);
}

void	rev_data(char *str)
{
  int	i;
  int	length;

  i = -1;
  length = my_strlen(str);
  while (length != i)
    {
      my_putchar(str[length]);
      length--;
    }
  my_putchar('\n');
}

char	*add_calc(char *scalc, char *fcalc)
{
  t_ope	ope;

  ope.j = 0;
  ope.length = my_strlen(scalc) - 1;
  ope.length2 = my_strlen(fcalc) - 1;
  ope.data = malloc(ope.length * sizeof(char) + 2);
  ope.i = -1;
  ope.retenu = 0;
  while (ope.length != ope.i)
    {
      ope.result = (fcalc[ope.length2] - '0')
	+ (scalc[ope.length] - '0') + ope.retenu;
      if (ope.result > 9)
	{
	  ope.result = ope.result - 10;
	  ope.retenu = 1;
	}
      else
	ope.retenu = 0;
      ope.data[ope.j] = ope.result + '0';
      ope.length--;
      ope.length2--;
      ope.j++;
    }
  return (ope.data);
}

void     check_addition2(char **argv, int nb, int argc)
{
  int	i;
  char	*result;

  i = 0;
  if (nb != argc)
    nb = nb + 1;
  while (argv[nb][i])
    {
      if (argv[nb][i] == '.' && i == 0)
	error();
      if (argv[nb][i] == '-' && i != 0)
	error();
      if ((argv[nb][i] < '0' || argv[nb][i] > '9') &&
	  argv[nb][i] != '-' && argv[nb][i] != '.')
	error();
      i++;
    }
  result = add_calc(argv[nb], argv[nb - 1]);
  rev_data(result);
}

void     check_addition(char **argv, int nb, int argc)
{
  int	i;

  i = 0;
  if (nb != argc)
    nb = nb + 1;
  while (argv[nb][i])
    {
      if (argv[nb][i] == '.' && i == 0)
	error();
      if (argv[nb][i] == '-' && i != 0)
	error();
      if ((argv[nb][i] < '0' || argv[nb][i] > '9') &&
	  argv[nb][i] != '-' && argv[nb][i] != '.')
	error();
      i++;
    }
  check_addition2(argv, nb, argc);
}
