/*
** create_bmp.c for create in /home/casier_s//raytracer-2017-journe_q/bonus
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sat Jun  8 14:25:57 2013 sofian casier
** Last update Sat Jun  8 16:44:15 2013 sofian casier
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"../point_h/define.h"
#include	"../point_h/struct.h"
#include	"../bmpfile/bmpfile.h"

void		check_bmp(t_coor *coor, char **argv)
{
  coor->bmp_file_name = argv[3];
  coor->bmp = 1;
  if ((coor->bmp_file = bmp_create(WIN_X, WIN_Y, 32)) == NULL)
    {
      printf("Couldn't create a bmp file\n");
      exit(-1);
    }
  if (my_memcmp(argv[2], "1", 1) != 0)
    {
      printf("Cannot create a BMP file with more than one core\n");
      exit(-1);
    }
}

void		create_bmp(t_coor *coor, int x, int y)
{
  rgb_pixel_t	pixel;

  pixel.red = coor->red;
  pixel.green = coor->green;
  pixel.blue = coor->blue;
  pixel.alpha = 0;
  bmp_set_pixel(coor->bmp_file, x, y, pixel);
  if (y == WIN_Y && x == WIN_X)
    bmp_save(coor->bmp_file, coor->bmp_file_name);
}
