/*
** ldi.c for  in src/vm/operators/ldi.c
** 
** Made by Robin Houssais
** Login   <robin.houssais@epitech.eu>
** 
** Started on  Fri Mar 31 14:08:19 2017 Robin Houssais
** Last update Fri Mar 31 14:08:19 2017 Robin Houssais
*/

#include "vm.h"
#include "operators.h"

void	ldi(t_machine *machine, t_champ *champ, t_fork *f, int *reg)
{
  int	i_o;
  int	i_t;
  int	r;
  int	first_val;

  (void)champ;
  f->cycle_before_ins = g_op_tab[9].nbr_cycles;
  i_o = (f->pos + get_indirect(machine->mem, (f->pos + 2) % MEM_SIZE) % IDX_MOD) % MEM_SIZE;
  i_t = get_indirect(machine->mem, (f->pos + 4) % MEM_SIZE);
  r = machine->mem[(f->pos + 6) % MEM_SIZE] - 1;
  while (i_o < 0)
    i_o = (i_o + MEM_SIZE) % MEM_SIZE;
  first_val = f->pos + (get_indirect(machine->mem, i_o)
    + i_t) % IDX_MOD;
  while (first_val < 0)
    first_val = (first_val + MEM_SIZE) % MEM_SIZE;
  reg[r] = get_direct(machine->mem, first_val % MEM_SIZE);
}
