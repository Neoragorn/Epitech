/*
** main.c for main in /home/amoure_a/os-home/maths/108monstre
** 
** Made by alix amoureux
** Login   <amoure_a@epitech.net>
** 
** Started on  Sun Mar 17 21:36:49 2013 alix amoureux
** Last update Sun Mar 24 16:51:59 2013 sofian casier
*/

#include	<stdio.h>
#include	<math.h>
#include	<stdlib.h>
#include        <unistd.h>
#include        <fcntl.h>
#include        <sys/mman.h>
#include        <X11/Xlib.h>
#include        <X11/Xutil.h>
#include        <sys/ipc.h>
#include        <sys/shm.h>
#include        <X11/extensions/XShm.h>
#include	"108monstre.h"

int     my_getnbr(char str)
{
  int   nb;

  nb = 0;
  if (str >= '0' && str <= '9')
    {
      nb = (nb * 10) + (str - '0');
    }
  return (nb);
}

int                     gere_expose(void *param)
{
  struct gere_exp       *my_var;

  my_var = param;
  mlx_put_image_to_window(my_var->mlx_ptr,
                          my_var->win_ptr, my_var->img_ptr, 0, 0);
}

int                     gere_key(int keycode, void *param)
{
  if (keycode == 65307)
    exit (0);
}

float          distance(float x1, float x2)
{
  int           d;

  if (x2 > x1)
    d = x2 - x1;
  else
    d = x1 - x2;
  return (d);
}

int		draw_curb_2(float x, float test, char *data)
{
  int           i;

  i = (SIZE_H * 4 * test) + (x * 4);
  data[i + 0] = 255;
  data[i + 1] = 255;
  data[i + 2] = 255;
  data[i + 3] = 255;
}

int		draw_axes(char *data ,struct gere_exp *win)
{
  int		x;
  int		y;
  int		i;
  char		*str;

  x = 100;
  y = 650;
  // mlx_string_put(win->mlx_ptr, win->win_ptr, 200, 200, 0xff0000, "somme");
  while (x < (SIZE_L - 100))
    {
      i = (SIZE_H * 4 * y) + (x * 4);
      data[i + 0] = 255;
      data[i + 1] = 255;
      data[i + 2] = 255;
      data[i + 3] = 255;
      x++;
    }
  x = 100;
  y = 100;
  while (y < SIZE_H - 150)
    {
      i = (SIZE_H * 4 * y) + (x * 4);
      data[i + 0] = 255;
      data[i + 1] = 255;
      data[i + 2] = 255;
      data[i + 3] = 255;
      y++;
    }
}

int             my_pixel_put(float x, float y, char *data)
{
  int           i;

  i = (SIZE_H * y * 4) + (x * 4);
  data[i + 0] = 255;
  data[i + 1] = 255;
  data[i + 2] = 255;
  data[i + 3] = 255;
  return (1);
}

int             draw_line_abs_bigger(float x1, float y1, float x2, float y2, char *data)
{
  int           x;
  int           Y;

  if (x2 >= x1)
    {
      x = x1;
      while (x <= x2)
        {
          x++;
          Y = y1 + ((y2-y1)*(x-x1))/(x2-x1);
          my_pixel_put(x, Y, data);
        }
    }
  if (x1 > x2)
    {
      x = x2;
      while (x <= x1)
        {
          x++;
          Y = y2 + ((y1-y2)*(x-x2))/(x1-x2);
          my_pixel_put(x, Y, data);
        }
    }
}

int             draw_line_ord_bigger(float x1, float y1, float x2, float y2, char *data)
{
  int           x;
  int           y;

  if (y2 >= y1)
    {
      y = y1;
      while (y <= y2)
        {
          y++;
          x = x1 + ((x2-x1)*(y-y1))/(y2-y1);
          my_pixel_put(x, y, data);
        }
    }
  if (y1 > y2)
    {
      y = y2;
      while (y <= y1)
        {
          y++;
          x = x2 + ((x1-x2)*(y-y2))/(y1-y2);
          my_pixel_put(x, y, data);
        }
    }
}

int             draw_line(float x1, float y1, float x2, float y2, char *data)
{
  if (distance(x1, x2) > distance(y1, y2))
    {
      draw_line_abs_bigger(x1, y1, x2, y2, data);
    }
  else
    draw_line_ord_bigger(x1, y1, x2, y2, data);
}

int		draw_curb(float x, float y, float x1, float y1, char *data, struct gere_exp *win)
{
  x += 3;
  x *= 100;
  if (x < 0)
    x = -x;
  y += 3;
  y *= 100;
  if (y < 0)
    y = -y;
  y = SIZE_H - y;
  x1 += 3;
  x1 *= 100;
  if (x1 < 0)
    x1 = -x1;
  y1 += 3;
  y1 *= 100;
  if (y1 < 0)
    y1 = -y1;
  y1 = SIZE_H - y1;
  //  printf("%f %f %f %f\n", x, y, x1, y1);
  //  mlx_string_put(win->mlx_ptr, win->win_ptr, 200, 200, 0xff0000, "somme");
  draw_line(x, y, x1, y1, data);
  draw_axes(data, win);
}

int		fonction(float nb1, double nb2, char *data, struct gere_exp *win)
{
  float		numer;
  float		denom;
  float		result;
  float		y;
  float		x;
  float		*test;
  float		test2;
  int		i;
  int		c;

  c = 0;
  i = 0;
  test = malloc(sizeof(float) * (10000));
  x = -2.0;
  while (x <= 2.0)
    {
      test[0] = 0;
      y = 0.0;
      while (y <= nb2)
	{
	  numer = cosf(pow(nb1, y) * (PI) * (x));
	  denom = pow(2, y);
	  result = numer / denom;
	  test[i] = test[i] + result;
	  y = y + 1.0;
	}
      c++;
      if (c > 2)
	draw_curb(x, test[i], x - 0.1, test[i - 1] , data, win);
      x = x + 0.05;
      i++;
    }
  free(test);
}

int		main(int ac, char **av)
{
  double       	nb1_1;
  double	nb1_2;
  float		nb1;
  double	nb2;
  struct gere_exp  *my_var;
  char		*data;
  int		bit;
  int		line;
  int		endian;

  if (ac == 3)
    {
      if (av[1][1] == '.')
	{
	  if (av[1][0] >= '0' && av[1][0] <= '9' && av[1][2] >= '0' && av[1][2] <= '9')
	    {
	      my_var = malloc(sizeof(struct gere_exp));
	      data = malloc(sizeof(char) * (100000));
	      my_var->mlx_ptr = mlx_init();
	      my_var->img_ptr = mlx_new_image(my_var->mlx_ptr, SIZE_L, SIZE_H);
	      data = mlx_get_data_addr(my_var->img_ptr, &bit, &line, &endian);
	      nb1_1 = atoi(av[1]);
	      nb1_2 = my_getnbr(av[1][2]);
	      nb1 = nb1_1 + (nb1_2/10);
	      nb2 = atoi(av[2]);
	      my_var->win_ptr = mlx_new_window(my_var->mlx_ptr, SIZE_L, SIZE_H, "108monstre");
	      mlx_string_put(my_var->mlx_ptr, my_var->win_ptr, 200, 200, 0xff0000, "soe");
	      fonction(nb1, nb2, data, my_var);
	      mlx_key_hook(my_var->win_ptr, &gere_key, my_var);
	      mlx_put_image_to_window(my_var->mlx_ptr, my_var->win_ptr, my_var->img_ptr, 0, 0);
	      mlx_expose_hook(my_var->win_ptr, &gere_expose, my_var);
	      mlx_loop(my_var->mlx_ptr);
	    }
	}
      else
	printf("The arguments should be like this: 'a.b c'\n");
    }
  else
    printf("The number of arguments isn't good\n");
}
