/*
** my_isalpha.c for libmy in my_isalpha.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Sun Nov 20 21:28:19 2016 Maxime Louet
** Last update Sun Nov 20 21:28:19 2016 Maxime Louet
*/

#include "my.h"

int	my_isalpha(int c)
{
  return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ? 1 : 0);
}
