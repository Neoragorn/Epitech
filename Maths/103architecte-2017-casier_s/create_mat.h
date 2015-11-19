/*
** create_mat.h for mat in /home/casier_s/os-home/103architecte-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Mon Dec 10 15:59:38 2012 sofian casier
** Last update Mon Dec 10 17:05:33 2012 sofian casier
*/

#ifndef MATRICE_H_
#define MATRICE_H_

typedef struct matrice  s_mat;
struct matrice
{
  float   *elem;
  int   h;
  int   l;
};

#endif
