/*
** light2.c for light2 in /home/casier_s//rtv1-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Mar 14 19:06:08 2013 sofian casier
** Last update Thu Mar 14 19:07:47 2013 sofian casier
*/

#include <math.h>
#include "my.h"

void    check_color(t_color *color)
{
  if (color->red > 255)
    color->red = 255;
  if (color->red < 0 )
    color->red = 0;
  if (color->green > 255)
    color->green = 255;
  if (color->green < 0 )
    color->green = 0;
  if (color->blue > 255)
    color->blue = 255;
  if (color->blue < 0 )
    color->blue = 0;
}

void    inter_light(t_interlight *interlight, t_color *color)
{
  float total;
  float N;
  float L;
  float cosalpha;

  interlight->lx = LX_SPOT - interlight->px;
  interlight->ly = LY_SPOT - interlight->py;
  interlight->lz = LZ_SPOT - interlight->pz;
  total = interlight->nx * interlight->lx + interlight->ly * interlight->ny
    + interlight->nz * interlight->nz;
  N = powf(interlight->nx, 2) +  powf(interlight->ny, 2)
    + powf(interlight->nz, 2);
  L = powf(interlight->lx, 2) +  powf(interlight->ly, 2)
    + powf(interlight->lz, 2);
  N = sqrtf(N);
  L = sqrtf(L);
  cosalpha = total / (N * L);
  color->red = color->red * cosalpha;
  color->green = color->green * cosalpha;
  color->blue = color->blue * cosalpha;
  check_color(color);
}
