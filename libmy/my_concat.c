/*
** my_concat.c for libmy in my_concat.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Mon Nov 28 22:38:17 2016 Maxime Louet
** Last update Mon Nov 28 22:38:17 2016 Maxime Louet
*/

#include <stdlib.h>
#include "my.h"

char	*my_concat(const char *s1, const char *s2)
{
  char	*result;

  result = malloc(my_strlen(s1) + my_strlen(s2) + 1);
  if (result != NULL)
  {
    my_strcpy(result, s1);
    my_strcat(result, s2);
  }
  return (result);
}
