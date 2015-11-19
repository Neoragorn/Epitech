/*
** usiv_func.c for usiv_function in /home/duques_a/Epitech/projet/101vecteur
** 
** Made by pierre duquesnoy
** Login   <duques_a@epitech.net>
** 
** Started on  Fri Nov  9 13:59:10 2012 pierre duquesnoy
** Last update Thu Nov 15 15:53:08 2012 sofian casier
*/

#include <stdio.h>
#include <time.h>
#include "vect_struct.h"
#include "my.h"

void	display_vecteur(s_vect *vector)
{
  int	i;
  
  i = 0;
  while (i < vector->size)
    {
      printf("%d",vector->elements[i]);
      printf("   ");
      i++;
    }
}

int		main(int argc, char **argv)
{
  s_vect	*u;
  s_vect	*v;
  s_vect	*p;
  s_vect	*add_res;
  s_vect        *mult_res;
  s_vect	*scal_res;
  int		p_res;
  
  srand(time(NULL));
  
  p = rnd_vect(1);
  if (argc == 1)
    {
      printf("Veuillez passer des paramètres \n");
      return (0);
    }
  if (argc == 3)
    {
      u = rnd_vect(my_get_nbr(argv[2]));
      v = rnd_vect(my_get_nbr(argv[2]));
      if (argv[1][0] == '1')
	{
	  printf("p	                 ");
	  display_vecteur(p);
	  printf("\n");
	  printf("vecteur u :	         ");
	  display_vecteur(u);
	  printf("\n");
	  printf("vecteur v :	         ");
	  display_vecteur(v);
	  printf("\n");
	  printf("vecteur u+v :		 ");
	  add_res = vecteur_add(u, v);
	  printf("\n");
	  printf("vecteur p.u :		 ");
	  mult_res = p_mult(p, u);
	  printf("\n");
	  printf("produit scalaire uv :		");
	  p_res = p_scalaire(u,v);
	  printf("\n");
	}
      else
	{
	  printf("Mauvaise option \n");
	  return (0);
	}
    }
  else if (argc == 2)
    {
      u = rnd_vect(3);
      v = rnd_vect(3);
      if (argv[1][0] == '2')
	{
	  printf("Vecteur u :     ");
	  display_vecteur(u);
	  printf("\n");
	  printf("Vecteur v :     ");
	  display_vecteur(v);
	  printf("\n");
	  printf("Vecteur u^v :   ");
	  p_vectoriel(u,v);
	  printf("\n");
	}
      else
	{
	  printf("Mauvaise option \n");
	}
    }
  else
    printf("Option invalide , choisissez 1 ou 2 \n");
}
