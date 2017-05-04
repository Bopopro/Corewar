/*
** my_strcat.c for libmy in my_strcat.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Thu Nov 17 22:15:27 2016 Maxime Louet
** Last update Thu Nov 17 22:15:27 2016 Maxime Louet
*/

#include "my.h"

char		*my_strcat(char *dest, const char *src)
{
  size_t	i;
  size_t	destlen;

  if (dest == NULL || src == NULL)
    return (NULL);
  destlen = my_strlen(dest);
  i = 0;
  while (src[i])
  {
    dest[destlen + i] = src[i];
    i++;
  }
  dest[destlen + i] = '\0';
  return (dest);
}
