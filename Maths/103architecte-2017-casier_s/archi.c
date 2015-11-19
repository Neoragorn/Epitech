/*
** architecte.c for architect in /home/casier_s/os-home/103architecte-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Mon Dec 10 14:56:00 2012 sofian casier
** Last update Thu Dec 13 17:38:24 2012 sofian casier
*/

#include <stdio.h>
#include <stdlib.h>
#include "create_mat.h"
#include <math.h>

int	create_normal_matrice(char **argv)
{
  double	matrice[3][3];

  matrice[0][0] = 1;
  printf("%.3f   ", matrice[0][0]);
  matrice[0][1] = 0;
  printf("%.3f   ", matrice[0][1]);
  matrice[0][2] = 0;
  printf("%.3f   \n", matrice[0][2]);
  matrice[1][0] = 0;
  printf("%.3f   ", matrice[1][0]);
  matrice[1][1] = 1;
  printf("%.3f   ", matrice[1][1]);
  matrice[1][2] = 0;
  printf("%.3f   \n", matrice[1][2]);
  matrice[2][0] = 0;
  printf("%.3f   ", matrice[2][0]);
  matrice[2][1] = 0;
  printf("%.3f   ", matrice[2][1]);
  matrice[2][2] = 1;
  printf("%.3f   ", matrice[2][2]);
}

int	error_message(char **argv)
{
  if (argv[1][0] < '0' || argv[1][0] > '9')
    {
      printf("Sorry, this option doesn't exist\n");
      exit (0);
    }
  if (argv[2][0] < '0' || argv[2][0] > '9')
    {
      printf("Sorry, this option doesn't exist\n");
      exit (0);
    }
  if (argv[4][0] < '0' || argv[4][0] > '9')
    {
      printf("Sorry, this option doesn't exist\n");
      exit (0);
    }
  if ((argv[3][0] != 'R' || argv[3][0] != 'S') && (argv[5][0] < '0' || argv[5][0] > '9'))
    {
      printf("Sorry, this option doesn't exist\n");
      exit (0);
    }
}

int	translation_matrice(char **argv)
{
  double	matrice[3][3];
 
  error_message(argv);
  printf("Translation de vecteur (%.f,.fd)\n", atof(argv[4]), atof(argv[5]));
  matrice[0][0] = 1;
  printf("%.3f   ", matrice[0][0]);
  matrice[0][1] = 0;
  printf("%.3f   ", matrice[0][1]);
  matrice[0][2] = atof(argv[1]) + atof(argv[4]);
  printf("%.3f   \n", matrice[0][2]);
  matrice[1][0] = 0;
  printf("%.3f   ", matrice[1][0]);
  matrice[1][1] = 1;
  printf("%.3f   ", matrice[1][1]);
  matrice[1][2] = atof(argv[2]) + atof(argv[5]);
  printf("%.3f   \n", matrice[1][2]);
  matrice[2][0] = 0;
  printf("%.3f   ", matrice[2][0]);
  matrice[2][1] = 0;
  printf("%.3f   ", matrice[2][1]);
  matrice[2][2] = 1;
  printf("%.3f   ", matrice[2][2]);
  printf("\n (%.f,%.f) => (%.f,%.f) \n", atof(argv[1]), atof(argv[2]), 
	 matrice[0][2], matrice[1][2]);
}

int	option(char **argv)
{
  
}
  
int	main(int argc, char **argv)
{
  double result;

  if (argc == 1)
    {
      printf("Veuillez entrer des parametres pour remplir la matrice \n");
      create_normal_matrice(argv);
    }
  if (argv[5] == 'R' || argv[5] == 'S')
    option(argv);
  if (argc > 6)
    option(argv);
  if (argv[3][0] == 'T')
    translation_matrice(argv);
  if (argv[3][0] == 'H')
    homothetie_matrice(argv);
  if (argv[3][0] == 'R')
    rotation(argv);
  if (argv[3][0] == 'S')
    symetry(argv);
}
