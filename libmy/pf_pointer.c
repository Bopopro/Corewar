/*
** f_pointer.c for my_printf in f_pointer.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Tue Nov  8 18:26:38 2016 Maxime Louet
** Last update Tue Nov  8 18:26:38 2016 Maxime Louet
*/

#include "my.h"

static size_t	ptr_toint(void *ptr)
{
  char		*ptr2;
  char		*zero;

  ptr2 = ptr;
  zero = NULL;
  return ((size_t)(ptr2 - zero));
}

void		pf_pointer(int fd, va_list ap)
{
  void		*ptr;

  ptr = (void *)va_arg(ap, void *);
  if (ptr == NULL)
    my_putstr_fd(fd, "(nil)");
  else
  {
    my_putstr_fd(fd, "0x");
    my_putnbr_base_fd(fd, (long int)ptr_toint(ptr), "0123456789abcdef");
  }
}
