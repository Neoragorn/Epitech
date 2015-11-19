/*
** main.c for mùain in /home/casier_s//bombyx
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Mon Feb 18 14:58:21 2013 sofian casier
** Last update Sun Feb 24 17:15:37 2013 sofian casier
*/

#include <mlx.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int     write_arrow(int keycode, void *param)
{
  param = 0;
  if (keycode == 65307)
    exit(1);
  return (1);
}

int     color_line1(t_image *image, t_expose *expose, int x, int y, int pos)
{
  image->data[pos] = 50;
  image->data[pos + 1] = 100;
  image->data[pos + 2] = 253;
  image->data[pos + 3] = 0;
}

int     fill_image(t_image *image, t_expose *expose, int x, int y)
{
  int           pos;
  int           color;

  pos = (x * (image->bpp / 8)) + (y * image->sizeline);
  color_line1(image, expose, x, y, pos);
}

int	option_1(char **argv, t_image *image, t_expose *expose)
{
  int	i;
  float	t;
  float y1;
  float k;
  int	count;
  float r;

  count = 0;
  t = 0;
  i = 1;
  r = 10;
  k = atof(argv[1]);
  if (k > 4 || k < 1)
    {
      printf("Choose between 1 & 4");
      exit (1);
    }
  while (i <= 100)
    {
      y1 = r;
      r = (k * y1) * ((1000 - y1) / 1000);
      t = t + (1920 / 100);
      printf(" y1 = %f   r = %f t = %f t modif = %f\n", y1, r, t, t + (1920/100));
      r = (int)(r);
      y1 = (int)(r);
      fill_image(image, expose, t, 1080 - r);
      if ((t + (1920 / 100)) - t >= (r - y1) && r - y1 > 0)
	draw_line(t, t + (1920/100), y1, r, expose, image);
      else if (t + (1920 / 100) - t <= (r - y1) && t - (1920 / 100 - y1))
	draw_line2(t, t + (1920/100), y1, r, expose, image);
      i++;
      count++;
    }
}

int	option_2(char **argv, t_image *image, t_expose *expose)
{

  int	imin;
  int	imax;
  float	k;
  float	y1;
  float	t;
  float	r;
  int	i;
  int	stock;

  i = 1;
  imin = atoi(argv[1]);
  imax = atoi(argv[2]);
  if (imin < 1 || imax < 1)
    {
      printf("Choose a number higher than 1\n");
      exit (1);
    }
  if (imax < imin)
    {
      printf("the second argument must be higher than the first one\n");
      exit (1);
    }
  if (atof(argv[1]) != atoi(argv[1]) || atof(argv[2]) != atoi(argv[2]))
    {
      printf("Choose a real number ! \n");
      exit (1);
    }
  k = 1;
  y1 = 10;
  while (k <= 4.000)
    {
      while (i <= atoi(argv[2]))
	{
	  while (i < atoi(argv[1]))
	    {
	      y1 = (k * y1) * ((1000 - y1) / 1000);
	      i++;
	    }
	  stock = (int)(y1);
	  printf(" y1 = %f %d  %f\n", y1, i , k);
	  fill_image(image, expose, k * (1920 / 3.04) - (1920 / 3.1), 1080 - stock);
	  y1 = (k * y1) * ((1000 - y1) / 1000);
	  i++;
	}
      i = 1;
      k = k + 0.01;
    }
}


int     manage_expose(t_expose *expose)
{
  mlx_put_image_to_window(expose->mlx_ptr, expose->win_ptr, expose->img, 0, 0);
}

int     main(int argc, char **argv, char **env)
{
  t_image       image;
  t_expose      expose;

  if (argc == 1)
    {
      printf("Choose a number\n");
      exit (1);
    }
  if (argc > 3)
    {
      printf("Too many arguments\n");
      exit(1);
    }
  if (WIN_Y != 1080 && WIN_X != 1920)
    return (-1);
  if ((expose.mlx_ptr = mlx_init()) == NULL)
    exit(-1);
  expose.win_ptr = mlx_new_window(expose.mlx_ptr, WIN_X, WIN_Y,"my fu'cking tp rtv1");
  expose.img = mlx_new_image(expose.mlx_ptr, WIN_X, WIN_Y);
  image.data = mlx_get_data_addr(expose.img, &image.bpp,
                                 &image.sizeline, &image.endian);
  draw_Vaxe(&expose, &image);
  draw_Haxe(&expose, &image);
  if (argc == 2)
    option_1(argv, &image, &expose);
  else if (argc == 3)
    option_2(argv, &image, &expose);
  mlx_key_hook(expose.win_ptr, write_arrow, 0);
  mlx_expose_hook(expose.win_ptr, manage_expose, &expose);
  mlx_loop(expose.mlx_ptr);
}
