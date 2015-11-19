/*
** rotationcone.c for rotation in /home/casier_s//rtv1-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sun Mar 17 14:51:43 2013 sofian casier
** Last update Sun Mar 17 14:53:24 2013 sofian casier
*/

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void    rotationcyl_x(t_cyl *cyl, float angle)
{
  float newy1;
  float newz1;

  angle = angle * RAD;
  newy1 = cyl->y1;
  newz1 = cyl->z1;
  cyl->y1 = ((cosf(angle) * newy1) - (sinf(angle) * newz1));
  cyl->z1 = ((sinf(angle) * newy1) + (cosf(angle) * newz1));
}

void    rotationcyl_y(t_cyl *cyl, float angle)
{
  float newx1;
  float newz1;

  angle = angle * RAD;
  newx1 = cyl->x1;
  newz1 = cyl->z1;
  cyl->x1 = ((cosf(angle) * newx1) + (sinf(angle) * newz1));
  cyl->z1 = (-(sinf(angle) * newx1) + (cosf(angle) * newz1) );
}

void    rotationcyl_z(t_cyl *cyl, float angle)
{
  float newx1;
  float newy1;

  angle = angle * RAD;
  newx1 = cyl->x1;
  newy1 = cyl->y1;
  cyl->x1 = ((cosf(angle) * newx1) - (sinf(angle) * newy1));
  cyl->y1 = ((sinf(angle) * newx1) + (cosf(angle) * newy1));
}
