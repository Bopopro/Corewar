/*
** swap_be.c for asm in src/asm/swap_be.c
**
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
**
** Started on  Fri Mar 24 14:22:27 2017 Maxime Louet
** Last update Thu Mar 30 21:48:04 2017 
*/

#include <stdlib.h>
#include "my.h"
#include "vm.h"

unsigned int	swap_be(unsigned int le)
{
  unsigned int	be;

  be = (le >> 24) & 0x000000FF;
  be |= (le >> 8) & 0x0000FF00;
  be |= (le << 8) & 0x00FF0000;
  be |= (le << 24) & 0xFF000000;
  return (be);
}

static char	*my_revstr_be(char *str, size_t length)
{
  size_t	i;
  char		tmp;

  i = 0;
  if (str == NULL)
    return (str);
  while (i < length / 2)
  {
    tmp = str[i];
    str[i] = str[length - 1 - i];
    str[length - 1 - i] = tmp;
    i = i + 1;
  }
  return (str);
}

unsigned int	swap_be_ui(unsigned int n)
{
  char		*a;

  a = (char*)(&n);
  a = my_revstr_be(a, sizeof(unsigned int));
  return (*((unsigned int*)a));
}

int	swap_be_i(int n)
{
  char	*a;

  a = (char*)(&n);
  a = my_revstr_be(a, sizeof(int));
  return (*((int*)a));
}

short	swap_be_s(short n)
{
  char	*a;

  a = (char*)(&n);
  a = my_revstr_be(a, sizeof(short));
  return (*((short*)a));
}
