/*
** soustraction.c for sous in /home/casier_s//colle1
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Tue Apr 23 10:31:15 2013 sofian casier
** Last update Tue Apr 23 11:27:07 2013 sofian casier
*/

#include <stdlib.h>
#include "my.h"

void     check_soustraction2(char **argv, int nb)
{
  int	i;

  i = 0;
  nb = nb + 1;
  while (argv[nb][i])
    {
      if (argv[nb][i] == '.' && i == 0)
        {
          my_putstr("Error on the soustraction argument\n");
          exit(1);
        }
      if (argv[nb][i] == '-' && i != 0)
        {
          my_putstr("Error on the soustraction argument\n");
          exit(1);
        }
      if ((argv[nb][i] < '0' || argv[nb][i] > '9') &&
	  argv[nb][i] != '-' && argv[nb][i] != '.')
        {
          my_putstr("Error on the soustraction argument\n");
          exit(1);
        }
      i++;
    }
}

void     check_soustraction(char **argv, int nb)
{
  int	i;

  i = 0;
  nb = nb + 1;
  while (argv[nb][i])
    {
      if (argv[nb][i] == '.' && i == 0)
        {
          my_putstr("Error on the soustraction argument\n");
          exit(1);
        }
      if (argv[nb][i] == '-' && i != 0)
        {
          my_putstr("Error on the soustraction argument\n");
          exit(1);
        }
      if ((argv[nb][i] < '0' || argv[nb][i] > '9') &&
	  argv[nb][i] != '-' && argv[nb][i] != '.')
        {
          my_putstr("Error on the soustraction argument\n");
          exit(1);
        }
      i++;
    }
  check_soustraction2(argv, nb);
}
