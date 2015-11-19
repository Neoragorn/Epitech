/*
** check_room.c for check room in /home/casier_s//lemin
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Apr 11 19:14:00 2013 sofian casier
** Last update Tue Apr 23 15:56:58 2013 clement lovergne
*/

#include	<stdlib.h>
#include	"funct.h"

int		check_space(t_parcer *parcer, int i)
{
  int		j;
  int		firstcount;
  int		count;

  firstcount = 0;
  count = 0;
  j = 0;
  while (parcer->final_read[i][j])
    {
      if (parcer->final_read[i][j] == ' ')
        firstcount++;
      j++;
    }
  if (firstcount == 0)
    return (1);
  while (parcer->final_read[i][j])
    {
      if (parcer->final_read[i][j] == ' ' &&
	  (parcer->final_read[i][j - 1] < '0' ||
	   parcer->final_read[i][j - 1] > '9'))
        count++;
      j++;
    }
  return (count);
}

int		check_numb(t_parcer *parcer, int i)
{
  int		j;
  int		count;

  count = 0;
  j = 0;
  while (parcer->final_read[i][j] != ' ' && parcer->final_read[i][j])
    j++;
  while (parcer->final_read[i][j])
    {
      if ((parcer->final_read[i][j] < '0' ||
	   parcer->final_read[i][j] > '9') &&
	  parcer->final_read[i][j] != ' ')
        count++;
      j++;
    }
  return (count);
}

void		check_room(t_parcer *parcer)
{
  int		i;
  int		j;
  int		count;

  j = 0;
  i = 0;
  parcer->room = malloc(my_tab_strlen(parcer->final_read) * sizeof(char *));
  while (parcer->final_read[i])
    {
      count = 0;
      count = check_numb(parcer, i);
      if (count == 0)
	{
	  count = check_space(parcer, i);
	  if (count == 0)
	    {
	      parcer->room[j] =
		malloc(my_strlen(parcer->final_read[i]) * sizeof(char) + 1);
	      parcer->room[j] = parcer->final_read[i];
	      j++;
	    }
	}
      i++;
    }
}
