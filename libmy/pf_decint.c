/*
** f_decint.c for my_printf in f_decint.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Mon Nov  7 18:36:01 2016 Maxime Louet
** Last update Mon Nov  7 18:36:01 2016 Maxime Louet
*/

#include "my.h"

void	pf_decintsigned(int fd, va_list ap)
{
  int	nb;

  nb = va_arg(ap, int);
  my_putnbr_fd(fd, nb);
}

void		pf_decintunsigned(int fd, va_list ap)
{
  unsigned int	nb;

  nb = va_arg(ap, unsigned int);
  my_putnbr_fd(fd, nb);
}
