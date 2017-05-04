/*
** zjmp.c for corewar in src/vm/operators/zjmp.c
** 
** Made by Robin Houssais
** Login   <robin.houssais@epitech.eu>
** 
** Started on  Fri Mar 31 14:18:19 2017 Robin Houssais
** Last update Fri Mar 31 14:18:19 2017 Robin Houssais
*/

#include "vm.h"
#include "operators.h"
#include "my.h"

extern t_op	g_op_tab[];

void	zjmp(t_machine *machine, t_champ *champ, t_fork *f, int *reg)
{
  (void)champ;
  (void)reg;
  f->cycle_before_ins = g_op_tab[8].nbr_cycles;
  f->pc = (f->pos + get_indirect(machine->mem, f->pos + 1) % IDX_MOD)
	  % MEM_SIZE;
  while (f->pc < 0)
    f->pc = (f->pc + MEM_SIZE) % MEM_SIZE;
}
