/*
** pipe.c for pipe in /home/casier_s//minishell2-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Feb 28 14:37:20 2013 sofian casier
** Last update Thu Mar  7 15:11:57 2013 sofian casier
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include "my.h"

void	check_tab_env(t_shell *shell)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (shell->tab[i] != NULL)
    {
      if (access(path_dir(shell->tab[i], shell->reader[j]), X_OK) != -1)
        {
          execve(path_dir(shell->tab[i], shell->reader[j]),
                 shell->reader, NULL);
          free(shell->tab);
          free(shell->reader);
          exit(1);
        }
      i++;
    }
  shell->reader[j] = NULL;
}

void	exec_read_succeed_pipe(char **argv, char **envp, pid_t pid,
                               t_shell *shell)
{
  struct sigaction	stop;
  int			fdpipe[2];
  int			error;

  stop.sa_handler = SIG_DFL;
  sigaction(SIGINT, &stop, NULL);
  error = pipe(fdpipe);
  if (error == -1)
    {
      my_putstr("error\n");
      exit (1);
    }
  check_tab_env(shell);
  exec_read_failed();
}

void    exec_read_pipe(char **argv, char **envp, t_shell *shell)
{
  pid_t                 pid;
  struct sigaction      stop;

  stop.sa_flags = 0;
  stop.sa_handler = SIG_IGN;
  sigaction(SIGINT, &stop, NULL);
  pid = fork();
  if (pid == 0)
    exec_read_succeed_pipe(argv, envp, pid, shell);
  else if (pid < 0)
    {
      my_putstr("fork failed\n");
      return;
    }
  else
    wait_command(pid);
}

int	pipe_success(t_shell *shell, char **envp, char **argv)
{
  exec_read_pipe(argv, envp, shell);
  return (1);
}
