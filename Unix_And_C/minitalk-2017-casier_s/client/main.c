/*
** main.c for main in /home/casier_s//minitalk
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Mon Mar 18 13:54:29 2013 sofian casier
** Last update Sun Mar 24 19:58:46 2013 sofian casier
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "my.h"

int	error()
{
  my_putstr("Wrong PID or server closed\n");
  exit (1);
}

int	zero(int pid)
{
  int	i;

  i = 0;
  while (i <= 7)
    {
      usleep(1000);
      kill(pid, SIGUSR2);
      i++;
    }
}

int	check_for_msg(int pid, char tmp)
{
  int	i;
  char	bit;

  i = 0;
  bit = 0;
  while (bit <= 7)
    {
      usleep(1000);
      if (((tmp >> bit) & 1))
	{
	  if (kill(pid, SIGUSR1) == -1)
	    error();
	}
      else
	if (kill(pid, SIGUSR2) == -1)
	  error();
      bit++;
    }
  return (1);
}

int	minitalk(char **argv)
{
  char		*buffer;
  int		i;
  int		pid;

  i = 0;
  pid = my_getnbr(argv[1]);
  if (pid == -1)
    {
      my_putstr("wrong pid\n");
      exit (1);
    }
  buffer = argv[2];
  while (buffer[i])
    {
      check_for_msg(pid, buffer[i]);
      i++;
    }
  zero(pid);
  return (0);
}

int	main(int argc, char **argv)
{
  if (argc != 3)
    {
      my_putstr("The correct input is : ./client / PIDserver / Message /\n");
      return (1);
    }
  minitalk(argv);
  return (1);
}
