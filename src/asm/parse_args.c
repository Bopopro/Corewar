/*
** parse_args.c for corewar in /home/zirk/Epitech/CPE_2016_corewar/src/asm
** 
** Made by Zirk
** Login   <zirk@epitech.net>
** 
** Started on  Tue Mar 14 22:56:38 2017 Zirk
** Last update Tue Mar 28 15:30:13 2017 Zirk
*/

#include "asm.h"
#include "my.h"

static int	parse_flags(t_options *options, int ac, char **av, int i)
{
  int		y;
  bool		is_flag_valid;

  while (i < ac)
  {
    y = 0;
    is_flag_valid = false;
    while (y < NB_FLAGS)
    {
      if (my_strcmp(av[i], options->flags[y]->name) == 0)
      {
	options->flags[y]->enabled = true;
	is_flag_valid = true;
      }
      y++;
    }
    if (!is_flag_valid)
      return (i);
    i++;
  }
  return (i);
}

bool	parse_args(t_options *options, int ac, char **av)
{
  int	i;

  i = parse_flags(options, ac, av, 1);
  if (i >= ac)
  {
    usage(options, av[0]);
    return (false);
  }
  options->pos_inputfile = i;
  i++;
  i = parse_flags(options, ac, av, i);
  if (i < ac)
    options->pos_outputfile = i;
  if (options->flags[HELP1]->enabled || options->flags[HELP2]->enabled)
    {
      usage(options, av[0]);
      return (false);
    }
  if (options->flags[WALL]->enabled)
    {
      options->flags[WUNUSED_LABEL]->enabled = true;
      options->flags[WINVALID_JUMP]->enabled = true;
      options->flags[WOVERFLOW]->enabled = true;
    }
  return (true);
}
