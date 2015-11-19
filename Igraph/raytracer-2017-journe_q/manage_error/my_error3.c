/*
** check_bonus.c for check_bonus in /home/amoure_a//raytracer-2017-journe_q/manage_error
** 
** Made by alix amoureux
** Login   <amoure_a@epitech.net>
** 
** Started on  Mon Jun  3 17:18:05 2013 alix amoureux
** Last update Sat Jun  8 15:46:44 2013 alix amoureux
*/

#include	<math.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"../point_h/fonction.h"

int		error_paraboloide(char *buffer, int *nbr, char **tab, float brill)
{
  if (my_memcmp(buffer, "paraboloide", 11) == 0
      && (check_ponctuation(buffer, 13)) == 1)
    {
      brill = atof(tab[4]);
      if (nbr[5] < 0 || nbr[5] > 255 || nbr[6] < 0
          || nbr[6] > 255 || nbr[7] < 0 || nbr[7] > 255 \
          )
        return (0);
      if (nbr[8] < -180 || nbr[8] > 180 || nbr[9] < -180 || nbr[9] > 180
	  || nbr[10] < -180 || nbr[10] > 180)
	return (0);
      if (nbr[11] > nbr[12])
	return (0);
      if (brill < 0 || brill > 1)
        return (0);
      return (1);
    }
  return (2);
}

int		error_plan(char *buffer, int *nbr, char **tab)
{
  float		brill;

  if (my_memcmp(buffer, "plan", 4) == 0 &&
      (check_ponctuation(buffer, 13)) == 1)
    {
      brill = atof(tab[3]);
      if (nbr[4] < 0 || nbr[4] > 255 || nbr[5] < 0
          || nbr[5] > 255 || nbr[6] < 0 || nbr[6] > 255)
        return (0);
      if (nbr[7] < -180 || nbr[7] > 180 || nbr[8] < -180 || nbr[8] > 180 ||
          nbr[9] < -180 || nbr[9] > 180)
        return (0);
      if (nbr[10] > nbr[11])
        return (0);
      if (nbr[12] != 0 && nbr[12] != 1)
	return (0);
      if (brill < 0 || brill > 1)
        return (0);
      return (1);
    }
  return (2);
}

int		error_spot_plan(char *buffer, int *nbr, char **tab)
{
  if (my_memcmp(buffer, "spot", 4) == 0 && (check_ponctuation(buffer, 6)) == 1)
    {
      if (nbr[3] < 0 || nbr[3] > 255 || nbr[4] < 0
          || nbr[4] > 255 || nbr[5] < 0 || nbr[5] > 255)
        return (0);
      return (1);
    }
  return (error_plan(buffer, nbr, tab));
}
