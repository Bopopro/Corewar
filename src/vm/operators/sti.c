/*
** sti.c for corewar in src/vm/operators/sti.c
** 
** Made by Robin Houssais
** Login   <robin.houssais@epitech.eu>
** 
** Started on  Fri Mar 31 14:20:06 2017 Robin Houssais
** Last update Fri Mar 31 14:20:06 2017 Robin Houssais
*/

#include "operators.h"
#include "vm.h"
#include "my.h"

extern t_op	g_op_tab[];

static int	verif_type_sti(int t, int *n1, t_machine *machine, t_fork *f)
{
  int		to_f;

  to_f = 0;
  if (t == REG_TYPE)
  {
    *n1 = f->reg[machine->mem[(f->pos + 3) % MEM_SIZE] - 1];
    to_f = REG_SIZE + 3;
  }
  else if (t == DIR_TYPE || t == IND_TYPE)
  {
    *n1 = get_indirect(machine->mem, (f->pos + 3) % MEM_SIZE);
    to_f = IND_SIZE + 3;
  }
  return (to_f);
}

void	sti(t_machine *machine, t_champ *champ, t_fork *f, int *reg)
{
  int	n1;
  int	n2;
  int	t;
  int	to_f;

  to_f = 0;
  n1 = 0;
  n2 = 0;
  (void)champ;
  f->cycle_before_ins = g_op_tab[10].nbr_cycles;
  t = get_cb_type(machine->mem[(f->pos + 1) % MEM_SIZE], SECOND_ARG);
  to_f += verif_type_sti(t, &n1, machine, f);
  t = get_cb_type(machine->mem[(f->pos + 1) % MEM_SIZE], THIRD_ARG);
  n2 = (t == DIR_TYPE || t == IND_TYPE) ?
       (get_indirect(machine->mem, (f->pos + to_f) % MEM_SIZE)) :
	(reg[machine->mem[(f->pos + to_f) % MEM_SIZE] - 1]);
  to_f = (f->pos + (n1 + n2) % IDX_MOD) % MEM_SIZE;
  while (to_f < 0)
    to_f = (to_f + MEM_SIZE) % MEM_SIZE;
  put_direct(machine->mem, to_f,
      reg[machine->mem[(f->pos + 2) % MEM_SIZE] - 1]);
}
