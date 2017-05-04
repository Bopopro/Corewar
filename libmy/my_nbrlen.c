/*
** my_nbrlen.c for libmy in my_nbrlen.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Thu Dec  1 10:59:13 2016 Maxime Louet
** Last update Thu Dec  1 10:59:13 2016 Maxime Louet
*/

#include "my.h"

size_t		my_nbrlen(long int nb)
{
  size_t	l;

  l = !nb;
  while (nb > 0)
  {
    nb /= 10;
    l++;
  }
  return (l);
}
