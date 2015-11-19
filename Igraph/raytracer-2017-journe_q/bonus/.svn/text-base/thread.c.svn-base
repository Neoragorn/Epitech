/*
** thread.c for thread in /home/journe_q//test/raytracer-2017-journe_q
** 
** Made by quentin journet
** Login   <journe_q@epitech.net>
** 
** Started on  Mon Jun  3 17:23:47 2013 quentin journet
** Last update Thu Jun  6 12:35:06 2013 clement lovergne
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<pthread.h>
#include	"../point_h/fonction.h"

static void	*my_pix_by_pix_4(t_coor *coor)
{
  t_calc	calc;
  t_coor	newc;

  newc = *coor;
  calc.x = (WIN_X / 4) * 3;
  while (calc.x <= WIN_X)
    {
      calc.y = 0;
      while (calc.y <= WIN_Y)
        {
          calc_director(&calc);
          my_check_obj(&calc, &newc, coor->obj);
          mppti(calc.x, calc.y, &newc);
          calc.y++;
        }
      calc.x++;
    }
  return (0);
}

static void	*my_pix_by_pix_3(t_coor *coor)
{
  t_calc	calc;
  int		end;
  t_coor	newc;

  newc = *coor;
  end = (WIN_X / 4) * 3;
  calc.x = (WIN_X / 4) * 2;
  while (calc.x < end)
    {
      calc.y = 0;
      while (calc.y <= WIN_Y)
        {
          calc_director(&calc);
          my_check_obj(&calc, &newc, coor->obj);
          mppti(calc.x, calc.y, &newc);
          calc.y++;
        }
      calc.x++;
    }
  return (0);
}

static void	*my_pix_by_pix_2(t_coor *coor)
{
  t_calc	calc;
  t_coor	newc;

  newc = *coor;
  calc.x = WIN_X / 4;
  while (calc.x < (WIN_X / 2))
    {
      calc.y = 0;
      while (calc.y <= WIN_Y)
        {
          calc_director(&calc);
          my_check_obj(&calc, &newc, coor->obj);
          mppti(calc.x, calc.y, &newc);
          calc.y++;
        }
      calc.x++;
    }
  return (0);
}

static void	*my_pix_by_pix_1(t_coor *coor)
{
  t_calc	calc;
  int		k;
  t_coor	newc;

  newc = *coor;
  calc.x = 0;
  k = 0;
  while (calc.x < (WIN_X / 4))
    {
      k++;
      check_length4(&calc, k);
      calc.y = 0;
      while (calc.y <= WIN_Y)
        {
          calc_director(&calc);
          my_check_obj(&calc, &newc, coor->obj);
          mppti(calc.x, calc.y, &newc);
          calc.y++;
        }
      calc.x++;
    }
  my_putchar('\n');
  return (0);
}

void		thread4(t_obj **obj, t_coor coor)
{
  t_thr		thr;

  coor.obj = obj;
  if (pthread_create(&thr.th1, NULL, (void*) &my_pix_by_pix_1,
                     (void*) &coor) != 0)
    exit(-1);
  if (pthread_create(&thr.th2, NULL, (void*) &my_pix_by_pix_2,
                     (void*) &coor) != 0)
    exit(-1);
  if (pthread_create(&thr.th3, NULL, (void*) &my_pix_by_pix_3,
                     (void*) &coor) != 0)
    exit(-1);
  if (pthread_create(&thr.th4, NULL, (void*) &my_pix_by_pix_4,
                     (void*) &coor) != 0)
    exit(-1);
  (void) pthread_join(thr.th1, &thr.ret);
  (void) pthread_join(thr.th2, &thr.ret);
  (void) pthread_join(thr.th3, &thr.ret);
  (void) pthread_join(thr.th4, &thr.ret);
}
