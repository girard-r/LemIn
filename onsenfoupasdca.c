/*
** onsenfoupasdca.c for lem-in in /home/joliva_d/rendu/lem-in
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sat Apr 26 16:26:36 2014 jolivald
** Last update Sun May  4 14:29:36 2014 jolivald
*/

#include "parsing.h"

int	add_room_in_way(int **ways, int nb, int line)
{
  int	i;
  int	*cpy;

  i = 0;
  while (ways[line][i] != -1)
    i++;
  if (i > 0 && ways[line][i - 1] == nb)
    return (0);
  if ((cpy = my_calloc(i + 2, sizeof(*cpy))) == NULL)
    {
      my_freeways(ways);
      return (-1);
    }
  i = 0;
  while (ways[line][i] != -1)
    {
      cpy[i] = ways[line][i];
      i++;
    }
  cpy[i] = nb;
  cpy[i + 1] = -1;
  free(ways[line]);
  ways[line] = cpy;
  return (0);
}

int	my_freeways(int **ways)
{
  int	i;

  i = 0;
  while (ways[i])
    {
      free(ways[i]);
      i++;
    }
  free(ways);
  return (-1);
}

int    my_realloc_ways(t_recurs *recurs)
{
  int	i;
  int	**cpy;
  int	**ways;

  ways = recurs->ways;
  i = -1;
  while (ways[++i]);
  recurs->rec = i;
  if ((cpy = my_calloc(i + 2, sizeof(*cpy))) == NULL)
    return (my_freeways(ways));
  i = -1;
  while (ways[++i])
    cpy[i] = ways[i];
  if ((cpy[i] = my_calloc(1, sizeof(*(cpy[i])))) == NULL)
    {
      my_freeways(ways);
      return (my_freeways(cpy));
    }
  cpy[i][0] = -1;
  cpy[i + 1] = NULL;
  free(ways);
  recurs->ways = cpy;
  return (0);
}
