/*
** my.h for ly.h in /home/casier_s/os-home/minishell
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Mon Dec 24 16:28:57 2012 sofian casier
** Last update Thu Mar  7 21:48:12 2013 sofian casier
*/

#ifndef __MY___
#define __MY___

typedef struct s_shell
{
  char *buffer;
  char **reader;
  char **tab;
  char *tmp;
  int	i;
  int	j;
  int	count;
  char	**envp2;
  char	**tmp2;
}	t_shell;

typedef struct s_str
{
  int	x;
  int	i;
  int	j;
  char	**dest;
}	t_str;

typedef struct s_readword
{
  int	i;
  int	j;
  int	x;
  char	**dest;
}	t_readword;

char	**un_setenv(char **envp, char **reader, int j);
char	**set_env(char **envp, char **reader, int j);
int	my_putint(int c);
char	*read_line(char *buffer);
char	**check_env(char **envp);
char	**my_read_to_wordtab(char *str);
char	**my_env_to_wordtab(char *str, char **envp);
char	*epur_str2(char *str, int i, char *tmp);
char	*epur_str(char *str);
void    my_putchar(char c);
void    my_putstr(char *str);
int     my_strlen(char *str);
int     space(char *str);
int     word(char *str);
void    putnbr(int nb);
void    my_put_nbr(int nb);
char    *path_dir(char *path, char *readfile);
int     my_strcmp(char *str, char *dest);
void    wait_command(pid_t pid);
int     my_strcmp(char *str, char *dest);
int     my_strncmp(char *s1, char *s2, int nb);
char    *read_line(char *buffer);
int     count_space(char *str, char c);
char    *my_strncpy(char *dest, char *src, int nb);

#endif /*__MY__*/
