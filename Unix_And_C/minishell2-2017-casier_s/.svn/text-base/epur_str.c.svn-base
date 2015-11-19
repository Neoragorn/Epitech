/*
** epur_str.c for epur str in /home/casier_s//minishell1-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Fri Feb 15 18:15:28 2013 sofian casier
** Last update Fri Mar  8 14:12:59 2013 sofian casier
*/

#include <stdlib.h>
#include "my.h"

char    *epur_str2(char *str, int i, char *tmp)
{
  int   j;

  j = 0;
  while (str[i])
    {
      if (str[i] != ' ' || str[i] != '\t')
        {
          tmp[j] = str[i];
          j++;
        }
      else if ((str[i] == ' ' && str[i + 1] != ' ')
	       || (str[i] == ' ' && str[i + 1] == '\t'))
        {
          tmp[j] = ' ';
          j++;
        }
      else if (str[i] == '\t' && str[i + 1] != '\t')
        {
          tmp[j] = ' ';
          j++;
        }
      i++;
    }
  tmp[j++] = '\0';
  return (tmp);
}

char    *epur_str(char *str)
{
  int   i;
  char  *tmp;

  tmp = malloc(my_strlen(str) * sizeof(char) + 1);
  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  epur_str2(str, i, tmp);
  return (tmp);
}
