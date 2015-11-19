/*
** plan.c for plan in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Fri May 24 20:22:02 2013 clement lovergne
** Last update Sat Jun  8 13:47:57 2013 alix amoureux
*/

#include	<math.h>
#include	"../point_h/fonction.h"

static int	trans_rot(t_calc *calc, t_obj *obj)
{
  calc->xcur -= obj->x;
  calc->ycur -= obj->y;
  calc->zcur -= obj->z;
  rotate_x(&calc->xcur, &calc->ycur, &calc->zcur, -obj->rot_x);
  rotate_y(&calc->xcur, &calc->ycur, &calc->zcur, -obj->rot_y);
  rotate_z(&calc->xcur, &calc->ycur, &calc->zcur, -obj->rot_z);
  rotate_x(&calc->vx, &calc->vy, &calc->vz, -obj->rot_x);
  rotate_y(&calc->vx, &calc->vy, &calc->vz, -obj->rot_y);
  rotate_z(&calc->vx, &calc->vy, &calc->vz, -obj->rot_z);
  if (fabs(calc->vz) <= 0.0001)
    return (0);
  return (1);
}

static void	change_to_plan(t_obj *obj, t_calc *calc,
			       t_coor *coor, float *k1)
{
  coor->blue = obj->b;
  coor->red = obj->r;
  coor->green = obj->g;
  set_checker(coor, obj, calc);
  calc->val = *k1;
  coor->shine = obj->bril;
  calc->px = calc->xcur + (*k1 * calc->vx);
  calc->py = calc->ycur + (*k1 * calc->vy);
  calc->pz = calc->zcur + (*k1 * calc->vz);
  coor->nx = 0;
  coor->ny = 0;
  coor->nz = 100;
  rotate_x(&coor->nx, &coor->ny, &coor->nz, obj->rot_x);
  rotate_y(&coor->nx, &coor->ny, &coor->nz, obj->rot_y);
  rotate_z(&coor->nx, &coor->ny, &coor->nz, obj->rot_z);
  coor->nx += obj->x;
  coor->ny += obj->y;
  coor->nz += obj->z;
  calc->rx = obj->rot_x;
  calc->ry = obj->rot_y;
  calc->rz = obj->rot_z;
}

void		replace_point(t_calc *calc, t_obj *obj)
{
  rotate_x(&calc->xcur, &calc->ycur, &calc->zcur, obj->rot_x);
  rotate_y(&calc->xcur, &calc->ycur, &calc->zcur, obj->rot_y);
  rotate_z(&calc->xcur, &calc->ycur, &calc->zcur, obj->rot_z);
  calc->xcur += obj->x;
  calc->ycur += obj->y;
  calc->zcur += obj->z;
  rotate_x(&calc->vx, &calc->vy, &calc->vz, obj->rot_x);
  rotate_y(&calc->vx, &calc->vy, &calc->vz, obj->rot_y);
  rotate_z(&calc->vx, &calc->vy, &calc->vz, obj->rot_z);
}

void		calc_plan(t_obj *obj, t_calc *calc, t_coor *coor)
{
  float		x;
  float		y;
  float		k1;

  if (trans_rot(calc, obj) == 1)
    {
      replace_point(calc, obj);
      k1 = (-1 * calc->zcur / calc->vz);
      x = calc->xcur + (k1 * calc->vx);
      y = calc->ycur + (k1 * calc->vy);
      if (k1 > 0 &&  k1 < calc->val &&
	  powf(x, 2) + powf(y, 2) < obj->max &&
	  powf(x, 2) + powf(y, 2) > obj->min)
        change_to_plan(obj, calc, coor, &k1);
    }
  else
    replace_point(calc, obj);
}
