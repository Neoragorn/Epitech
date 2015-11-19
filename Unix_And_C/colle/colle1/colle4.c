/*
** colle4.c for colle in /home/casier_s//colle1
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Sat Oct 27 18:47:41 2012 sofian casier
** Last update Sat Oct 27 21:16:48 2012 sofian casier
*/

int     my_putchar(char c)
{
  write(1, &c, 1);
}

int     my_putstr(char *str)
{
  int   i;

  i = 0;
  while (str[i] != 0)
    {
      my_putchar(str[i]);
      i++;
    }
}

int     cat(int fd)
{
  int   ret;
  char  buffer[30000];
  int   i;

  ret = read(fd, buffer, 30000);
  while ( ret != 0)
    {
      i = 0;
      if ( ret == -1)
        {
          close(fd);
          my_putstr("error in file \n");
          return (1);
        }
      else
        {
          while (i < ret)
            {
              my_putchar(buffer[i]);
              i++;
            }
          ret = read(fd, buffer, 30000);
        }
      return (0);
    }
}

int     main(int argc, char **argv)
{
