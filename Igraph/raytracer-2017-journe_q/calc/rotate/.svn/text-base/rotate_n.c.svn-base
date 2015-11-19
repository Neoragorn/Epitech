/*
** rotate_n.c for rotate_n in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc/rotate
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Sun Jun  2 20:58:56 2013 clement lovergne
** Last update Sun Jun  2 20:59:18 2013 clement lovergne
*/

#include	<math.h>
#include	"../../point_h/fonction.h"

void		rotate_nx(t_coor *coor, float ang)
{
  float		myy;
  float		myz;

  ang *= RAD;
  myy = coor->ny;
  myz = coor->nz;
  coor->ny = (cosf(ang) * myy) + (-1 * sinf(ang) * myz);
  coor->nz = (sinf(ang) * myy) + (cosf(ang) * myz);
}

void		rotate_ny(t_coor *coor, float ang)
{
  float		myx;
  float		myz;

  ang *= RAD;
  myx = coor->nx;
  myz = coor->nz;
  coor->nx = (cosf(ang) * myx) + (sinf(ang) * myz);
  coor->nz = (-1 * sinf(ang) * myx) + (cosf(ang) * myz);
}

void		rotate_nz(t_coor *coor, float ang)
{
  float		myx;
  float		myy;

  ang *= RAD;
  myx = coor->nx;
  myy = coor->ny;
  coor->nx = (cosf(ang) * myx) + (-1 * sinf(ang) * myy);
  coor->ny = (sinf(ang) * myx) + (cosf(ang) * myy);
}
