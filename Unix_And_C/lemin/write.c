/*
** write.c for write in /home/casier_s//lemin
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Wed Apr  3 15:48:30 2013 sofian casier
** Last update Tue Apr 23 15:58:45 2013 clement lovergne
*/

#include	<unistd.h>
#include	"funct.h"

int		my_strcmp(char *str, char *dest)
{
  int		i;

  i = 0;
  while (str[i] == dest[i])
    {
      if (str[i] == dest[i] && str[i] == '\0')
        return (0);
      i++;
    }
  if (str[i] != dest[i])
    return (str[i] - dest[i]);
  else
    return (0);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int		my_tab_strlen(char **str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] && str)
    {
      my_putchar(str[i]);
      i++;
    }
}
