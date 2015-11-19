/*
** table_data.c for table in /home/casier_s//lemin
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Apr 18 18:00:27 2013 sofian casier
** Last update Fri Apr 26 20:42:25 2013 sofian casier
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"funct.h"

void		fill_struct_data(t_parcer *parcer)
{
  t_data	*data;
  int		lengh;
  int		i;
  int		j;

  data = malloc(my_tab_strlen(parcer->name_room) * sizeof(void *) + 1);
  lengh = my_tab_strlen(parcer->name_room);
  i = 0;
  j = 0;
  while (i < lengh)
    {
      data[i].name_room = parcer->name_room[i];
      data[i].numb_room = i;
      i++;
    }
  i = 0;
  while (i < lengh)
    {
      data[i].x = my_getnbr(parcer->data_x_y[j]);
      j++;
      data[i].y = my_getnbr(parcer->data_x_y[j]);
      j++;
      i++;
    }
  i = 0;
  while (parcer->link_x_y[i])
    {
      printf("link is %s\n", parcer->link_x_y[i]);
      i++;
    }
}

void		my_data_x_y(t_parcer *parcer)
{
  int		i;
  int		j;
  int		lengh;

  j = 0;
  i = 0;
  lengh = my_tab_strlen(parcer->name_room) * 2;
  parcer->data_x_y = malloc(lengh * sizeof(char *));
  while (i < lengh)
    {
      parcer->data_x_y[i] = malloc(lengh * sizeof(char));
      parcer->wordtab_x_y = my_str_to_wordtab(parcer->room[j]);
      parcer->data_x_y[i] = parcer->wordtab_x_y[1];
      i++;
      parcer->data_x_y[i] = parcer->wordtab_x_y[2];
      i++;
      j++;
    }
}

  void		my_data_block(t_parcer *parcer)
  {
    my_data_x_y(parcer);
  }
