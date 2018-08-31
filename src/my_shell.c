/*
** my_shell.c for my_shell in /home/sadiqu-m/delivery/Systeme_unix/PSU_2016_minishell1/src
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Sun Jan 15 14:21:46 2017 Sadiqu-m
** Last update Sun Jan 22 21:45:35 2017 Sadiqu-m
*/

#include "my.h"

int	remove_first(char *str)
{
  int	i;

  i = 0;
  while (str[i] == ' ' || str[i] == '\t')
    i++;
  return (i);
}

char	*my_epurstr(char *str)
{
  int	i;
  int	j;
  char  *new_str;

  new_str = malloc(sizeof(char) * my_strlen(str) + 1);
  i = remove_first(str);
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] != ' ' && str[i] != '\t')
	{
	  new_str[j] = str[i];
	  j++;
	  if (str[i + 1] == ' ' || str[i + 1] == '\t')
	    {
	      new_str[j] = ' ';
	      j++;
	    }
	}
      i++;
    }
  new_str[j] = '\0';
  if (j > 1 && new_str[j - 1] == ' ')
    new_str[j - 1] = '\0';
  return (new_str);
}

char	**my_env(char **env)
{
  int   i;
  char  **new_tab;

  i = 0;
  while (env[i])
    {
      if (env[i][0] == 'P' && env[i][1] == 'A' &&
	  env[i][2] == 'T' && env[i][3] == 'H')
	{
	  if ((new_tab = my_str_tab(env[i])) == NULL)
	    return (NULL);
	  }
      i++;
    }
  return (new_tab);
}

int	mysh(char **env, char **array)
{
  int	readed;
  char	buffer[READ_SIZE];
  char	**arg;
  char  *clean;
  int	res;
  pid_t	pid;

  res = 0;
  while ((readed = read(0, buffer, READ_SIZE)) > 0)
    {
      clean = my_epurstr(buffer);
      if ((arg = my_str_tab(clean)) == NULL)
	return (1);
      if ((res = my_command(arg, array, env, clean, pid)) == 256)
	res = 1;
      if ((my_cd(clean, arg)) == 84)
	res = 1;
      default_prompt();
    }
  if (readed == 0)
    if (isatty(0))
      my_putstr("exit\n");
  return (res);
}
