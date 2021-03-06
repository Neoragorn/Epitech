/*
** my.h for my.h in /home/casier_s//tprtv1
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Tue Feb  5 09:46:59 2013 sofian casier
** Last update Tue Jun  4 15:59:22 2013 sofian casier
*/

#ifndef __MY___
#define __MY___

#include "struct.h"

#define RAD (3.14159265 / 180)
#define WIN_X (1920)
#define WIN_Y (1200)

#define X_1 (0)
#define Y_1 (0)
#define Z_PLAN (30)

#define X_O (-300)
#define Y_O (0)
#define Z_O (10)

#define X_SPHERE (-400)
#define Y_SPHERE (700)
#define Z_SPHERE (10)
#define R_SPHERE (150)

#define X_CYL (-700)
#define Y_CYL (0)
#define Z_CYL (100)
#define R_CYL (0)

#define X_CONE (0)
#define Y_CONE (200)
#define Z_CONE (10)
#define ANGLE_CONE (20)

#define LX_SPOT (-300)
#define LY_SPOT (300)
#define LZ_SPOT (150)

#define BL_SPOTSH (0.4)
#define BL_SPOTPL (0.9)
#define BL_SPOTCYL (0)
#define BL_CONE (0.2)

#define CONE_ROTX (0)
#define CONE_ROTY (0)
#define CONE_ROTZ (0)

#define SPHERE_ROTX (0)
#define SPHERE_ROTY (0)
#define SPHERE_ROTZ (0)

#define PLAN_ROTX (0)
#define PLAN_ROTY (0)
#define PLAN_ROTZ (0)

#define CYL_ROTX (0)
#define CYL_ROTY (0)
#define CYL_ROTZ (0)

#define PARAL_X1 (300)
#define PARAL_X2 (380)
#define PARAL_X3 (370)
#define PARAL_Y2 (360)
#define PARAL_Y3 (330)

#define PARAL_X1 (0)
#define PARAL_X2 (110)
#define PARAL_X3 (155)
#define PARAL_Y1 (0)
#define PARAL_Y2 (162)
#define PARAL_Y3 (160)

int	main();
void    rotation_x(t_sphere*, float);
void    rotation_y(t_sphere*, float);
void    rotation_z(t_sphere*, float);
int     write_arrow(int, t_expose*);
void    color_pixel(t_image*, t_color*, t_expose*);
void    draw_line(t_image*, t_expose*);
void    fill_image(t_image*, t_expose*, t_interlight*, t_sphere*);
int     manage_expose(t_expose*);
float   create_sphere(t_sphere*);
float   inter_plan(t_sphere*, t_expose*);
void    coord(t_sphere*, int, int, t_cyl*);
void	calc(t_expose*, t_sphere*, t_interlight*, t_color*);
void	inter_light(t_interlight*, t_color*);
void	inter_light_plan(t_sphere*, t_interlight*, t_color*);
void	inter_light_sphere(t_sphere*, t_interlight*, t_color*);
void	inter_light_cyl(t_cyl*, t_interlight*, t_color*);
void	inter_light_color(t_interlight*, t_color*);
int	my_strlen(char*);
int	my_tabstrlen(char *);
void	my_putchar(char);
void	my_putstr(char*);
void	color_sphere(t_interlight*, t_sphere*, t_color*);
void	color_plane(t_interlight*, t_sphere*, t_color*);
void	color_void(t_color*);
void	color_cone(t_interlight*, t_sphere*, t_color*);
void	check_color(t_color*);
void	brilliance_sphere(t_color*);
void	brilliance_plan(t_color*);
void	brilliance_cyl(t_color*);
void	brilliance_cone(t_color*);
float	create_cylindre(t_cyl*);
void	color_cyl(t_interlight*, t_cyl*, t_color*);
float	create_cone(t_sphere*);
void	inter_light_cone(t_sphere*, t_interlight*, t_color*);
void	init_coord(t_cyl*);
void	check_env(t_interlight*, t_sphere*, t_color*, t_cyl*);
float	create_cone_follow(t_sphere*);
void	check_inter(t_interlight*, t_sphere*, t_color*, t_cyl*, t_paral*);
float	create_sphere_follow(t_sphere*);
void	rotationcyl_x(t_cyl*, float);
void	rotationcyl_y(t_cyl*, float);
void	rotationcyl_z(t_cyl*, float);
void	check_brilliance(t_color*);

#endif /*__MY__*/
