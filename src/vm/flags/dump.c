/*
** dump.c for vm in src/vm/flags/dump.c
** 
** Made by Bilel Fourati
** Login   <bilel.fourati@epitech.eu>
** 
** Started on  Wed Mar 29 18:33:15 2017 Bilel Fourati
** Last update Wed Mar 29 18:33:15 2017 Bilel Fourati
*/

#include "vm.h"
#include "my.h"

void	show_dump(t_machine *machine)
{
  int	i;

  i = 0;
  while (i < MEM_SIZE)
  {
    if (machine->mem[i] == 0)
      my_printf("00 ");
    else
    {
      my_putnbr_base(machine->mem[i], "0123456789ABCDEF");
      my_printf(" ");
    }
    if (i % 32 == 0)
      my_printf("\n");
    i++;
  }
}

static int	is_dump_flag(char **av)
{
  int	i;
  int	ind;

  i = 1;
  ind = -1;
  while (av[i] && ind == -1)
  {
    if (my_strcmp("-dump", av[i]) == 0)
      ind = i;
    i++;
  }
  i--;
  return ((i == 1 && av[ind + 1] && my_str_isdigit(av[ind + 1])) ?
    (ind + 1) : (FAIL));
}

int	dump_f(char **av, t_machine *mach)
{
  int	ind_nf;

  if ((ind_nf = is_dump_flag(av)) == FAIL)
    mach->dump_cycle = -1;
  else
    mach->dump_cycle = my_atoi(av[ind_nf]);
  if (mach->dump_cycle > CYCLE_TO_DIE)
    return (FAIL);
  return (SUCCESS);
}
