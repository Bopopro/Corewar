/*
** my_strchr.c for libmy in my_strchr.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Fri Jan 13 11:20:36 2017 Maxime Louet
** Last update Fri Jan 13 11:20:36 2017 Maxime Louet
*/

#include "my.h"

char	*my_strchr(const char *s, int c)
{
  if (s == NULL)
    return (NULL);
  while (*s != c)
  {
    if (*s == '\0')
      return (NULL);
    s++;
  }
  return ((char *)s);
}
