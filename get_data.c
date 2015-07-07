/*
** get_data.c for lem-in in /home/joliva_d/rendu/lem-in
** 
** Made by jolivald
** Login   <joliva_d@epitech.net>
** 
** Started on  Sat May  3 19:58:08 2014 jolivald
** Last update Sun May  4 23:07:24 2014 jolivald
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "parsing.h"

int	my_put_error(char *s, int i)
{
  my_putstr(s);
  my_putchar('\n');
  my_putstr("wrong syntax at line ");
  my_putnbr(i);
  my_putchar('\n');
  return (-1);
}

int	loop_data_pipes(t_pipe **pipes, char *s, int i)
{
  char	**tab;

  if ((tab = my_str_to_wordtab(s)) == NULL)
    return (-1);
  if (tab[0] != NULL && tab[1] == NULL)
    {
      if (fill_pipe(pipes, tab[0]) < 0)
	return (-1);
    }
  else if (s[0] != 0)
    return (my_put_error(s, i));
  return (0);
}

int		loop_data_rooms(t_room **rooms, char *s, int i)
{
  char		**tab;
  static char	extremity;

  if ((tab = my_str_to_wordtab(s)) == NULL)
    return (-1);
  if (tab[0] != NULL && tab[1] != NULL
      && tab[2] != NULL && tab[3] == NULL)
    {
      if (fill_rooms(rooms, tab, &extremity) < 0)
	return (-1);
    }
  else if (tab[0] != NULL && tab[1] == NULL)
    {
      if (my_strcmp("##start", tab[0]) == 0)
	extremity = 1;
      else if (my_strcmp("##end", tab[0]) == 0)
	extremity = 2;
      else
	return (-2);
    }
  else if (s[0] != 0)
    return (my_put_error(s, i));
  return (0);
}

t_room	*get_data_rooms(t_room *rooms, char **s)
{
  int	i;
  int	ret;

  i = 0;
  while ((*s = get_next_line(0)) != NULL)
    {
      my_putstr(*s);
      my_putchar('\n');
      if (*s[0] != 0 && (ret = loop_data_rooms(&rooms, *s, i++)) < 0)
	{
	  if (ret == -2)
	    return (rooms);
	  return (NULL);
	}
      free(*s);
    }
  return (NULL);
}

t_pipe	*get_data_pipes(t_pipe *pipes, char *s)
{
  int	i;

  i = 0;
  if (s != NULL && s[0] != 0 && loop_data_pipes(&pipes, s, i++) < 0)
    return (NULL);
  free(s);
  while ((s = get_next_line(0)) != NULL)
    {
      my_putstr(s);
      my_putchar('\n');
      if (s[0] != 0 && loop_data_pipes(&pipes, s, i++) < 0)
	return (NULL);
      free(s);
    }
  return (pipes);
}
