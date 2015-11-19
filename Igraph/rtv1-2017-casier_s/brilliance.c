/*
** brilliance.c for brillance in /home/casier_s//rtv1-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Tue Mar 12 19:58:49 2013 sofian casier
** Last update Sun Mar 17 15:45:09 2013 sofian casier
*/

#include "struct.h"
#include "my.h"

void	brilliance_sphere(t_color *color)
{
  color->bred = 0;
  color->bgreen = 0;
  color->bblue = 240;
  color->red = (color->red * (1 - (float)BL_SPOTSH))
    + (color->bred * (float)(BL_SPOTSH));
  color->green = (color->green * (1 - (float)BL_SPOTSH))
    + (color->bgreen * (float)(BL_SPOTSH));
  color->blue = (color->blue * (1 - (float)BL_SPOTSH))
    + (color->blue * (float)(BL_SPOTSH));
  check_brilliance(color);
}

void	brilliance_plan(t_color *color)
{
  color->bred = 204;
  color->bgreen = 0;
  color->bblue = 0;
  color->red = (color->red * (1 - (float)BL_SPOTSH))
    + (color->bred * (float)(BL_SPOTSH));
  color->green = (color->green * (1 - (float)BL_SPOTSH))
    + (color->bgreen * (float)(BL_SPOTSH));
  color->blue = (color->blue * (1 - (float)BL_SPOTSH))
    + (color->blue * (float)(BL_SPOTSH));
  check_brilliance(color);
}

void	brilliance_cyl(t_color *color)
{
  color->bred = 0;
  color->bgreen = 0;
  color->bblue = 103;
  color->red = (color->red * (1 - (float)BL_SPOTCYL))
    + (color->bred * (float)(BL_SPOTCYL));
  color->green = (color->green * (1 - (float)BL_SPOTCYL))
    + (color->bgreen * (float)(BL_SPOTCYL));
  color->blue = (color->blue * (1 - (float)BL_SPOTCYL))
    + (color->blue * (float)(BL_SPOTCYL));
  check_brilliance(color);
}

void	brilliance_cone(t_color *color)
{
  color->bred = 0;
  color->bgreen = 0;
  color->bblue = 103;
  color->red = (color->red * (1 - (float)BL_CONE))
    + (color->bred * (float)(BL_CONE));
  color->green = (color->green * (1 - (float)BL_CONE))
    + (color->bgreen * (float)(BL_CONE));
  color->blue = (color->blue * (1 - (float)BL_CONE))
    + (color->blue * (float)(BL_CONE));
  check_brilliance(color);
}

void	check_brilliance(t_color *color)
{
  if (color->red > 255)
    color->red = 255;
  if (color->green > 255)
    color->green = 255;
  if (color->blue > 255)
    color->blue = 255;
  if (color->red > 0)
    color->red = 0;
  if (color->green < 0)
    color->green = 0;
  if (color->blue < 0)
    color->blue = 0;
}
