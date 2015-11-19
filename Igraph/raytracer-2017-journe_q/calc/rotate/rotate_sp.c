/*
** rotate_sp.c for rotate_sp in /home/loverg_c//raytracer/raytracer-2017-journe_q
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Wed Jun  5 13:46:18 2013 clement lovergne
** Last update Wed Jun  5 14:08:52 2013 clement lovergne
*/

#include	<math.h>
#include	"../../point_h/fonction.h"

void		rotate_spx(t_obj *obj, float ang)
{
  float		myy;
  float		myz;

  ang *= RAD;
  myy = obj->y;
  myz = obj->z;
  obj->y = (cosf(ang) * myy) + (-1 * sinf(ang) * myz);
  obj->z = (sinf(ang) * myy) + (cosf(ang) * myz);
}

void		rotate_spy(t_obj *obj, float ang)
{
  float		myx;
  float		myz;

  ang *= RAD;
  myx = obj->x;
  myz = obj->z;
  obj->x = (cosf(ang) * myx) + (sinf(ang) * myz);
  obj->z = (-1 * sinf(ang) * myx) + (cosf(ang) * myz);
}

void		rotate_spz(t_obj *obj, float ang)
{
  float		myx;
  float		myy;

  ang *= RAD;
  myx = obj->x;
  myy = obj->y;
  obj->x = (cosf(ang) * myx) + (-1 * sinf(ang) * myy);
  obj->y = (sinf(ang) * myx) + (cosf(ang) * myy);
}
