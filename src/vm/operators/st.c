/*
** st.c for corewar in st.c
** 
** Made by Bilel Fourati
** Login   <bilel.fourati@epitech.eu>
** 
** Started on  Fri Mar 31 14:34:34 2017 Bilel Fourati
** Last update Fri Mar 31 14:34:34 2017 Bilel Fourati
*/

#include <stdio.h>
#include "operators.h"
#include "vm.h"

extern t_op	g_op_tab[];

void	st(t_machine *machine, t_champ *champ, t_fork *f, int *reg)
{
  int	getind;

  (void)champ;
  f->cycle_before_ins = g_op_tab[2].nbr_cycles;
  if (get_cb_type(machine->mem[(f->pos + 1) % MEM_SIZE],
		  SECOND_ARG) == REG_TYPE)
    reg[machine->mem[(f->pos + 3) % MEM_SIZE] - 1]
      = reg[machine->mem[(f->pos + 2) % MEM_SIZE] - 1];
  else
  {
    getind = (f->pos + get_indirect(machine->mem, (f->pos + 3) % MEM_SIZE));
    while (getind < 0)
      getind = (getind + MEM_SIZE) % MEM_SIZE;
    put_direct(machine->mem, getind,
	reg[machine->mem[(f->pos + 2) % MEM_SIZE] - 1]);
//    printf("%s effectue le ST de %d a %d\n", champ->head->prog_name, reg[machine->mem[(f->pos + 2) % MEM_SIZE] - 1], getind);
  }
}
