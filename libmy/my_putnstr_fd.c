/*
** my_putnstr_fd.c for libmy in my_putnstr_fd.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Thu Nov 17 22:55:23 2016 Maxime Louet
** Last update Thu Nov 17 22:55:23 2016 Maxime Louet
*/

#include <unistd.h>
#include "my.h"

void	my_putnstr_fd(int fd, const char *str, size_t n)
{
  write(fd, str, my_strnlen(str, n));
}
