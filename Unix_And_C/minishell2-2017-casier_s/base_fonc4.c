/*
** base_fonc4.c for base fonc in /home/casier_s/os-home/minishell1-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Jan 24 15:26:42 2013 sofian casier
** Last update Sat Mar  9 15:51:37 2013 sofian casier
*/

#include <stdlib.h>
#include "my.h"

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}

char	**my_read_to_wordtab(char *str)
{
  t_readword word;

  word.j = 0;
  word.i = 0;
  word.x = 0;
  word.dest = malloc(6000 * sizeof(char *));
  if (word.dest == NULL)
    exit (1);
  while (str[word.i])
    {
      word.x = 0;
      word.dest[word.j] = malloc(10000 * sizeof(char));
      while (str[word.i] != ' ' && str[word.i] && str[word.i] != '\t')
	{
	  word.dest[word.j][word.x] = str[word.i];
	  word.x++;
	  word.i++;
	}
      word.dest[word.j][word.x] = '\0';
      word.j++;
      word.i++;
    }
  word.dest[word.j] = NULL;
  return (word.dest);
}

int     count_word(char *str)
{
  int   i;
  int   n;

  i = 0;
  n = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ' ' && str[i + 1] != '\0')
        n++;
      i++;
    }
  return (n);
}

int	init(t_str *numb)
{
  numb->x = 0;
  numb->j = 0;
  numb->x = 0;
}

char **my_env_to_wordtab(char *str, char **envp)
{
  t_str numb;

  init(&numb);
  if ((numb.dest = malloc(my_tab_strlen(envp) * sizeof(char *) * 100)) == NULL)
    exit (1);
  while (str[numb.i] != '=')
    numb.i++;
  numb.i++;
  while (str[numb.i])
    {
      numb.x = 0;
      numb.dest[numb.j] = malloc(my_strlen(envp[numb.j]) * sizeof(char));
      while (str[numb.i] != ':' && str[numb.i])
	{
	  numb.dest[numb.j][numb.x] = str[numb.i];
	  numb.x++;
	  numb.i++;
	}
      numb.dest[numb.j][numb.x] = '\0';
      numb.j++;
      numb.i++;
    }
  numb.dest[numb.j] = NULL;
  return (numb.dest);
}
