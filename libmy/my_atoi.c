/*
** my_atoi.c for libmy in my_atoi.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Wed Nov 16 13:35:11 2016 Maxime Louet
** Last update Wed Nov 16 13:35:11 2016 Maxime Louet
*/

#include "my.h"

int	my_atoi(const char *str)
{
  int	res;
  int	neg;
  int	i;

  if (str == NULL)
    return (0);
  res = 0;
  i = 0;
  neg = str[i] == '-' ? 1 : 0;
  while (my_isspace(str[i]) || str[i] == '-')
    i++;
  while (str[i] != '\0')
  {
    if (my_isdigit(str[i]))
    {
      res *= 10;
      res += str[i] - '0';
    }
    else
      return (res);
    i++;
  }
  return (neg ? -res : res);
}
