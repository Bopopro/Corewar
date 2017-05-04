/*
** my_and.c for corewar in src/vm/operators/my_and.c
** 
** Made by Robin Houssais
** Login   <robin.houssais@epitech.eu>
** 
** Started on  Fri Mar 31 14:16:41 2017 Robin Houssais
** Last update Fri Mar 31 14:16:41 2017 Robin Houssais
*/

#include "vm.h"
#include "operators.h"

extern t_op	g_op_tab[];

void	my_and(t_machine *machine, t_champ *champ, t_fork *f, int *reg)
{
  (void)champ;
  f->cycle_before_ins = g_op_tab[5].nbr_cycles;
  reg[machine->mem[(f->pos + 4) % MEM_SIZE] - 1]
  = reg[machine->mem[(f->pos + 2) % MEM_SIZE] - 1]
    & reg[machine->mem[(f->pos + 3) % MEM_SIZE] - 1];
}
