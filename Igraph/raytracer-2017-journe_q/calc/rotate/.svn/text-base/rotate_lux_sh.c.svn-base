/*
** rotate_lux_sh.c for rotate_lux_sha in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc/shadow
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Sat May 25 17:18:03 2013 clement lovergne
** Last update Tue May 28 16:25:00 2013 clement lovergne
*/

#include	<math.h>
#include	"../../point_h/fonction.h"

void		rotate_x_l(t_calc *calc, float ang)
{
  float		myy;
  float		myz;

  ang *= RAD;
  myy = calc->ly;
  myz = calc->lz;
  calc->ly = (cosf(ang) * myy) + (-1 * sinf(ang) * myz);
  calc->lz = (sinf(ang) * myy) + (cosf(ang) * myz);
}

void		rotate_y_l(t_calc *calc, float ang)
{
  float		myx;
  float		myz;

  ang *= RAD;
  myx = calc->lx;
  myz = calc->lz;
  calc->lx = (cosf(ang) * myx) + (sinf(ang) * myz);
  calc->lz = (-1 * sinf(ang) * myx) + (cosf(ang) * myz);
}

void		rotate_z_l(t_calc *calc, float ang)
{
  float		myx;
  float		myy;

  ang *= RAD;
  myx = calc->lx;
  myy = calc->ly;
  calc->lx = (cosf(ang) * myx) + (-1 * sinf(ang) * myy);
  calc->ly = (sinf(ang) * myx) + (cosf(ang) * myy);
}
