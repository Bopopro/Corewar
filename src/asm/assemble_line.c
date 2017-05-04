/*
** assemble.c for asm in src/asm/assemble.c
**
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
**
** Started on  Tue Mar 14 22:38:05 2017 Maxime Louet
** Last update Sun Apr  2 20:51:31 2017 Zirk
*/

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "mylist.h"
#include "op.h"
#include "parse_string.h"
#include "loli.h"

bool	assemble_line(t_options *options, t_io *io,
			      t_header *header, t_line_content *line_content)
{
  if (options->flags[DEBUG]->enabled)
    my_printf("\n");
  io->line_counter++;
  if (first_char_pos(line_content->line) == -1)
  {
    if (options->flags[DEBUG]->enabled)
      my_printf("\x1B[33m[DEBUG: line %d]\x1B[0m Skipping empty line...\n",
	  io->line_counter);
    return (true);
  }
  else if (line_content->line[first_char_pos(line_content->line)] == '.')
  {
      if (!assemble_dot_instruction(line_content->line, header, io, options))
	return (false);
      else
	return (true);
  }
  else
    if (!assemble_instruction(line_content, options, io))
      return (false);
  line_content->memsize = compute_line_size(line_content);
  if (line_content->memsize > 0 && options->flags[DEBUG]->enabled)
    my_printf("\x1B[33m[DEBUG: line %d]\x1B[0m Line size in bytes: %u\n",
	      io->line_counter, line_content->memsize);
  return (true);
}
