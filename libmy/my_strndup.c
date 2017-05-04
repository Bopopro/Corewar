/*
** my_strndup.c for libmy in my_strdup.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Tue Jan 10 17:43:53 2017 Maxime Louet
** Last update Tue Jan 10 17:43:53 2017 Maxime Louet
*/

#include <stdlib.h>
#include "my.h"

char	*my_strndup(const char *s, size_t n)
{
  char	*new;

  new = NULL;
  if (s != NULL)
  {
    new = malloc(my_strlen(s) + 1);
    if (new != NULL)
      my_strncpy(new, s, n);
  }
  return (new);
}
