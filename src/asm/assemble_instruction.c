/*
** assemble_instruction.c for asm in src/asm/assemble_instruction.c
**
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
**
** Started on  Thu Mar 23 14:02:50 2017 Maxime Louet
** Last update Sun Apr  2 16:36:40 2017 Zirk
*/

#include "asm.h"
#include "parse_string.h"
#include "my.h"

static int	count_args(char *line, int i)
{
  int		nb_args;

  nb_args = 1;
  while (line[i] && line[i] != COMMENT_CHAR)
  {
    if (line[i] == SEPARATOR_CHAR)
      nb_args++;
    i++;
  }
  return (nb_args);
}

static bool	argument_manager(int i, t_line_content *line_content,
				 t_options *options, t_io *io)
{
  int		nb_args;

  nb_args = count_args(line_content->line, i);
  if (!check_arg(options, io, line_content, nb_args))
    return (false);
  nb_args = 1;
  check_if_arg_valid(options, io, (int[2]){get_arg(line_content, i,
						   options->flags[DEBUG]->
						   enabled,
						   io->line_counter),
	nb_args}, line_content->instruction);
  while (line_content->line[i] && line_content->line[i] != COMMENT_CHAR)
  {
    if (line_content->line[i] == SEPARATOR_CHAR)
    {
      nb_args++;
      check_if_arg_valid(options, io,
			 (int[2]){get_arg(line_content, i + 1,
					  options->flags[DEBUG]->enabled,
					  io->line_counter), nb_args},
			 line_content->instruction);
    }
    i++;
  }
  return (true);
}

static void	fill_label(t_options *options, t_line_content *line_content,
			   t_io *io)
{
  if (my_strlen(line_content->instruction) - 1 > 0)
    line_content->instruction[my_strlen(line_content->instruction) - 1]
      = '\0';
  if (options->flags[DEBUG]->enabled)
    my_printf("\x1B[33m[DEBUG: line %d]\x1B[0m Label: [%s]\n",
	      io->line_counter, line_content->instruction);
  line_content->label = line_content->instruction;
  line_content->instruction = get_word(line_content->line,
				       my_strlen(line_content->
						 instruction) + 1);
}

bool	assemble_instruction(t_line_content *line_content,
			     t_options *options,
			     t_io *io)
{
  int	i;

  i = 0;
  line_content->instruction = get_word(line_content->line, 0);
  if (line_content->instruction[my_strlen(line_content->instruction) - 1]
      == LABEL_CHAR)
    fill_label(options, line_content, io);
  while (line_content->line[i] && line_content->line[i] != COMMENT_CHAR
	 && line_content->line[i] != SEPARATOR_CHAR)
    i++;
  if (!line_content->line[i] && line_content->instruction == NULL)
    return (true);
  while (i > 0 && !my_isspace(line_content->line[i]))
    i--;
  if (!argument_manager(i, line_content, options, io))
    return (false);
  return (true);
}
