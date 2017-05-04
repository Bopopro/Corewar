/*
** assemble_instruction.c for asm in src/asm/assemble_instruction.c
**
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
**
** Started on  Thu Mar 23 14:02:50 2017 Maxime Louet
** Last update Sun Apr  2 20:40:26 2017 Zirk
*/

#include "asm.h"
#include "parse_string.h"
#include "my.h"

static int	print_debug(char *arg, bool is_debug_mode,
			    t_line_content *line_content, int var_type)
{
  if (is_debug_mode)
  {
    if (var_type == T_REG)
      my_printf(" --- \x1B[32mOK\x1B[0m [%s] (%s)\n", "Register",
		((is_label(arg)) ? ("is a label") :
		("is not a label")));
    else if (var_type == T_DIR)
      my_printf(" --- \x1B[32mOK\x1B[0m [%s] (%s)\n", "Direct",
		((is_label(arg)) ? ("is a label") :
		("is not a label")));
    else if (var_type == T_IND)
      my_printf(" --- \x1B[32mOK\x1B[0m [%s] (%s)\n", "Indirect",
		((is_label(arg)) ? ("is a label") :
		("is not a label")));
  }
  if (line_content->prog_arg < line_content->nb_args)
  {
    line_content->arguments[line_content->prog_arg].arg = arg;
    line_content->arguments[line_content->prog_arg].type = var_type;
    line_content->arguments[line_content->prog_arg].is_label = is_label(arg);
    line_content->prog_arg++;
  }
  return (var_type);
}

/*
** Returns what kind of argument is one given in parameter.
**
** @param line : The line the param is on
** @param pos_arg : The position of the argument
** @return 0 is the argument is invalid, 1 if it's a register
**         2 if it's a direct value, 4 if it's an indirect one
**         -1 if the stupid programmer gave something wrong to the function
*/
int		get_arg(t_line_content *line_content, int pos_arg,
			bool debug_mode, int nb_line)
{
  char		*arg;

  arg = get_instruction(line_content->line, pos_arg);
  if (debug_mode)
    my_printf("\x1B[33m[DEBUG: line %d]\x1B[0m Argument: [%s]", nb_line, arg);
  if (is_register(arg))
    return (print_debug(arg, debug_mode, line_content, T_REG));
  else if (is_direct(arg))
    return (print_debug(arg, debug_mode, line_content, T_DIR));
  else if (is_indirect(arg))
    return (print_debug(arg, debug_mode, line_content, T_IND));
  else
  {
    if (debug_mode)
      my_printf(" --- \x1B[31mERROR: unknown argument.\x1B[0m\n");
    return (0);
  }
}
