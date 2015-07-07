/*
** basics_2.c for basics_2 in /home/girard_r/lem-in
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sun Apr 20 15:44:53 2014 girard_r
** Last update Sun May  4 01:07:56 2014 jolivald
*/

#include <unistd.h>
#include "parsing.h"

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	a;

  i = 0;
  nb = 0;
  a = 1;
  if (str[0] == '-')
    a = -1;
  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
    i = i + 1;
  while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
    {
      nb = (nb * 10) + (str[i] - 48);
      i = i + 1;
    }
  return (nb * a);
}

int	my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * (-1);
    }
  if (nb > 9)
    {
      my_putnbr(nb / 10);
      my_putnbr(nb % 10);
    }
  else
      my_putchar(48 + nb);
  return (0);
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}
