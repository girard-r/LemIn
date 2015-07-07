/*
** basics.c for basics.c in /home/girard_r/lem-in
** 
** Made by girard_r
** Login   <girard_r@epitech.net>
** 
** Started on  Tue Apr 15 23:23:31 2014 girard_r
** Last update Sun Apr 27 17:22:38 2014 jolivald
*/

#include <unistd.h>
#include "parsing.h"

void	my_putstr(char *s)
{
  write(1, s, my_strlen(s));
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i += 1;
  return (i);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] && s1[i] == s2[i])
    {
      if (s1[i] == '\0')
	return (0);
      i = i + 1;
    }
  return (s1[i] - s2[i]);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = 0;
  return (dest);
}

char	*my_strdup(char *src)
{
  char	*dest;

  if ((dest = malloc(sizeof(char) * (my_strlen(src) + 1))) == NULL)
    return (NULL);
  my_strcpy(dest, src);
  return (dest);
}
