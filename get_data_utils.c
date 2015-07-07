/*
** get_data_utils.c for lem-in in /home/joliva_d/rendu/lem-in
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sun May  4 12:12:24 2014 jolivald
** Last update Sun May  4 14:33:41 2014 jolivald
*/

#include <stdlib.h>
#include "parsing.h"

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i++])
    free(tab[i]);
  free(tab);
}

int		fill_pipe(t_pipe **pipes, char *str)
{
  int		i;
  int		j;
  int		k;

  k = 0;
  i = 0;
  j = 0;
  if ((*pipes = add_pipe_in_list(*pipes)) == NULL)
    return (-1);
  while (str[i] != 0 && str[i++] != '-');
  if (((*pipes)->start = malloc(sizeof(char) * i)) == NULL)
    return (-1);
  while (j != (i - 1))
    {
      (*pipes)->start[j] = str[j];
      j++;
    }
  (*pipes)->start[j] = 0;
  while (str[i++] != 0);
  if (((*pipes)->end = malloc(sizeof(char) * (i - j))) == NULL)
    return (-1);
  while (str[++j] != 0)
    (*pipes)->end[k++] = str[j];
  (*pipes)->end[k] = 0;
  return (0);
}

int		fill_rooms(t_room **rooms, char **tab, char *extremity)
{
  if ((*rooms = add_room_in_list(*rooms)) == NULL)
    return (-1);
  if (((*rooms)->name = my_strdup(tab[0])) == NULL)
    return (-1);
  (*rooms)->posx = my_getnbr(tab[1]);
  (*rooms)->posy = my_getnbr(tab[2]);
  (*rooms)->extremity = *extremity;
  (*rooms)->used = 0;
  *extremity = 0;
  return (0);
}
