/*
** check_ant_end_start.c for check in /home/casier_s//lemin
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Apr 11 19:10:35 2013 sofian casier
** Last update Tue Apr 23 15:56:15 2013 clement lovergne
*/

#include	<stdlib.h>
#include	"funct.h"

void		check_end(t_parcer *parcer)
{
  int		i;

  i = 0;
  while (parcer->final_read[i])
    {
      if (my_strcmp("##end", parcer->final_read[i]) == 0)
        return;
      i++;
    }
  my_putstr("You have to put a ##end line in your file\n");
  exit (1);
}

/*
int	check_line_start(t_parcer *parcer)
{
  int	i;
  int	j;
  int	end;

  i = 0;
  while (parcer->final_read[i])
    {
      if (my_strcmp("##start", parcer->final_read[i]) == 0)
	j = i;
      i++;
    }
  while (parcer->final_read[j])
    {
      if ((parcer->final_read[j][1] >= '0' || parcer->final_read[j][1] <= '9') && (parcer->final_read[j][2] >= '0' || parcer->final_read[j][2] <= '9'))
	{
	  my_putstr("everything is fine for rooms!\n");
	  return (0);
	}
      if (my_strcmp("##end", parcer->final_read[j]) == 0)
	{
	  my_putstr("You have to put a start room!\n");
	  exit(1);
	}
      j++;
    }
  return (1);
}

*/

void		check_start(t_parcer *parcer)
{
  int		i;

  i = 0;
  while (parcer->final_read[i])
    {
      if (my_strcmp("##start", parcer->final_read[i]) == 0)
	return;
      i++;
    }
  my_putstr("You have to put a ##start line in your file\n");
  exit(1);
}

void		check_ant(t_parcer *parcer)
{
  int		ant;
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (parcer->final_read[i][j])
    {
      if (parcer->final_read[i][j] < '0' || parcer->final_read[i][j] > '9')
	{
	  my_putstr("Something is wrong with the number of ants\n");
	  exit(1);
	}
      j++;
    }
  ant = my_getnbr(parcer->final_read[0]);
  my_put_nbr(ant);
  my_putchar('\n');
}

      //	{
      //	  check = check_line_start(parcer);
      //	  if (check == 0)
