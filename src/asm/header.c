/*
** header.c for asm in src/asm/header.c
**
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
**
** Started on  Wed Mar 15 00:50:22 2017 Maxime Louet
** Last update Tue Mar 21 11:40:48 2017 Zirk
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"
#include "op.h"
#include "my.h"

bool	write_header(t_header *header, t_options *options, t_io *io)
{
  if (options->flags[DEBUG]->enabled)
    my_printf("\x1B[33m[DEBUG]\x1B[0m Writing header to file\n");
  write(io->output_fd, header, sizeof(*header));
  return (true);
}

bool		prepare_header(t_header **header)
{
  if ((*header = my_calloc(sizeof(**header), 1)) == NULL)
    return (false);
  (*header)->magic = swap_be(COREWAR_EXEC_MAGIC);
  return (true);
}

bool	write_header_output(t_header *header, t_options *options, t_io *io,
			    size_t final_size)
{
  header->prog_size = swap_be_ui(final_size);
  lseek(io->output_fd, 0, SEEK_SET);
  if (!write_header(header, options, io))
    return (false);
  free(header);
  return (true);
}
