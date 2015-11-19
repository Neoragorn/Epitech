/*
** cylindre.c for cylindre in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Fri May 24 20:59:16 2013 clement lovergne
** Last update Sat Jun  8 16:54:50 2013 quentin journet
*/

#include	<math.h>
#include	"../point_h/fonction.h"

static void	calc_trans_cyl(t_calc *calc, t_my_c *my_c, t_obj *obj)
{
  calc->xcur -= obj->x;
  calc->ycur -= obj->y;
  calc->zcur -= obj->z;
  rotate_x(&calc->xcur, &calc->ycur, &calc->zcur, -obj->rot_x);
  rotate_z(&calc->xcur, &calc->ycur, &calc->zcur, -obj->rot_z);
  rotate_y(&calc->xcur, &calc->ycur, &calc->zcur, -obj->rot_y);
  rotate_x(&calc->vx, &calc->vy, &calc->vz, -obj->rot_x);
  rotate_z(&calc->vx, &calc->vy, &calc->vz, -obj->rot_z);
  rotate_y(&calc->vx, &calc->vy, &calc->vz, -obj->rot_y);
  my_c->a = powf(calc->vx, 2) + powf(calc->vy, 2);
  my_c->b = ((calc->xcur * calc->vx) + (calc->ycur * calc->vy)) * 2;
  my_c->c = powf(calc->xcur, 2) + powf(calc->ycur, 2) - powf(obj->ray, 2);
}

static int	check_hight_cyl(t_calc *calc, float *k2, t_obj *obj)
{
  float		z;

  z = calc->zcur + (*k2 * calc->vz);
  if (z < obj->min || z > obj->max)
    return (0);
  return (1);
}

static void	calc_cyl2(t_my_c *my_c, float my_delta, float *k2)
{
  float		k1;
  float		k0;

  k1 = ((-1 * (my_c->b)) + sqrtf(my_delta)) / (2 * my_c->a);
  k0 = ((-1 * (my_c->b)) - sqrtf(my_delta)) / (2 * my_c->a);
  if ((k0 < k1 && k0 > 0) || (k0 > 0 && k1 < 0))
    *k2 = k0;
  else if ((k1 < k0 && k1 > 0) || (k1 > 0 && k0 < 0) || k1 == k0)
    *k2 = k1;
}

static void	change_to_cylindre(t_obj *obj, t_calc *calc,
				   t_coor *coor, float *k2)
{
  coor->blue = obj->b;
  coor->red = obj->r;
  coor->green = obj->g;
  calc->val = *k2;
  coor->shine = obj->bril;
  calc->px = calc->xcur + (calc->val * calc->vx);
  calc->py = calc->ycur + (calc->val * calc->vy);
  calc->pz = calc->zcur + (calc->val * calc->vz);
  coor->nx = calc->px;
  coor->ny = calc->py;
  coor->nz = 0;
  rotate_x(&coor->nx, &coor->ny, &coor->nz, obj->rot_x);
  rotate_z(&coor->nx, &coor->ny, &coor->nz, obj->rot_z);
  rotate_y(&coor->nx, &coor->ny, &coor->nz, obj->rot_y);
  coor->nx += obj->x;
  coor->ny += obj->y;
  coor->nz += obj->z;
  calc->rx = obj->rot_x;
  calc->ry = obj->rot_y;
  calc->rz = obj->rot_z;
}

void		calc_cylindre(t_obj *obj, t_calc *calc, t_coor *coor)
{
  float		my_delta;
  t_my_c	my_c;
  float		k2;
  int		hight;

  k2 = -1;
  calc_trans_cyl(calc, &my_c, obj);
  my_delta = (my_c.b * my_c.b) - (4 * my_c.a * my_c.c);
  hight = check_hight_cyl(calc, &k2, obj);
  if (my_delta == 0)
    k2 = (-1 * (my_c.b)) / (2 * my_c.a);
  else if (my_delta > 0)
    calc_cyl2(&my_c, my_delta, &k2);
  if (k2 > 0 && k2 < calc->val && hight == 1)
    change_to_cylindre(obj, calc, coor, &k2);
  replace_point(calc, obj);
}
