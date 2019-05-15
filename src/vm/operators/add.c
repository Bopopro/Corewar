
#include "vm.h"
#include "op.h"
#include "operators.h"

extern t_op	g_op_tab[];

void	add(t_machine *machine, t_champ *champ, t_fork *f, int *reg)
{
  (void)champ;
  f->cycle_before_ins = g_op_tab[3].nbr_cycles;
  reg[machine->mem[(f->pos + 4) % MEM_SIZE] - 1]
    = reg[machine->mem[(f->pos + 2) % MEM_SIZE] - 1]
    + reg[machine->mem[(f->pos + 3) % MEM_SIZE] - 1];
}
