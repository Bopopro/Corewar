/*
** my_memset.c for libmy in my_memset.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Wed Nov 16 11:14:23 2016 Maxime Louet
** Last update Wed Nov 16 11:14:23 2016 Maxime Louet
*/

#include <stdlib.h>
#include "my.h"

void	*my_memset(void *s, int c, size_t n)
{
  char	*str;

  str = (char *)s;
  while (n--)
    *str++ = (char)c;
  return (s);
}
