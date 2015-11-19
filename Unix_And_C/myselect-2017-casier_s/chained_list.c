/*
** chained_list.c for chained list in /home/casier_s//my_select
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sun Jan 20 17:00:03 2013 sofian casier
** Last update Sat May 25 17:47:14 2013 sofian casier
*/

#include <stdlib.h>
#include <curses.h>
#include <term.h>
#include <termios.h>
#include <curses.h>
#include "my.h"

char *add(t_init *init, char *txt)
{
  t_list *element;

  element = malloc(sizeof(t_list));
  if (!element)
    exit(1);
  element->prec = NULL;
  element->string = txt;
  element->next = init->head;
  if (init->head)
    init->head->prec = element;
  else
    init->final = element;
  init->head = element;
}

int     initiate(t_init *init)
{
  init->head = NULL;
  init->final = NULL;
}

void display(t_init *init)
{
  t_list *list;

  list = init->final;
  while (list)
    {
      my_putstr(list->string);
      my_putchar('\n');
      list = list->prec;
    }
}

char     *modif(int x, int y, int count,
	      int argc, char **argv, t_init init)
{
  char	carac;

  while (carac != '\n')
    {
      read(0, &carac , 1);
      /*      if (carac == 65)
        up_cursor(x, y--);
      if (carac == 66)
        down_cursor(x, y++);
      if (carac == 67)
        right_cursor(x++, y);
      if (carac == 68)
        left_cursor(x--, y);
      */
      if (carac == 32)
        {
          clear_window();
          display(&init);
          underline(argc, argv, count);
          count++;
          if (count == argc)
            count = 1;
        }
    }
  final_msg(argv, count, argc);
    if (count - 1 == 0)
      count = argc;
  return (argv[count - 1]);
}
