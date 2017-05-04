/*
** my_putchar_fd.c for libmy in my_putchar_fd.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Wed Nov 16 10:45:00 2016 Maxime Louet
** Last update Wed Nov 16 10:45:00 2016 Maxime Louet
*/

#include <unistd.h>
#include "my.h"

void	my_putchar_fd(int fd, int c)
{
  if (fd >= 0)
    write(fd, &c, 1);
}
