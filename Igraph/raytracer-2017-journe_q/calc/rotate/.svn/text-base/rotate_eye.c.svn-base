/*
** rotate_eye.c for rotate_eye in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon May  6 19:47:10 2013 clement lovergne
** Last update Thu Jun  6 11:23:58 2013 clement lovergne
*/

#include	<math.h>
#include	"../../point_h/fonction.h"

void		rotate_x(float *x, float *y, float *z, float ang)
{
  float		myy;
  float		myz;

  (void) *x;
  ang *= RAD;
  myy = *y;
  myz = *z;
  *y = (cosf(ang) * myy) + (-1 * sinf(ang) * myz);
  *z = (sinf(ang) * myy) + (cosf(ang) * myz);
}

void		rotate_y(float *x, float *y, float *z, float ang)
{
  float		myx;
  float		myz;

  (void) *y;
  ang *= RAD;
  myx = *x;
  myz = *z;
  *x = (cosf(ang) * myx) + (sinf(ang) * myz);
  *z = (-1 * sinf(ang) * myx) + (cosf(ang) * myz);
}

void		rotate_z(float *x, float *y, float *z, float ang)
{
  float		myx;
  float		myy;

  (void) *z;
  ang *= RAD;
  myx = *x;
  myy = *y;
  *x = (cosf(ang) * myx) + (-1 * sinf(ang) * myy);
  *y = (sinf(ang) * myx) + (cosf(ang) * myy);
}
