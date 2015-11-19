/*
** basefonc.c for base in /home/casier_s//colle3
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Tue May  7 09:38:55 2013 sofian casier
** Last update Tue May  7 09:38:58 2013 sofian casier
*/

#include <unistd.h>

int     my_strlen(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

int     my_tabstrlen(char *str)
{
  int   i;
  int   j;

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

void    my_putchar(char c)
{
  write(1, &c, 1);
}

void    my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i++;
    }
}
