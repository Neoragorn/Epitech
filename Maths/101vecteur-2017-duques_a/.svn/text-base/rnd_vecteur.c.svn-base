/*
** rnd_vecteur.c for rnd_vecteur in /home/duques_a/Epitech/projet/101vecteur
** 
** Made by pierre duquesnoy
** Login   <duques_a@epitech.net>
** 
** Started on  Fri Nov  9 10:23:56 2012 pierre duquesnoy
** Last update Tue Nov 13 13:47:48 2012 pierre duquesnoy
*/

#include <time.h>
#include <stdlib.h>
#include "vect_struct.h"
#include "my.h"

s_vect		*rnd_vect(int size)
{
  int		*elem;
  int		i;
  s_vect	*vect;
  
  i = 0;
  vect = malloc(sizeof(s_vect));
  vect->size = size;
  elem = malloc(size*sizeof(int));
  while (i < size)
    {
      elem[i] = (rand() % (MAX - MIN)) + MIN;
      i++;
    }
  vect->elements = elem;
  return (vect);
}
