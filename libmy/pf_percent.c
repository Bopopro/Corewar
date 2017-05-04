/*
** f_percent.c for my_printf in printf/f_percent.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Tue Nov  8 12:12:49 2016 Maxime Louet
** Last update Tue Nov  8 12:12:49 2016 Maxime Louet
*/

#include "my.h"

void	pf_percent(int fd, va_list ap)
{
  (void)ap;
  my_putchar_fd(fd, '%');
}
