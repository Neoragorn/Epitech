/*
** check_link.c for link in /home/casier_s//lemin
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Apr 11 21:50:57 2013 sofian casier
** Last update Fri Apr 26 17:13:29 2013 sofian casier
*/

#include	<stdlib.h>
#include	"funct.h"

void		data_room_link(t_parcer *parcer)
{
  char		*buffer;
  int		i;
  int		j;

  i = 0;
  parcer->room_link = malloc(my_tab_strlen(parcer->link) * sizeof(int *));
+
  .buffer = malloc(10000 * sizeof(char));
  while (parcer->link[i])
    {
      j = 0;
      while (parcer->link[i][j] != '-')
	{
	  buffer[j] = parcer->link[i][j];
	  j++;
	}
      parcer->room_link[i] = malloc(my_strlen(parcer->link[i]) * sizeof(int));
      parcer->room_link[i] = my_getnbr(buffer);
      j++;
      while (parcer->link[i][j] != '\0' && parcer->link[i][j] != '\n')
	{
	  buffer[j] = parcer->link[i][j];
	  j++;
	}
      parcer->room_link[i] = my_getnbr(buffer);
      printf("new link is %d\n", parcer->room_link[i]);
      i++;
    }
}

int		check_carac_link(t_parcer *parcer, int i)
{
  int		j;
  int		count;

  j = 0;
  count = 0;
  while (parcer->final_read[i][j])
    {
      if (parcer->final_read[i][j] == '-')
        count++;
      j++;
    }
  if (count == 1)
    return (1);
  else
    return (0);
}

int		check_good_link(t_parcer *parcer, int i)
{
  int		j;
  int		count;

  count = 0;
  j = 0;
  while (parcer->final_read[i][j])
    {
      if ((parcer->final_read[i][j] < '0' ||
	   parcer->final_read[i][j] > '9') &&
	  parcer->final_read[i][j] != '-' &&
	  parcer->final_read[i][j] != ' ')
	count++;
      j++;
    }
  return (count);
}

void		check_link(t_parcer *parcer)
{
  int		i;
  int		j;
  int		count;

  j = 0;
  i = 0;
  parcer->link = malloc(my_tab_strlen(parcer->final_read) * sizeof(char *));
  while (parcer->final_read[i])
    {
      count = 0;
      count = check_good_link(parcer, i);
      if (count == 0)
        {
          count = check_carac_link(parcer, i);
          if (count == 1)
	    {
	      parcer->link[j] = malloc(my_strlen(parcer->final_read[i]) * sizeof(char) + 1);
	      parcer->link[j] = parcer->final_read[i];
	      j++;
              
	    }
        }
      i++;
    }
  data_room_link(parcer);
}
