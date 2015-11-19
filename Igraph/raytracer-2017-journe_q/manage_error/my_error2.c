/*
** error2.c for error2 in /home/amoure_a//rt2
** 
** Made by alix amoureux
** Login   <amoure_a@epitech.net>
** 
** Started on  Sat Apr 13 10:25:48 2013 alix amoureux
** Last update Sat Jun  8 15:46:29 2013 alix amoureux
*/

#include	<math.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	"../point_h/fonction.h"

static int	error_cyl(char *buffer, int *nbr, char **tab)
{
  float		brill;

  if (my_memcmp(buffer, "cylindre", 8) == 0
      && (check_ponctuation(buffer, 13)) == 1)
    {
      brill = atof(tab[4]);
      if (nbr[5] < 0 || nbr[5] > 255 || nbr[6] < 0
	  || nbr[6] > 255 || nbr[7] < 0 || nbr[7] > 255)
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

static int	error_cone(char *buffer, int *nbr, char **tab, float brill)
{
  if (my_memcmp(buffer, "cone", 4) == 0 &&
      (check_ponctuation(buffer, 13)) == 1)
    {
      brill = atof(tab[4]);
      if (nbr[5] < 0 || nbr[5] > 255 || nbr[6] < 0
          || nbr[6] > 255 || nbr[7] < 0 || nbr[7] > 255)
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

static int	error_sphere_cone(char *buffer, int *nbr,
				  char **tab, float brill)
{
  if (my_memcmp(buffer, "sphere", 6) == 0
      && (check_ponctuation(buffer, 8)) == 1)
    {
      brill = atof(tab[4]);
      if (nbr[5] < 0 || nbr[5] > 255 || nbr[6] < 0
	  || nbr[6] > 255 || nbr[7] < 0 || nbr[7] > 255)
        return (0);
      if (brill < 0 || brill > 1)
        return (0);
      return (1);
    }
  return (error_cone(buffer, nbr, tab, brill));
}

static int	check_name(char *buffer, int *nbr, char **tab)
{
  int		h;
  float		brill;

  brill = 0;
  if ((h = error_cyl(buffer, nbr, tab)) == 0)
    return (0);
  if (h == 1)
    return (1);
  if ((h = error_sphere_cone(buffer, nbr, tab, brill)) == 0)
    return (0);
  if (h == 1)
    return (1);
  if ((h = error_spot_plan(buffer, nbr, tab)) == 0)
    return (0);
  if (h == 1)
    return (1);
  if ((h = error_paraboloide(buffer, nbr, tab, brill)) == 0)
    return (0);
  if (h == 1)
    return (1);
  return (0);
}

int		name_ponct_error(char *buffer)
{
  char		**tab;
  int		*nbr;
  int		i;

  i = 0;
  tab = my_str_to_word_tab2(buffer);
  if ((nbr = malloc(sizeof(float) * (13))) == NULL)
    error_message("Error on malloc\n");
  while (tab[i])
    {
      nbr[i] = atof(tab[i]);
      i++;
    }
  return (check_name(buffer, nbr, tab));
}
