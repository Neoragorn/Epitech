/*
** read_cur.c for read current in /home/casier_s/os-home/tpmyls
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Fri Nov 30 15:30:43 2012 sofian casier
** Last update Sun Dec  2 00:02:12 2012 sofian casier
*/

#include <stdlib.h>
#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include "my.h"

int     read_current_dir(int argc, char **argv, DIR *rep)
{
  struct dirent *readfile;

  while ((readfile = readdir(rep)) != NULL)
    {
      if ((readfile->d_name)[0] != '.')
	{
	  my_putstr(readfile->d_name);
	  my_putchar('\t');
	}
    }
  my_putchar('\n');
  return (1);
}

int     full_info_dir(int argc, char **argv, DIR *rep, char *path)
{
  struct dirent		*readfile;
  struct stat           statut;
  struct group          getgr;
  struct passwd         user;

  while ((readfile = readdir(rep)) != NULL)
    {
      lstat(path_dir(path, readfile->d_name), &statut);
      type_file(&statut, readfile);
      right_file(readfile, &statut);
      info_file(&statut, &user, &getgr);
      timels(&statut);
      my_putstr(readfile->d_name);
      my_putchar('\n');
    }
  return (1);
}

int     no_hidden_info_dir(int argc, char **argv, DIR *rep, char *path)
{
  struct dirent		*readfile;
  struct stat           statut;
  struct group          getgr;
  struct passwd         user;

  while ((readfile = readdir(rep)) != NULL)
    {
      lstat(path_dir(path, readfile->d_name), &statut);
      if ((readfile->d_name)[0] != '.')
	{
	  type_file(&statut, readfile);
	  right_file(readfile, &statut);
	  info_file(&statut, &user, &getgr);
	  timels(&statut);
	  my_putstr(readfile->d_name);
	  my_putchar('\n');
	}
    }
  return (1);
}

int     full_info_current_dir(int argc, char **argv, DIR *rep)
{
  struct dirent		*readfile;
  struct stat           statut;
  struct group          getgr;
  struct passwd         user;

  while ((readfile = readdir(rep)) != NULL)
    {
      lstat(readfile->d_name, &statut);
      {
	type_file(&statut, readfile);
	right_file(readfile, &statut);
	info_file(&statut, &user, &getgr);
	timels(&statut);
	my_putstr(readfile->d_name);
	my_putchar('\n');
      }
    }
  exit(1);
}

int     info_dir_current(int argc, char **argv, DIR *rep)
{
  struct dirent		*readfile;
  struct stat           statut;
  struct group          getgr;
  struct passwd         user;

  while ((readfile = readdir(rep)) != NULL)
    {
      lstat(readfile->d_name, &statut);
      if ((readfile->d_name)[0] != '.')
	{
	  type_file(&statut, readfile);
	  right_file(readfile, &statut);
	  info_file(&statut, &user, &getgr);
	  timels(&statut);
	  my_putstr(readfile->d_name);
	  my_putchar('\n');
	}
    }
  exit(1);
}
