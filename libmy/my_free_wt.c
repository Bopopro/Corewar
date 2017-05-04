/*
** my_free_wt.c for libmy in my_free_wt.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Tue Jan 10 11:34:28 2017 Maxime Louet
** Last update Tue Jan 10 11:34:28 2017 Maxime Louet
*/

#include <stdlib.h>
#include "my.h"

void	my_free_wt(char **wt)
{
  int	i;

  i = 0;
  while (wt != NULL && wt[i] != NULL)
  {
    free(wt[i]);
    i++;
  }
  free(wt);
}
