/*
** ants.h for ants in /home/girard_r/lem-in
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sat May  3 18:36:06 2014 girard_r
** Last update Sun May  4 23:08:15 2014 jolivald
*/

#ifndef ANTS_H_
# define ANTS_H_

#include "parsing.h"

typedef struct	s_ants
{
  int		**sol;
  int		*ways_ants;
}		t_ants;

int	end_display(t_ants ants, int nb_ants, t_graph **graph);
int	pnb_len(int *way);
int	**pinit(int *way);
int	my_nbrcmp(int *mod, int *test);
int	test_intersect(int **sol, int *way);
int	ptab_len(int **tab);
int	**my_array_push(int **sol, int *way, int max_ways, int *is_max);
int	**loop_way(int **sol, int **ways, int max_ways);
int	display_tab(int **sol);
int	*init_ways_ants(int **sol);
int	*init_lenway(int **sol);
int	calc_sum(int *len_way, int nb_send);
int	send_ants(t_ants *ants, int nb_send);
int	split_ants_in_ways(t_ants *ants, int nb_ants);


#endif /* !ANTS_H_ */
