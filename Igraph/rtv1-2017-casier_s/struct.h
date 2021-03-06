/*
** struct.h for struct in /home/casier_s//rtv1-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sun Mar 17 15:43:18 2013 sofian casier
** Last update Mon Jun  3 16:13:24 2013 sofian casier
*/

#ifndef __MY__
#define __MY__

typedef struct s_image
{
  int   sizeline;
  int   endian;
  int   bpp;
  char  *data;
}       t_image;

typedef struct s_expose
{
  void  *mlx_ptr;
  void  *win_ptr;
  void  *img;
  void  *img2;
  int   x;
  int   y;
}       t_expose;

typedef struct s_interlight
{
  float px;
  float py;
  float pz;
  float nx;
  float ny;
  float nz;
  float lx;
  float ly;
  float lz;
  float coscolor;
}       t_interlight;

typedef struct s_color
{
  float red;
  float green;
  float blue;
  float bred;
  float bgreen;
  float bblue;
}       t_color;

typedef struct s_sphere
{
  float x1;
  float y1;
  float z1;
  float xo;
  float yo;
  float zo;
  float k;
  float k1;
  float k2;
  float ksphere;
  float kplan;
  float kcone;
  float ip;
  float cs;
  float cc;
  float cco;
  float a;
  float b;
  float c;
  float delta;
}       t_sphere;

typedef struct s_cone
{
  float x1;
  float y1;
  float z1;
  float xo;
  float yo;
  float zo;
  float k;
  float k1;
  float k2;
  float ksphere;
  float kplan;
  float kcone;
}       t_cone;

typedef struct s_paral
{
  float x;
  float y;
  float v1x;
  float v1y;
  float v1;
  float v2x;
  float v2y;
  float v2;
  float	k1;
  float k2;
  float P;
  float	cp;
}	t_paral;

typedef struct s_cyl
{
  float x1;
  float y1;
  float z1;
  float xo;
  float yo;
  float zo;
  float k;
  float k1;
  float k2;
  float kcyl;
  float delta;
  float a;
  float b;
  float c;
}       t_cyl;

#endif /*__MY__*/
