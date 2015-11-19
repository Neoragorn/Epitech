/*
** my_str_to_word_tab.c for my_str_to_word_tab in /home/amoure_a//prog_elem/bsq
** 
** Made by alix amoureux
** Login   <amoure_a@epitech.net>
** 
** Started on  Tue Dec  4 11:00:06 2012 alix amoureux
** Last update Fri Jun  7 14:04:11 2013 alix amoureux
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"../point_h/fonction.h"
#include	"../point_h/struct.h"

static int	lengh_char(char *str, int i)
{
  int		lengh;

  while (str[i] != ';')
    i++;
  lengh = sizeof(i + 1);
  return (lengh);
}

static int	how_many_words(char *s)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (s[i] != '\0')
    {
      while (s[i] ==  ';')
	i++;
      while (s[i] != ';' && s[i] != '\0')
	i++;
      j++;
    }
  return (j + 1);
}

static void	init_tab(char ***wordtab, t_wordtab *tab, char *str)
{
  tab->h = how_many_words(str);
  if ((*wordtab = malloc(sizeof(char **) * (tab->h))) == NULL)
    error_message("Error on malloc\n");
  tab->i = 0;
  tab->j = 0;
}

char		**my_str_to_word_tab2(char *str)
{
  char		**wordtab;
  t_wordtab	tab;

  init_tab(&wordtab, &tab, str);
  while (str[tab.i] != ':')
    tab.i++;
  tab.i++;
  while (str[tab.i] != '\0')
    {
      if ((wordtab[tab.j] = malloc(sizeof(char *)
				   * (lengh_char(str, tab.i)))) == NULL)
	error_message("Error on malloc\n");
      tab.k = 0;
      while (str[tab.i] == ';')
	tab.i++;
      while (str[tab.i] != ';' && str[tab.i] != '\0')
        {
	  wordtab[tab.j][tab.k] = str[tab.i];
          tab.i++;
	  tab.k++;
        }
      wordtab[tab.j][tab.k] = '\0';
      tab.j++;
    }
  return (wordtab);
}

char		**my_str_to_word_tab(char *str)
{
  char		**wordtab;
  t_wordtab	tab;

  init_tab(&wordtab, &tab, str);
  while (str[tab.i] != '\0')
    {
      if ((wordtab[tab.j] = malloc(sizeof(char)
				   * (lengh_char(str, tab.i)))) == NULL)
	error_message("Error on malloc\n");
      tab.k = 0;
      while (str[tab.i] == ';')
	tab.i++;
      while (str[tab.i] != ';' && str[tab.i] != '\0')
        {
	  wordtab[tab.j][tab.k] = str[tab.i];
          tab.i++;
	  tab.k++;
        }
      wordtab[tab.j][tab.k] = '\0';
      tab.j++;
    }
  return (wordtab);
}
