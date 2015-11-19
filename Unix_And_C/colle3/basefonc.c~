/*
** basefonc.c for base in /home/casier_s//tprtv1
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Tue Feb  5 09:52:55 2013 sofian casier
** Last update Tue Mar 12 21:05:45 2013 sofian casier
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
