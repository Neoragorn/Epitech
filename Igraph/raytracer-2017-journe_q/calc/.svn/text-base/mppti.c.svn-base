/*
** mppti.c for mppti in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon May  6 19:50:07 2013 clement lovergne
** Last update Mon Jun  3 10:38:18 2013 sofian casier
*/

#include	<mlx.h>
#include	<X11/X.h>
#include	"../point_h/fonction.h"

int		mppti(int x, int y, t_coor *coor)
{
  int		pos;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;

  data = mlx_get_data_addr(coor->img_ptr, &bpp, &sizeline, &endian);
  pos = ((bpp / 8) * x) + (y * sizeline);
  data[pos] = coor->blue;
  data[pos + 1] = coor->green;
  data[pos + 2] = coor->red;
  return (0);
}
