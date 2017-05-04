/*
** clean.c for asm in src/asm/clean.c
**
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
**
** Started on  Wed Mar 22 22:32:10 2017 Maxime Louet
** Last update Thu Mar 23 22:56:42 2017 Zirk
*/

#include <stdlib.h>
#include "asm.h"

void	asm_clean(t_options *options, t_io *io)
{
  int	i;

  i = 0;
  while (i < NB_FLAGS)
  {
    free(options->flags[i]->name);
    free(options->flags[i]);
    i++;
  }
  free(options);
  free(io->input_name);
  free(io->output_name);
  free(io);
}
