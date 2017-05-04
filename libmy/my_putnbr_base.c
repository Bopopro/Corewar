/*
** my_putnbr_base.c for libmy in my_putnbr_base.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Sun Nov 20 21:20:32 2016 Maxime Louet
** Last update Sun Nov 20 21:20:32 2016 Maxime Louet
*/

#include <limits.h>
#include "my.h"

void	my_putnbr_base(long int nb, const char *base)
{
  my_putnbr_base_fd(1, nb, base);
}
