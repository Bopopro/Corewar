/*
** compute_size.c for asm in src/asm/compute_size.c
**
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
**
** Started on  Thu Mar 30 20:38:05 2017 Maxime Louet
** Last update Thu Mar 30 20:38:05 2017 Maxime Louet
*/

#include <stddef.h>
#include "asm.h"

/*
** "the description of the parameters types, called the coding byte,
**  except for the following instructions: live, zjmp, fork, lfork"
*/
bool	has_parameters_description(char code)
{
  if (code == 1 ||
      code == 9 ||
      code == 12 ||
      code == 15)
    return (false);
  else
    return (true);
}

/*
** @returns true if the parameter MAY BE an index.
*/
bool	argument_is_index(int instruction_code, int iarg)
{
  if (instruction_code == 9 && iarg == 0)
    return (true);
  if (instruction_code == 10 && (iarg == 0 || iarg == 1))
    return (true);
  if (instruction_code == 11 && (iarg == 1 || iarg == 2))
    return (true);
  if (instruction_code == 12 && iarg == 0)
    return (true);
  if (instruction_code == 15 && iarg == 0)
    return (true);
  else
    return (false);
}

size_t		compute_line_size(t_line *line)
{
  size_t	memsize;
  int		i;

  memsize = 0;
  i = 0;
  if (line->instruction == NULL)
    return (0);
  memsize += sizeof(char);
  if (has_parameters_description(line->instruction_code))
    memsize += sizeof(char);
  while (i < line->nb_args)
  {
    if (line->arguments[i].type == T_REG)
      memsize += 1;
    else if (line->arguments[i].type == T_DIR &&
	     !argument_is_index(line->instruction_code, i) &&
	     line->instruction_code != 12)
      memsize += DIR_SIZE;
    else
      memsize += IND_SIZE;
    i++;
  }
  return (memsize);
}
