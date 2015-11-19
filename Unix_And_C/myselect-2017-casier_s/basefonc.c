/*
** basefonc.c for basefonc in /home/casier_s//wolf
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Mon Jan  7 18:10:30 2013 sofian casier
** Last update Sun Jan 20 19:30:36 2013 sofian casier
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int	my_tabstrlen(char *str)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (i <= my_strlen(str))
    {
      if (str[i] == '\n')
	j++;
      i++;
    }
  return (j);
}

void	my_putchar(char c)
{
  write(0, &c, 1);
}

void	my_putstr_spe(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] && str)
    {
      my_putchar(str[i]);
      i++;
    }
}
