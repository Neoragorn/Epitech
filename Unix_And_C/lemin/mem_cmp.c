/*
** mem_cmp.c for mem in /home/casier_s//lemin
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Apr 25 18:10:17 2013 sofian casier
** Last update Thu Apr 25 18:10:34 2013 sofian casier
*/

#include "my.h"

int     my_memcmp(void *b, void *c, int len)
{
  char  *i;
  char  *j;

  i = b;
  j = c;
  while (len--)
    if (*i != *j)
      return (*i - *j);
    else
      {
        i++;
        j++;
      }
  return (0);
}
