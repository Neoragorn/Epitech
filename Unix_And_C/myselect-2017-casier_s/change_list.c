/*
** change_list.c for change list in /home/casier_s//my_select
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sun Jan 20 17:05:37 2013 sofian casier
** Last update Sat May 25 18:08:07 2013 sofian casier
*/

#include <term.h>
#include <termios.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void	final_msg(char **argv, int count, int argc)
{
  my_putstr2("\nLa donnée selectionnée est ");
  if (count + 1 == argc - (argc - 2))
    my_putstr2(argv[argc - 1]);
  else
    my_putstr2(argv[count - 1]);
  my_putchar('\n');
}

int     no_show_carac()
{
  struct termios term;
  char          buffer[4096];

  tcgetattr(0, &term);
  if (tgetent(buffer, "xterm") == -1)
    exit (1);
  term.c_lflag &= ~ICANON;
  term.c_lflag &= ~ECHO;
  if ((tcsetattr(0, 0, &term)) == -1)
    {
      my_putstr("doesnt work");
      return (1);
    }
}

int     underline(int argc, char **argv, int count)
{
  struct termios term;
  char buffer[5000];
  char *capacity;

  if (tgetent(buffer, "xterm") == -1)
    exit (1);
  capacity = tgetstr("mr", NULL);
  tputs(capacity, 1, my_putint);
  my_putstr(argv[count]);
  capacity = tgetstr("me", NULL);
  tputs(capacity, 1, my_putint);
}

void    my_putchar2(char c)
{
  write(1, &c, 1);
}

void	my_putstr2(char *str)
{
  int   m;

  m = 0;
  while (str && str[m])
    {
      my_putchar2(str[m]);
      m++;
    }
}
