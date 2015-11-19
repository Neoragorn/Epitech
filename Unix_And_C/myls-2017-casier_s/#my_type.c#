/*
** my_files.c for my files in /home/casier_s/os-home/tpmyls
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Wed Nov 28 14:19:10 2012 sofian casier
** Last update Sun Dec  2 16:57:02 2012 sofian casier
*/

#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include "my.h"

DIR	*current_dir(int argc, char **argv)
{
  struct dirent *readfile;
  DIR		*rep;

  rep = opendir(".");
  while ((readfile = readdir(rep)) != NULL)
    {
      if ((readfile->d_name)[0] != '.')
      	{
	  my_putstr(readfile->d_name);
	  my_putstr("  ");
	}
    }
  my_putchar('\n');
  closedir(rep);
  return (rep);
}

char	*path_dir(char *path, char *readfile)
{
  char *tmp;
  int   i;
  int   j;

  j = 0;
  i = 0;
  tmp  = malloc(my_strlen(path) + my_strlen(readfile) + 2);
  while (path[i] != 0)
    {
      tmp[i] = path[i];
      i++;
    }
  tmp[i++] = '/';
  while (readfile[j] != 0)
    {
      tmp[i] = readfile[j];
      j++;
      i++;
    }
  return (tmp);
}

DIR	*wrong_dir(int argc, char **argv, DIR *rep)
{
  my_putstr("Cannot open the file or the directory \n");
  exit(0);
}

DIR	*check_option(int argc, char **argv, DIR *rep, char *path)
{
  if (argc > 3)
    {
      my_putstr("I do not take so many parameters, sorry \n");
      return (0);
    }
  if (argv[2][0] == '-' && (argv[2][1] == 'm' && argv[2][2] == 0))
    display_current_option();
  if (argv[2][0] == '-' && (argv[2][1] == 'm' || argv[2][1] == 'a'))
    {
      if (argv[1][1] == 'a'|| argv[1][2] == 'm')
        display_path_hidden_option(path);
      else if (argv[2][1] == 'm' || argv[2][2] == 'a')
        display_path_hidden_option(path);
    }
  if (argv[2][0] == '-' && argv[2][1] == 'l')
    {
      if (argv[2][2] == 'a')
	full_info_dir(argc, argv, rep, path);
    }
  if (argv[2][0] == '-' && argv[2][1] == 'l')
    no_hidden_info_dir(argc, argv, rep, path);
  return (rep);
}
