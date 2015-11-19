/*
** fonction.h for fonction in /home/journe_q//projet/raytracer
** 
** Made by quentin journet
** Login   <journe_q@epitech.net>
** 
** Started on  Wed Apr 10 13:42:57 2013 quentin journet
** Last update Sat Jun  8 16:41:51 2013 sofian casier
*/

#ifndef		__FONCTION_H__
# define	__FONCTION_H__

#include	<stdlib.h>
#include	"struct.h"
#include	"define.h"

const char	*path_dir(char*, const char*);
void		check_bmp(t_coor*, char**);
void		create_bmp(t_coor*, int, int);
void		set_checker(t_coor*, t_obj*, t_calc*);
void		*my_malloc(size_t);
void		check_length(t_calc*, int);
void		calc_director(t_calc*);
void		my_putchar(char);
void		my_putstr(char*);
void		my_putinlist(t_obj**, char*);
void		error_message(char*);
int		my_memcmp(void*, void*, int);
int		my_strlen(char*);
int		my_analyse(char*);
int		nex(char**, t_obj**);
int		name_ponct_error(char*);
int		check_ponctuation(char*, int);
int		check_error(char*);
int		check_numbers(char*, int);
int		lengh_line(char*, int);
int		error_paraboloide(char*, int*, char**, float);
int		error_spot_plan(char *, int *, char **);
char		*my_strcpy(char*, char*);
char		*my_strcat(char*, char*);
char		*my_realloc(char*);
char		**my_str_to_word_tab(char*);
char		**my_str_to_word_tab2(char*);
void		rotate_x(float*, float*, float*, float);
void		rotate_y(float*, float*, float*, float);
void		rotate_z(float*, float*, float*, float);
void		my_putnbr(int);
void		calc_sphere(t_obj*, t_calc*, t_coor*);
int		mppti(int, int, t_coor*);
void		calc_plan(t_obj*, t_calc*, t_coor*);
void		calc_cylindre(t_obj*, t_calc*, t_coor*);
void		calc_para(t_obj*, t_calc*, t_coor*);
void		my_pix_by_pix(t_coor*, t_obj**);
void		calc_cone(t_obj*, t_calc*, t_coor*);
void		calc_shine(t_obj*, t_calc*, t_coor*, t_tmp_col*);
void		check_max_col(int*, int* , int*);
void		calc_sha_sph(t_obj*, t_calc*, t_tmp_col*);
void		calc_sha_plan(t_obj*, t_calc*, t_tmp_col*);
void		calc_sha_cyl(t_obj*, t_calc*, t_tmp_col*);
void		calc_sha_para(t_obj*, t_calc*, t_tmp_col*);
void		calc_sha_cone(t_obj*, t_calc*, t_tmp_col*);
void		calc_my_shadow(t_obj**, t_calc*, t_tmp_col*, t_obj*);
void		my_check_obj(t_calc*, t_coor*, t_obj**);
void		my_check_spot(t_calc*, t_coor*, t_obj**, t_obj*);
void		thread(t_obj**, t_coor, char*);
void		thread3(t_obj**, t_coor);
void		thread4(t_obj**, t_coor);
void		check_length2(t_calc*, int);
void		check_length3(t_calc*, int);
void		check_length4(t_calc*, int);
void		replace_point(t_calc*, t_obj*);

#endif		/* __FONCTION_H__*/
