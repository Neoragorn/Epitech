/*
** usualfonction.c for usualfonction in /home/loverg_c//localwork/igraph/raytracer/raytracergroupe/rt
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Tue May  7 15:47:25 2013 clement lovergne
** Last update Sat Jun  8 16:56:51 2013 sofian casier
*/

#include	"../point_h/fonction.h"

int		my_special_strlen(const char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

const char	*path_dir(char *path, const char *readfile)
{
  char		*tmp;
  int		i;
  int		j;

  j = 0;
  i = 0;
  tmp = malloc((my_strlen(path) + my_special_strlen(readfile) + 2) *
	       sizeof(char));
  if (tmp == NULL)
    exit(1);
  while (path[i] != 0)
    {
      tmp[i] = path[i];
      i++;
    }
  tmp[i++] = '/';
  while (readfile[j] != 0)
    {
      tmp[i] = readfile[j];
      j++;
      i++;
    }
  tmp[i] = '\0';
  return (tmp);
}

void		my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = 0 - nb;
    }
  if (nb > 9)
    my_putnbr(nb / 10);
  my_putchar(nb % 10 + '0');
}
