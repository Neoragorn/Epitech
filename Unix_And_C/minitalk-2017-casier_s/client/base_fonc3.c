/*
** base_fonc3.c for base fonc in /home/casier_s/os-home/minishell
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sun Dec 30 15:03:42 2012 sofian casier
** Last update Mon Mar 18 18:52:21 2013 sofian casier
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

char    *my_strncpy(char *dest, char *src, int nb)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      while (i < nb)
        {
          dest[i] = src[i];
          i++;
        }
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
