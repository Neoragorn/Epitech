/*
** check.c for check in /home/casier_s//lemin
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Wed Apr 10 18:51:51 2013 sofian casier
** Last update Fri Apr 26 20:43:28 2013 sofian casier
*/

#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"funct.h"

void		data_link(t_parcer *parcer)
{
  int		i;
  int		j;
  int		z;

  j = 0;
  i = 0;
  parcer->link_x_y = malloc(my_tab_strlen(parcer->link) * sizeof(char *));
  while (parcer->link[i])
    {
      j = 0;
      z = 0;
      parcer->link_x_y[i] = malloc(my_strlen(parcer->link[i]) * sizeof(char) + 10);
      while (parcer->link[i][j])
	{
	  if (parcer->link[i][j] != '-')
	    {
	      parcer->link_x_y[i][z] = parcer->link[i][j];
	      z++;
	    }
	  j++;
	}
      parcer->link_x_y[i][z] = '\0';
      printf("link are %s\n", parcer->link_x_y[i]);
      i++;
    }
  parcer->link_x_y[i] = NULL;
}

void		check_info(t_parcer *parcer)
{
  int	i;

  i = 0;
  check_start(parcer);
  check_end(parcer);
  check_ant(parcer);
  check_room(parcer);
  room_keeper(parcer);
  check_link(parcer);
  link_keeper(parcer);
  my_data_block(parcer);
  data_link(parcer);
  fill_struct_data(parcer);
}

int		check_carac_first(char *str)
{
  int		i;
  int		check;

  i = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
        check++;
      i++;
    }
  return (check);
}
