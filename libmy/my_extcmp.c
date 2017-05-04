/*
** my_extcmp.c for libmy in src/libmy/my_extcmp.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Mon Mar  6 16:14:38 2017 Maxime Louet
** Last update Tue Mar  7 12:49:58 2017 Maxime Louet
*/

#include "my.h"

int	my_extcmp(const char *path, const char *ext)
{
  int	i;
  int	j;

  i = 0;
  j = -1;
  while (path[i] != '\0')
  {
    if (path[i] == '.')
      j = i + 1;
    i++;
  }
  if (j == -1)
    return (-1);
  return (my_strcmp(&path[j], ext));
}
