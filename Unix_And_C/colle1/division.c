/*
** division.c for dibision in /home/casier_s//colle1
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Tue Apr 23 10:33:20 2013 sofian casier
** Last update Tue Apr 23 11:27:20 2013 sofian casier
*/

#include <stdlib.h>
#include "my.h"

void     check_division2(char **argv, int nb)
{
  int	i;

  nb = nb + 1;
  i = 0;
  while (argv[nb][i])
    {
      if (argv[nb][i] == '.' && i == 0)
        {
          my_putstr("Error on the division argument\n");
          exit(1);
        }
      if (argv[nb][i] == '-' && i != 0)
        {
          my_putstr("Error on the division argument\n");
          exit(1);
        }
      if ((argv[nb][i] < '0' || argv[nb][i] > '9')
	  && argv[nb][i] != '-' && argv[nb][i] != '.')
        {
          my_putstr("Error on the division argument\n");
          exit(1);
        }
      i++;
    }
}

void     check_division(char **argv, int nb)
{
  int	i;

  nb = nb + 1;
  i = 0;
  while (argv[nb][i])
    {
      if (argv[nb][i] == '.' && i == 0)
        {
          my_putstr("Error on the division argument\n");
          exit(1);
        }
      if (argv[nb][i] == '-' && i != 0)
        {
          my_putstr("Error on the division argument\n");
          exit(1);
        }
      if ((argv[nb][i] < '0' || argv[nb][i] > '9') &&
	  argv[nb][i] != '-' && argv[nb][i] != '.')
        {
          my_putstr("Error on the division argument\n");
          exit(1);
        }
      i++;
    }
  check_division2(argv, nb);
}
