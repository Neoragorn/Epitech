/*
** cursor.c for cursor in /home/casier_s//my_select
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sun Jan 20 16:55:45 2013 sofian casier
** Last update Sun Jan 20 17:04:33 2013 sofian casier
*/

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <termios.h>
#include <curses.h>
#include "my.h"

int     left_cursor(int x, int y)
{
  struct termios term;
  char		*cursor;
  char		*togo;
  char		buffer[5000];

  if (tgetent(buffer, "xterm") == -1)
    exit (1);
  togo = tgetstr("cm", NULL);
  cursor = tgoto(togo, (x - 1), (y));
  tputs(cursor, 1, my_putint);
  return (x);
}

int     right_cursor(int x, int y)
{
  struct termios term;
  char		*cursor;
  char		*togo;
  char		buffer[5000];

  if (tgetent(buffer, "xterm") == -1)
    exit (1);
  togo = tgetstr("cm", NULL);
  cursor = tgoto(togo, (x + 1), (y));
  tputs(cursor, 1, my_putint);
  return (x);
}

int     up_cursor(int x, int y)
{
  struct termios term;
  char		*cursor;
  char		*togo;
  char		buffer[5000];

  if (tgetent(buffer, "xterm") == -1)
    exit (1);
  togo = tgetstr("cm", NULL);
  cursor = tgoto(togo, (x), (y - 1));
  tputs(cursor, 1, my_putint);
  return (y);
}

int     down_cursor(int x, int y)
{
  struct termios term;
  char		*cursor;
  char		*togo;
  char		buffer[5000];

  if (tgetent(buffer, "xterm") == -1)
    exit (1);
  togo = tgetstr("cm", NULL);
  cursor = tgoto(togo, (x), (y + 1));
  tputs(cursor, 1, my_putint);
  return (y);
}
