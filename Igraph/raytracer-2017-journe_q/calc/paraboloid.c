/*
** hyperboloid.c for hyperboloid in /home/amoure_a//rtv1-2017-amoure_a
** 
** Made by alix amoureux
** Login   <amoure_a@epitech.net>
** 
** Started on  Thu May 30 22:50:31 2013 alix amoureux
** Last update Sat Jun  8 15:31:54 2013 alix amoureux
*/

#include	<math.h>
#include	"../point_h/define.h"
#include	"../point_h/struct.h"
#include	"../point_h/fonction.h"

static int	calc_para3(t_calc *calc, float *k6, t_obj *obj)
{
  float		z;

  z = calc->zcur + (*k6 * calc->vz);
  if (z < obj->min || z > obj->max)
    return (0);
  return (1);
}

static void	calc_trans_para(t_calc *calc, t_my_c *my_c, t_obj *obj)
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
  my_c->a = powf(calc->vx, 2) + powf(calc->vy, 2);
  my_c->b = 2 * ((calc->xcur * calc->vx) + (calc->ycur * calc->vy)) -
    (tanf(RAD * obj->ray) * calc->vz);
  my_c->c = pow(calc->xcur, 2) + pow(calc->ycur, 2)
    - (tanf(obj->ray * RAD) * calc->zcur);
}

static void	calc_para2(t_my_c *my_c, float my_delta, float *k6)
{
  float		k1;
  float		k2;

  k1 = ((-1 * (my_c->b)) + sqrtf(my_delta)) / (2 * my_c->a);
  k2 = ((-1 * (my_c->b)) - sqrtf(my_delta)) / (2 * my_c->a);
  if ((k2 < k1 && k2 > 0) || (k2 > 0 && k1 < 0))
    *k6 = k2;
  else if ((k1 < k2 && k1 > 0) || (k1 > 0 && k2 < 0) || k1 == k2)
    *k6 = k1;
}

static void	change_to_para(t_obj *obj, t_calc *calc,
			       t_coor *coor, float *k6)
{
  coor->blue = obj->b;
  coor->red = obj->r;
  coor->green = obj->g;
  calc->val = *k6;
  coor->shine = obj->bril;
  calc->px = calc->xcur + (*k6 * calc->vx);
  calc->py = calc->ycur + (*k6 * calc->vy);
  calc->pz = calc->zcur + (*k6 * calc->vz);
  coor->nx = calc->px;
  coor->ny = calc->py;
  coor->nz = -1 * (obj->ray * RAD);
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

void		calc_para(t_obj *obj, t_calc *calc, t_coor *coor)
{
  float		my_delta;
  t_my_c	my_c;
  float		k6;

  k6 = -1;
  calc_trans_para(calc, &my_c, obj);
  my_delta = (my_c.b * my_c.b) - (4 * my_c.a * my_c.c);
  if (my_delta == 0)
    k6 = (-1 * (my_c.b)) / (2 * my_c.a);
  else if (my_delta > 0)
    calc_para2(&my_c, my_delta, &k6);
  if ((calc_para3(calc, &k6, obj) == 1) && k6 > 0 && k6 < calc->val)
    change_to_para(obj, calc, coor, &k6);
  replace_point(calc, obj);
}
