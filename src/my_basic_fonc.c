/*
** my_basic_fonc.c for my_basic_fonc in /home/sadiqu-m/delivery/C_prog_elem/CPE_2016_BSQ/src
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Mon Dec  5 13:11:17 2016 Sadiqu-m
** Last update Sun Jan 22 14:58:39 2017 Sadiqu-m
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int	hidenp(char *s1, char *s2)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (s2[j] != '\0')
    {
      if (s1[i] == s2[j])
	i++;
      j++;
    }
  if (s1[i] == '\0' && s2[j] == '\0')
    return (1);
  else
    return (0);
}

char	*my_strpath(char *array, char *arg)
{
  int   i;
  int   j;
  char  *new_str;

  i = 0;
  j = 0;
  if ((new_str = malloc(sizeof(char) * my_strlen(array) + 1)) == NULL)
    return (NULL);
  while (array[i] != '\0')
    {
      new_str[i] = array[i];
      i++;
    }
  new_str[i++] = '/';
  while (arg[j] != '\0')
    {
      new_str[i] = arg[j];
      i++;
      j++;
    }
  new_str[i] = '\0';
  return (new_str);
}
