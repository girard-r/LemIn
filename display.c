/*
** display.c for lem-in in /home/joliva_d/rendu/lem-in
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sun May  4 17:28:44 2014 jolivald
** Last update Sun May  4 21:05:09 2014 jolivald
*/

#include "parsing.h"

void		aff_rooms(t_room *rooms, t_pipe *pipes)
{
  t_room	*tmp;
  t_pipe	*tmp2;

  tmp = rooms;
  tmp2 = pipes;
  my_putstr("Rooms :\n");
  while (tmp != NULL)
    {
      my_putstr(tmp->name);
      my_putchar(10);
      tmp = tmp->next;
    }
  my_putstr("\nLinks :\n");
  while (tmp2 != NULL)
    {
      my_putstr(tmp2->start);
      my_putchar('-');
      my_putstr(tmp2->end);
      my_putchar(10);
      tmp2 = tmp2->next;
    }
}

void		aff_graph(t_graph **graph)
{
  int		i;
  int		j;
  t_room	*tmp;

  i = -1;
  while(graph[++i])
    {
      j = -1;
      my_putstr("Num : ");
      my_putstr(graph[i]->room->name);
      if (graph[i]->room->extremity == 1)
	my_putstr(" | Extremity : START");
      else if (graph[i]->room->extremity == 2)
	my_putstr(" | Extremity : END");
      my_putchar('\n');
      while (graph[i]->links[++j])
	{
	  tmp = graph[i]->links[j]->room;
	  my_putstr("\tName : ");
	  my_putstr(tmp->name);
	  my_putstr(" | Num : ");
	  my_putnbr(tmp->num);
	  my_putchar('\n');
	}
    }
}

void	aff_ways(int **ways)
{
  int	i;
  int	j;

  i = 0;
  while (ways[i])
    {
      j = 0;
      if (ways[i][0] >= 0)
	{
	  my_putstr("Chemin ");
	  my_putnbr(i);
	  my_putstr(" : ");
	}
      while (ways[i][j] != -1)
	{
	  my_putchar('[');
	  my_putnbr(ways[i][j]);
	  my_putchar(']');
	  j++;
	}
      if (ways[i][0] != -1)
	my_putchar('\n');
      i++;
    }
  my_putchar('\n');
}
