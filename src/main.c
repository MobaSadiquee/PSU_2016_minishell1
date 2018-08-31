/*
** main.c for main in /home/sadiqu-m/delivery/Systeme_unix/PSU_2016_minishell1/src
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Sun Jan 15 14:10:41 2017 Sadiqu-m
** Last update Sun Jan 22 13:50:55 2017 Sadiqu-m
*/

#include "my.h"

int	my_error(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      write(2, &str[i], 1);
      i++;
    }
  return (0);
}

void	default_prompt()
{
  if (isatty(0))
    my_putstr("$> ");
}

void	signal_prompt()
{
  if (isatty(0))
    {
      my_putchar('\n');
      my_putstr("$> ");
    }
}

int	main(int ac, char **av, char **env)
{
  char	**array;
  int	val;

  val = 0;
  if (ac > 1)
    {
      my_error("[No need for parameters or arguments...]\n");
      return (84);
    }
  else
    {
      default_prompt();
      signal(SIGINT, signal_prompt);
      signal(SIGTSTP, signal_prompt);
      if ((array = my_env(env)) == NULL)
	{
	  my_error("[Error] Path\n");
	  return (84);
	}
      val = mysh(env, array);
    }
  return (val);
}
