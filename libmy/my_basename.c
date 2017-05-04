/*
** my_basename.c for libmy in my_basename.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Wed Nov 23 03:57:58 2016 Maxime Louet
** Last update Wed Nov 23 03:57:58 2016 Maxime Louet
*/

#include "my.h"

char	*my_basename(char *path)
{
  char	*basename;

  if (path == NULL)
    return (NULL);
  basename = path;
  while (*path)
  {
    if (*path++ && *path == '/' && *(path + 1))
      basename = path + 1;
  }
  return (basename);
}
