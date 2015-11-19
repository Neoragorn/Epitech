/*
** color.c for color in /home/casier_s//rtv1-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Tue Mar 12 18:47:00 2013 sofian casier
** Last update Mon Jun  3 16:50:29 2013 sofian casier
*/

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

void	color_sphere(t_interlight *interlight,
		     t_sphere *sphere, t_color *color)
{
  color->red = 0;
  color->green = 0;
  color->blue = 53;
  inter_light_sphere(sphere, interlight, color);
}

void	color_plane(t_interlight *interlight, t_sphere *sphere, t_color *color)
{
  color->red = 2;
  color->green = 45;
  color->blue = 153;
  inter_light_plan(sphere, interlight, color);
}

void	color_cyl(t_interlight *interlight, t_cyl *cyl, t_color *color)
{
  color->red = 0;
  color->green = 145;
  color->blue = 0;
  inter_light_cyl(cyl, interlight, color);
}

void	color_cone(t_interlight *interlight, t_sphere *sphere, t_color *color)
{
  color->red = 130;
  color->green = 32;
  color->blue = 10;
  inter_light_cone(sphere, interlight, color);
}

void	color_paral(t_interlight *interlight, t_sphere *sphere, t_color *color, t_paral *paral)
{
  color->red = 200;
  color->green = 45;
  color->blue = 0;
}

void	color_void(t_color *color)
{
  color->red = 25;
  color->green = 0;
  color->blue = 0;
}
