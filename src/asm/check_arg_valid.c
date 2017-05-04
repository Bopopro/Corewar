/*
** assemble_instruction.c for asm in src/asm/assemble_instruction.c
**
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
**
** Started on  Thu Mar 23 14:02:50 2017 Maxime Louet
** Last update Sun Apr  2 16:37:11 2017 Zirk
*/

#include <stdlib.h>
#include "asm.h"
#include "parse_string.h"
#include "my.h"

/*
** arg 0: value_arg
** arg 1: nb_arg
*/
void	check_if_arg_valid(t_options *options, t_io *io,
			   int arg[2], char *instruction)
{
  int	i;

  i = 0;
  if (arg[0] == 0)
  {
    code_error(INVALID_ARGUMENT, io->line_counter, options);
    return ;
  }
  while (my_strcmp(instruction, g_op_tab[i].mnemonique) != 0 &&
	 g_op_tab[i].mnemonique != 0)
    i++;
  if (g_op_tab[i].mnemonique == 0)
    return ;
  if ((arg[0] & (g_op_tab[i].type[arg[1] - 1])) == 0)
    code_error(WRONG_ARGUMENT, io->line_counter, options);
}

bool	check_arg(t_options *options,
		   t_io *io,
		   t_line_content *line_content,
		   int nb_args)
{
  int		i;

  i = 0;
  while (my_strcmp(line_content->instruction, g_op_tab[i].mnemonique) != 0 &&
	 g_op_tab[i].mnemonique != 0)
    i++;
  if (options->flags[DEBUG]->enabled)
    my_printf("\x1B[33m[DEBUG: line %d]\x1B[0m Instruction: [%s] "
	      "--- Taking %d arguments\n",
	      io->line_counter, line_content->instruction,
	      ((g_op_tab[i].mnemonique == 0) ? (0) : (g_op_tab[i].nbr_args)));
  line_content->nb_args
    = ((g_op_tab[i].mnemonique == 0) ? (0) : (g_op_tab[i].nbr_args));
  if ((line_content->arguments = my_calloc(line_content->nb_args + 1,
					   sizeof(t_arg))) == NULL)
    return (false);
  if (g_op_tab[i].mnemonique != 0)
    line_content->instruction_code = i + 1;
  if (g_op_tab[i].mnemonique == 0)
    code_error(INVALID_FUNCTION, io->line_counter, options);
  if (nb_args > g_op_tab[i].nbr_args)
    code_error(TOO_MANY_ARGS, io->line_counter, options);
  else if (nb_args < g_op_tab[i].nbr_args)
    code_error(NOT_ENOUGH_ARGS, io->line_counter, options);
  return (true);
}
