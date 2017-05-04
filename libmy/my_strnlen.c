/*
** my_strnlen.c for libmy in my_strnlen.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Mon Nov 21 18:37:35 2016 Maxime Louet
** Last update Mon Nov 21 18:37:35 2016 Maxime Louet
*/

#include "my.h"

size_t		my_strnlen(const char *str, size_t n)
{
  size_t	length;

  if (str == NULL)
    return (0);
  length = 0;
  while (str[length] != '\0' && length <= n)
    length++;
  return (length);
}
