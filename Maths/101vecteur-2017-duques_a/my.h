/*
** my.h for my in /home/duques_a/101vecteur-2017-duques_a
** 
** Made by pierre duquesnoy
** Login   <duques_a@epitech.net>
** 
** Started on  Tue Nov 13 13:43:32 2012 pierre duquesnoy
** Last update Tue Nov 13 16:45:34 2012 pierre duquesnoy
*/

#ifndef MY_H_
#define MY_H_

void	my_putchar(char c);
void	my_putstr(char *str);
int	my_fonction(int a, int nb);
int	my_put_nbr(int nb);
void	display_vecteur(s_vect *vector);
s_vect	*vecteur_add(s_vect *u, s_vect *v);
s_vect	*p_mult(s_vect *p, s_vect *u);
int	p_scalaire(s_vect *u, s_vect *v);
s_vect	*p_vectoriel(s_vect *u, s_vect *v);
s_vect	*rnd_vect(int size);

#endif
