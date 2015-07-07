/*
** functions_ants_2.c for functions_ants2 in /home/girard_r/lem-in/Algo
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sun May  4 21:31:43 2014 girard_r
** Last update Sun May  4 23:09:25 2014 jolivald
*/

#include <stdlib.h>
#include "ants.h"
#include "parsing.h"

int	test_intersect(int **sol, int *way)
{
  int	j;

  j = 0;
  while (sol[j])
    {
      if (my_nbrcmp(sol[j], way) == -1)
	return (-1);
      j += 1;
    }
  return (1);
}

int		**my_array_push(int **sol, int *way, int max_ways, int *is_max)
{
  int		**new_sol;
  int		j;
  static int	cmp = 1;

  if ((new_sol = malloc(sizeof(int *) * (ptab_len(sol) + 2))) == NULL)
    return (NULL);
  j = 0;
  while (sol[j])
    {
      new_sol[j] = sol[j];
      j++;
    }
  new_sol[j++] = way;
  new_sol[j] = NULL;
  free(sol);
  cmp += 1;
  if (cmp == max_ways)
    {
      *is_max = 1;
      cmp = 0;
    }
  return (new_sol);
}

int		*init_lenway(int **sol)
{
  int		*len_way;
  int		j;

  j = 0;
  if ((len_way = malloc(sizeof(int) * (ptab_len(sol) + 1))) == NULL)
    return (NULL);
  while (sol[j])
    {
      len_way[j] = pnb_len(sol[j]);
      j++;
    }
  len_way[j] = -1;
  return (len_way);
}

int		calc_sum(int *len_way, int nb_send)
{
  int		i;
  int		sum;

  i = 0;
  sum = 0;
  while (len_way[i] != -1 && i < nb_send)
    sum = sum + len_way[i++];
  return (sum);
}
