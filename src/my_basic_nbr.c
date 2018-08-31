/*
** my_basic_nbr.c for my_basic_nbr in /home/sadiqu-m/delivery/C_prog_elem/CPE_2016_BSQ/src
** 
** Made by Sadiqu-m
** Login   <mobashir-ahmed.sadiquee@epitech.eu@epitech.net>
** 
** Started on  Mon Dec  5 13:13:04 2016 Sadiqu-m
** Last update Sun Dec 18 18:30:19 2016 Sadiqu-m
*/

#include "my.h"

int	my_put_nbr(int nb)
{
  if (nb < 0)
    {
      nb = -nb;
      my_putchar('-');
    }
  if (nb >= 10)
    {
      my_put_nbr(nb / 10);
      my_put_nbr(nb % 10);
    }
  else
    my_putchar(nb + '0');
  return (0);
}
