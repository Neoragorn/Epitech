/*
** shadow_para.c for shadow_para in /home/loverg_c//raytracer/rt
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Thu Jun  6 15:09:27 2013 clement lovergne
** Last update Sat Jun  8 17:04:50 2013 quentin journet
*/

#include	<math.h>
#include	"../../point_h/fonction.h"

static void	calc_trans_para_sha(t_calc *calc, t_my_c *my_c, t_obj *obj)
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
  my_c->a = powf(calc->lx, 2) + powf(calc->ly, 2);
  my_c->b = 2 * ((calc->px * calc->lx) + (calc->py * calc->ly)) -
    (tanf(RAD * obj->ray) * calc->lz);
  my_c->c = pow(calc->px, 2) + pow(calc->py, 2) -
    (tanf(obj->ray * RAD) * calc->pz);
}

static int	check_hight_para_sha(t_calc *calc, float *k6, t_obj *obj)
{
  float		z;

  z = calc->pz + (*k6 * calc->lz);
  if (z < obj->min || z > obj->max)
    return (0);
  return (1);
}

static void	calc_para2_sha(t_my_c *my_c, float my_delta, float *k6)
{
  float		k1;
  float		k0;

  k1 = ((-1 * (my_c->b)) + sqrtf(my_delta)) / (2 * my_c->a);
  k0 = ((-1 * (my_c->b)) - sqrtf(my_delta)) / (2 * my_c->a);
  if ((k0 < k1 && k0 > 0) || (k0 > 0 && k1 < 0))
    *k6 = k0;
  else if ((k1 < k0 && k1 > 0) || (k1 > 0 && k0 < 0) || k1 == k0)
    *k6 = k1;
}

void		calc_sha_para(t_obj *obj, t_calc *calc, t_tmp_col *col)
{
  float		my_delta;
  t_my_c	my_c;
  float		k6;
  float		px;
  float		py;
  float		pz;

  px = calc->px;
  py = calc->py;
  pz = calc->pz;
  k6 = -1;
  calc_trans_para_sha(calc, &my_c, obj);
  my_delta = (my_c.b * my_c.b) - (4 * my_c.a * my_c.c);
  if (my_delta == 0)
    k6 = (-1 * (my_c.b)) / (2 * my_c.a);
  else if (my_delta > 0)
    calc_para2_sha(&my_c, my_delta, &k6);
  if (k6 > 0 && k6 < 1 && check_hight_para_sha(calc, &k6, obj) == 1)
    col->shadow *= k6;
  calc->px = px;
  calc->py = py;
  calc->pz = pz;
  rotate_x(&calc->lx, &calc->ly, &calc->lz, obj->rot_x);
  rotate_z(&calc->lx, &calc->ly, &calc->lz, obj->rot_z);
  rotate_y(&calc->lx, &calc->ly, &calc->lz, obj->rot_y);
}
