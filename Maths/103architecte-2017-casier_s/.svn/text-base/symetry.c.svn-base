/*
** symetry.c for symetry in /home/casier_s/os-home/103architecte-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Dec 13 15:13:54 2012 sofian casier
** Last update Thu Dec 13 16:51:11 2012 sofian casier
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double          convert_to_sym(double result, char **argv)
{
  double        pi;
  double        result2;
  double        result_cos;
  double        result_sin;
  double        null;
  double        one;
  double        sym_prime_x;
  double        sym_prime_y;
  double        result_f_x;
  double        result_f_y;

  one = 1,000;
  null = 0,000;
  pi = 3.141592654;
  result2 = (result * pi) / 180;
  result_cos = cos(result2);
  result_sin = sin(result2);
  sym_prime_x = result_cos * (atoi(argv[1])) - result_sin * (atoi(argv[2]));
  sym_prime_y = (-1) * (result_sin * (atoi(argv[1])) + result_cos * (atoi(argv[2])));
  result = atof(argv[4]);
  result2 = (result * pi) / 180;
  result_cos = cos(result2);
  result_sin = sin(result2);
  result_f_x = result_cos * sym_prime_x - result_sin * sym_prime_y;
  result_f_y = result_sin * sym_prime_x + result_cos * sym_prime_y;
  printf("\n (%.f,%.f) => (%.f,%.f) \n", atof(argv[1]), atof(argv[2]),
         result_f_x, result_f_y);
}

int             symetry(char **argv)
{
  double        result;
  double        result2;
  double	matrice[3][3];

  error_message(argv);
  result = (-1) * atof(argv[4]);
    printf("\n Symétrie par rapport à un axe incliné de %.f \n", atof(argv[4]));
  matrice[0][0] = 0;
  printf("%.3f   ", matrice[0][0]);
  matrice[0][1] = 1;
  printf("%.3f   ", matrice[0][1]);
  matrice[0][2] = 0;
  printf("%.3f   \n", matrice[0][2]);
  matrice[1][0] = 0;
  printf("%.3f   ", matrice[1][0]);
  matrice[1][1] = -1;
  printf("%.3f   ", matrice[1][1]);
  matrice[1][2] = 0;
  printf("%.3f   \n", matrice[1][2]);
  matrice[2][0] = 0;
  printf("%.3f   ", matrice[2][0]);
  matrice[2][1] = 0;
  printf("%.3f   ", matrice[2][1]);
  matrice[2][2] = 1;
  printf("%.3f   ", matrice[2][2]);
  convert_to_sym(result, argv);
}
