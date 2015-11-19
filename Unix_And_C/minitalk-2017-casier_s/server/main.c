/*
** server.c for server in /home/casier_s//minitalk
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Mon Mar 18 18:44:41 2013 sofian casier
** Last update Sun Mar 24 20:13:34 2013 sofian casier
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include "my.h"

int	error()
{
  my_putstr("Wrong signal\n");
  exit(1);
}

int	decode(int signal)
{
  static int	i;
  static char	bit;
  int		j;
  char		n;

  n = '\n';
  j = 0;
  bit = (signal << i++) + bit;
  if (i > 7)
    {
      if (bit != 0)
	{
	  write(fd, &bit, 1);
	  my_putchar(bit);
	  j++;
	}
      else
	{
	  my_putchar('\n');
	  write(fd, &n, 1);
	  j++;
	}
      bit = 0;
      i = 0;
    }
}

void	signal_check(int sig)
{
  if (sig == SIGUSR1)
      decode(1);
  else if (sig == SIGUSR2)
      decode(0);
}

void	check_sig()
{
  usleep(1000);
  if (signal(SIGUSR1, signal_check) == SIG_ERR)
    error();
  else if (signal(SIGUSR2, signal_check) == SIG_ERR)
    error();
}

int	main(int argc, char **argv)
{
  char	buffer[4096];
  int	i;

  fd = open("Historic", O_RDWR | O_CREAT, 0666);
  my_putstr("PID of the server is: ");
  my_put_nbr(getpid());
  my_putchar('\n');
  while (1)
    {
      check_sig();
      i = 0;
      read(0, buffer, 4096);
      while (buffer[i])
	{
	  if (buffer[i] == '\n')
	    exit (1);
	  i++;
	}
    }
  return (1);
}
