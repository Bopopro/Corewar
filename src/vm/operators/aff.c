/*
** aff.c for corewar in src/vm/aff.c
** 
** Made by Bilel Fourati
** Login   <bilel.fourati@epitech.eu>
** 
** Started on  Fri Mar 31 03:01:41 2017 Bilel Fourati
** Last update Fri Mar 31 03:01:41 2017 Bilel Fourati
*/

#include <unistd.h>
#include "operators.h"
#include "vm.h"

extern t_op	g_op_tab[];

void	aff(t_machine *machine, t_champ *champ, t_fork *f, int *reg)
{
  unsigned char	n;

  (void)champ;
  f->cycle_before_ins = g_op_tab[15].nbr_cycles;
  n = reg[machine->mem[(f->pos + 2) % MEM_SIZE] - 1] % 256;
  write(1, &n, 1);
}
