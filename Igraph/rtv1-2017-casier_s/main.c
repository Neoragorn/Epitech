/*
** main.c for main in /home/casier_s//tprtv1
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Tue Feb  5 09:45:06 2013 sofian casier
** Last update Fri Jun  7 11:26:48 2013 sofian casier
*/

#include <mlx.h>
#include <X11/X.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "struct.h"
#include "my.h"

void	coord(t_sphere *sphere, int x, int y, t_cyl *cyl)
{
  sphere->x1 = (X_1);
  sphere->y1 = (float)(WIN_X / 2) - (float)x;
  sphere->z1 = (float)(WIN_Y / 2) - (float)y;
  sphere->xo = X_O;
  sphere->yo = Y_O;
  sphere->zo = Z_O;
  cyl->x1 = (X_1);
  cyl->y1 = (float)(WIN_X / 2) - (float)x;
  cyl->z1 = (float)(WIN_Y / 2) - (float)y;
  cyl->xo = X_O;
  cyl->yo = Y_O;
  cyl->zo = Z_O;
}

void	check_inter_follow(t_interlight *interlight, t_sphere *sphere,
			   t_color *color, t_cyl *cyl, t_paral *paral)
{
  if ((sphere->ip <= sphere->cs || sphere->ip <= sphere->cc
       || sphere->ip <= sphere->cco) && sphere->ip != 0)
    color_plane(interlight, sphere, color);
  else if ((sphere->cs <= sphere->ip || sphere->cs <= sphere->cc
	    || sphere->cs <= sphere->cco) && sphere->cs != 0)
    color_sphere(interlight, sphere, color);
  else if ((sphere->cc <= sphere->ip && sphere->cc <= sphere->cs)
	   || (sphere->cc <= sphere->cco && sphere->cc != 0))
    color_cyl(interlight, cyl, color);
  else if ((sphere->cco <= sphere->ip || sphere->cco <= sphere->cc
	    || sphere->cco <= sphere->cs) && sphere->cco != 0)
    color_cone(interlight, sphere, color);
  else if (paral->cp != 0)
    color_paral(interlight, sphere, color, paral);
}

void	check_inter(t_interlight *interlight, t_sphere *sphere,
		    t_color *color, t_cyl *cyl, t_paral *paral)
{
  if (sphere->ip != 0 && sphere->cs == 0
      && sphere->cc == 0 && sphere->cco == 0)
    color_plane(interlight, sphere, color);
  else if (sphere->cs != 0 && sphere->ip == 0 && sphere->cc == 0 &&
	   sphere->cco == 0)
    color_sphere(interlight, sphere, color);
  else if (sphere->cc != 0 && sphere->ip == 0 && sphere->cs == 0 &&
	   sphere->cco == 0)
    color_cyl(interlight, cyl, color);
  else if (sphere->cco != 0 && sphere->cc == 0 && sphere->cs == 0 &&
	   sphere->ip == 0)
    color_cone(interlight, sphere, color);
  else if (sphere->cs != 0 || sphere->cc != 0 ||
	   sphere->ip != 0 || sphere->cco != 0)
    check_inter_follow(interlight, sphere, color, cyl, paral);
  else
    color_void(color);
}

void	calc(t_expose *expose, t_sphere *sphere,
	     t_interlight *interlight, t_color *color)
{
  t_cyl		cyl;
  t_paral	paral;

  coord(sphere, expose->x, expose->y, &cyl);
  sphere->ip = inter_plan(sphere, expose);
  sphere->cs = create_sphere(sphere);
  sphere->cc = create_cylindre(&cyl);
  sphere->cco = create_cone(sphere);
  sphere->ksphere = sphere->cs;
  sphere->kplan = sphere->ip;
  sphere->kcone = sphere->cco;
  //  paral.cp = create_paralel(sphere, &paral, expose);
  cyl.kcyl = sphere->cc;
  check_inter(interlight, sphere, color, &cyl, &paral);
}

int     main()
{
  t_image       image;
  t_expose      expose;

  if ((expose.mlx_ptr = mlx_init()) == NULL)
    exit(-1);
  expose.win_ptr = mlx_new_window(expose.mlx_ptr, WIN_X, WIN_Y,
				  "my fu'cking rtv1");
  expose.img = mlx_new_image(expose.mlx_ptr, WIN_X, WIN_Y);
  image.data = mlx_get_data_addr(expose.img, &image.bpp,
				 &image.sizeline, &image.endian);
  draw_line(&image, &expose);
  mlx_hook(expose.win_ptr, KeyPress, KeyPressMask, write_arrow, &expose);
  mlx_expose_hook(expose.win_ptr, manage_expose, &expose);
  mlx_loop(expose.mlx_ptr);
  return (0);
}
