/*
** main.c for main in /home/casier_s//colle3
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Tue May  7 09:23:24 2013 sofian casier
** Last update Tue May  7 12:01:55 2013 sofian casier
*/

#include <mlx.h>
#include <X11/X.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"

void     my_put_pixel_to_image_black(t_expose *expose, t_image *image, int x, int y)
{
  int   pos;

  pos = (x * image->bpp / 8) + (y * image->sizeline);
  image->data[pos] = 0;
  image->data[pos + 1] = 200;
  image->data[pos + 2] = 10;
}

void     my_put_pixel_to_image(t_expose *expose, t_image *image, int x, int y)
{
  int   pos;

  pos = (x * image->bpp / 8) + (y * image->sizeline);
  image->data[pos] = 254;
  image->data[pos + 1] = 254;
  image->data[pos + 2] = 254;
}

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

int    my_carre(t_expose *expose, t_image *image, int x, int y, char **argv)
{
  int   x1;
  int   y1;

  y1 = x;
  while (y1 < y + atoi(argv[1]))
    {
      x1 = x;
      while (x1 < x + atoi(argv[2]))
        {
          my_put_pixel_to_image(expose, image, x1, y1);
	  x1++;
        }
      y1++;
    }
  return (x1);
}

void	check_carre(t_expose *expose, t_image *image, char **argv)
{
  int	x;
  int	y;
  int	nb_x;
  int	nb_y;

  nb_x = 0;
  nb_y = 0;
  y = 0;
  x = 0;
  while (nb_y < SQUARE_Y)
    {
      x = 0;
      while (nb_x < SQUARE_X)
	{
	  x = my_carre(expose, image, x, y, argv);
	  nb_x++;
	}
      //      x = x + 1;
      y = y + 50;
      nb_y++;
    }
}

int     manage_expose(t_expose *expose)
{
  mlx_put_image_to_window(expose->mlx_ptr, expose->win_ptr, expose->img, 0, 0);
  return (0);
}

int     main(int argc, char **argv)
{
  t_image       image;
  t_expose      expose;

  if (argc == 1)
    {
      my_putstr("nothing to do\n");
      return (1);
    }
  if ((expose.mlx_ptr = mlx_init()) == NULL)
    exit(-1);
  expose.win_ptr = mlx_new_window(expose.mlx_ptr, WIN_X, WIN_Y,
                                  "my fu'cking rtv1");
  expose.img = mlx_new_image(expose.mlx_ptr, WIN_X, WIN_Y);
  image.data = mlx_get_data_addr(expose.img, &image.bpp,
                                 &image.sizeline, &image.endian);
  check_carre(&expose, &image, argv);
  mlx_hook(expose.win_ptr, KeyPress, KeyPressMask, write_arrow, &expose);
  mlx_expose_hook(expose.win_ptr, manage_expose, &expose);
  mlx_loop(expose.mlx_ptr);
  return (0);
}
