/*
** my_wtlen.c for libmy in my_wtlen.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Tue Jan 10 16:38:16 2017 Maxime Louet
** Last update Tue Jan 10 16:38:16 2017 Maxime Louet
*/

#include "my.h"

size_t		my_wtlen(char **wt)
{
  size_t	i;

  i = 0;
  while (wt != NULL && wt[i] != NULL)
    i++;
  return (i);
}
