/*
** lld.c for corewar in src/vm/operators/lld.c
** 
** Made by Robin Houssais
** Login   <robin.houssais@epitech.eu>
** 
** Started on  Fri Mar 31 14:10:08 2017 Robin Houssais
** Last update Fri Mar 31 14:10:08 2017 Robin Houssais
*/

#include <stddef.h>
#include <math.h>
#include "vm.h"
#include "op.h"
#include "operators.h"

extern t_op	g_op_tab[];

void	lld(t_machine *machine, t_champ *champ, t_fork *f, int *reg)
{
  (void)champ;
  f->cycle_before_ins = g_op_tab[12].nbr_cycles;
  if (get_cb_type(machine->mem[f->pos + 1], FIRST_ARG) == IND_TYPE)
  {
    reg[machine->mem[(f->pos + 4) % MEM_SIZE] - 1] = get_direct(machine->mem,
	(f->pc + get_indirect(machine->mem, f->pos + 2)));
  }
  else if (get_cb_type(machine->mem[f->pos + 1], FIRST_ARG) == DIR_TYPE)
  {
    reg[machine->mem[(f->pos + 6) % MEM_SIZE] - 1] = get_direct(machine->mem,
	((f->pos + 2) % MEM_SIZE));
  }
  else
    return ;
}
