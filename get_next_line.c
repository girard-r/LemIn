/*
** get_next_line.c for getnextline source in /home/vadee_s/rendu/CPE_2013_getnextline
** 
** Made by vadee_s
** Login   <vadee_s@epitech.net>
** 
** Started on  Sun Nov 24 12:02:50 2013 vadee_s
** Last update Sun May  4 22:59:42 2014 jolivald
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "parsing.h"
#include "get_next_line.h"

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  j = 0;
  i = my_strlen(dest);
  while (src[j])
    {
      dest[i] = src[j];
      i = i + 1;
      j = j + 1;
    }
  dest[i] = 0;
  return (dest);
}

int	stack_buffer(char *buffer, char *tmp)
{
  int	j;

  j = 0;
  while (tmp[j] != 0)
    {
      if (tmp[j] == '\n')
        {
          tmp[j] = 0;
          *buffer = 0;
	  my_strcat(buffer, &tmp[j + 1]);
          return (0);
        }
      j = j + 1;
    }
  *buffer = 0;
  return (1);
}

char	*my_realloc_gnl(char *src, int ret)
{
  char	*dest;

  if (ret == 0)
    return (src);
  dest = malloc((my_strlen(src) + ret + 1) * sizeof(char));
  if (dest == NULL)
    return (NULL);
  *dest = 0;
  my_strcat(dest, src);
  free(src);
  return (dest);
}

char		*get_next_line(const int fd)
{
  static char	buffer[BUFFER];
  char		*tmp;
  int		ret;

  tmp = malloc(BUFFER * sizeof(char));
  if (tmp == NULL || fd < 0)
    return (NULL);
  *tmp = 0;
  my_strcat(tmp, buffer);
  *buffer = 0;
  ret = BUFFER;
  while (stack_buffer(buffer, tmp) != 0 && ret == BUFFER)
    {
      ret = read(fd, buffer, BUFFER);
      if (ret == - 1)
        return (NULL);
      buffer[ret] = 0;
      tmp = my_realloc_gnl(tmp, ret);
      my_strcat(tmp, buffer);
       if (tmp[0] == 10)
       	return (tmp);
    }
  if (*tmp == 0 && my_strlen(buffer) == 0 && ret != BUFFER)
    return (NULL);
  return (tmp);
}
