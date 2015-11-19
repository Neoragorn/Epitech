/*
** list.c for list in /home/koszycl/myselect-2017-koszyc_l
** 
** Made by laurent koszyczek
** Login   <koszyc_l@epitech.net>
** 
** Started on  Thu Jan 17 15:24:51 2013 laurent koszyczek
** Last update Sat Jun  8 15:15:38 2013 clement lovergne
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"../point_h/fonction.h"

static int	get_obj_type(char *str)
{
  if (my_memcmp(str, "sphere", 6) == 0)
    return (SPHERE);
  else if (my_memcmp(str, "cylindre", 8) == 0)
    return (CYLINDRE);
  else if (my_memcmp(str, "cone", 4) == 0)
    return (CONE);
  else if (my_memcmp(str, "plan", 4) == 0)
    return (PLAN);
  else if (my_memcmp(str, "spot", 4) == 0)
    return (SPOT);
  else if (my_memcmp(str, "paraboloide", 11) == 0)
    return (PARA);
  else
    {
      my_putstr("Error Object type\n");
      exit(1);
    }
}

static float	get_next_value(char *str, int *i)
{
  char		*nb;
  int		tmp;
  int		j;
  float		nbtmp;

  tmp = *i;
  j = 0;
  while (str[*i] != ';')
    *i = *i + 1;
  nb = my_malloc(sizeof (char) * (*i - tmp + 1));
  *i = tmp;
  while (str[*i] != ';' && str[*i] != '\0')
    {
      nb[j++] = str[*i];
      *i += 1;
    }
  nb[j] = '\0';
  *i += 1;
  nbtmp = atof(nb);
  return (nbtmp);
}

static void	next_put_in_list(t_obj *elem, char *str, int *i)
{
  if (elem->type != SPHERE && elem->type != SPOT)
    {
      elem->rot_x = get_next_value(str, i);
      elem->rot_y = get_next_value(str, i);
      elem->rot_z = get_next_value(str, i);
      elem->min = get_next_value(str, i);
      elem->max = get_next_value(str, i);
    }
  if (elem->type == PLAN)
    elem->chess = get_next_value(str, i);
}

void		my_putinlist(t_obj **list, char *str)
{
  int		i;
  t_obj		*elem;

  i = 0;
  elem = my_malloc(sizeof (t_obj));
  while (str[i] != ':' && str[i] != '\0' && str[i] != '\n')
    i++;
  i++;
  elem->type = get_obj_type(str);
  elem->x = get_next_value(str, &i);
  elem->y = get_next_value(str, &i);
  elem->z = get_next_value(str, &i);
  elem->ray = 0;
  if (elem->type != PLAN && elem->type != SPOT)
    elem->ray = get_next_value(str, &i);
  elem->bril = 0;
  if (elem->type != SPOT)
    elem->bril = get_next_value(str, &i);
  elem->r = get_next_value(str, &i);
  elem->g = get_next_value(str, &i);
  elem->b = get_next_value(str, &i);
  next_put_in_list(elem, str, &i);
  elem->next = *list;
  *list = elem;
}
