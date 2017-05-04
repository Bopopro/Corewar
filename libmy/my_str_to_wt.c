/*
** my_str_to_wt.c for libmy in my_str_to_wt.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Mon Jan  9 20:43:20 2017 Maxime Louet
** Last update Mon Jan  9 20:43:20 2017 Maxime Louet
*/

#include <stdlib.h>
#include "my.h"

static size_t	strtowt_getwordsnb(const char *str, char delimiter)
{
  size_t	i;
  size_t	delimiters;

  i = 0;
  delimiters = 0;
  while (str[i])
  {
    if (i > 0 && str[i] != delimiter && str[i - 1] == delimiter)
      delimiters++;
    i++;
  }
  return (delimiters);
}

static size_t	strtowt_getchars(const char *str, char delimiter)
{
  size_t	chars;

  chars = 0;
  while (str[chars] && str[chars] != delimiter)
    chars++;
  return (chars);
}

static char	*strtowt_getword(size_t word, const char *str, char delimiter)
{
  size_t	i;
  size_t	chars;
  char		*arg;

  i = 0;
  while (i < word)
  {
    while (*str && *str != delimiter)
      str++;
    while (*str && *str == delimiter)
      str++;
    i++;
  }
  chars = strtowt_getchars(str, delimiter);
  i = 0;
  if ((arg = malloc((size_t)(chars + 1))) == NULL)
    return (NULL);
  while (i < chars)
  {
    arg[i] = str[i];
    i++;
  }
  arg[i] = '\0';
  return (arg);
}

char		**my_str_to_wt(const char *str, char delimiter)
{
  size_t	argsnb;
  char		**args;
  size_t	i;

  argsnb = strtowt_getwordsnb(str, delimiter);
  if ((args = malloc(sizeof(char *) * (argsnb + 2))) == NULL)
    return (NULL);
  i = 0;
  while (i < argsnb + 1)
  {
    args[i] = strtowt_getword(i, str, delimiter);
    i++;
  }
  args[i] = NULL;
  return (args);
}
