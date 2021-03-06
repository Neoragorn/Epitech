/*
** wait.c for wait in /home/casier_s/os-home/minishell
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sun Dec 30 14:51:12 2012 sofian casier
** Last update Thu Jan  5 08:19:12 2012 sofian casier
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include "my.h"

void    wait_command(pid_t pid)
{
  int   status;
  int   i;

  while (1)
    {
      i = waitpid(pid, &status, 0);
      if (i < 0 )
        {
          if (i == EINTR)
            continue;
          my_putstr("erreur de waitpid\n");
          return;
        }
      if (WIFEXITED(status))
	return;
      if (WIFSIGNALED(status))
        {
          my_putstr("terminaison par signal\n");
          return;
        }
    }
}

void	show_env(char **envp)
{
  int	i;

  i = 0;
  while (envp[i] != NULL)
    {
      my_putstr(envp[i]);
      my_putchar('\n');
      i++;
    }
  exit(1);
}

void	check_first(char **argv, char **envp, pid_t pid, t_shell *shell)
{
  int	i;

  i = 0;
    if (shell->buffer[0] == 'l' && shell->buffer[1] == 's'
	&& shell->buffer[3] == ' ' && shell->buffer[4] == '\0')
    {
      execve(path_dir("/bin/", "ls"), argv, NULL);
      exit(1);
    }
  if (my_strncmp(shell->buffer, "cd", 2) == 0)
    {
      i = chdir(shell->reader[1]);
      exit(1);
    }
  else if (my_strcmp(shell->buffer, "exit") == 0)
    {
      kill(pid, 1);
      exit(1);
    }
  else if (my_strcmp(shell->buffer, "env") == 0)
    show_env(envp);
  else if (my_strcmp(shell->buffer, "clear") == 0)
    clear_window();
}

void    exec_read_failed()
{
  struct sigaction	stop;

  stop.sa_handler = SIG_DFL;
  sigaction(SIGINT, &stop, NULL);
  my_putstr("impossible to execute\n");
  exit(0);
}

void    exec_read_succeed(char **argv, char **envp, pid_t pid, t_shell *shell)
{
  struct sigaction	stop;
  int			i;
  int			j;

  j = 0;
  i = 0;
  stop.sa_handler = SIG_DFL;
  sigaction(SIGINT, &stop, NULL);
  check_first(argv, envp, pid, shell);
  while (shell->tab[i] != NULL)
    {
      if (access(path_dir(shell->tab[i], shell->reader[j]), X_OK) != -1)
	{
	  execve(path_dir(shell->tab[i], shell->reader[j]),
		 shell->reader, envp);
	  exit(1);
	}
      i++;
    }
  shell->reader[j] = NULL;
  exec_read_failed();
}
