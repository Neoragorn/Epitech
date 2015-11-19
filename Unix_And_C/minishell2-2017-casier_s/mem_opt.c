/*
** mem_opt.c for mem opt in /home/casier_s//minishell2-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sun Feb 24 18:03:12 2013 sofian casier
** Last update Sun Mar 10 17:18:45 2013 sofian casier
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int     cd(char **reader, char *buffer)
{
  if (reader[1] == NULL)
    chdir("/home");
  else if (chdir(reader[1]) == -1)
      my_putstr("No such file or directory\n");
  return (1);
}

int     error_envp(char **envp)
{
  if (envp == NULL)
    {
      my_putstr("An environement is necessary");
      return (1);
    }
}

int     memory_buff(t_shell *shell)
{
  shell->buffer = malloc(4096 * sizeof(char));
  shell->reader = malloc(6000 * sizeof(char *));
  while (shell->reader[shell->i] != NULL)
    {
      shell->reader[shell->i] = malloc(10000 * sizeof(char));
      shell->i++;
    }
}

char	**un_setenv(char **envp, char **reader, int j)
{
  int		i;
  char		**envp2;

  if (reader[1] == NULL)
    return (envp);
  if (my_tab_strlen(envp) < j)
    error_env();
  envp2 = malloc(my_tab_strlen(envp) * sizeof(char *) + 1000);
  if (envp2 == NULL)
    exit (1);
  i = 0;
  while (envp[i] != NULL)
    {
      if (my_strcmp(reader[1], envp[i]) == 0)
	i++;
      if (envp[i] == NULL)
	return (envp2);
      envp2[i] = envp[i];
      i++;
    }
  envp2[i + 1] = NULL;
  return (envp2);
}

char   	**set_env(char **envp, char **reader, int j)
{
  int		i;
  static char	**envp2;

  if (reader[1] == NULL)
    {
      my_putstr("No arguments\n");
      return (envp);
    }
  if (my_tab_strlen(envp) < j)
    error_env();
  envp2 = malloc(my_tab_strlen(envp) * sizeof(char *) + 1000);
  if (envp2 == NULL)
    exit (1);
  i = 0;
  while (envp[i] != NULL)
    {
      envp2[i] = envp[i];
      i++;
    }
  envp2[i] = reader[1];
  envp2[i + 1] = NULL;
  return (envp2);
}
