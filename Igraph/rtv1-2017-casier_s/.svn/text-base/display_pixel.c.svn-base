/*
** pixel_image.c for pixel_image in /home/casier_s//tprtv1
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Mon Mar 11 16:49:59 2013 sofian casier
** Last update Thu Mar 14 19:03:12 2013 sofian casier
*/

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int     write_arrow(int keycode, t_expose *expose)
{
  if (keycode == 65362)
    my_putstr("fleche du haut\n");
  else if (keycode == 65364)
    my_putstr("fleche du bas\n");
  else if (keycode == 65363)
    my_putstr("fleche du droite\n");
  else if (keycode == 65361)
    my_putstr("fleche du gauche\n");
  else if (keycode == 65307)
    {
      mlx_destroy_window(expose->mlx_ptr, expose->win_ptr);
      exit(1);
    }
  return (1);
}

void     color_pixel(t_image *image, t_color *color, t_expose *expose)
{
  int	pos;

  pos = (expose->x * (image->bpp / 8)) + (expose->y * image->sizeline);
  image->data[pos] = color-> blue;
  image->data[pos + 1] = color->green;
  image->data[pos + 2] = color->red;
}

void     fill_image(t_image *image, t_expose *expose,
		   t_interlight *interlight, t_sphere *sphere)
{
  t_color color;

  calc(expose, sphere, interlight, &color);
  color_pixel(image, &color, expose);
}

void    draw_line(t_image *image, t_expose *expose)
{
  t_sphere	sphere;
  t_interlight	interlight;

  expose->x = 0;
  while (expose->x <= WIN_X)
    {
      expose->y = 0;
      while (expose->y <= WIN_Y)
        {
          fill_image(image, expose, &interlight, &sphere);
          expose->y++;
        }
      expose->x++;
    }
}

int     manage_expose(t_expose *expose)
{
  mlx_put_image_to_window(expose->mlx_ptr, expose->win_ptr, expose->img, 0, 0);
  return (0);
}
