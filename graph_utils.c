/*
** graph_utils.c for lem-in in /home/joliva_d/rendu/lem-in
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sun May  4 12:09:44 2014 jolivald
** Last update Sun May  4 21:22:39 2014 jolivald
*/

#include "parsing.h"

int		get_room_len(t_room *rooms)
{
  int		len;
  t_room	*tmp;

  len = 0;
  tmp = rooms;
  while (tmp)
    {
      tmp->num = len;
      tmp = tmp->next;
      len++;
    }
  return (len);
}

t_graph	*search_connexion(char *name, t_graph **graph)
{
  int	i;

  i = 0;
  while (graph[i])
    {
      if (my_strcmp(name, graph[i]->room->name) == 0)
	return (graph[i]);
      i++;
    }
  return (NULL);
}

t_graph		*get_start(t_graph **graph)
{
  t_graph	*start;
  int		i;

  i = 0;
  start = graph[i];
  while(graph[i] && start->room->extremity != 1)
    {
      i++;
      start = graph[i];
    }
  if (graph[i] == NULL)
    return (NULL);
  return (start);
}

t_graph		*get_end(t_graph **graph)
{
  t_graph	*end;
  int		i;

  i = 0;
  end = graph[i];
  while(graph[i] && end->room->extremity != 2)
    {
      i++;
      end = graph[i];
    }
  if (graph[i] == NULL)
    return (NULL);
  return (end);
}
