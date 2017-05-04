/*
** my_isalnum.c for libmy in my_isalnum.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Sun Nov 20 21:26:20 2016 Maxime Louet
** Last update Sun Nov 20 21:26:20 2016 Maxime Louet
*/

#include "my.h"

int	my_isalnum(int c)
{
  return (my_isalpha(c) || my_isdigit(c));
}
