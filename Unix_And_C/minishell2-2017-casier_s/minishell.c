/*
** minishell.c for minishell in /home/casier_s/os-home/minishell
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Fri Dec 14 15:10:26 2012 sofian casier
** Last update Mon Jan  2 10:10:45 2012 sofian casier
*/

#define READ (4096)
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include "my.h"

char	*read_line(char *buffer)
{
  int	i;
  int	x;

  i = 0;
  x = read(0, buffer, READ);
  if (x == -1)
    {
      my_putchar('\n');
      exit (1);
    }
  if (x == 0)
      exit(1);
  if (buffer[x - 1] != '\n')
    exit(1);
  while (buffer[i] != '\n')
    i++;
  buffer[i] = '\0';
  return (buffer);
}

void	exec_read(char **argv, char **envp, t_shell *shell)
{
  pid_t			pid;
  struct sigaction      stop;

  stop.sa_flags = 0;
  stop.sa_handler = SIG_IGN;
  sigaction(SIGINT, &stop, NULL);
  pid = fork();
  if (pid == 0)
    exec_read_succeed(argv, envp, pid, shell);
  else if (pid < 0)
    {
      my_putstr("fork failed\n");
      return;
    }
  else
    wait_command(pid);
}

void	display_invit()
{
  my_putstr("casier_s> ");
  return;
}

char	**check_env(char **envp)
{
  int			i;
  char			*buffer;
  char			**tab;

  i = 0;
  while (envp[i] != NULL)
    {
      if (my_strncmp(envp[i], "PATH=", 5) == 0)
	{
	  buffer = malloc(my_strlen(envp[i]) * sizeof(char) + 1);
	  my_strcpy(buffer, envp[i]);
	  tab = my_env_to_wordtab(buffer, envp);
	  return (tab);
	}
      i++;
    }
  return (tab);
}
