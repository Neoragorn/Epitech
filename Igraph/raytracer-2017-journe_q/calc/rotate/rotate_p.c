/*
** rotate_p.c for rotate_p in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc/rotate
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Sun Jun  2 20:59:39 2013 clement lovergne
** Last update Sun Jun  2 21:00:03 2013 clement lovergne
*/

#include	<math.h>
#include	"../../point_h/fonction.h"

void		rotate_xp(t_calc *calc, float ang)
{
  float		myy;
  float		myz;

  ang *= RAD;
  myy = calc->py;
  myz = calc->pz;
  calc->py = (cosf(ang) * myy) + (-1 * sinf(ang) * myz);
  calc->pz = (sinf(ang) * myy) + (cosf(ang) * myz);
}

void		rotate_yp(t_calc *calc, float ang)
{
  float		myx;
  float		myz;

  ang *= RAD;
  myx = calc->px;
  myz = calc->pz;
  calc->px = (cosf(ang) * myx) + (sinf(ang) * myz);
  calc->pz = (-1 * sinf(ang) * myx) + (cosf(ang) * myz);
}

void		rotate_zp(t_calc *calc, float ang)
{
  float		myx;
  float		myy;

  ang *= RAD;
  myx = calc->px;
  myy = calc->py;
  calc->px = (cosf(ang) * myx) + (-1 * sinf(ang) * myy);
  calc->py = (sinf(ang) * myx) + (cosf(ang) * myy);
}
