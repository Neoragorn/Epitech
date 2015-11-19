/*
** base_func_for_get.c for base_func_for_get7 in /home/journe_q//projet/raytracer
** 
** Made by quentin journet
** Login   <journe_q@epitech.net>
** 
** Started on  Thu Apr 25 14:36:34 2013 quentin journet
** Last update Sun Jun  2 21:23:30 2013 clement lovergne
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"../point_h/fonction.h"

char		*my_strcpy(char *dest, char *src)
{
  int		k;

  k = 0;
  while (src[k] != '\0')
    {
      dest[k] = src[k];
      k++;
    }
  return (dest);
}

char		*my_strcat(char *src, char *dest)
{
  int		i;
  int		k;

  i = 0;
  while (dest[i])
    i++;
  k = 0;
  while (src[k])
    {
      dest[i] = src[k];
      i++;
      k++;
    }
  return (dest);
}

int		my_analyse(char *str)
{
  int		k;

  k = 0;
  while (str[k])
    {
      if (str[k] == '\n')
        return (1);
      k++;
    }
  return (0);
}

char		*my_realloc(char *str)
{
  char		*dest;
  int		n;

  n = 0;
  while (str[n])
    n++;
  if ((dest = malloc((n + MY_SIZE) * sizeof(char))) == NULL)
    error_message("Error malloc\n");
  dest = my_strcpy(dest, str);
  free(str);
  return (dest);
}
