/*
** info_time.c for info & time in /home/casier_s/os-home/tpmyls
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Fri Nov 30 12:20:08 2012 sofian casier
** Last update Sun Dec  2 16:27:52 2012 sofian casier
*/

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <pwd.h>
#include <time.h>
#include <grp.h>
#include "my.h"

int	manage_os(struct stat *statut, struct group *getgr,
		  struct passwd *user)
{
  my_put_nbr(statut->st_nlink);
  my_putchar('\t');
  my_put_nbr(statut->st_uid);
  my_putchar('\t');
  my_putstr(getgr->gr_name);
  my_putchar('\t');
  my_put_nbr(statut->st_size);
  my_putchar('\t');
  return (1);
}

int	manage_os2(struct stat *statut, struct group *getgr,
		   struct passwd *user)
{
  my_put_nbr(statut->st_nlink);
  my_putchar('\t');
  my_putstr(user->pw_name);
  my_putchar('\t');
  my_put_nbr(statut->st_gid);
  my_putchar('\t');
  my_put_nbr(statut->st_size);
  my_putchar('\t');
  return (1);
}

int	manage_os3(struct stat *statut, struct group *getgr,
		   struct passwd *user)
{
  my_put_nbr(statut->st_nlink);
  my_putchar('\t');
  my_put_nbr(statut->st_uid);
  my_putchar('\t');
  my_put_nbr(statut->st_gid);
  my_putchar('\t');
  my_put_nbr(statut->st_size);
  my_putchar('\t');
  return (1);
}

int     info_file(struct stat *statut, struct passwd *user,
		  struct group *getgr)
{
  getgr = getgrgid(statut->st_gid);
  user = getpwuid(statut->st_uid);
  if (user == NULL)
    manage_os(statut, getgr, user);
  else if (getgr == NULL)
    manage_os2(statut, getgr, user);
  else if (getgr == NULL && user == NULL)
    manage_os3(statut, getgr, user);
  else
    {
      my_put_nbr(statut->st_nlink);
      my_putchar('\t');
      my_putstr(user->pw_name);
      my_putchar(' ');
      my_putstr(getgr->gr_name);
      my_putchar(' ');
      my_put_nbr(statut->st_size);
      my_putchar('\t');
    }
  return (0);
}

int     timels(struct stat *statut)
{
  int   i;
  char  *date;

  i = 5;
  date = malloc(sizeof(char) * 256);
  date = ctime(&(statut->st_mtime));
  my_putchar(date[4] + 32);
  while (i != 16)
    {
      if (i == 7)
        my_putstr(". ");
      my_putchar(date[i]);
      i++;
    }
  my_putchar(' ');
  return (1);
}
