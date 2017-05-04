/*
** get_type.c for corewar in get_type.c
** 
** Made by Bilel Fourati
** Login   <bilel.fourati@epitech.eu>
** 
** Started on  Thu Mar 30 23:38:57 2017 Bilel Fourati
** Last update Thu Mar 30 23:38:57 2017 Bilel Fourati
*/

#include <stdlib.h>
#include "vm.h"

static int	get_first_type(char);
static int	get_second_type(char);
static int	get_third_type(char);

static int	(*fnc_type[MAX_ARGS_NUMBER])(char) =
{
  (get_first_type),
  (get_second_type),
  (get_third_type),
  (NULL)
};

static int	get_first_type(char cb)
{
  if ((cb >> 7 & 1) == 1 && (cb >> 6 & 1) == 1)
    return (IND_TYPE);
  else if ((cb >> 7 & 1) == 1 && (cb >> 6 & 1) == 0)
    return (DIR_TYPE);
  else if ((cb >> 7 & 1) == 0 && (cb >> 6 & 1) == 1)
    return (REG_TYPE);
  return (FAIL);
}

static int	get_second_type(char cb)
{
  if ((cb >> 5 & 1) == 1 && (cb >> 4 & 1) == 1)
    return (IND_TYPE);
  else if ((cb >> 5 & 1) == 1 && (cb >> 4 & 1) == 0)
    return (DIR_TYPE);
  else if ((cb >> 5 & 1) == 0 && (cb >> 4 & 1) == 1)
    return (REG_TYPE);
  return (FAIL);
}

static int	get_third_type(char cb)
{
  if ((cb >> 3 & 1) == 1 && (cb >> 2 & 1) == 1)
    return (IND_TYPE);
  else if ((cb >> 3 & 1) == 1 && (cb >> 2 & 1) == 0)
    return (DIR_TYPE);
  else if ((cb >> 3 & 1) == 0 && (cb >> 2 & 1) == 1)
    return (REG_TYPE);
  return (FAIL);
}

int	get_cb_type(char cb, int n_arg)
{
  return (fnc_type[n_arg](cb));
}
