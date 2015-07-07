/*
** end_display.c for lem-in in /home/joliva_d/rendu/lem-in
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sun May  4 18:34:22 2014 jolivald
** Last update Sun May  4 22:40:44 2014 jolivald
*/

#include "ants.h"
#include "parsing.h"
#include "display.h"

int		add_ants_in_list(t_display *display)
{
  t_display	*elem;

  if ((elem = my_calloc(1, sizeof(*elem))) == NULL)
    return (-1);
  elem->ant_num = -1;
  elem->ended = 0;
  elem->prev = display->prev;
  elem->pos = 0;
  elem->way = -1;
  elem->next = display;
  display->prev->next = elem;
  display->prev = elem;
  return (0);
}

void		assign_way(t_ants ants, t_display *display)
{
  t_display	*tmp;
  int		pos;
  int		state;

  pos = 0;
  state = ants.ways_ants[0];
  tmp = display->next;
  while (tmp != display)
    {
      tmp->way = pos;
      tmp->room_num = ants.sol[pos][0];
      state -= 1;
      if (state <= 0)
	{
	  pos += 1;
	  state = ants.ways_ants[pos];
	}
      tmp = tmp->next;
    }
}

int		end_display(t_ants ants, int nb_ants, t_graph **graph)
{
  t_display	display;
  int		i;

  i = 0;
  display.next = &display;
  display.prev = &display;
  display.ant_num = -1;
  display.way = -1;
  display.ended = -1;
  while (i < nb_ants)
    {
      if (add_ants_in_list(&display) < 0)
	return (-1);
      i++;
    }
  assign_way(ants, &display);
  process_display(&display, graph, ants);
  return (0);
}

void		process_display(t_display *display, t_graph **graph,
				t_ants ants)
{
  int		end_num;
  t_graph	*end_room;

  end_room = get_end(graph);
  end_num = end_room->room->num;
  while (test_ended(display) == 0)
    {
      aff_ant_way(display, graph, ants, end_num);
      my_putchar('\n');
    }
}
