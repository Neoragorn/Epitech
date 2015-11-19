/*
** shadow.c for shadow in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Sat May 25 15:51:24 2013 clement lovergne
** Last update Fri Jun  7 17:10:31 2013 clement lovergne
*/

#include	<math.h>
#include	"../../point_h/fonction.h"

void		calc_my_shadow(t_obj **obj, t_calc *calc,
			       t_tmp_col *col, t_obj *actu)
{
  t_obj		*elem;

  elem = *obj;
  while (elem != NULL)
    {
      if (elem != actu)
	{
	  if (elem->type == SPHERE)
	    calc_sha_sph(elem, calc, col);
	  else if (elem->type == PLAN)
	    calc_sha_plan(elem, calc, col);
	  else if (elem->type == CYLINDRE)
	    calc_sha_cyl(elem, calc, col);
	  else if (elem->type == CONE)
	    calc_sha_cone(elem, calc, col);
	  else if (elem->type == PARA)
	    calc_sha_para(elem, calc, col);
	}
      elem = elem->next;
    }
}
