/*
** rotation.c for rotation in /home/casier_s//tprtv1
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Mon Mar 11 16:03:48 2013 sofian casier
** Last update Sun Mar 17 15:46:14 2013 sofian casier
*/

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "struct.h"

void	rotation_x(t_sphere *sphere, float angle)
{
  float newy1;
  float	newz1;

  angle = angle * RAD;
  newy1 = sphere->y1;
  newz1 = sphere->z1;
  sphere->y1 = ((cosf(angle) * newy1) - (sinf(angle) * newz1));
  sphere->z1 = ((sinf(angle) * newy1) + (cosf(angle) * newz1));
}

void	rotation_y(t_sphere *sphere, float angle)
{
  float newx1;
  float	newz1;

  angle = angle * RAD;
  newx1 = sphere->x1;
  newz1 = sphere->z1;
  sphere->x1 = ((cosf(angle) * newx1) + (sinf(angle) * newz1));
  sphere->z1 = (-(sinf(angle) * newx1) + (cosf(angle) * newz1) );
}

void	rotation_z(t_sphere *sphere, float angle)
{
  float newx1;
  float	newy1;

  angle = angle * RAD;
  newx1 = sphere->x1;
  newy1 = sphere->y1;
  sphere->x1 = ((cosf(angle) * newx1) - (sinf(angle) * newy1));
  sphere->y1 = ((sinf(angle) * newx1) + (cosf(angle) * newy1));
}
