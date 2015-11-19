/*
** second_fonc.c for second in /home/casier_s//106bombyx-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sun Feb 24 17:11:06 2013 sofian casier
** Last update Sun Feb 24 17:15:39 2013 sofian casier
*/

#include <mlx.h>
#include "my.h"

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

int     draw_Haxe(t_expose *expose, t_image *image)
{
  int   x;
  int   y;
  int   count;
  int   i;

  count = 0;
  y = WIN_Y;
  x = 30;
  i = (WIN_X / 100) * 2;
  while (x <= WIN_X)
    {
      y = WIN_Y;
      if (i == x)
        {
          if (count % 2 == 0)
            {
              while (y >= (WIN_Y - 80))
                {
                  fill_image(image,expose, x, y);
                  y--;
                }
            }
          y = WIN_Y;
          if (count % 2 != 0)
            {
              while (y >= (WIN_Y - 60))
                {
                  fill_image(image,expose, x, y);
                  y--;
                }
            }
          count++;
          i = (WIN_X / 100) + i;
        }
      x++;
    }
}

int     draw_Vaxe(t_expose *expose, t_image *image)
{
  int   x;
  int   y;
  int   count;
  int   i;

  count = 0;
  y = 0;
  x = 0;
  i = 0;
  while (y <= WIN_Y)
    {
      x = 0;
      if (y == i)
        {
          if (count % 2 == 0)
            {
              while (x <= 30)
                {
                  fill_image(image,expose, x, y);
                  x++;
                }
            }
          x = 0;
          if (count % 2 != 0)
            {
              while (x <= 15)
                {
                  fill_image(image,expose, x, y);
                  x++;
                }
            }
          i = (WIN_Y / 100) + i;
          count++;
        }
      if (count == 0)
        i = (WIN_Y / 100) + i;
      fill_image(image,expose, x, y);
      y++;
    }
}
