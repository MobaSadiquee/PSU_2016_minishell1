/*
** my_fonc_shell.c for my_fonc_shell in /home/sadiqu-m/delivery/Systeme_unix/PSU_2016_minishell1/src
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Sun Jan 15 14:55:51 2017 Sadiqu-m
** Last update Sun Jan 22 16:11:51 2017 Sadiqu-m
*/

#include "my.h"

int	my_cd(char *path, char **arg)
{
  if ((hidenp("cd", path)) == 1)
    {
      if (arg[1] != '\0')
	{
	  if (access(arg[1], F_OK) == -1)
	    {
	      my_putstr(arg[1]);
	      my_error(": Aucun fichier ou dossier de ce type.\n");
	      return (84);
	    }
	  else if (access(arg[1], X_OK) == -1)
	    {
	      my_putstr(arg[1]);
	      my_error(": Permission non accordée.\n");
	      return (84);
	    }
	  if ((chdir(arg[1])) == -1)
	    {
	      my_putstr(arg[1]);
	      my_error(": N'est pas un dossier.\n");
	      return (84);
	    }
	}
    }
  return (0);
}

int	wait_child(char *buffer)
{
  int	status;

  wait(&status);
  if (WIFSIGNALED(status))
    {
      if (WTERMSIG(status) == 11)
	{
	  my_error("Segmentation fault (core dumped)\n");
	  status = 139;
	}
    }
  if ((hidenp("cd", buffer)) == 1)
    return (0);
  else
    return (status);
}

int	exec_error(char **array, char **arg, int i, char *buffer)
{
  if (array[i] == 0 && hidenp("cd", buffer) == 0)
    {
      my_putstr(arg[0]);
      my_putstr(": Command not found.\n");
      return (1);
    }
  return (0);
}

int	my_command(char **arg, char **array, char **env, char *buffer, pid_t pid)
{
  char	*str;
  int	i;
  int	status;

  i = 0;
  if ((pid = fork()) == 0)
    {
      if (arg[0] == '\0')
	exit (0);
      else
	{
	  while (array[i])
	    {
	      str = my_strpath(array[i], arg[0]);
	      execve(str, arg, env);
	      i++;
	    }
	  if ((execve(arg[0], arg, env)) == -1)
	      if ((exec_error(array, arg, i, buffer)) == 1)
		exit (1);;
	}
    }
  else if (pid != -1)
    status = wait_child(buffer);
  return (status);
}
