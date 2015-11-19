/*
** base_fonc2.c for base in /home/casier_s//minitalk
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Mon Mar 18 18:49:16 2013 sofian casier
** Last update Mon Mar 18 18:49:24 2013 sofian casier
*/

int     my_getnbr(char *str)
{
  int   a;
  int   c;
  int   result;

  a = 0;
  c = 0;
  result = 0;
  while (str[a] == '+' || str[a] == '-')
    {
      if (str[a] == '-')
        c++;
      a++;
    }
  while (str[a] <= '9' && str[a] >= '0')
    {
      result = (result * 10) + str[a] - 48;
      a++;
    }
  if ((c % 2) != 0)
    result = result * -1;
  return (result);
}
