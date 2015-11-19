/*
** shadow_cone.c for shadowcone in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Sat May 25 16:02:28 2013 clement lovergne
** Last update Sat Jun  8 17:06:09 2013 quentin journet
*/

#include	<math.h>
#include	"../../point_h/fonction.h"

static void	calc_trans_cone_sha(t_calc *calc, t_my_c *my_c, t_obj *obj)
{
  calc->px -= obj->x;
  calc->py -= obj->y;
  calc->pz -= obj->z;
  rotate_x(&calc->px, &calc->py, &calc->pz, -obj->rot_x);
  rotate_y(&calc->px, &calc->py, &calc->pz, -obj->rot_y);
  rotate_z(&calc->px, &calc->py, &calc->pz, -obj->rot_z);
  rotate_x(&calc->lx, &calc->ly, &calc->lz, -obj->rot_x);
  rotate_y(&calc->lx, &calc->ly, &calc->lz, -obj->rot_y);
  rotate_z(&calc->lx, &calc->ly, &calc->lz, -obj->rot_z);
  my_c->a = powf(calc->lx, 2) + powf(calc->ly, 2) -
    (powf(calc->lz, 2) * powf(tanf(obj->ray * RAD), 2));
  my_c->b = ((calc->px * calc->lx) + (calc->py * calc->ly) -
	     ((calc->pz * calc->lz) * powf(tanf(obj->ray * RAD), 2))) * 2;
  my_c->c = powf(calc->px, 2) + powf(calc->py, 2) -
    (powf(calc->pz, 2) * powf(tanf(obj->ray * RAD), 2));
}

static void	calc_cone2_sha(t_my_c *my_c, float my_delta, float *k3)
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

static int	calc_cone3_sha(t_calc *calc, float *k3, t_obj *obj)
{
  float		z;

  z = calc->pz + (*k3 * calc->lz);
  if (z < obj->min || z > obj->max)
    return (0);
  return (1);
}

void		calc_sha_cone(t_obj *obj, t_calc *calc, t_tmp_col *col)
{
  float		my_delta;
  t_my_c	my_c;
  float		k3;
  float		px;
  float		py;
  float		pz;

  px = calc->px;
  py = calc->py;
  pz = calc->pz;
  k3 = -1;
  calc_trans_cone_sha(calc, &my_c, obj);
  my_delta = (my_c.b * my_c.b) - (4 * my_c.a * my_c.c);
  if (my_delta == 0)
    k3 = (-1 * (my_c.b)) / (2 * my_c.a);
  else if (my_delta > 0)
    calc_cone2_sha(&my_c, my_delta, &k3);
  if (calc_cone3_sha(calc, &k3, obj) == 1 && k3 > 0 && k3 < 1)
    col->shadow *= k3;
  calc->px = px;
  calc->py = py;
  calc->pz = pz;
  rotate_x(&calc->lx, &calc->ly, &calc->lz, obj->rot_x);
  rotate_y(&calc->lx, &calc->ly, &calc->lz, obj->rot_y);
  rotate_z(&calc->lx, &calc->ly, &calc->lz, obj->rot_z);
}
