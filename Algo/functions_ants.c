/*
** functions_ants.c for functions_ants in /home/girard_r/lem-in/Algo
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Sun May  4 21:28:43 2014 girard_r
** Last update Sun May  4 21:30:51 2014 girard_r
*/

#include <stdlib.h>
#include "ants.h"
#include "parsing.h"

int	pnb_len(int *way)
{
  int	i;

  i = 0;
  while (way[i] != -2)
    i += 1;
  return (i);
}

int	my_nbrcmp(int *mod, int *test)
{
  int	i;
  int	j;

  i = 0;
  while (mod[i] != -2)
    {
      j = 0;
      while (test[j] != -2)
	{
	  if (test[j] == mod[i])
	    return (-1);
	  j += 1;
	}
      i += 1;
    }
  return (0);
}

int	ptab_len(int **tab)
{
  int	i;

  i = 0;
  while (tab[i] != NULL)
    i += 1;
  return (i);
}

int	**pinit(int *way)
{
  int	**sol;

  if ((sol = malloc(sizeof(int *) * 2)) == NULL)
    return (NULL);
  *sol = way;
  sol[1] = NULL;
  return (sol);
}

int		*init_ways_ants(int **sol)
{
  int		j;
  int		*ways_ants;

  j = 0;
  if ((ways_ants = malloc(sizeof(int) * (ptab_len(sol) + 1))) == NULL)
    return (NULL);
  while (sol[j])
    ways_ants[j++] = 0;
  ways_ants[j] = -1;
  return (ways_ants);
}
