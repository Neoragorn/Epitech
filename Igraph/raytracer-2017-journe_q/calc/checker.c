/*
** checker.c for checker in /home/koszycl/raytracer-2017-journe_q
** 
** Made by laurent koszyczek
** Login   <koszyc_l@epitech.net>
** 
** Started on  Wed May 29 11:51:08 2013 laurent koszyczek
** Last update Sat Jun  8 15:07:28 2013 quentin journet
*/

#include	<math.h>
#include	"../point_h/struct.h"

void		set_color(t_coor *coor, int r, int g, int b)
{
  coor->blue = b;
  coor->red = r;
  coor->green = g;
}

int		is_odd_or_even(t_calc *calc, int l)
{
  if (((int) round(calc->px / l) % 2 == 0 &&
       (int) round(calc->py / l) % 2 == 0) ||
      ((int) round(calc->px / l) % 2 == 1 &&
       (int) round(calc->px / l )% 2 == 1))
    return (1);
  return (0);
}

void		pz_odd(t_calc *calc, t_obj *obj, int l, t_coor *coor)
{
  if (is_odd_or_even(calc, l))
    {
      if ((int)round(calc->py / l) % 2 == 0)
	{
	  if ((int) round(calc->px / l) % 2 == 0)
	    set_color(coor, obj->r, obj->g, obj->b);
	  else
	    set_color(coor, 0, 0, 0);
	}
      else
	set_color(coor, obj->r, obj->g, obj->b);
    }
  else
    {
      if ((int)round(calc->px / l) % 2 == 0)
	set_color(coor, 0, 0, 0);
      else if ((int) round(calc->py / l) % 2 == 0)
	set_color(coor, 0, 0, 0);
      else
	set_color(coor, obj->r, obj->g, obj->b);
    }
}

void		pz_even(t_calc *calc, t_obj *obj, int l, t_coor *coor)
{
  if (is_odd_or_even(calc, l))
    {
      if ((int)round(calc->px / l) % 2 == 0)
	set_color(coor, 0, 0, 0);
      else if ((int)round(calc->py / l) % 2 == 0)
	set_color(coor, obj->r, obj->g, obj->b);
      else
	set_color(coor, 0, 0, 0);
    }
  else
    {
      if (! (int)round(calc->py / l) % 2 == 0
	  && (int)round(calc->px / l) % 2 == 0)
	{
	  if ((int)round(calc->px / l) % 2 == 0)
	    set_color(coor, obj->r, obj->g, obj->b);
	  else
	    set_color(coor, 200, 0, 0);
	}
      else if (((int) round(calc->py / l) % 2) == 0)
	set_color(coor, obj->r, obj->g, obj->b);
      else
	set_color(coor, 0, 0, 0);
    }
}

void		set_checker(t_coor *coor, t_obj *obj, t_calc *calc)
{
  int		l;

  if (obj->chess == 1)
    l = 30;
  else
    l = 0;
  if (((int)round(calc->pz / l) % 2) == 0)
    pz_odd(calc, obj, l, coor);
  else
    pz_even(calc, obj, l, coor);
}
