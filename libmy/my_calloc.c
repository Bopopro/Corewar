/*
** my_calloc.c for libmy in my_calloc.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Wed Nov 16 10:52:06 2016 Maxime Louet
** Last update Wed Nov 16 10:52:06 2016 Maxime Louet
*/

#include <stdlib.h>
#include "my.h"

void		*my_calloc(size_t count, size_t size)
{
  void		*value;
  size_t	total;

  total = count * size;
  value = malloc(total);
  if (value != NULL)
    my_memset(value, 0, total);
  return (value);
}
