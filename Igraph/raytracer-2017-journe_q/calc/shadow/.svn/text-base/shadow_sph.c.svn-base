/*
** shadow_sph.c for shadow_sph in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Sat May 25 16:02:53 2013 clement lovergne
** Last update Tue Jun  4 19:48:49 2013 clement lovergne
*/

#include	<math.h>
#include	"../../point_h/fonction.h"

static void	calc_trans_sha(t_calc *calc, t_my_c *my_c, t_obj *obj)
{
  float		px;
  float		py;
  float		pz;

  px = calc->px - obj->x;
  py = calc->py - obj->y;
  pz = calc->pz - obj->z;
  my_c->a = powf(calc->lx, 2) + powf(calc->ly, 2) + powf(calc->lz, 2);
  my_c->b = ((px * calc->lx) + (py * calc->ly) + (pz * calc->lz)) * 2;
  my_c->c = powf(px, 2) + powf(py, 2) + powf(pz, 2) - powf(obj->ray, 2);
}

static void	calc_dsha_spher(t_my_c *my_c, float my_delta, float *k0)
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

void		calc_sha_sph(t_obj *obj, t_calc *calc, t_tmp_col *col)
{
  float		my_delta;
  t_my_c	my_c;
  float		k0;

  k0 = -1;
  calc_trans_sha(calc, &my_c, obj);
  my_delta = (my_c.b * my_c.b) - (4 * my_c.a * my_c.c);
  if (my_delta == 0)
    k0 = (-1 * (my_c.b)) / (2 * my_c.a);
  else if (my_delta > 0)
    calc_dsha_spher(&my_c, my_delta, &k0);
  if (k0 > 0 && k0 < 1)
    col->shadow *= k0;
}
