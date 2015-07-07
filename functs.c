/*
** functs.c for lem-in in /home/joliva_d/rendu/lem-in
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sun Apr 27 16:36:20 2014 jolivald
** Last update Sun May  4 16:54:52 2014 jolivald
*/

#include "parsing.h"

int	end_found(t_recurs *recurs, int *line)
{
  if (add_room_in_way(recurs->ways, recurs->node->room->num, *line) < 0 ||
      add_room_in_way(recurs->ways, -2, *line) < 0)
      return (-1);
  if (my_realloc_ways(recurs) < 0)
    return (-1);
  if (my_cpy_way(recurs, *line) < 0)
    return (-1);
  *line = recurs->rec;
  return (0);
}

int	my_cpy_way_if_used(t_recurs *recurs, int line, int num)
{
  int		count;
  int		i;
  int		nb;
  t_graph	**tmp;

  i = 0;
  count = 0;
  tmp = recurs->node->root_node;
  while (tmp[i])
    {
      count += tmp[i]->room->used == 1 && i != recurs->start_num ? 1 : 0;
      i++;
    }
  i = 0;
  while (i < count && recurs->ways[line][i] >= 0)
    {
      nb = recurs->ways[line][i];
      if (add_room_in_way(recurs->ways, nb, recurs->rec) < 0)
	return (-1);
      i++;
    }
  if (add_room_in_way(recurs->ways, num, recurs->rec) < 0)
    return (-1);
  return (0);
}


int		my_cpy_way(t_recurs *recurs, int line)
{
  int		count;
  int		i;
  int		nb;
  t_graph	**tmp;

  i = 0;
  count = 0;
  tmp = recurs->node->root_node;
  while (tmp[i])
    {
      count += tmp[i]->room->used == 1 && i != recurs->start_num ? 1 : 0;
      i++;
    }
  i = 0;
  while (i < count && recurs->ways[line][i] >= 0)
    {
      nb = recurs->ways[line][i];
      if (add_room_in_way(recurs->ways, nb, recurs->rec) < 0)
	return (-1);
      i++;
    }
  return (0);
}
