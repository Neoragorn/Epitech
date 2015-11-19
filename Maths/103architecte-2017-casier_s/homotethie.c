/*
** homotethie.c for homothetie in /home/casier_s/os-home/103architecte-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Dec 13 15:18:51 2012 sofian casier
** Last update Thu Dec 13 15:19:38 2012 sofian casier
*/

#include <stdlib.h>
#include <stdio.h>

int             homothetie_matrice(char **argv)
{
  double        matrice[3][3];

  error_message(argv);
  printf("Homothétie de rapport %d et %d\n", atoi(argv[4]), atoi(argv[5]));
  matrice[0][0] = atoi(argv[1]) * atoi(argv[4]);
  printf("%.3f    ", matrice[0][0]);
  matrice[0][1] = 0;
  printf("%.3f    ", matrice[0][1]);
  matrice[0][2] = 0;
  printf("%.3f    \n", matrice[0][2]);
  matrice[1][0] = 0;
  printf("%.3f    ", matrice[1][0]);
  matrice[1][1] = atoi(argv[2]) * atoi(argv[5]);
  printf("%.3f    ", matrice[1][1]);
  matrice[1][2] = 0;
  printf("%.3f    \n", matrice[1][2]);
  matrice[2][0] = 0;
  printf("%.3f    ", matrice[2][0]);
  matrice[2][1] = 0;
  printf("%.3f    ", matrice[2][1]);
  matrice[2][2] = 1;
  printf("%.3f    ", matrice[2][2]);
  printf("\n (%d,%d) => (%.f,%.f) \n", atoi(argv[1]), atoi(argv[2]), matrice[0][0], matrice[1][1]);
}
