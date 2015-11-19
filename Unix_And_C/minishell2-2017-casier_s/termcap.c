/*
** termcap.c for term cap in /home/casier_s//alumi
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Wed Jan 30 16:24:15 2013 sofian casier
** Last update Sun Feb 24 19:36:29 2013 sofian casier
*/

#include <termios.h>
#include <curses.h>
#include <term.h>
#include <stdlib.h>
#include <stdio.h>

int     my_putint(int c)
{
  write(1, &c, 1);
}

int     clear_window()
{
  struct termios	term;
  char			*capacity;

  if (tgetent(NULL, "xterm") == -1)
    exit(1);
  else if (tgetent(NULL, "xterm") == 0)
  {
    my_putstr("Xterm n'existe pas");
    exit(1);
  }
  else
    {
      capacity = tgetstr("cl", NULL);
      tputs(capacity, 1, my_putint);
    }
}
