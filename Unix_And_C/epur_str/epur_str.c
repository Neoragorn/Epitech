/*
** epur_str.c for epur in /home/casier_s//epur_str
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sun Feb 24 19:47:43 2013 sofian casier
** Last update Sun Feb 24 20:39:12 2013 sofian casier
*/

#include <stdio.h>
#include <stdlib.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

char    *epur_str2(char *str, char *tmp, int i)
{
  int   j;

  j = 0;
  while (str[i])
    {
      if (str[i] != ' ')
	{
	  tmp[j] = str[i];
	  j++;
	}
      else if (str[i] == ' ' && str[i + 1] != ' ')
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

  i = 0;
  printf("%d\n", my_strlen(str));
  tmp = malloc(my_strlen(str) * sizeof(char) + 1);
  while (str[i] == ' ' || str[i] == '\t')
    i++;  
  epur_str2(str, tmp, i);
  return (tmp);
}

int	main(int argc, char **argv)
{
  char buffer[] = "    a   b  c de   f e g    ";
  char *tmp;


  tmp = epur_str(buffer);
  printf("%s\n", tmp);
  printf("%d\n", my_strlen(tmp));
}
