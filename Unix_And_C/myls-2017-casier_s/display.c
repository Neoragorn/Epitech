/*
** display.c for display in /home/casier_s/os-home/myls-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sat Dec  1 20:03:23 2012 sofian casier
** Last update Sun Dec  2 16:49:49 2012 sofian casier
*/

#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"

int     display_current_option(void)
{
  DIR*		rep;
  struct dirent	*readfile;

  rep = opendir(".");
  while ((readfile = readdir(rep)) != NULL)
    {
      if ((readfile->d_name)[0] != '.')
        {
          my_putstr(readfile->d_name);
          my_putstr(",  ");
        }
    }
  my_putchar('\n');
  exit(1);
}

int	display_current_hidden_option(void)
{
  DIR *rep;
  struct dirent	*readfile;

  rep = opendir(".");
  while ((readfile = readdir(rep)) != NULL)
    {
      my_putstr(readfile->d_name);
      my_putstr(",  ");
    }
  my_putchar('\n');
  exit(1);
}

int     display_path_option(char *path)
{
  DIR*		rep;
  struct dirent	*readfile;

  rep = opendir(path);
  while ((readfile = readdir(rep)) != NULL)
    {
      if ((readfile->d_name)[0] != '.')
        {
          my_putstr(readfile->d_name);
          my_putstr(",  ");
        }
    }
  my_putchar('\n');
  exit(1);
}

int	display_path_hidden_option(char *path)
{
  DIR *rep;
  struct dirent	*readfile;

  rep = opendir(path);
  while ((readfile = readdir(rep)) != NULL)
    {
      my_putstr(readfile->d_name);
      my_putstr(",  ");
    }
  my_putchar('\n');
  exit(1);
}
