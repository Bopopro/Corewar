/*
** my_strcpy.c for libmy in my_strcpy.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Tue Dec  6 18:22:00 2016 Maxime Louet
** Last update Tue Dec  6 18:22:00 2016 Maxime Louet
*/

#include "my.h"

char		*my_strcpy(char *dest, const char *src)
{
  size_t	i;

  if (dest == NULL || src == NULL)
    return (NULL);
  i = 0;
  while (src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return (dest);
}
