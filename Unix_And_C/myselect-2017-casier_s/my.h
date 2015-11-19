/*
** my.h for my.h in /home/casier_s//my_select
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Fri Jan 18 11:32:56 2013 sofian casier
** Last update Sat May 25 17:47:26 2013 sofian casier
*/

typedef struct s_list
{
  int		valeur;
  char		*string;
  struct s_list *prec;
  struct s_list *next;
}		t_list;

typedef struct s_init
{
  t_list	*head;
  t_list	*final;
}		t_init;

typedef struct s_data
{
  int		x;
  int		y;
  char		carac;
  int		count;
  int		i;
}		t_data;

int	my_putint(int c);
char	*modif(int x, int y, int count,
		int argc, char **argv, t_init init);
void	my_putstr2(char *str);
