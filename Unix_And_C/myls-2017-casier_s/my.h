/*
** my.h for my.h in /home/casier_s/os-home/tpmyls
** 
** Made by sofian casier
** Login   <casier_s@epitech.net>
** 
** Started on  Thu Nov 29 20:02:49 2012 sofian casier
** Last update Sun Dec  2 16:53:57 2012 sofian casier
*/

#ifndef	LS_H_
#define	LS_H_

int	full_info_current_dir(int argc, char **argv, DIR *rep);
int	option_current(int argc, char **argv);
int	option_current2(int argc, char **argv);
char	*path_dir(char *path, char *readfile);
DIR	*check_option(int argc, char **argv, DIR *rep, char *path);
void	my_putchar(char c);
int	my_putstr(char *str);
int	my_put_nbr(int nb);
int	my_strlen(char *str);
int     info_file(struct stat *statut, struct passwd *user,
		  struct group *getgr);
int     timels(struct stat *statut);
int     right_file(struct dirent *readfile, struct stat *statut);
int	type_file(struct stat *statut, struct dirent *readfile);
DIR	*current_dir(int argc, char **argv);
DIR	*wrong_dir(int argc, char **argv, DIR *rep);
int     full_info_dir(int argc, char **argv, DIR *rep, char *path);
int	read_current_dir(int argc, char **argv, DIR *rep);
int	no_hidden_info_dir(int argc, char **argv, DIR *rep, char *path);
int	info_dir_current(int argc, char **argv, DIR *rep);
int	main_3(char **argv, int argc, char *path);
int	main_2(char **argv, int argc, char *path);
int	display_current_option();
int	display_current_hidden_option();
int	manage_os(struct stat *statut, struct group *getgr,
		  struct passwd *user);
int	manage_os2(struct stat *statut, struct group *getgr,
		   struct passwd *user);
int	manage_os2(struct stat *statut, struct group *getgr,
		   struct passwd *user);
int	display_path_hidden_option(char *path);
int	display_path_option(char *path);
#endif
