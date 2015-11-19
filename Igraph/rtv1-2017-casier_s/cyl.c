/*
** cyl.c for cyl in /home/casier_s//rtv1-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Wed Mar 13 16:59:15 2013 sofian casier
** Last update Sun Mar 17 15:45:45 2013 sofian casier
*/

#include <mlx.h>
#include <X11/X.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "my.h"

void	init_coord(t_cyl *cyl)
{
  cyl->x1 -= X_CYL;
  cyl->y1 -= Y_CYL;
  cyl->z1 -= Z_CYL;
  rotationcyl_x(cyl, CYL_ROTX);
  rotationcyl_y(cyl, CYL_ROTY);
  rotationcyl_z(cyl, CYL_ROTZ);
  cyl->a = powf(cyl->x1, 2) + powf(cyl->y1, 2);
  cyl->b = 2 * ((cyl->xo * cyl->x1) + (cyl->yo * cyl->y1));
  cyl->c = powf(cyl->xo, 2) + powf(cyl->yo, 2) - powf(R_CYL, 2);
  rotationcyl_x(cyl, -(CYL_ROTX));
  rotationcyl_y(cyl, -(CYL_ROTY));
  rotationcyl_z(cyl, -(CYL_ROTZ));
  cyl->x1 += X_CYL;
  cyl->y1 += Y_CYL;
  cyl->z1 += Z_CYL;
  cyl->delta = powf(cyl->b, 2) - (4 *  cyl->a *  cyl->c);
}

float	create_cylindre(t_cyl *cyl)
{
  init_coord(cyl);
  if (cyl->delta < 0)
    return (0);
  else if (cyl->delta == 0)
    {
      cyl->k1 = (-cyl->b) / (2 * cyl->a);
      return (cyl->k1);
    }
  else
    {
      cyl->k1 = (-cyl->b - sqrtf(cyl->delta)) / (2 * cyl->a);
      cyl->k2 = (-cyl->b + sqrtf(cyl->delta)) / (2 * cyl->a);
      if (cyl->k1 < 0 && cyl->k2 < 0)
	return (0);
      else if ((cyl->k2 <= cyl->k1
		&& cyl->k2 >= 0) || (cyl->k2 >= 0 && cyl->k1 < 0))
	return (cyl->k2);
      else if ((cyl->k1 <= cyl->k2 && cyl->k1 >= 0)
	       || (cyl->k1 >= 0 && cyl->k2 < 0))
	return (cyl->k1);
    }
  return (0);
}
