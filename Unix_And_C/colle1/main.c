/*
** main.c for main in /home/casier_s//colle1
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Tue Apr 23 09:39:17 2013 sofian casier
** Last update Tue Apr 23 11:40:22 2013 sofian casier
*/

#include <stdlib.h>
#include "my.h"

int	check_precision(char **argv, int nb)
{
  int	i;

  i = 0;
  nb = nb + 1;
  while (argv[nb][i])
    {
      if (argv[nb][i] == '-' || argv[nb][i] == ',')
        {
          my_putstr("Error on the precision argument\n");
          exit(1);
        }
      i++;
    }
  return (SUCCESS);
}

int	check_deep(char **argv, int nb)
{
  int	i;

  i = 0;
  nb = nb + 1;
  while (argv[nb][i])
    {
      if (argv[nb][i] == '-' || argv[nb][i] == ',')
        {
          my_putstr("Error on the deep argument\n");
          exit(1);
        }
      i++;
    }
  return (SUCCESS);
}

void	parcer(char **argv, int argc)
{
  int	i;

  i = 1;
  while (i < argc)
    {
      if (my_strcmp(argv[i], "-p") == 0)
	check_deep(argv, i);
      if (my_strcmp(argv[i], "-P") == 0)
	check_precision(argv, i);
      if (my_strcmp(argv[i], "-a") == 0)
	check_addition(argv, i, argc);
      if (my_strcmp(argv[i], "-s") == 0)
	check_soustraction(argv, i);
      if (my_strcmp(argv[i], "-d") == 0)
	check_division(argv, i);
      i++;
    }
}

int	main(int argc, char **argv)
{
  if (argc == 1)
    {
      my_putstr("No argument\n");
      return (1);
    }
  parcer(argv, argc);
}
