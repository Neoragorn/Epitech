/*
** my_functions.c for my_functions in /home/liagre_c//Math/105
** 
** Made by clement liagre
** Login   <liagre_c@epitech.net>
** 
** Started on  Mon Jan 14 14:27:16 2013 clement liagre
** Last update Tue Jan 15 12:08:48 2013 sofian casier
*/

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putnbr(int nbr)
{
  int	a;

  a = 1;
  if (nbr < 0)
    nbr = nbr * -1;
  if (nbr >= 10)
    {
      my_putnbr(nbr / 10);
      my_putnbr(nbr % 10);
    }
  else
    my_putchar(48 + nbr);
}

int	my_swap(float a, float b)
{
  float c;

  c = a;
  a = b;
  b = c;
}
