/*
** ld.c for corewar in src/vm/operators/ld.c
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

void	ld(t_machine *machine, t_champ *champ, t_fork *f, int *reg)
{
  int	p1;

  f->cycle_before_ins = g_op_tab[1].nbr_cycles;
  (void)champ;
  if (get_cb_type(machine->mem[f->pos + 1], FIRST_ARG) == IND_TYPE)
  {
    p1 = f->pos + get_indirect(machine->mem, f->pos + 2) % IDX_MOD;
    while (p1 < 0)
      p1 = (p1 + MEM_SIZE) % MEM_SIZE;
    reg[(machine->mem[(f->pos + 4) % MEM_SIZE] - 1) % REG_NUMBER] =
      get_direct(machine->mem, p1);
  }
  else if (get_cb_type(machine->mem[f->pos + 1], FIRST_ARG) == DIR_TYPE)
  {
    p1 = (f->pos + 2) % MEM_SIZE;
    while (p1 < 0)
      p1 = (p1 + MEM_SIZE) % MEM_SIZE;
    reg[(machine->mem[(f->pos + 6) % MEM_SIZE] - 1) % REG_NUMBER] =
      get_direct(machine->mem, p1);
  }
  else
    return;
}
