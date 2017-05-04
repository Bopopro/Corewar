/*
** f_character.c for my_printf in f_character.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Mon Nov  7 19:03:33 2016 Maxime Louet
** Last update Mon Nov  7 19:03:33 2016 Maxime Louet
*/

#include "my.h"

void	pf_character(int fd, va_list ap)
{
  my_putchar_fd(fd, va_arg(ap, int));
}
