/*
** eyevector.c for eyevector in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt/calc
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Mon May  6 19:29:56 2013 clement lovergne
** Last update Sat Jun  8 16:33:35 2013 quentin journet
*/

#include	<math.h>
#include	"../point_h/fonction.h"

void		calc_director(t_calc *calc)
{
  calc->vx = (((float)WIN_X / 2) / tanf(RAD * 25));
  calc->vy = (((float)WIN_X / 2) - (float)calc->x);
  calc->vz = (((float)WIN_Y / 2) - (float)calc->y);
  rotate_x(&calc->vx, &calc->vy, &calc->vz, -ROT_X_EYE);
  rotate_y(&calc->vx, &calc->vy, &calc->vz, -ROT_Y_EYE);
  rotate_z(&calc->vx, &calc->vy, &calc->vz, -ROT_Z_EYE);
  calc->xcur = (float)X_EYE;
  calc->ycur = (float)Y_EYE;
  calc->zcur = (float)Z_EYE;
  rotate_x(&calc->xcur, &calc->ycur, &calc->zcur, -ROT_X_EYE);
  rotate_y(&calc->xcur, &calc->ycur, &calc->zcur, -ROT_Y_EYE);
  rotate_z(&calc->xcur, &calc->ycur, &calc->zcur, -ROT_Z_EYE);
  calc->rx = 0;
  calc->ry = 0;
  calc->rz = 0;
}

void		my_pix_by_pix(t_coor *coor, t_obj **obj)
{
  t_calc	calc;
  int		k;

  k = -1;
  calc.x = 0;
  while (calc.x <= WIN_X)
    {
      k++;
      check_length(&calc, k);
      calc.y = 0;
      while (calc.y <= WIN_Y)
	{
	  calc_director(&calc);
	  my_check_obj(&calc, coor, obj);
	  if (coor->bmp == 1)
	    create_bmp(coor, calc.x, calc.y);
	  mppti(calc.x, calc.y, coor);
	  calc.y++;
	}
      calc.x++;
    }
  my_putchar('\n');
}
