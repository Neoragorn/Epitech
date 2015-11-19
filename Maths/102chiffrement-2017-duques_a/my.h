/*
** my.h for my in /home/duques_a/102chiffrement-2017-duques_a
** 
** Made by pierre duquesnoy
** Login   <duques_a@epitech.net>
** 
** Started on  Tue Nov 27 15:24:46 2012 pierre duquesnoy
** Last update Sun Dec  2 19:36:31 2012 sofian casier
*/

#ifndef MY_H_
#define MY_H_

#include "chiffre.h"

s_mat	*create_matrice(int x, int y);
void	display_matrice(s_mat *matrice);
void	my_putchar(char c);
void	my_putnbr(int nb);
void	my_put_nbr(int nb);
void	my_putstr(char *str);
char	*alpha_pos(char *str, s_mat *matrice);

#endif
