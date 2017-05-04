/*
** read.c for tetris in src/vm/read.c
** 
** Made by Bilel Fourati
** Login   <bilel.fourati@epitech.eu>
** 
** Started on  Wed Mar 22 22:17:43 2017 Bilel Fourati
** Last update Wed Mar 22 22:17:43 2017 Bilel Fourati
*/

#include <stdlib.h>
#include <unistd.h>
#include "vm.h"

t_header	*read_header(int fd)
{
  t_header	*h;

  if ((h = malloc(sizeof(t_header))) == NULL)
    return (NULL);
  read(fd, h, sizeof(t_header));
  h->magic = swap_be(h->magic);
  h->prog_size = swap_be(h->prog_size);
  return (h);
}

char	*read_string(int fd, int length)
{
  int	rt;
  char	*buf;

  if ((buf = malloc(length)) == NULL)
    return (NULL);
  if ((rt = read(fd, buf, length)) == -1 || rt == 0)
    return (NULL);
  return (buf);
}

int	read_int(int fd)
{
  int	rt;
  int	mag;

  if ((rt = read(fd, &mag, sizeof(int))) == -1 || rt == 0)
    return (FAIL);
  return (mag);
}

char	read_char(int fd)
{
  int	rt;
  char	mag;

  if ((rt = read(fd, &mag, sizeof(char))) == -1 || rt == 0)
    return (FAIL);
  return (mag);
}
