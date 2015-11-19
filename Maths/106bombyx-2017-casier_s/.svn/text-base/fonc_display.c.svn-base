/*
** fonc_display.c for fonc in /home/casier_s//bombyx
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Feb 21 13:55:54 2013 sofian casier
** Last update Thu Feb 21 13:57:23 2013 sofian casier
*/

#include "my.h"

int     color_line1(t_image *image, t_expose *expose, int x, int y, int pos)
{

  image->data[pos] = 255;
  image->data[pos + 1] = 255;
  image->data[pos + 2] = 255;
  image->data[pos + 3] = 0;
}

int     fill_image(t_image *image, t_expose *expose, int x, int y)
{
  int           pos;
  int           color;

  pos = (x * (image->bpp / 8)) + (y * image->sizeline);
  color_line1(image, expose, x, y, pos);
}

int     draw_line(int x1, int x2, int y1, int y2, t_expose *expose, t_image *image)
{
  int   x;

  x = x1;
  while (x <= x2)
    {
      fill_image(image, expose, x1, y1 + ((y2 - y1) * (x - x1)) / (x2 - x1));
      x++;
    }
}


int     draw_line2(int x1, int x2, int y1, int y2, t_expose *expose, t_image *image)
{
  int   y;

  y = y1;
  while (y <= y2)
    {
      fill_image(image, expose, (x1 + (x2 - x1) * (y - y1) / (y2 - y1)), y);
      y++;
    }
}
