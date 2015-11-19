/*
** carre.c for carre in /home/duques_a//colle1
** 
** Made by pierre duquesnoy
** Login   <duques_a@epitech.net>
** 
** Started on  Sat Oct  6 15:31:54 2012 pierre duquesnoy
** Last update Sat Oct 27 16:27:23 2012 pierre duquesnoy
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int	param(int taille, char cg, char cd, char centre)
{
  int	i;

  i = 0;
  while ( i < taille)
    {
      if (i == 0)
	{
	  my_putchar(cg);
	}
      else if ( i < taille - 1)
	{
	  my_putchar(centre);
	}
      else
	{
	  my_putchar(cd);
	}
      i++;
    }
}

int	colle(int x, int y)
{
  int	i;
  
  i = 0;

  while ( i < y )
    {
      if ( i == 0)
	{
	  param(x,'A','C','B');
	  my_putchar('\n');
	}
      else if ( i < y - 1 )
	{
	  param(x,'B','B',' ');
	  my_putchar('\n');
	}
      else
	{
	  param(x,'C','A','B');
	  my_putchar('\n');
	}
      i++;
    }
}

int	main()
{
  colle(5, 5);
  return(0);
}
