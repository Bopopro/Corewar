/*
** my_gnl.c for tetris in my_gnl.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Sat Jan 14 14:46:11 2017 Maxime Louet
** Last update Sat Jan 14 14:46:11 2017 Maxime Louet
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

static char	*gnl_append(char *str, char c)
{
  int		i;
  char		*new;

  i = 0;
  new = my_calloc(my_strlen(str) + 2, sizeof(char));
  if (new == NULL)
    return (NULL);
  while (str[i] != '\0')
  {
    new[i] = str[i];
    i++;
  }
  new[i] = c;
  new[i + 1] = '\0';
  free(str);
  return (new);
}

char		*my_gnl(int fd)
{
  static char	buff[512 + 1];
  static int	i;
  char		*final;

  if (fd < 0 || (final = my_calloc(1, sizeof(char))) == NULL)
    return (NULL);
  while (42)
  {
    while (buff[i] != '\0' && buff[i] != '\n' && final != NULL)
      final = gnl_append(final, buff[i++]);
    if (buff[i++] == '\n')
      break;
    else
    {
      i = 0;
      my_memset(buff, 0, 512 + 1);
      if (read(fd, buff, 512) <= 0)
	return (final[0] == '\0' ? NULL : final);
    }
  }
  return (final);
}
