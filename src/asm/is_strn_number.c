/*
** assemble_instruction.c for asm in src/asm/assemble_instruction.c
**
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
**
** Started on  Thu Mar 23 14:02:50 2017 Maxime Louet
** Last update Sun Mar 26 21:43:46 2017 Zirk
*/

#include "parse_string.h"
#include "my.h"

int	is_strn_number(const char *str, int ini_pos)
{
  int	i;

  i = ini_pos;
  if (str == NULL || str[i] == '\0')
    return (-1);
  if (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
    i++;
  if (str[i] == '\0')
    return (-1);
  while (str[i] != '\0')
  {
    if (!my_isdigit(str[i]))
      return (i);
    i++;
  }
  return (-2);
}
