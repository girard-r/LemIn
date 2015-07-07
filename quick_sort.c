/*
** quick_sort.c for lem in in /home/vadee_s/rendu/lem_in/lem-in
** 
** Made by vadee
** Login   <vadee_s@epitech.net>
** 
** Started on  Sat Apr 26 18:17:27 2014 vadee
** Last update Sun May  4 14:21:07 2014 jolivald
*/

#include <stdlib.h>
#include "parsing.h"

int	*init_sort(int **ways, int *i)
{
  int	*len_ways;

  *i = -1;
  while (ways[++(*i)] != NULL);
  if ((len_ways = malloc(sizeof(int) * (*i))) == NULL)
    return (NULL);
  *i = 0;
  while (ways[*i] != NULL)
    {
      len_ways[*i] = tab_len(ways[*i]);
      *i += 1;
    }
  return (len_ways);
}

int	partition(int *len_ways, int first, int last, int pivot)
{
  int	j;
  int	i;
  int	swap;

  swap = len_ways[pivot];
  len_ways[pivot] = len_ways[last];
  len_ways[last] = swap;
  i = first;
  j = first;
  while (i <= (last - 1))
    {
      if (len_ways[i] <= len_ways[last])
	{
	  swap = len_ways[j];
	  len_ways[j] = len_ways[i];
	  len_ways[i] = swap;
	  j += 1;
	}
      i += 1;
    }
  swap = len_ways[j];
  len_ways[j] = len_ways[last];
  len_ways[last] = swap;
  return (j);
}

void	quick_sort(int *len_ways, int first, int last)
{
  int	pivot;

  if (first < last)
    {
      pivot = first;
      pivot = partition(len_ways, first, last, pivot);
      quick_sort(len_ways, first, pivot - 1);
      quick_sort(len_ways, pivot + 1, last);
    }
}
