/*
** lux1.c for lux in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Sat May 25 13:32:15 2013 clement lovergne
** Last update Fri Jun  7 17:08:42 2013 clement lovergne
*/

#include	<math.h>
#include	"../point_h/fonction.h"

static float	calc_cos_l(t_coor *coor, t_calc *calc)
{
  float		cos;
  float		bign;
  float		bigl;
  float		tot;

  bign  = powf(coor->nx, 2) + powf(coor->ny, 2) + powf(coor->nz, 2);
  bigl = powf(calc->lx, 2) + powf(calc->ly, 2) + powf(calc->lz, 2);
  bign = sqrtf(bign);
  bigl = sqrtf(bigl);
  tot = (calc->lx * coor->nx) + (calc->ly * coor->ny) + (calc->lz * coor->nz);
  cos = (tot / (bign * bigl));
  return (cos);
}

void		calc_shine(t_obj *obj, t_calc *calc, t_coor *coor, t_tmp_col *col)
{
  float		cos;
  float		n_shine;

  calc->lx = obj->x - calc->px;
  calc->ly = obj->y - calc->py;
  calc->lz = obj->z - calc->pz;
  cos = calc_cos_l(coor, calc);
  n_shine = 1 - coor->shine;
  col->tred = (coor->red * n_shine) + (coor->shine * obj->r);
  col->tgreen = (coor->green * n_shine) + (coor->shine * obj->g);
  col->tblue = (coor->blue * n_shine) + (coor->shine * obj->b);
  check_max_col(&col->tred, &col->tgreen, &col->tblue);
  if (cos < 0)
    cos = 0;
  col->tred *= cos;
  col->tgreen *= cos;
  col->tblue *= cos;
  check_max_col(&col->tred, &col->tgreen, &col->tblue);
}
