/*
** my_putchar.c for libmy in my_putchar.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Wed Nov 16 10:45:00 2016 Maxime Louet
** Last update Wed Nov 16 10:45:00 2016 Maxime Louet
*/

#include "my.h"

void	my_putchar(int c)
{
  my_putchar_fd(1, c);
}
