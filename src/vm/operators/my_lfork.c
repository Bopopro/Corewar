/*
** my_lfork.c for corewar in src/vm/operators/my_lfork.c
** 
** Made by Bilel Fourati
** Login   <bilel.fourati@epitech.eu>
** 
** Started on  Sun Apr  2 01:00:13 2017 Bilel Fourati
** Last update Sun Apr  2 01:00:13 2017 Bilel Fourati
*/

#include <stdlib.h>
#include "operators.h"

extern t_op	g_op_tab[];

void		my_lfork(t_machine *machine, t_champ *champ, t_fork *f,
    int *reg)
{
  t_fork	*f_m;
  t_fork	*p;
  int		i;

  (void)champ;
  (void)reg;
  f->cycle_before_ins = g_op_tab[14].nbr_cycles;
  i = 0;
  if ((f_m = malloc(sizeof(t_fork))) == NULL)
    return ;
  p = f;
  while (p->next != NULL)
    p = p->next;
  p->next = f_m;
  f_m->next = NULL;
  f_m->prev = p;
  f_m->id = p->id + 1;
  while (i < REG_NUMBER)
  {
    f_m->reg[i] = f->reg[i];
    i++;
  }
  f_m->pc = (f->pos + get_indirect(machine->mem,
	(f->pos + 1) % MEM_SIZE)) % MEM_SIZE;
  f_m->pos = f_m->pc;
  return ;
}
