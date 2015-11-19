/*
** cone.c for cone in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/raytracer-2017-journe_q/calc
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Fri May 24 21:27:33 2013 clement lovergne
** Last update Fri Jun  7 17:15:53 2013 clement lovergne
*/

#include	<math.h>
#include	"../point_h/fonction.h"

static void	calc_trans_cone(t_calc *calc, t_my_c *my_c, t_obj *obj)
{
  calc->xcur -=  obj->x;
  calc->ycur -=  obj->y;
  calc->zcur -=  obj->z;
  rotate_x(&calc->xcur, &calc->ycur, &calc->zcur, -obj->rot_x);
  rotate_y(&calc->xcur, &calc->ycur, &calc->zcur, -obj->rot_y);
  rotate_z(&calc->xcur, &calc->ycur, &calc->zcur, -obj->rot_z);
  rotate_x(&calc->vx, &calc->vy, &calc->vz, -obj->rot_x);
  rotate_y(&calc->vx, &calc->vy, &calc->vz, -obj->rot_y);
  rotate_z(&calc->vx, &calc->vy, &calc->vz, -obj->rot_z);
  my_c->a = powf(calc->vx, 2) + powf(calc->vy, 2) -
    (powf(calc->vz, 2) * powf(tanf(obj->ray * RAD), 2));
  my_c->b = ((calc->xcur * calc->vx) + (calc->ycur * calc->vy) -
	     ((calc->zcur * calc->vz) * powf(tanf(obj->ray * RAD), 2))) * 2;
  my_c->c = powf(calc->xcur, 2) + powf(calc->ycur, 2) -
    (powf(calc->zcur, 2) * powf(tanf(obj->ray * RAD), 2));
}

static void	calc_cone2(t_my_c *my_c, float my_delta, float *k3)
{
  float		k1;
  float		k2;

  k1 = ((-1 * (my_c->b)) + sqrtf(my_delta)) / (2 * my_c->a);
  k2 = ((-1 * (my_c->b)) - sqrtf(my_delta)) / (2 * my_c->a);
  if ((k2 < k1 && k2 > 0) || (k2 > 0 && k1 < 0))
    *k3 = k2;
  else if ((k1 < k2 && k1 > 0) || (k1 > 0 && k2 < 0) || k1 == k2)
    *k3 = k1;
}

static int	calc_cone3(t_calc *calc, float *k3, t_obj *obj)
{
  float		z;

  z = calc->zcur + (*k3 * calc->vz);
  if (z < obj->min || z > obj->max)
    return (0);
  return (1);
}

static void	change_to_cone(t_obj *obj, t_calc *calc,
			       t_coor *coor, float *k3)
{
  coor->blue = obj->b;
  coor->red = obj->r;
  coor->green = obj->g;
  calc->val = *k3;
  coor->shine = obj->bril;
  calc->px = calc->xcur + (calc->val * calc->vx);
  calc->py = calc->ycur + (calc->val * calc->vy);
  calc->pz = calc->zcur + (calc->val * calc->vz);
  coor->nx = calc->px;
  coor->ny = calc->py;
  coor->nz = powf(tanf(obj->ray * RAD), 2) * calc->pz;
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

void		calc_cone(t_obj *obj, t_calc *calc, t_coor *coor)
{
  float		my_delta;
  t_my_c	my_c;
  float		k3;

  k3 = -1;
  calc_trans_cone(calc, &my_c, obj);
  my_delta = (my_c.b * my_c.b) - (4 * my_c.a * my_c.c);
  if (my_delta == 0)
    k3 = (-1 * (my_c.b)) / (2 * my_c.a);
  else if (my_delta > 0)
    calc_cone2(&my_c, my_delta, &k3);
  if (calc_cone3(calc, &k3, obj) == 1 && k3 > 0 && k3 < calc->val)
    change_to_cone(obj, calc, coor, &k3);
  replace_point(calc, obj);
}
