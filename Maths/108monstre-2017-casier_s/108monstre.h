/*
** 108monstre.h for 108monstre in /home/amoure_a/os-home/maths/108monstre
** 
** Made by alix amoureux
** Login   <amoure_a@epitech.net>
** 
** Started on  Sun Mar 17 22:45:33 2013 alix amoureux
** Last update Mon Mar 18 17:43:42 2013 alix amoureux
*/

#ifndef MATH

#define MATH

#define         SIZE_L (800)
#define         SIZE_H (800)

#define PI (3.1415)

struct gere_exp
{
  void          *mlx_ptr;
  void          *win_ptr;
  void          *img_ptr;
  char          *data;
};

void *mlx_init();
void *mlx_new_window(void *, int, int, char *);
void *mlx_new_image(void *, int, int);
char *mlx_get_data_addr(void *, int *, int *, int *);
int  mlx_string_put(void *, void *, int, int, int, char *);

#endif
