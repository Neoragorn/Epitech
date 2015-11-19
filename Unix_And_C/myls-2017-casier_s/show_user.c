/*
** show_user.c for show user in /home/casier_s/os-home/myls-2017-casier_s
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Fri Dec  7 14:37:54 2012 sofian casier
** Last update Fri Dec  7 14:42:36 2012 sofian casier
*/

#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <grp.h>
#include <pwd.h>

int	main(int argc, char **argc)
{
  struct dirent *readfile;
  DIR		*rep;

  rep = opendir(argv[1]);

  while ((readfile = readdir(rep)) != NULL)
    {
      
    }
  
}
