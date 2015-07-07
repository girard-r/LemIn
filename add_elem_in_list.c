/*
** my_put_in_list.c for my_put_in_list in /home/vadee_s/rendu/Piscine-C-Jour_12
** 
** Made by vadee_s
** Login   <vadee_s@epitech.net>
** 
** Started on  Tue Oct 22 09:06:11 2013 vadee_s
** Last update Sun Apr 27 17:22:46 2014 jolivald
*/

#include "parsing.h"

t_room		*add_room_in_list(t_room *list)
{
  t_room       	*new;

  if ((new = malloc(sizeof(t_room))) == NULL)
    return (NULL);
  new->next = list;
  return (new);
}

t_pipe		*add_pipe_in_list(t_pipe *list)
{
  t_pipe	*new;

  if ((new = malloc(sizeof(t_pipe))) == NULL)
    return (NULL);
  new->next = list;
  return (new);
}
