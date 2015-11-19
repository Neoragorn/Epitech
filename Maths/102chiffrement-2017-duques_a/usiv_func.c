/*
** usiv_func.c for usiv_func in /home/duques_a/102chiffrement-2017-duques_a
** 
** Made by pierre duquesnoy
** Login   <duques_a@epitech.net>
** 
** Started on  Tue Nov 27 14:13:10 2012 pierre duquesnoy
** Last update Mon Dec 10 15:58:55 2012 sofian casier
*/

#include <stdlib.h>
#include <stdio.h>
#include "chiffre.h"
#include "my.h"

void	my_putstr(char *str)
{
  int	i;
  
  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

s_mat		*create_matrice(int x, int y)

{
  s_mat		*matrice;
  
  matrice = malloc(sizeof(s_mat));
  matrice->hauteur = x;
  matrice->largeur = y;
  matrice->elements = malloc(x * y * sizeof(int));  
}

void		display_matrice(s_mat *matrice)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < matrice->largeur * matrice->hauteur)
    {
      if (j == matrice->largeur)
	{
	  printf("\n");
	  j = 0;
	}
      else
	{
	  printf("%d ",matrice->elements[i]);
	  i++;
	  j++;
	}
    }
  printf("\n");
}
