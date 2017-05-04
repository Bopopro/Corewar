/*
** assemble_dot_instruction.c for asm in src/asm/assemble_dot_instruction.c
**
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
**
** Started on  Thu Mar 23 12:16:17 2017 Maxime Louet
** Last update Fri Mar 31 01:01:26 2017 Zirk
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "parse_string.h"

static void	fill_dot_name(t_header *header, t_options *options,
			      t_io *io, char *content)
{
  if (options->flags[DEBUG]->enabled)
    my_printf("\x1B[33m[DEBUG: line %d]\x1B[0m %s set to %s\n",
	      io->line_counter, NAME_CMD_STRING, content);
  my_strcpy(header->prog_name, content);
}

static void	fill_dot_instruction(t_header *header, t_options *options,
				     t_io *io, char *content)
{
  if (options->flags[DEBUG]->enabled)
    my_printf("\x1B[33m[DEBUG: line %d]\x1B[0m %s set to %s\n",
	      io->line_counter, COMMENT_CMD_STRING, content);
  my_strcpy(header->comment, content);
}

static bool	free_and_return_true(void *arg1, void *arg2)
{
  free(arg1);
  free(arg2);
  return (true);
}

bool		assemble_dot_instruction(char *line, t_header *header,
					 t_io *io, t_options *options)
{
  const int	dot_pos = first_char_pos(line);
  char		*instruction;
  char		*content;

  instruction = get_word(line, dot_pos);
  content = NULL;
  if (my_strcmp(instruction, NAME_CMD_STRING) == 0)
  {
    content = get_string(line, dot_pos + my_strlen(instruction));
    if (my_strlen(content) > PROG_NAME_LENGTH)
      code_error(NAME_TOO_LONG, io->line_counter, options);
    else
      fill_dot_name(header, options, io, content);
  }
  else if (my_strcmp(instruction, COMMENT_CMD_STRING) == 0)
  {
    content = get_string(line, dot_pos + my_strlen(instruction));
    if (my_strlen(content) > COMMENT_LENGTH)
      code_error(COMMENT_TOO_LONG, io->line_counter, options);
    else
      fill_dot_instruction(header, options, io, content);
  }
  else
    asm_warning(UNHANDLED_INSTRUCTION, io->line_counter, options);
  return (free_and_return_true(instruction, content));
}
