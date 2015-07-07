/*
** end_aff_functs.c for lem-in in /home/joliva_d/rendu/lem-in
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sun May  4 22:39:25 2014 jolivald
** Last update Sun May  4 22:56:46 2014 jolivald
*/

#include "ants.h"
#include "parsing.h"
#include "display.h"

void		aff_ant_move(t_display *display, t_graph **graph, int end_room)
{
  char		*name;
  static int	num = 1;

  if (display->room_num != -2)
    name = graph[display->room_num]->room->name;
  else
    name = graph[end_room]->room->name;
  if (display->ant_num == -1)
    {
      display->ant_num = num;
      num++;
    }
  my_putchar('P');
  my_putnbr(display->ant_num);
  my_putchar('-');
  my_putstr(name);
  if (display->room_num == -2)
    display->ended = 1;
}

void	process_already_used(t_calc *calc, t_ants ants,
			     t_graph **graph, int end_room)
{
  if (calc->first != 0)
    my_putchar(' ');
  calc->first = 1;
  aff_ant_move(calc->tmp, graph, end_room);
  calc->tmp->pos += 1;
  calc->tmp->room_num = ants.sol[calc->tmp->way][calc->tmp->pos];
  calc->tmp = calc->tmp->next;
}

void	process_not_used(t_calc *calc, t_ants ants,
			 t_graph **graph, int end_room)
{
  if (calc->first != 0)
    my_putchar(' ');
  calc->first = 1;
  aff_ant_move(calc->tmp, graph, end_room);
  calc->tmp->pos += 1;
  calc->tmp->room_num = ants.sol[calc->tmp->way][calc->tmp->pos];
  calc->tmp = calc->tmp->next;
}

void		aff_ant_way(t_display *display, t_graph **graph,
			      t_ants ants, int end_room)
{
  int		start_pos;
  int		cur_way;
  t_calc	calc;

  calc.first = 0;
  calc.tmp = display->next;
  while (calc.tmp != display)
    {
      while (calc.tmp->ended == 1)
	calc.tmp = calc.tmp->next;
      if (calc.tmp != display)
	{
	  cur_way = calc.tmp->way;
	  start_pos = ants.sol[cur_way][0];
	}
      while (calc.tmp != display && calc.tmp->way == cur_way &&
	     calc.tmp->room_num != start_pos)
	process_already_used(&calc, ants, graph, end_room);
      if (calc.tmp != display && calc.tmp->way == cur_way)
	process_not_used(&calc, ants, graph, end_room);
      while (calc.tmp->way == cur_way)
	calc.tmp = calc.tmp->next;
    }
}

int		test_ended(t_display *display)
{
  t_display	*tmp;

  tmp = display->next;
  while (tmp != display)
    {
      if (tmp->ended == 0)
	return (0);
      tmp = tmp->next;
    }
  return (1);
}
