/*
** keep.c for keep in /home/casier_s//lemin
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Fri Apr 12 00:28:23 2013 sofian casier
** Last update Fri Apr 26 20:43:34 2013 sofian casier
*/

#include	<stdlib.h>
#include	"funct.h"

void		link_keeper(t_parcer *parcer)
{
  int		i;
  int		j;

  i = 0;
  parcer->name_link = malloc(my_tab_strlen(parcer->link) * sizeof(char *));
  while (parcer->link[i])
    {
      j = 0;
      parcer->name_link[i] = malloc(my_strlen(parcer->link[i]) *
				    sizeof(char));
      while (parcer->link[i][j])
	{
	  if (parcer->link[i][j] != '-' &&
	      parcer->link[i][j] && parcer->link[i][j] != ' ')
	    parcer->name_link[i][j] = parcer->link[i][j];
	  j++;
	}
      parcer->name_link[i][j] = '\0';
      i++;
    }
  parcer->name_link[i] = NULL;
}

void		room_keeper(t_parcer *parcer)
{
  int		i;
  int		j;

  i = 0;
  parcer->name_room =
    malloc(my_tab_strlen(parcer->room) * sizeof(char *));
  while (parcer->room[i])
    {
      j = 0;
      parcer->name_room[i] = malloc(my_strlen(parcer->room[i]) *
				    sizeof(char));
      while (parcer->room[i][j])
	{
	  if (parcer->room[i][j] != ' ')
	    parcer->name_room[i][j] = parcer->room[i][j];
	  j++;
	}
      parcer->name_room[i][j] = '\0';
      i++;
    }
  parcer->name_room[i] = NULL;
}
