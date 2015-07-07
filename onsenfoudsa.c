
/*
** onsenfoudsa.c for lem-in in /home/joliva_d/rendu/lem-in
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Mon Apr 21 16:09:19 2014 jolivald
** Last update Sun May  4 16:56:53 2014 jolivald
*/

#include "parsing.h"

void	my_aff_way(int *way)
{
  int	i;

  i = 0;
  while (way[i] != -1)
    {
      my_putnbr(way[i]);
      my_putstr("  ");
      i++;
    }
  my_putchar('\n');
}

int	**my_recursivity(t_recurs *recurs, int start_line)
{
  int	i;
  int	line;
  char	used;

  used = 0;
  line = start_line;
  i = 0;
  while (recurs->node->links[i])
    {
      if (recurs->node->links[i]->room->extremity == 2)
	{
	  used = 1;
	  if (end_found(recurs, &line) < 0)
	    return (NULL);
	}
      else if (recurs->node->links[i]->room->used == 0)
	{
	  if (new_rooms(recurs, &line, &used, i) < 0)
	    return (NULL);
	}
      i++;
    }
  return (recurs->ways);
}

int		**loop_graph(t_graph **graph)
{
  int		**ways;
  t_recurs	recurs;
  t_graph	*start;

  if ((start = get_start(graph)) == NULL)
    return (NULL);
  start->room->used = 1;
  if ((ways = malloc(2 * sizeof(*ways))) == NULL)
    return (NULL);
  if ((ways[0] = malloc(sizeof(int))) == NULL)
    {
      free(ways);
      return (NULL);
    }
  ways[0][0] = -1;
  ways[1] = NULL;
  recurs.ways = ways;
  recurs.node = start;
  recurs.rec = 0;
  recurs.start_num = start->room->num;
  if ((ways = my_recursivity(&recurs, 0)) == NULL)
    return (NULL);
  return (ways);
}
