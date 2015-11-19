/*
** point.c for point in /home/casier_s//minishell2-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Feb 28 15:40:56 2013 sofian casier
** Last update Mon Jan  2 10:58:14 2012 sofian casier
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include "my.h"

int	check_command(t_shell *shell, char **argv, char **envp, int i)
{
  int	j;
  int	z;
  int	count;
  pid_t	pid;

  z = 0;
  j = 0;
  while (z != i)
    {
      j = 0;
      count = i - z;
      while (shell->tab[j] != NULL)
        {
          if (access(path_dir(shell->tab[j], shell->reader[0]), X_OK) != -1)
	    {
            execve(path_dir(shell->tab[j],
			    shell->reader[0]), shell->tmp2, NULL);
	    exit (1);
	    }
          j++;
        }
      z++;
    }
  exit (1);
}

int	access_do(t_shell *shell, int i, int j)
{
  while (shell->tab[j] != NULL)
    {
      if (access(path_dir(shell->tab[j], shell->reader[i + 1]), X_OK) != -1)
	{
        execve(path_dir(shell->tab[j], shell->reader[i + 1]),
	       shell->tmp2, NULL);
	exit (1);
	}
      j++;
    }
  exit (1);
}

int	command(t_shell *shell, char **argv, char **envp, int count)
{
  int	i;
  int	x;
  int	j;
  pid_t	pid;

  j = 0;
  i = 0;
  x = 0;
  shell->tmp2 = malloc(my_tab_strlen(shell->reader) * sizeof(char *));
  while (shell->reader[i] != NULL && shell->reader[i][x] != ';')
    {
      shell->tmp2[i] = malloc(my_strlen(shell->reader[i]) * sizeof(char) + 10);
      shell->tmp2[i] = shell->reader[i];
      i++;
    }
  pid = fork();
  if (pid < 0)
    exit (1);
  else if (pid == 0)
    check_command(shell, argv, envp, i);
  else
    access_do(shell, i, j);
  my_putstr("No command found\n");
  exit(1);
}

void	exec_read_succeed_point(char **argv, char **envp,
                                pid_t pid, t_shell *shell)
{
  struct sigaction	stop;
  int			i;
  int			j;
  int			x;
  int			count;

  j = 0;
  i = 0;
  x = 0;
  count = 0;
  stop.sa_handler = SIG_DFL;
  sigaction(SIGINT, &stop, NULL);
  command(shell, argv, envp, count);
  exec_read_failed();
}

void	exec_read_point(char **argv, char **envp, t_shell *shell)
{
  pid_t			pid;
  struct sigaction	stop;

  stop.sa_flags = 0;
  stop.sa_handler = SIG_IGN;
  sigaction(SIGINT, &stop, NULL);
  pid = fork();
  if (pid == 0)
    exec_read_succeed_point(argv, envp, pid, shell);
  else if (pid < 0)
    {
      my_putstr("fork failed\n");
      return;
    }
  else
    wait_command(pid);
}
