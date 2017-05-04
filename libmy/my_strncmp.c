/*
** my_strncmp.c for libmy in my_strncmp.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Wed Nov 23 20:27:18 2016 Maxime Louet
** Last update Wed Nov 23 20:27:18 2016 Maxime Louet
*/

#include "my.h"

int		my_strncmp(const char *s1, const char *s2, size_t n)
{
  if ((s1 == NULL && s2 == NULL) || n == 0)
    return (0);
  else if (s1 == NULL)
    return (-1);
  else if (s2 == NULL)
    return (1);
  while (n > 0 && *s1 == *s2 && *s1 != '\0')
  {
    s1++;
    s2++;
    n--;
  }
  if (n == 0)
    return (0);
  else
    return ((*s1 < *s2) ? (-1) : (1));
}
