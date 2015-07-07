/*
** main.c for lem-in in /home/joliva_d/rendu/lem-in
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sat May  3 19:58:35 2014 jolivald
** Last update Sun May  4 23:07:44 2014 jolivald
*/

#include "get_next_line.h"
#include "parsing.h"


int	count_links(t_graph *graph)
{
  int	i;

  i = 0;
  while (graph->links[i])
    i++;
  return (i);
}

int		**init_ways(t_graph ***graph, int *nb_rooms)
{
  t_room	*rooms;
  t_pipe	*pipes;
  char		*s;
  int		**ways;

  rooms = NULL;
  pipes = NULL;
  if ((rooms = get_data_rooms(rooms, &s)) == NULL)
    return (NULL);
  if ((pipes = get_data_pipes(pipes, s)) == NULL)
    return (NULL);
  if ((*graph = do_graph(rooms, pipes, nb_rooms)) == NULL)
    return (NULL);
  if (get_start(*graph) == NULL || get_end(*graph) == NULL)
    return (NULL);
  if ((ways = loop_graph(*graph)) == NULL)
    return (NULL);
  if (sort_ways(ways) < 0)
    return (NULL);
  return (ways);
}

int		get_process(t_graph **graph, int **ways, int nb_ants)
{
  int		diff;
  int		links;

  diff = count_links(get_start(graph));
  links = count_links(get_end(graph));
  diff = diff > links ? links : diff;
  return (process_ants(ways, nb_ants, diff, graph));
}

int		main()
{
  int		nbr_ants;
  int		**ways;
  t_graph	**graph;
  int		nb_rooms;
  char		*s;

  nb_rooms = 0;
  if ((s = get_next_line(0)) && s[0] != 0)
    nbr_ants = my_getnbr(s);
  my_putstr(s);
  my_putchar('\n');
  if ((ways = init_ways(&graph, &nb_rooms)) == NULL)
    return (-1);
  if (get_process(graph, ways, nbr_ants) < 0)
    return (-1);
  return (0);
}
