/*
** my_getnbr.c for my_putnbr in /home/casier_s//afs/rendu/lib/my
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Wed Oct 10 10:48:41 2012 sofian casier
** Last update Mon Oct 22 17:11:26 2012 sofian casier
*/

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	n;
  int	compteur;
  int	j;

  compteur = 0;
  n = 0;
  i = my_strlen(str);
  while (str[n] == '+' || str[n] == '-')
    {
      if (str[n] == '-')
	{
	  compteur++;
	}
      n++;
      i--;
    }
  j = my_getnbr2(str, i, n, compteur);
}

int	my_getnbr2(char *str, int i, int n, int compteur)
{
  int	nb;

  nb = 0;
  if (compteur % 2 == 1)
    {
      my_putchar('-');
    }
  while (i > 0 && str[n] >= '0' && str[n] <= '9')
    {
      nb = (nb * 10) + (str[n] - '0');
      i--;
      n++;
    }
  return (nb);
}
