/*
** findcolor.c for findcolor in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Sun Jun  2 20:52:29 2013 clement lovergne
** Last update Sat Jun  8 16:35:49 2013 quentin journet
*/

#include	<math.h>
#include	"../point_h/fonction.h"

void		check_max_col(int *red, int *green, int *blue)
{
  if (*red > 255)
    *red = 255;
  if (*blue > 255)
    *blue = 255;
  if (*green > 255)
    *green = 255;
  if (*red < 0)
    *red = 0;
  if (*blue < 0)
    *blue = 0;
  if (*green < 0)
    *green = 0;
}

static int	color_luxshadow(t_coor *coor, t_tmp_col *col,
				t_calc *calc, t_obj **obj, t_obj *actu)
{
  t_obj		*elem;
  int		i;

  i = 0;
  elem = *obj;
  while (elem != NULL)
    {
      if (elem->type == SPOT)
	{
	  i++;
	  col->tred = 0;
	  col->tgreen = 0;
	  col->tblue = 0;
	  calc_shine(elem, calc, coor, col);
	  calc_my_shadow(obj, calc, col, actu);
	  col->fred += col->tred;
	  col->fgreen += col->tgreen;
	  col->fblue += col->tblue;
	}
      elem = elem->next;
    }
  return (i);
}

void		my_check_spot(t_calc *calc, t_coor *coor, t_obj **obj, t_obj *actu)
{
  t_tmp_col	col;
  int		i;

  col.fred = coor->red;
  col.fgreen = coor->green;
  col.fblue = coor->blue;
  col.shadow = 1;
  i = color_luxshadow(coor, &col, calc, obj, actu);
  coor->blue = (col.fblue / i) * col.shadow;
  coor->green = (col.fgreen / i) * col.shadow;
  coor->red = (col.fred / i) * col.shadow;
  check_max_col(&coor->red, &coor->green, &coor->blue);
}

void		my_check_obj(t_calc *calc, t_coor *coor, t_obj **obj)
{
  t_obj		*elem;

  coor->blue = 0;
  coor->red = 0;
  coor->green = 0;
  calc->val = 30000000;
  elem = *obj;
  while (elem != NULL)
    {
      if (elem->type == SPHERE)
	calc_sphere(elem, calc, coor);
      else if (elem->type == CYLINDRE)
	calc_cylindre(elem, calc, coor);
      else if (elem->type == CONE)
	calc_cone(elem, calc, coor);
      else if (elem->type == PLAN)
	calc_plan(elem, calc, coor);
      else if (elem->type == PARA)
	calc_para(elem, calc, coor);
      if (calc->val != 30000000)
	my_check_spot(calc, coor, obj, elem);
      elem = elem->next;
    }
}
