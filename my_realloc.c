/*
** my_realloc.c for my_realloc.c in /home/girard_r/lem-in
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Tue Apr 15 22:12:48 2014 girard_r
** Last update Sun May  4 15:05:28 2014 jolivald
*/

#include "parsing.h"

int	count_nodes(t_graph **map)
{
  int	i;

  if (map != NULL)
    {
      i = 0;
      while (map[i])
	i += 1;
      return (i);
    }
  else
    return (-1);
}

t_graph		**my_realloc(t_graph **map, t_graph *new_elem)
{
  t_graph	**new_map;
  int		nodes;
  int		i;

  i = 0;
  if ((nodes = count_nodes(map)) >= 0)
    {
      if ((new_map = my_calloc((nodes + 2), sizeof(t_graph *))) == NULL)
	return (NULL);
      while (map[i])
	{
	  new_map[i] = map[i];
	  i++;
	}
      new_map[i] = new_elem;
      free(map);
      return (new_map);
    }
  return (NULL);
}

void	*my_calloc(int nmemb, int size)
{
  void	*result;

  result = malloc(nmemb * size);
  if (result == NULL)
    {
      my_putstr("Malloc Error\n");
      return (NULL);
    }
  result = my_memset((char*)result, nmemb * size);
  return (result);
}

char	*my_memset(char *result, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      result[i] = 0;
      i++;
    }
  return (result);
}
