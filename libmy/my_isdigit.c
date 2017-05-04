/*
** my_isdigit.c for libmy in my_isdigit.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Sat Nov 19 18:58:23 2016 Maxime Louet
** Last update Sat Nov 19 18:58:23 2016 Maxime Louet
*/

#include "my.h"

int	my_isdigit(int c)
{
  return (c >= '0' && c <= '9' ? 1 : 0);
}
