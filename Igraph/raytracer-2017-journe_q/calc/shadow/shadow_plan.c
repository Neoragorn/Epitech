/*
** shadow_plan.c for plan in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Sat May 25 16:02:15 2013 clement lovergne
** Last update Fri Jun  7 15:52:18 2013 clement lovergne
*/

#include	<math.h>
#include	"../../point_h/fonction.h"

static int	trans_rot_sha(t_calc *calc, t_obj *obj)
{
  calc->px -= obj->x;
  calc->py -= obj->y;
  calc->pz -= obj->z;
  rotate_x(&calc->px, &calc->py, &calc->pz, -obj->rot_x);
  rotate_z(&calc->px, &calc->py, &calc->pz, -obj->rot_z);
  rotate_y(&calc->px, &calc->py, &calc->pz, -obj->rot_y);
  rotate_x(&calc->lx, &calc->ly, &calc->lz, -obj->rot_x);
  rotate_z(&calc->lx, &calc->ly, &calc->lz, -obj->rot_z);
  rotate_y(&calc->lx, &calc->ly, &calc->lz, -obj->rot_y);
  if (fabs(calc->lz) <= 0.0001)
    return (0);
  return (1);
}

void		calc_sha_plan(t_obj *obj, t_calc *calc, t_tmp_col *col)
{
  float		x;
  float		y;
  float		k1;
  float		px;
  float		py;
  float		pz;

  px = calc->px;
  py = calc->py;
  pz = calc->pz;
  if (trans_rot_sha(calc, obj) == 1)
    {
      k1 = (-1 * calc->pz / calc->lz);
      x = calc->px + (k1 * calc->lx);
      y = calc->py + (k1 * calc->ly);
      if (k1 > 0 &&  k1 < 1 && powf(x, 2) + powf(y, 2) < obj->max
	  && powf(x, 2) + powf(y, 2) > obj->min)
	col->shadow *= k1;
    }
  calc->px = px;
  calc->py = py;
  calc->pz = pz;
  rotate_x(&calc->lx, &calc->ly, &calc->lz, obj->rot_x);
  rotate_z(&calc->lx, &calc->ly, &calc->lz, obj->rot_z);
  rotate_y(&calc->lx, &calc->ly, &calc->lz, obj->rot_y);
}
