/*
** my_strtoi.c for libmy in my_strtoi.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Tue Dec  6 11:01:26 2016 Maxime Louet
** Last update Tue Dec  6 11:01:26 2016 Maxime Louet
*/

#include "my.h"

int	my_strtoi(char *str, char **endptr)
{
  int	nb;

  nb = 0;
  while (my_isnum(*str) && nb <= 21474836)
    {
      nb = nb * 10 + (*str - '0');
      str++;
    }
  *endptr = str;
  return (nb);
}
