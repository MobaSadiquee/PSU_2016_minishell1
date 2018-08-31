/*
** my.h for my.h in /home/sadiqu-m/delivery/Systeme_unix/PSU_2016_minishell1/include
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Sun Jan 15 14:33:36 2017 Sadiqu-m
** Last update Sun Jan 22 16:40:40 2017 Sadiqu-m
*/

#ifndef _MY_H_
# define _MY_H_

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

void	my_putchar(char c);
void	my_putstr(char *str);
void	default_prompt();
void	signal_prompt();
int	my_strlen(char *str);
int	hidenp(char *s1, char *s2);
int	my_cd(char *buffer, char **arg);
int	wait_child();
int	my_command(char **arg, char **array, char **env, char *buffer, pid_t pid);
int	mysh(char **env, char **array);
int	my_error(char *str);
int	wait_child(char *buffer);
int	exec_error(char **array, char **arg, int i, char *buffer);
int	remove_first(char *str);
int	remove_space_double(char *str, int i);
char	**my_env(char **env);
char	**my_str_tab(char *str);
char	*my_strpath(char *array, char *arg);
char	*my_epurstr(char *str);
char	*get_bin_path(char *filename, char **env);
char	*my_strcpy(char *dest, char *src);

#ifndef READ_SIZE
# define READ_SIZE 4096

#endif /* _READ_SIZE_ */
#endif /* _MY_H_ */
