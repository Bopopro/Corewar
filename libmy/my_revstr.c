/*
** my_revstr.c for libmy in my_revstr.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Sun Dec  4 15:32:08 2016 Maxime Louet
** Last update Sun Dec  4 15:32:08 2016 Maxime Louet
*/

#include "my.h"

char		*my_revstr(char *str)
{
  size_t	i;
  size_t	length;
  char		tmp;

  i = 0;
  if (str == NULL)
    return (str);
  length = my_strlen(str);
  while (i < length / 2)
  {
    tmp = str[i];
    str[i] = str[length - 1 - i];
    str[length - 1 - i] = tmp;
    i = i + 1;
  }
  return (str);
}
