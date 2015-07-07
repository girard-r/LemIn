/*
** sort_ways.c for lem-in in /home/joliva_d/rendu/lem-in
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sat May  3 19:59:50 2014 jolivald
** Last update Sun May  4 14:40:47 2014 jolivald
*/

#include <stdlib.h>
#include "parsing.h"

int	tab_len(int *way)
{
  int	count;

  count = 0;
  while (way[count] != -1)
    {
      count = count + 1;
    }
  if (count > 0 && way[count - 1] != -2)
    {
      way[0] = -1;
      return (-1);
    }
  else
    return (count - 1);
}

void		swap_tab(int **ways, int len)
{
  static int	i;
  int		j;
  int		*swap;

  j = i;
  while (ways[j] != NULL)
    {
      if (tab_len(ways[j]) == len)
	{
	  swap = ways[i];
	  ways[i] = ways[j];
	  ways[j] = swap;
	  i += 1;
	  return ;
	}
      j += 1;
    }
}

int	sort_ways(int **ways)
{
  int	i;
  int	j;
  int	*len_ways;

  i = 0;
  j = 0;
  if ((len_ways = init_sort(ways, &i)) == NULL)
    return (-1);
  quick_sort(len_ways, 0, i - 1);
  j = 0;
  while (j != i)
    {
      if (len_ways[j] > 0)
	swap_tab(ways, len_ways[j]);
      j += 1;
    }
  return (0);
}
