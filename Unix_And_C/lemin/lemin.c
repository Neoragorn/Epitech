/*
** lemin.c for lemin in /home/casier_s//lemin
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Wed Apr  3 15:22:00 2013 sofian casier
** Last update Tue Apr 23 15:47:28 2013 clement lovergne
*/

#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"funct.h"

void		my_tab_copy(t_parcer *parcer, int i, int line)
{
  parcer->final_read[line] = malloc(my_strlen(parcer->clean_read[i])
				    * sizeof(char) + 1);
  parcer->final_read[line] = parcer->clean_read[i];
}

int		check_carac_second(char *str)
{
  int		i;
  int		check;

  check = 0;
  i = 0;
  while (str[i])
    {
      if ((str[i] == ' ' || str[i] == '\t') &&
	  (str[i + 1] == '\t' || str[i + 1] == ' '))
	check++;
      i++;
    }
  return (check);
}

void		no_carac(t_parcer *parcer)
{
  int		i;
  int		numb;

  i = 0;
  numb = 0;
  parcer->final_read = malloc(my_tab_strlen(parcer->clean_read)
			      * sizeof(char *));
  while (parcer->clean_read[i] != NULL)
    {
      if (check_carac_second(parcer->clean_read[i]) != 0)
	{
	  my_tab_copy(parcer, i, numb);
	  numb++;
	}
      else if (check_carac_first(parcer->clean_read[i]) != 0)
	{
	  my_tab_copy(parcer, i, numb);
	  numb++;
	}
      i++;
    }
  parcer->final_read[numb] = NULL;
}

char		*open_read(const char **argv, t_parcer *parcer)
{
  int		lengh;

  parcer->fd = open(argv[1], O_RDONLY);
  lengh = read(parcer->fd, parcer->buffer, 4096);
  parcer->buffer[lengh] = '\0';
  return (parcer->buffer);
}

int		main(int argc, const char **argv)
{
  t_parcer	parcer;
  char		*buffer;
  int		i;

  i = 0;
  if (argc != 2)
    {
      my_putstr("Put only one argument!\n");
      return (1);
    }
  buffer = open_read(argv, &parcer);
  parcer.clean_read = my_read_to_wordtab(buffer);
  no_carac(&parcer);
    while (parcer.final_read[i])
    {
      parcer.final_read[i] = epur_str(parcer.final_read[i]);
      //      my_putstr(parcer.final_read[i]);
      //my_putchar('\n');
      i++;
    }
    check_info(&parcer);
    return (0);
}
