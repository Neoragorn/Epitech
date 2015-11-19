/*
** my.h for my.h in /home/casier_s//lemin
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Wed Apr  3 15:57:32 2013 sofian casier
** Last update Fri Apr 26 17:06:20 2013 sofian casier
*/

#ifndef		MY_H_
# define	MY_H_


typedef struct	s_parcer
{
  char		buffer[4096];
  char		**clean_read;
  char		**final_read;
  char		**room;
  char		**name_room;
  char		*number_room;
  char		**final_number_room;
  char		**link;
  char		**name_link;
  char		**link_x_y;
  char		**wordtab_x_y;
  char		**data_x_y;
  char		***data_bank;
  int		**room_link;
  int		numbant;
  int		fd;
  int		*line;
}		t_parcer;

typedef struct	s_data
{
  int		numb_room;
  int		x;
  int		y;
  int		distance;
  int		weight;
  char		**wordtab_link;
  char		**link;
  char		*name_room;
}		t_data;

typedef struct s_link
{
  int		room1;
  int		room2;
  int		distance;
}		t_link;

typedef struct	s_readword
{
  int		i;
  int		j;
  int		x;
  char		**dest;
}		t_readword;

#endif		/* MY_H_ */
