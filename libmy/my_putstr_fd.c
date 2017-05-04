/*
** my_putstr_fd.c for libmy in my_putstr_fd.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Wed Nov 16 10:45:23 2016 Maxime Louet
** Last update Wed Nov 16 10:45:23 2016 Maxime Louet
*/

#include <unistd.h>
#include "my.h"

void	my_putstr_fd(int fd, const char *str)
{
  if (str != NULL)
    write(fd, str, my_strlen(str));
}
