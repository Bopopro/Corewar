/*
** lldi.c for  in src/vm/operators/lldi.c
** 
** Made by Robin Houssais
** Login   <robin.houssais@epitech.eu>
** 
** Started on  Fri Mar 31 14:08:19 2017 Robin Houssais
** Last update Fri Mar 31 14:08:19 2017 Robin Houssais
*/

#include "vm.h"
#include "operators.h"

extern t_op	g_op_tab[];

void	lldi(t_machine *machine, t_champ *champ, t_fork *f, int *reg)
{
  int	i_o;
  int	i_t;
  int	r;
  int	first_val;

  (void)champ;
  f->cycle_before_ins = g_op_tab[13].nbr_cycles;
  i_o = get_indirect(machine->mem, (f->pos + 2) % MEM_SIZE);
  i_t = get_indirect(machine->mem, (f->pos + 4) % MEM_SIZE);
  r = machine->mem[(f->pos + 6) % MEM_SIZE] - 1;
  first_val = get_indirect(machine->mem, (f->pos + i_o) % MEM_SIZE)
    + i_t;
  reg[r] = get_direct(machine->mem, (f->pos + first_val) % MEM_SIZE);
}
