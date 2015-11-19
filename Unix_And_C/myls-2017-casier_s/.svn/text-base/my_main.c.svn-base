/*
** my_main.c for main c in /home/casier_s/os-home/myls-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sat Dec  1 16:07:24 2012 sofian casier
** Last update Sun Dec  2 16:45:10 2012 sofian casier
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <dirent.h>
#include <grp.h>
#include "my.h"

int	option_current(int argc, char **argv)
{
  DIR	*rep;

  rep = opendir(".");
  info_dir_current(argc, argv, rep);
  return (1);
}

int	option_current2(int argc, char **argv)
{
  DIR	*rep;

  rep = opendir(".");
  full_info_current_dir(argc, argv, rep);
  return (1);
}

int	main_2(char **argv, int argc, char *path)
{
  DIR	*rep;

  if (argv[1][0] == '-' && (argv[1][1] == 'm' && argv[1][2] == 0))
    display_current_option();
  if (argv[1][0] == '-' && (argv[1][1] == 'm' || argv[1][1] == 'a'))
    {
      if (argv[1][1] == 'a'|| argv[1][2] == 'm')
	display_current_hidden_option();
      else if (argv[1][1] == 'm' || argv[1][2] == 'a')
	display_current_hidden_option();
    }
  if (argv[1][0] == '-' && argv[1][1] == 'l')
    {
      if (argv[1][2] == 'a')
	option_current2(argc, argv);
      option_current(argc, argv);
    }
  rep = opendir(argv[1]);
  if (rep == NULL)
    wrong_dir(argc, argv, rep);
  read_current_dir(argc, argv, rep);
  closedir(rep);
  return (1);
}

int	main_3(char **argv, int argc, char *path)
{
  DIR	*rep;

  rep = opendir(argv[1]);
  if (rep == NULL)
    return (my_putstr("This directory or file cannot be found \n"));
  rep = check_option(argc, argv, rep, path);
  closedir(rep);
  return (1);
}

int     main(int argc, char **argv)
{
  char	*path;

  path = argv[1];
  if (argc == 1)
    current_dir(argc, argv);
  else if (argc == 2)
    main_2(argv, argc, path);
  else if (argc >= 3)
    main_3(argv, argc, path);
  return (1);
}
