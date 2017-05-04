/*
** my_isspace.c for libmy in my_isspace.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Thu Jan 26 10:31:30 2017 Maxime Louet
** Last update Thu Jan 26 10:31:30 2017 Maxime Louet
*/

#include "my.h"

int	my_isspace(int c)
{
  return ((c == ' ' || c == '\t' || c == '\v' || c == '\f') ? (1) : (0));
}
