/*
** process_ants.c for process_ants in /home/girard_r/lem-in
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sat May  3 18:35:13 2014 girard_r
** Last update Sun May  4 21:44:58 2014 jolivald
*/

#include <stdlib.h>
#include "ants.h"
#include "parsing.h"

int	**loop_way(int **sol, int **ways, int max_ways)
{
  int	j;
  int	is_max;

  j = 0;
  is_max = 0;
  if (max_ways == 1)
    return (sol);
  while (ways[j])
    {
      if (test_intersect(sol, ways[j]) == 1)
	{
	  if ((sol = my_array_push(sol, ways[j], max_ways, &is_max)) == NULL)
	    return (NULL);
	  else if (is_max == 1)
	    return (sol);
	}
      j += 1;
    }
  return (sol);
}

int		send_ants(t_ants *ants, int nb_send)
{
  int		i;

  i = 0;
  while (ants->ways_ants[i] != -1 && i < nb_send)
    {
      ants->ways_ants[i] += 1;
      i += 1;
    }
  return (0);
}

int		split_ants_in_ways(t_ants *ants, int nb_ants)
{
  int		*len_way;
  int		sum;
  int		nb_send;

  if ((len_way = init_lenway(ants->sol)) == NULL)
    return (-1);
  nb_send = ptab_len(ants->sol);
  while (nb_ants > 0)
    {
      sum = calc_sum(len_way, nb_send);
      while ((nb_ants - sum) < nb_send && nb_send > 1)
	{
	  nb_send -= 1;
	  sum = calc_sum(len_way, nb_send);
	}
      if (send_ants(ants, nb_send) == -1)
	return (-1);
      nb_ants -= nb_send;
    }
  return (0);
}

int		process_ants(int **ways, int nb_ants, int max_ways, t_graph **graph)
{
  t_ants	ants;
  int		i;

  if ((ants.sol = pinit(ways[0])) == NULL
      || (ants.sol = loop_way(ants.sol, ways, max_ways)) == NULL
      || (ants.ways_ants = init_ways_ants(ants.sol)) == NULL)
    return (-1);
  if (split_ants_in_ways(&ants, nb_ants) == -1)
    return (-1);
  i = 0;
  while (ants.ways_ants[i] != -1)
    i += 1;
  if (end_display(ants, nb_ants, graph) < 0)
    return (-1);
  return (0);
}
