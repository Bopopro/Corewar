/*
** my_wtdup.c for libmy in my_wtdup.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Tue Jan 10 17:34:27 2017 Maxime Louet
** Last update Tue Jan 10 17:34:27 2017 Maxime Louet
*/

#include <stdlib.h>
#include "my.h"

char	**my_wtdup(char **wt)
{
  int	i;
  char	**dup;

  i = 0;
  if (wt == NULL)
    return (NULL);
  if ((dup = malloc(sizeof(char *) * (my_wtlen(wt) + 1))) == NULL)
    return (NULL);
  while (wt[i] != NULL)
  {
    if ((dup[i] = my_strdup(wt[i])) == NULL)
      return (NULL);
    i++;
  }
  dup[i] = NULL;
  return (dup);
}
