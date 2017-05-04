/*
** is_label_chars.c for corewar in /home/zirk/epitech/CPE_2016_corewar/src/asm
** 
** Made by Zirk
** Login   <zirk@epitech.net>
** 
** Started on  Fri Mar 24 11:11:55 2017 Zirk
** Last update Mon Mar 27 17:39:26 2017 Zirk
*/

#include <stdlib.h>
#include "asm.h"

static bool	is_valid_char(char c)
{
  int		i;
  const char	*ref_str = LABEL_CHARS;

  i = 0;
  while (ref_str[i] != '\0')
  {
    if (c == ref_str[i])
      return (true);
    i++;
  }
  return (false);
}

int	is_label_chars(const char *str, int ini_pos)
{
  int	i;

  i = ini_pos;
  if (str == NULL || str[i] == '\0')
    return (-1);
  while (str[i] != '\0')
  {
    if (!is_valid_char(str[i]))
      return (i);
    i++;
  }
  return (-2);
}
