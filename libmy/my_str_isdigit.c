/*
** my_str_isnum.c for libmy in my_str_isnum.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Sat Nov 19 19:00:04 2016 Maxime Louet
** Last update Sat Nov 19 19:00:04 2016 Maxime Louet
*/

#include "my.h"

int	my_str_isdigit(const char *str)
{
  int	i;

  if (str == NULL)
    return (0);
  i = 0;
  while (str[i] != '\0')
  {
    if (!my_isdigit(str[i]))
      return (0);
    i++;
  }
  return (1);
}
