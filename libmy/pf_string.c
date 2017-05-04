/*
** f_string.c for my_printf in f_string.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Mon Nov  7 19:11:18 2016 Maxime Louet
** Last update Sun Nov 20 21:56:27 2016 Maxime Louet
*/

#include "my.h"

void	pf_string(int fd, va_list ap)
{
  char	*arg;

  arg = va_arg(ap, char *);
  if (arg == NULL)
    my_putstr_fd(fd, "(null)");
  else
    my_putstr_fd(fd, arg);
}
