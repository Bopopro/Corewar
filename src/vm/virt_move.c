/*
** virt_move.c for coerwar in virt_move.c
** 
** Made by Bilel Fourati
** Login   <bilel.fourati@epitech.eu>
** 
** Started on  Sun Apr  2 19:16:11 2017 Bilel Fourati
** Last update Sun Apr  2 19:16:11 2017 Bilel Fourati
*/

#include <stdlib.h>
#include <stdio.h>
#include "vm.h"
#include "my.h"
#include "operators.h"
#include "op.h"

static int 	dep_opcode_first(unsigned char cb, unsigned char ins)
{
  int		siz;
  int		typ;

  siz = 0;
  if ((typ = get_cb_type(cb, FIRST_ARG)) == IND_TYPE)
    siz += IND_SIZE;
  else if (typ == DIR_TYPE)
    siz += (ins == 0x09 || ins == 0x0a || ins == 0x0e) ? (IND_SIZE) :
      (DIR_SIZE);
  else if (typ == REG_TYPE)
    siz += 1;
  return (siz);
}

static int 	dep_opcode_second(unsigned char cb, unsigned char ins)
{
  int		siz;
  int		typ;

  siz = 0;
  if ((typ = get_cb_type(cb, SECOND_ARG)) == IND_TYPE)
    siz += IND_SIZE;
  else if (typ == DIR_TYPE)
    siz += (ins == 0x0a || ins == 0x0b || ins == 0x0e) ? (IND_SIZE) :
      (DIR_SIZE);
  else if (typ == REG_TYPE)
    siz += 1;
  return (siz);
}

static int 	dep_opcode_third(unsigned char cb, unsigned char ins)
{
  int		siz;
  int		typ;

  siz = 0;
  if ((typ = get_cb_type(cb, THIRD_ARG)) == IND_TYPE)
    siz += IND_SIZE;
  else if (typ == DIR_TYPE)
    siz += (ins == 0x0b) ? (IND_SIZE) : (DIR_SIZE);
  else if (typ == REG_TYPE)
    siz += 1;
  return (siz);
}

int	set_pc_dep_opcode(int pc, unsigned char *mem, unsigned char ins)
{
  unsigned char	cb;
  int		siz;

  siz = 0;
  cb = mem[(pc + 1) % MEM_SIZE];
  siz += dep_opcode_first(cb, ins);
  siz += dep_opcode_second(cb, ins);
  siz += dep_opcode_third(cb, ins);
  return (siz + 1);
}
