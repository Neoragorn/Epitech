/*
** struct.h for .h in /home/journe_q//projet/raytracer
** 
** Made by quentin journet
** Login   <journe_q@epitech.net>
** 
** Started on  Tue Apr  9 15:29:20 2013 quentin journet
** Last update Sat Jun  8 14:52:18 2013 quentin journet
*/

#ifndef			__STRUCT_H__
# define		__STRUCT_H__

#include		<pthread.h>
#include		"../bmpfile/bmpfile.h"

typedef	struct		s_obj
{
  float			x;
  float			y;
  float			z;
  float			ray;
  float			bril;
  char			type;
  int			r;
  int			g;
  int			b;
  float			rot_x;
  float			rot_y;
  float			rot_z;
  float			min;
  float			max;
  int			chess;
  struct s_obj		*next;
}			t_obj;

typedef struct		s_calc
{
  float			vx;
  float			vy;
  float			vz;
  float			val;
  int			x;
  int			y;
  float			lx;
  float			ly;
  float			lz;
  float			xcur;
  float			ycur;
  float			zcur;
  float			px;
  float			py;
  float			pz;
  float			rx;
  float			ry;
  float			rz;
}			t_calc;

typedef struct		s_tmp_col
{
  int			tred;
  int			tgreen;
  int			tblue;
  int			fred;
  int			fgreen;
  int			fblue;
  float			shadow;
}			t_tmp_col;

typedef struct		s_coor
{
  void			*img_ptr;
  void			*mlx_ptr;
  void			*win_ptr;
  int			blue;
  int			green;
  int			red;
  float			shine;
  float			nx;
  float			ny;
  float			nz;
  char			*bmp_file_name;
  int			bmp;
  bmpfile_t		*bmp_file;
  t_obj			**obj;
}			t_coor;

typedef struct		s_my_c
{
  float			a;
  float			b;
  float			c;
}			t_my_c;

typedef struct		s_get
{
  char			*my_r;
  int			j;
}			t_get;

typedef struct		s_tab
{
  int			h;
  int			i;
  int			k;
  int			j;
}			t_wordtab;

typedef struct		s_thr
{
  pthread_t		th1;
  pthread_t		th2;
  pthread_t		th3;
  pthread_t		th4;
  void			*ret;
}			t_thr;

#endif			/* __STRUCT_H__ */
