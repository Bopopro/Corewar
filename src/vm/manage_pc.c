/*
** manage_pc.c for corewar in src/vm/manage_pc.c
** 
** Made by Bilel Fourati
** Login   <bilel.fourati@epitech.eu>
** 
** Started on  Sun Apr  2 19:46:57 2017 Bilel Fourati
** Last update Sun Apr  2 19:46:57 2017 Bilel Fourati
*/

#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "my.h"
#include "operators.h"
#include "op.h"

extern t_opcode	g_opcode[NB_OPCODE];

static void	set_pc_mem(unsigned char *mem, int *pc)
{
  int		i;
  bool		stop;

  i = 0;
  stop = false;
  while (i < NB_OPCODE && !stop)
  {
    if (mem[*pc % MEM_SIZE] == g_opcode[i].id)
    {
      if (g_opcode[i].hav_cb == false)
	*pc = (*pc + 2 + 1) % MEM_SIZE;
      else
	*pc = (*pc + set_pc_dep_opcode(*pc, mem,
	      g_opcode[i].id) + 1) % MEM_SIZE;
      stop = true;
      while (!is_valid_opcode(mem[*pc % MEM_SIZE]))
	*pc = (*pc + 1) % MEM_SIZE;
    }
    i++;
  }
}

int	set_pc(int *pc, unsigned char *mem)
{
  while (!is_valid_opcode(mem[*pc % MEM_SIZE]))
    *pc = (*pc + 1) % MEM_SIZE;
  if (mem[*pc % MEM_SIZE] == 0x01)
    *pc = (*pc + 5) % MEM_SIZE;
  else if (mem[*pc % MEM_SIZE] == 0x0c || mem[*pc % MEM_SIZE] == 0x0f)
    *pc = (*pc + 3) % MEM_SIZE;
  else
    set_pc_mem(mem, pc);
  while (*pc < 0)
    *pc += MEM_SIZE;
  return (*pc);
}

int	set_pos(int pc)
{
  return (pc);
}
