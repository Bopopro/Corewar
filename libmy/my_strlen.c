/*
** my_strlen.c for libmy in my_strlen.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Wed Nov 16 10:42:09 2016 Maxime Louet
** Last update Wed Nov 16 10:42:09 2016 Maxime Louet
*/

#include "my.h"

size_t		my_strlen(const char *str)
{
  size_t	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i])
    i++;
  return (i);
}
