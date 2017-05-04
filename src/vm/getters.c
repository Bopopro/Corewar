/*
** getters.c for vm in src/vm/getters.c
** 
** Made by Bilel Fourati
** Login   <bilel.fourati@epitech.eu>
** 
** Started on  Wed Mar 29 16:50:31 2017 Bilel Fourati
** Last update Wed Mar 29 16:50:31 2017 Bilel Fourati
*/

#include <stdlib.h>
#include "op.h"
#include "vm.h"

int		get_direct(unsigned char *mem, int pos)
{
  int		i;
  unsigned char	*dir_c;
  int		value;

  i = 0;
  if ((dir_c = malloc(sizeof(unsigned char) * DIR_SIZE)) == NULL)
    return (FAIL);
  if (pos < 0)
    pos += MEM_SIZE;
  while (i < DIR_SIZE)
  {
    dir_c[i] = mem[pos % MEM_SIZE];
    i++;
    pos++;
  }
  value = *((int*)dir_c);
  value = swap_be(value);
  free(dir_c);
  return (value);
}

int		get_indirect(unsigned char *mem, int pos)
{
  int		i;
  unsigned char	*dir_c;
  short		value;

  i = 0;
  if ((dir_c = malloc(sizeof(unsigned char) * IND_SIZE)) == NULL)
    return (FAIL);
  if (pos < 0)
    pos += MEM_SIZE;
  while (i < IND_SIZE)
  {
    dir_c[i] = mem[pos % MEM_SIZE];
    i++;
    pos++;
  }
  value = *((short*)dir_c);
  free(dir_c);
  value = swap_be_s(value);
  return (value);
}

void		put_direct(unsigned char *mem, int pos, int nb)
{
  unsigned char	*nb_c;
  int		i;

  i = 0;
  nb = swap_be(nb);
  nb_c = (unsigned char*)(&nb);
  if (pos < 0)
    pos += MEM_SIZE;
  while (i < DIR_SIZE)
  {
    mem[pos] = nb_c[i];
    i++;
    pos++;
  }
}

void		put_indirect(unsigned char *mem, int pos, short nb)
{
  unsigned char	*nb_c;
  int		i;

  i = 0;
  nb = swap_be_s(nb);
  nb_c = (unsigned char*)(&nb);
  if (pos < 0)
    pos += MEM_SIZE;
  while (i < IND_SIZE)
  {
    mem[pos] = nb_c[i];
    i++;
    pos++;
  }
}
