/*
** sphere.c for sphere in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon May  6 19:27:41 2013 clement lovergne
** Last update Sat Jun  8 16:54:13 2013 quentin journet
*/

#include	<math.h>
#include	"../point_h/fonction.h"

static void	calc_trans(t_calc *calc, t_my_c *my_c, t_obj *obj)
{
  calc->xcur -= obj->x;
  calc->ycur -= obj->y;
  calc->zcur -= obj->z;
  my_c->a = powf(calc->vx, 2) + powf(calc->vy, 2)
    + powf(calc->vz, 2);
  my_c->b = ((calc->xcur * calc->vx) + (calc->ycur * calc->vy)
	     + (calc->zcur * calc->vz)) * 2;
  my_c->c = powf(calc->xcur, 2) + powf(calc->ycur, 2)
    + powf(calc->zcur, 2) - powf(obj->ray, 2);
}

static void	calc_d_spher(t_my_c *my_c, float my_delta, float *k0)
{
  float		k1;
  float		k2;

  k1 = ((-1 * (my_c->b)) + sqrtf(my_delta)) / (2 * my_c->a);
  k2 = ((-1 * (my_c->b)) - sqrtf(my_delta)) / (2 * my_c->a);
  if ((k2 < k1 && k2 > 0) || (k2 > 0 && k1 < 0))
    *k0 = k2;
  else if ((k1 < k2 && k1 > 0) || (k1 > 0 && k2 < 0) || k1 == k2)
    *k0 = k1;
}

static void	change_to_sphere(t_coor *coor, t_obj *obj, float *k0,
				 t_calc *calc)
{
  coor->blue = obj->b;
  coor->red = obj->r;
  coor->green = obj->g;
  calc->val = *k0;
  coor->shine = obj->bril;
  calc->px = calc->xcur + (calc->val * calc->vx);
  calc->py = calc->ycur + (calc->val * calc->vy);
  calc->pz = calc->zcur + (calc->val * calc->vz);
  coor->nx = calc->px;
  coor->ny = calc->py;
  coor->nz = calc->pz;
  coor->nx += obj->x;
  coor->ny += obj->y;
  coor->nz += obj->z;
  calc->rx = 0;
  calc->ry = 0;
  calc->rz = 0;
}

static void	replace_point_sph(t_calc *calc, t_obj *obj)
{
  calc->xcur +=  obj->x;
  calc->ycur +=  obj->y;
  calc->zcur +=  obj->z;
}

void		calc_sphere(t_obj *obj, t_calc *calc, t_coor *coor)
{
  float		my_delta;
  t_my_c	my_c;
  float		k0;

  k0 = -1;
  calc_trans(calc, &my_c, obj);
  my_delta = (my_c.b * my_c.b) - (4 * my_c.a * my_c.c);
  if (my_delta == 0)
    k0 = (-1 * (my_c.b)) / (2 * my_c.a);
  else if (my_delta > 0)
    calc_d_spher(&my_c, my_delta, &k0);
  if (k0 > 0 && k0 < calc->val)
    change_to_sphere(coor, obj, &k0, calc);
  replace_point_sph(calc, obj);
}
