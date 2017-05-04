/*
** my_str_isalnum.c for libmy in my_str_isalnum.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Mon Jan 16 09:57:28 2017 Maxime Louet
** Last update Mon Jan 16 09:57:28 2017 Maxime Louet
*/

#include "my.h"

int	my_str_isalnum(const char *str)
{
  if (str == NULL)
    return (0);
  while (*str)
  {
    if (!my_isalnum(*str))
      return (0);
    str++;
  }
  return (1);
}
