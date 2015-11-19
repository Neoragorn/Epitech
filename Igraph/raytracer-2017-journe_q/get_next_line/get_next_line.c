/*
** get_next_line.c for get_next_linec in /home/loverg_c//svn/c_prog_elem/getnextline-2017-loverg_c
** 
** Made by clement lovergne
** Login   <loverg_c@epitech.net>
** 
** Started on  Fri Nov 23 14:54:48 2012 clement lovergne
** Last update Fri Jun  7 17:44:18 2013 quentin journet
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"../point_h/fonction.h"

static char	*next(t_get *get, int k)
{
  if (get->j != 0 && k <= 0)
    return (get->my_r);
  free(get->my_r);
  return (NULL);
}

static int	check_end(int *i, char *buffer)
{
  int		j;

  j = 1;
  if (buffer[*i])
    return (*i);
  else
    {
      while (buffer[j])
	{
	  buffer[j - 1] = '\0';
	  j++;
	}
      buffer[j - 1] = '\0';
    }
  return (0);
}

static char	*get_next_line(int fd)
{
  t_get		get;
  static char	buffer [MY_SIZE];
  static int	i = -1;
  static int	k = 1;

  get.j = 0;
  i++;
  if ((get.my_r = malloc(MY_SIZE * sizeof(char))) == NULL)
    error_message("Error malloc\n");
  while (get.my_r[get.j] != '\n' && k > 0)
    {
      k = (i == 0 ? read(fd, buffer, MY_SIZE) : k);
      if (k > 0)
	{
	  while (buffer[i] && buffer[i] != '\n')
	    get.my_r[get.j++] = buffer[i++];
	  if (buffer[i] == '\n')
	    return (get.my_r);
	  i = check_end(&i, buffer);
	  get.my_r = (get.my_r[get.j] ? get.my_r : my_realloc(get.my_r));
	}
    }
  return (next(&get, k));
}

int		nex(char **argv, t_obj **obj)
{
  char		*buffer;
  int		fd;

  if (argv[1])
    {
      if ((fd = open(argv[1], O_RDONLY)) == -1)
	error_message("The file doesn't exist\n");
      while ((buffer = get_next_line(fd)) != NULL)
	{
	  if (check_error(buffer) == 0)
	    exit(-1);
	  else
	    my_putinlist(obj, buffer);
	}
      free(buffer);
    }
  return (0);
}
