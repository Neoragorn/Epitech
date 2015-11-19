/*
** my_getnbr.c for my_getnbr in /afs/epitech.net/users/epitech_2017/duques_a/rendu/piscine/Jour_04
** 
** Made by pierre duquesnoy
** Login   <duques_a@epitech.net>
** 
** Started on  Thu Oct  4 13:58:48 2012 pierre duquesnoy
** Last update Tue Nov 13 11:15:32 2012 pierre duquesnoy
*/

int	my_get_nbr(char *str)
{
  int	a;
  int	b;
  int	c;
  int	neg;
  int	nb;

  a = 0;
  neg = 1;
  nb = 0;
  c = 1;
  b = 0;

  while (str[b] >= '0' && str[b++] <= '9')
    c *= 10;
  while (str[a] >= '0' && str[a] <= '9')
    {
      c /= 10;
      nb += (str[a++] - '0') * c;
    }
  return (nb * neg);
}
