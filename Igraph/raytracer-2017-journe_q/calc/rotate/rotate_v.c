/*
** rotate_v.c for rotate_v in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc/rotate
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Sun Jun  2 20:57:59 2013 clement lovergne
** Last update Sun Jun  2 20:58:22 2013 clement lovergne
*/

#include	<math.h>
#include	"../../point_h/fonction.h"

void		rotate_x(t_calc *calc, float ang)
{
  float		myy;
  float		myz;

  ang *= RAD;
  myy = calc->vy;
  myz = calc->vz;
  calc->vy = (cosf(ang) * myy) + (-1 * sinf(ang) * myz);
  calc->vz = (sinf(ang) * myy) + (cosf(ang) * myz);
}

void		rotate_y(t_calc *calc, float ang)
{
  float		myx;
  float		myz;

  ang *= RAD;
  myx = calc->vx;
  myz = calc->vz;
  calc->vx = (cosf(ang) * myx) + (sinf(ang) * myz);
  calc->vz = (-1 * sinf(ang) * myx) + (cosf(ang) * myz);
}

void		rotate_z(t_calc *calc, float ang)
{
  float		myx;
  float		myy;

  ang *= RAD;
  myx = calc->vx;
  myy = calc->vy;
  calc->vx = (cosf(ang) * myx) + (-1 * sinf(ang) * myy);
  calc->vy = (sinf(ang) * myx) + (cosf(ang) * myy);
}
