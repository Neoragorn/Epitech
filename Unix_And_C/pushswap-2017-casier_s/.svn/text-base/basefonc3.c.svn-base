/*
** basefonc3.c for base fonc in /home/casier_s/os-home/pushswap
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Wed Jan  2 20:39:35 2013 sofian casier
** Last update Sun Jan  6 23:23:55 2013 sofian casier
*/

#include <stdlib.h>
#include "my.h"

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] || dest[i])
    {
      dest[i] = src[i];
      i++;
    }
  return (dest);
}

int	my_tabstrlen(char **str)
{
  int	i;
  int	j;
  int	x;
  int	count;

  x = 0;
  i = 0;
  count = 0;
  while (str[i] != NULL)
    {
      j = 0;
      while (str[i][j])
	{
	  if (str[i][j] >= '0' && str[i][j] <= '9')
	    j++;
	  else
	    return (count);
	}
      if (j == my_strlen(str[i]))
	count++;
      i++;
    }
  return (count);
}

int            *my_intdup(char **str, int *l_a, int argc)
{
  int   i;
  int   j;

  if (l_a == NULL)
    return (NULL);
  if (str == NULL)
    return (NULL);
  i = 1;
  j = 0;
  while (argc >= 1 && str[i] != 0)
    {
      l_a[j] = my_getnbr(str[i]);
      j++;
      i++;
      argc--;
    }
  return (l_a);
}

char    **my_str_to_wordtab(char *str, char space)
{
  char  **tab;
  int   word;
  int   i;
  int   lengh;

  tab = malloc(count_space(str, space) * sizeof(char *));
  word = 0;
  i = 0;
  while (str[i])
    {
      lengh = 0;
      while (str[i] == ' ' && str[i] != '\0')
	i++;
      while (str[i + lengh] != space && str[i + lengh] != '\n' &&
             str[i + lengh] != '\0')
	lengh++;
      if (lengh == 0)
	return;
      tab[word] = malloc((lengh + 1) * sizeof(char));
      my_strncpy(tab[word], str + i, lengh);
      tab[word][lengh] = '\0';
      i += lengh;
      word++;
    }
  tab[word] = '\0';
  return (tab);
}
