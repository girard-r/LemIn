/*
** graph.c for lem-in in /home/joliva_d/rendu/lem-in
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Tue Apr 15 22:01:38 2014 jolivald
** Last update Sun May  4 15:05:26 2014 jolivald
*/

#include "parsing.h"

t_graph		**get_rooms(t_room *rooms, int *max)
{
  int		i;
  t_room	*tmp;
  t_graph	**graph;

  tmp = rooms;
  *max = get_room_len(rooms);
  if ((graph = my_calloc((*max) + 1, sizeof(*graph))) == NULL)
    return (NULL);
  i = 0;
  while (tmp)
    {
      if ((graph[i] = my_calloc(1, sizeof(*(graph[i])))) == NULL)
	return (NULL);
      graph[i]->room = tmp;
      if ((graph[i]->links = my_calloc(1, sizeof(*(graph[i]->links)))) == NULL)
	return (NULL);
      graph[i]->links[0] = NULL;
      tmp = tmp->next;
      i++;
    }
  graph[i] = NULL;
  return (graph);
}

int	check_links(t_graph *start, char *name)
{
  int	i;

  i = 0;
  while (start->links[i])
    {
      if (my_strcmp(start->links[i]->room->name, name) == 0)
	return (-1);
      i++;
    }
  return (1);
}

int		get_pipes(t_graph **graph, t_pipe *pipes)
{
  t_pipe	*tmp;
  t_graph	*start;
  t_graph	*end;

  tmp = pipes;
  while (tmp)
    {
      if ((start = search_connexion(tmp->start, graph)) == NULL)
	return (-1);
      if ((end = search_connexion(tmp->end, graph)) == NULL)
	return (-1);
      if (start != end)
	{
	  if (check_links(start, end->room->name) > 0)
	    if ((start->links = my_realloc(start->links, end)) == NULL)
	      return (-1);
	  if (check_links(end, start->room->name) > 0)
	    if ((end->links = my_realloc(end->links, start)) == NULL)
	      return (-1);
	}
      tmp = tmp->next;
    }
  return (0);
}

t_graph		**do_graph(t_room *rooms, t_pipe *pipes, int *len)
{
  t_graph	**graph;
  int		i;

  i = 0;
  if ((graph = get_rooms(rooms, len)) == NULL)
    return (NULL);
  if (get_pipes(graph, pipes) < 0)
    return (NULL);
  while (graph[i])
    {
      graph[i]->root_node = graph;
      i++;
    }
  return (graph);
}
