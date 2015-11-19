/*
** funct.h for funct in /home/loverg_c//localwork/c_prog_elem/lemmin
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Tue Apr 23 15:09:40 2013 clement lovergne
** Last update Thu Apr 25 19:40:23 2013 sofian casier
*/

#ifndef		FUNCT_H_
# define	FUNCT_H_

#include	"my.h"

void		check_end(t_parcer*);
void		check_start(t_parcer*);
void		check_ant(t_parcer*);
void		data_link(t_parcer*);
void		check_info(t_parcer*);
int		check_carac_first(char*);
int		check_numb_link(t_parcer*, int);
int		check_carac_link(t_parcer*, int);
int		check_good_link(t_parcer*, int);
void		check_link(t_parcer*);
int		check_space(t_parcer*, int);
int		check_numb(t_parcer*, int);
void		check_room(t_parcer*);
char		**my_read_to_wordtab(char*);
char		**my_numb_to_wordtab(char*);
char		**my_str_to_wordtab(char*);
char		*epur_str2(char*, int, char*);
char		*epur_str(char*);
void		putnbr(int);
void		my_put_nbr(int);
int		my_getnbr_neg(char*, int);
int		my_getnbr_calc(char*, int, int);
int		my_getnbr(char*);
void		key_to_room(t_parcer*);
void		link_keeper(t_parcer*);
void		room_keeper(t_parcer*);
void		my_tab_copy(t_parcer*, int, int);
int		check_carac_second(char*);
void		no_carac(t_parcer*);
char		*open_read(const char**, t_parcer*);
int		main(int, const char**);
void		fill_struct_data(t_parcer*);
void		my_data_x_y(t_parcer*);
void		my_data_block(t_parcer*);
int		my_strcmp(char*, char*);
int		my_strlen(char*);
int		my_tab_strlen(char**);
void		my_putchar(char);
void		my_putstr(char*);
int		my_memcmp(void*, void*, int);
#endif		/* FUNCT_H_ */
