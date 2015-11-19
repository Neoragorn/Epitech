/*
** error.c for error in /home/amoure_a//rt
** 
** Made by alix amoureux
** Login   <amoure_a@epitech.net>
** 
** Started on  Thu Apr 11 15:27:57 2013 alix amoureux
** Last update Fri Jun  7 15:40:49 2013 alix amoureux
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<math.h>
#include	"../point_h/fonction.h"

int		check_ponctuation(char *buffer, int nb)
{
  int		i;
  int		c;

  i = 0;
  c = 0;
  while (buffer[i])
    {
      if (buffer[i] == ';')
	c++;
      i++;
    }
  i = 0;
  while (buffer[i])
    {
      if (buffer[i] == ';' && buffer[i - 1] == ';')
	return (0);
      i++;
    }
  if (buffer[i - 1] != ';' && buffer[i] == '\0')
    return (0);
  if (c != nb)
    return (0);
  return (1);
}

int		lengh_line(char *buffer, int j)
{
  int		lengh;

  lengh = 0;
  while (buffer[j] != ' ' && buffer[j] != '\t'
	 && buffer[j] != '\0' && buffer[j] != '\n')
    {
      j++;
      lengh++;
    }
  return (lengh + 1);
}

static int	check_points(char *buffer)
{
  int		c;
  int		i;

  c = 0;
  i = 0;
  while (buffer[i] != '\0')
    {
      if (buffer[i] == ':')
	c = 1;
      i++;
    }
  if (c == 0)
    {
      printf("The sign of ponctuation ':' is missing\n");
      return (0);
    }
  return (1);
}

int		check_error(char *buffer)
{
  int		i;

  i = 0;
  if (check_points(buffer) == 0)
    return (0);
  while (buffer[i] != ':')
    i++;
  i++;
  if (check_numbers(buffer, i) == 0)
    {
      printf("The coordonnees are not recognized\n");
      return (0);
    }
  if (name_ponct_error(buffer) == 0)
    {
      printf("The objects or the ponctuation are not recognised\n");
      return (0);
    }
  return (1);
}
