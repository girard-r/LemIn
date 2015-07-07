/*
** new_rooms.c for lem-in in /home/joliva_d/rendu/lem-in
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sun May  4 14:15:12 2014 jolivald
** Last update Sun May  4 18:29:23 2014 jolivald
*/

#include "parsing.h"

int	not_used(t_recurs *recurs, int i, t_recurs *recurs_tmp, int *line)
{
  recurs->node->links[i]->room->used = 1;
  if (add_room_in_way(recurs->ways, recurs->node->links[i]->room->num, *line) < 0)
    return (-1);
  if ((recurs->ways = my_recursivity(recurs_tmp, *line)) == NULL)
    return (-1);
  recurs->node->links[i]->room->used = 0;
  if (my_realloc_ways(recurs) < 0)
    return (-1);
  if (my_cpy_way(recurs, *line) < 0)
    return (-1);
  *line = recurs->rec;
  return (0);
}

int	already_used(t_recurs *recurs, int i, t_recurs *recurs_tmp, int *line)
{
  recurs->node->links[i]->room->used = 1;
  if (my_realloc_ways(recurs) < 0)
    return (-1);
  if (my_cpy_way_if_used(recurs, *line, recurs->node->links[i]->room->num) < 0)
    return (-1);
  recurs_tmp->ways = recurs->ways;
  if ((recurs->ways = my_recursivity(recurs_tmp, recurs->rec)) == NULL)
    return (-1);
  recurs->node->links[i]->room->used = 0;
  return (0);
}

int		new_rooms(t_recurs *recurs, int *line, char *used, int i)
{
  t_recurs	recurs_tmp;

  recurs_tmp.node = recurs->node->links[i];
  recurs_tmp.rec = recurs->rec;
  recurs_tmp.ways = recurs->ways;
  recurs_tmp.start_num = recurs->start_num;
  if ((*used) == 0)
    {
     *used = 1;
     if (not_used(recurs, i, &recurs_tmp, line) < 0)
       return (-1);
    }
  else if (already_used(recurs, i, &recurs_tmp, line) < 0)
    return (-1);
  recurs->rec = recurs_tmp.rec;
  return (0);
}
