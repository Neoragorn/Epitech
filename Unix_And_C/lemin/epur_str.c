/*
** epur_str.c for epur str in /home/casier_s//minishell1-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Fri Feb 15 18:15:28 2013 sofian casier
** Last update Thu Apr 25 19:34:41 2013 sofian casier
*/

#include	<stdlib.h>
#include	"funct.h"

char		**my_read_to_wordtab(char *str)
{
  t_readword	word;

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
      while (str[word.i] != '\n' && str[word.i])
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

char		**my_str_to_wordtab(char *str)
{
  t_readword	word;

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
      while (str[word.i] != ' ' && str[word.i] && str[word.i] != '\n')
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

char		**my_numb_to_wordtab(char *str)
{
  t_readword	word;

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
      while (str[word.i] != '-' && str[word.i])
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

char		*epur_str2(char *str, int i, char *tmp)
{
  int		j;

  j = 0;
  while (str[i])
    {
      if (str[i] != ' ' && str[i] != '\t')
        {
          tmp[j] = str[i];
          j++;
        }
      else if ((str[i] == ' ' && str[i + 1] != ' ')
	       || (str[i] == '\t' && str[i + 1] != '\t'))
        {
          tmp[j] = ' ';
          j++;
        }
      i++;
    }
  tmp[j++] = '\0';
  return (tmp);
}

char		*epur_str(char *str)
{
  int		i;
  char		*tmp;

  tmp = malloc(my_strlen(str) * sizeof(char) + 1);
  i = 0;
  while ((str[i] == ' ' || str[i] == '\t') && str[i] != '\0')
    i++;
  epur_str2(str, i, tmp);
  return (tmp);
}

void		putnbr(int nb)
{
  int		n;

  if (nb != 0)
    {
      n = nb % 10;
      putnbr(nb / 10);
      my_putchar('0' + n);
    }
}

void		my_put_nbr(int nb)
{
  if (nb < 0)
    my_putchar('-');
  if (nb == 0)
    my_putchar('0');
  putnbr(nb);
}
