/*
** main.c for main.c in /home/amoure_a//raytracer-2017-journe_q
** 
** Made by alix amoureux
** Login   <amoure_a@epitech.net>
** 
** Started on  Mon May 13 17:20:06 2013 alix amoureux
** Last update Sat Jun  8 16:42:10 2013 sofian casier
*/

#include	<pthread.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<mlx.h>
#include	<X11/X.h>
#include	<math.h>
#include	"./point_h/fonction.h"

static int	my_expose(t_coor *coor)
{
  mlx_put_image_to_window(coor->mlx_ptr, coor->win_ptr, coor->img_ptr, 0, 0);
  return (0);
}

static int	my_keyboard(int keycode, t_coor *coor)
{
  if (keycode == 65307)
    {
      mlx_destroy_window(coor->mlx_ptr, coor->win_ptr);
      exit(1);
    }
  mlx_put_image_to_window(coor->mlx_ptr, coor->win_ptr, coor->img_ptr, 0, 0);
  return (0);
}

static int	nb_spot(t_obj **obj)
{
  t_obj		*elem;
  int		i;

  i = 0;
  elem = *obj;
  while (elem != NULL)
    {
      if (elem->type == SPOT)
	i++;
      elem = elem->next;
    }
  return (i);
}

static void		raytracer(t_coor coor, char **argv, int argc)
{
  t_obj			*obj;

  obj = NULL;
  nex(argv, &obj);
  if (nb_spot(&obj) == 0)
    error_message("There is no Spot !\n");
  if ((coor.mlx_ptr = mlx_init()) == NULL)
    error_message("Error in mlx_init ! \n");
  coor.win_ptr = mlx_new_window(coor.mlx_ptr,
				WIN_X, WIN_Y, "Raytracer");
  coor.img_ptr = mlx_new_image(coor.mlx_ptr, WIN_X, WIN_Y);
  if (argc >= 3)
    thread(&obj, coor, argv[2]);
  else
    my_pix_by_pix(&coor, &obj);
  mlx_hook(coor.win_ptr, KeyPress, KeyPressMask, my_keyboard, &coor);
  mlx_expose_hook(coor.win_ptr, my_expose, &coor);
  mlx_loop(coor.mlx_ptr);
}

int		main(int argc, char **argv)
{
  t_coor	coor;

  if (argv[2] && argv[3])
    check_bmp(&coor, argv);
  else
    coor.bmp = 0;
  if (argc == 2 || argc == 3 || argc == 4)
    raytracer(coor, argv, argc);
  else
    my_putstr("Put a config file in argument and read the README\n");
  return (0);
}
