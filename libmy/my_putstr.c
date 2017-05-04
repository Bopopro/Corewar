/*
** my_putstr.c for libmy in my_putstr.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Sun Nov 20 19:52:42 2016 Maxime Louet
** Last update Sun Nov 20 19:52:42 2016 Maxime Louet
*/

#include "my.h"

void	my_putstr(const char *str)
{
  if (str != NULL)
    my_putstr_fd(1, str);
}
