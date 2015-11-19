/*
** light.c for light in /home/casier_s//tprtv1
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Mon Mar 11 17:12:14 2013 sofian casier
** Last update Sun Mar 17 15:45:56 2013 sofian casier
*/

#include <mlx.h>
#include <math.h>
#include "my.h"
#include "struct.h"

void	inter_light_plan(t_sphere *sphere, t_interlight *interlight,
			 t_color *color)
{
  interlight->px = X_O + (sphere->kplan * sphere->x1);
  interlight->py = Y_O + (sphere->kplan * sphere->y1);
  interlight->pz = Z_O + (sphere->kplan * sphere->z1);
  interlight->nx = 0;
  interlight->ny = 0;
  interlight->nz = 100;
  brilliance_plan(color);
  inter_light(interlight, color);
}

void	inter_light_sphere(t_sphere *sphere, t_interlight *interlight,
			   t_color *color)
{
  interlight->px = X_O + (sphere->ksphere * sphere->x1);
  interlight->py = Y_O + (sphere->ksphere * sphere->y1);
  interlight->pz = Z_O + (sphere->ksphere * sphere->z1);
  interlight->nx = interlight->px;
  interlight->ny = interlight->py;
  interlight->nz = interlight->pz;
  brilliance_sphere(color);
  inter_light(interlight, color);
}

void	inter_light_cone(t_sphere *sphere, t_interlight *interlight,
			 t_color *color)
{
  interlight->px = X_O + (sphere->kcone * sphere->x1);
  interlight->py = Y_O + (sphere->kcone * sphere->y1);
  interlight->pz = Z_O + (sphere->kcone * sphere->z1);
  interlight->nx = interlight->px;
  interlight->ny = interlight->py;
  interlight->nz = interlight->pz;
  brilliance_cone(color);
  inter_light(interlight, color);
}

void	inter_light_cyl(t_cyl *cyl, t_interlight *interlight,
			t_color *color)
{
  interlight->px = X_O + (cyl->kcyl * cyl->x1);
  interlight->py = Y_O + (cyl->kcyl * cyl->y1);
  interlight->nx = interlight->px;
  interlight->ny = interlight->py;
  brilliance_cyl(color);
  inter_light_color(interlight, color);
}

void	inter_light_color(t_interlight *interlight, t_color *color)
{
  float total;
  float	n;
  float	l;
  float cosalpha;

  interlight->lx = LX_SPOT - interlight->px;
  interlight->ly = LY_SPOT - interlight->py;
  total = interlight->nx * interlight->lx + interlight->ly
    * interlight->ny;
  n = powf(interlight->nx, 2) +  powf(interlight->ny, 2)
    + powf(interlight->nz, 2);
  l = powf(interlight->lx, 2) +  powf(interlight->ly, 2)
    + powf(interlight->lz, 2);
  n = sqrtf(n);
  l = sqrtf(l);
  cosalpha = total / (n * l);
  color->red = color->red * cosalpha;
  color->green = color->green * cosalpha;
  color->blue = color->blue * cosalpha;
  check_color(color);
}
