/*
** my_putnstr.c for libmy in my_putnstr.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Thu Nov 17 22:55:23 2016 Maxime Louet
** Last update Thu Nov 17 22:55:23 2016 Maxime Louet
*/

#include "my.h"

void	my_putnstr(const char *str, size_t n)
{
  my_putnstr_fd(1, str, n);
}
