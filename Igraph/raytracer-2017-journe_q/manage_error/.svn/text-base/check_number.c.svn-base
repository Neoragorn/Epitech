/*
** check_number.c for check_number in /home/amoure_a//raytracer-2017-journe_q
** 
** Made by alix amoureux
** Login   <amoure_a@epitech.net>
** 
** Started on  Mon May 13 17:31:25 2013 alix amoureux
** Last update Fri Jun  7 17:32:48 2013 alix amoureux
*/

#include	<stdlib.h>
#include	"../point_h/fonction.h"

void		error_message(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  exit(0);
}

static int	check_numbers2(char *buffer)
{
  int		i;

  i = 0;
  while (buffer[i])
    {
      if ((buffer[i] < '0' || buffer[i] > '9')
	  && (buffer[i] != '-' && buffer[i] != '.'))
	return (0);
      i++;
    }
  return (1);
}

int		check_numbers(char *buffer, int j)
{
  char		**tab;
  int		i;
  char		*buffer2;
  int		k;

  if ((buffer2 = malloc(sizeof(char) * (lengh_line(buffer, j)))) == NULL)
    error_message("Error on malloc\n");
  i = 0;
  while (buffer[j])
    {
      buffer2[i] = buffer[j];
      i++;
      j++;
    }
  buffer2[i] = '\0';
  i = 0;
  tab = my_str_to_word_tab(buffer2);
  while (tab[i])
    {
      k = check_numbers2(tab[i]);
      if (k == 0)
	return (0);
      i++;
    }
  return (1);
}
