/*
** usage.c for asm in src/asm/usage.c
**
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
**
** Started on  Tue Mar 28 18:13:07 2017 Maxime Louet
** Last update Tue Mar 28 18:13:07 2017 Maxime Louet
*/

#include "asm.h"
#include "my.h"

static void	print_usage_options(const t_options *options)
{
  int		i;

  i = 0;
  while (i < NB_FLAGS)
  {
    if (my_strcmp(options->flags[i]->name, "-loli") != 0)
    {
      my_printf("\t\t%s", options->flags[i]->name);
      my_printf("\t\t%s\n", options->flags_description[i]);
    }
    i++;
  }
}

void	usage(const t_options *options, const char *progname)
{
  my_printf("USAGE:\n");
  my_printf("\t%s [options] input[.s] [output]\n", progname);
  my_printf("\nDESCRIPTION\n");
  my_printf("\tinput\t");
  my_printf("File in assembly language to be converted into output.cor, or ");
  my_printf("to the specified name. That file will be read by the Corewar ");
  my_printf("Virtual Machine.\n");
  my_printf("\toptions\n");
  print_usage_options(options);
}
