/*
** main.c for main in /home/casier_s//minishell2-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Mon Feb 25 19:37:56 2013 sofian casier
** Last update Thu Jan  5 08:14:37 2012 sofian casier
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

int	check_pipe(t_shell *shell, char **envp, char **argv)
{
  int	i;

  i = 0;
  while (shell->reader[i] != NULL)
    {
      if (my_strcmp(shell->reader[i], "|") == 0)
	pipe_success(shell, envp, argv);
      else if (my_strcmp(shell->reader[i], ";") == 0)
	exec_read_point(argv, envp, shell);
      i++;
    }
  return (1);
}

int     minishell(char **envp, t_shell *shell, char **argv, int argc)
{
  while (1)
    {
      memory_buff(shell);
      display_invit();
      read_line(shell->buffer);
      shell->tmp = epur_str(shell->buffer);
      if (shell->tmp[0] != '\n' && shell->tmp[0] != '\0')
	{
	  shell->reader = my_read_to_wordtab(shell->tmp);
	  shell->tab = check_env(envp);
	  check_pipe(shell, envp, argv);
	  if (my_strcmp(shell->reader[0], "setenv") == 0)
	    envp = set_env(envp, shell->reader, shell->j);
	  else if (my_strcmp(shell->reader[0], "unsetenv") == 0)
	    envp = un_setenv(envp, shell->reader, shell->j);
	  else if (shell->tmp[0] == 'c' && shell->tmp[1] == 'd')
	    cd(shell->reader, shell->buffer);
	  else
	    exec_read(argv, envp, shell);
	  shell->count++;
	}
      free(shell->buffer);
    }
}

  int     main(int argc, char **argv, char **envp)
  {
    t_shell shell;

    shell.count = 0;
    shell.i = 0;
    error_envp(envp);
    shell.j = my_tab_strlen(envp);
    minishell(envp, &shell, argv, argc);
    return (0);
  }
