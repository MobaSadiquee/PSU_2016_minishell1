/*
** my_str_to_wortab.c for my_str_to_wordtab in /home/sadiqu-m/delivery/Systeme_unix/PSU_2016_minishell1/src
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Sun Jan 15 14:25:48 2017 Sadiqu-m
** Last update Sun Jan 22 16:41:26 2017 Sadiqu-m
*/

#include "my.h"

int	count_word(char *str)
{
  int   i;
  int   j;

  i = 0;
  j = 1;
  while (str[i] != '\0' && str[i] != '\n')
    {
      if (str[i] == ':' && str[i + 1] != '\0')
	j++;
      else if (str[i] == ' ' && str[i + 1] != '\0')
	j++;
      i++;
    }
  return (j);
}

int	remove_space_double(char *str, int i)
{
  int	j;

  j = i;
  while (str[j] == ' ' || str[j] == ':')
    j++;
  return (j);
}

char	**my_str_tab(char *str)
{
  char	**new_tab;
  int	i;
  int	j;
  int	x;

  i = 0;
  j = 0;
  x = 0;
  if ((new_tab = malloc(sizeof(*new_tab) * ((count_word(str) + 1)))) == NULL)
    return (NULL);
  while (str[i] != '\n' && str[i] != '\0')
    {
      if (str[i] == ' ' || str[i] == ':' )
	{
	  i = remove_space_double(str, i);
	  j = j + 1;
	  x = 0;
	}
      if ((new_tab[j] = malloc(sizeof(char) * (my_strlen(str + i)))) == NULL)
	return (NULL);
      while (str[i] != ':' && str[i] != ' ' && str[i] != '\n' && str[i] != '\0')
	new_tab[j][x++] = str[i++];
    }
  new_tab[j + 1] = '\0';
  return (new_tab);
}
