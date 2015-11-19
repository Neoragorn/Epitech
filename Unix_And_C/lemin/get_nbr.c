/*
** get_nbr.c for get in /home/casier_s//lemin
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Wed Apr  3 16:36:09 2013 sofian casier
** Last update Tue Apr 23 15:58:11 2013 clement lovergne
*/

#include	"funct.h"

int		my_getnbr_neg(char *str, int i)
{
  int		c;

  c = 1;
  while (i >= 0 && (str[i] == 45 || str[i] == 43))
    {
      if (str[i] == 45)
        c = c * -1;
      i--;
    }
  return (c);
}

int		my_getnbr_calc(char *str, int i, int a)
{
  int		nb;
  int		c;

  nb = 0;
  while ((!(str[i] >= 48 && str[i] <= 57)) || str[i] != '\0')
    {
      if (str[i] >= 48 && str[i] <= 57)
        {
          a = i;
          i--;
          while (str[a] >= 48 && str[a] <= 57 && str[a] != '\0')
            {
              nb *= 10;
              nb = nb + (str[a] - 48);
              a++;
            }
          c = my_getnbr_neg(str, i);
          nb = nb * c;
          return (nb);
        }
      i++;
    }
  return (0);
}

int		my_getnbr(char *str)
{
  int		i;
  int		a;
  int		nb;

  a = 0;
  i = 0;
  nb = my_getnbr_calc(str, i, a);
  if (nb <= 2147483647 || nb >= -2147483647)
    return (nb);
  else
    return (0);
}

/*
void    putnbr(int nb, t_parcer *parcer)
{
  int   n;

  if (nb != 0)
    {
      n = nb % 10;
      putnbr(nb / 10);
      my_putchar('0' + n);
    }
}

void    my_put_nbr(int nb)
{
  if (nb < 0)
    parcer->room_number[0] = '-';
  if (nb == 0)
    my_putchar('0');
  putnbr(nb);
}

*/
