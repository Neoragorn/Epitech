/*
** right_type.c for right and type in /home/casier_s/os-home/tpmyls
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Nov 29 19:42:21 2012 sofian casier
** Last update Fri Nov 30 16:33:47 2012 sofian casier
*/

#include <pwd.h>
#include <grp.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>
#include "my.h"

int     right_file(struct dirent *readfile, struct stat *statut)
{
  char	str[11] = "--------- ";

  if ((statut->st_mode & S_IRUSR) != 0)
    str[0] = 'r';
  if ((statut->st_mode & S_IWUSR) != 0)
    str[1] = 'w';
  if ((statut->st_mode & S_IXUSR) != 0)
    str[2] = 'x';
  if ((statut->st_mode & S_IRGRP) != 0)
    str[3] = 'r';
  if ((statut->st_mode & S_IWGRP) != 0)
    str[4] = 'w';
  if ((statut->st_mode & S_IXGRP) != 0)
    str[5] = 'x';
  if ((statut->st_mode & S_IROTH) != 0)
    str[6] = 'r';
  if ((statut->st_mode & S_IWOTH) != 0)
    str[7] = 'w';
  if ((S_IXOTH & statut->st_mode) != 0)
    str[8] = 'x';
  my_putstr(str);
  return (0);
}

int   type_file(struct stat *statut, struct dirent *readfile)
{
  if (S_ISLNK(statut->st_mode) != 0)
    my_putstr("l");
  else if (S_ISREG(statut->st_mode) != 0)
    my_putstr("-");
  else if (S_ISDIR(statut->st_mode) != 0)
    my_putstr("d");
  else if (S_ISCHR(statut->st_mode) != 0)
    my_putstr("c");
  else if (S_ISBLK(statut->st_mode) != 0)
    my_putstr("b");
  else if (S_ISFIFO(statut->st_mode) != 0)
    my_putstr("p");
  else if (S_ISSOCK(statut->st_mode) != 0)
    my_putstr("s");
  return (0);
}
