/*
** start.c for corewar in src/vm/start.c
** 
** Made by Bilel Fourati
** Login   <bilel.fourati@epitech.eu>
** 
** Started on  Fri Mar 31 14:43:01 2017 Bilel Fourati
** Last update Fri Mar 31 14:43:01 2017 Bilel Fourati
*/

#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "my.h"
#include "operators.h"
#include "op.h"

t_opcode	g_opcode[NB_OPCODE] =
{
  {0x02, true, &ld},
  {0x03, true, &st},
  {0x04, true, &add},
  {0x05, true, &sub},
  {0x06, true, &my_and},
  {0x07, true, &my_or},
  {0x08, true, &my_xor},
  {0x09, false, &zjmp},
  {0x0a, true, &ldi},
  {0x0b, true, &sti},
  {0x0c, false, &my_fork},
  {0x0d, true, &lld},
  {0x0e, true, &lldi},
  {0x0f, false, &my_lfork},
  {0x10, true, &aff}
};
int	g_live_counter = 0;

bool	is_valid_opcode(unsigned char b)
{
  if (b < 1 || b > NB_OPCODE)
    return (false);
  return (true);
}

static void	cycle_manager(int *cycle, t_champ **champs, bool *win)
{
  int		i;
  int		nb_alive;
  int		who;

  i = 0;
  who = 0;
  if (g_live_counter >= NBR_LIVE)
  {
    *cycle -= CYCLE_DELTA;
    g_live_counter = 0;
    nb_alive = 0;
    while (champs[i])
    {
      if (champs[i]->alive == true)
      {
	nb_alive++;
	who = i;
      }
      i++;
    }
    if (nb_alive <= 1)
      *win = true;
    if (nb_alive == 1)
      my_printf("The player %d(%s) has won.", champs[who]->id ,
	  champs[who]->head->prog_name);
  }
}

static void	fork_manager(t_champ **champs, int i, t_machine *machine)
{
  t_fork	*ptr;
  t_fork	*tmp;
  int		j;

  ptr = champs[i]->fork;
  tmp = champs[i]->fork->next;
  if (tmp != NULL)
  {
    //printf("MON PREMIER FORK: POS: %d PC: %d\n", tmp->pos, tmp->pc);
  }
  while (ptr != NULL)
  {
    if (ptr->cycle_before_ins <= 0)
    {
      ptr->pos = set_pos(ptr->pc);
      ptr->pc = set_pc(&ptr->pc, machine->mem);
    }
    j = 0;
    while (j < NB_OPCODE)
    {
//      printf("CHAMP: %d FORK: %d INS: %d && OPCODE: %d CYCLE: %d\n", champs[i]->id, ptr->id, machine->mem[ptr->pos % MEM_SIZE], g_opcode[j].id, ptr->cycle_before_ins);
      if (machine->mem[ptr->pos % MEM_SIZE] == 0x01
	  && ptr->cycle_before_ins <= 0)
	live(machine, champs, ptr);
      else if (machine->mem[ptr->pos % MEM_SIZE] == g_opcode[j].id
	  && ptr->cycle_before_ins <= 0)
	g_opcode[j].fnc(machine, champs[i], ptr, ptr->reg);
      j++;
    }
    ptr = ptr->next;
  }
}

static int	manager_cycle_two(t_champ **champs, t_machine *machine,
				  int nb_cycle)
{
  int		i;
  t_fork	*ptr;

  i = 0;
  while (champs[i])
  {
    fork_manager(champs, i, machine);
    i++;
  }
  if (nb_cycle % (NBR_LIVE / CYCLE_DELTA) == 0)
  {
    i = 0;
    while (champs[i])
    {
      ptr = champs[i]->fork;
      while (ptr != NULL)
      {
	if (ptr->cycle_before_ins > 0)
	  ptr->cycle_before_ins--;
	ptr = ptr->next;
      }
      i++;
    }
  }
  return (SUCCESS);
}

int	start(t_champ **champs, t_machine *machine)
{
  int	i;
  bool	win;
  int	cycle;
  int	nb_cycle;

  win = 0;
  cycle = CYCLE_TO_DIE;
  nb_cycle = 0;
  while (cycle > 0 && !win)
  {
    i = 0;
    while (champs[i])
    {
      if (g_live_counter == 0)
	champs[i]->alive = false;
      i++;
    }
    cycle_manager(&cycle, champs, &win);
    manager_cycle_two(champs, machine, nb_cycle);
    nb_cycle++;
    if (nb_cycle % machine->dump_cycle == 0 && machine->dump_cycle != -1)
      show_dump(machine);
  }
      i = 0;
      while (i < MEM_SIZE)
      {
	printf("%d   \t", machine->mem[i]);
	i++;
      }
  return (0);
}
