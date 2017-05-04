/*
** my_toupper.c for libmy in my_toupper.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Tue Nov 29 14:04:42 2016 Maxime Louet
** Last update Tue Nov 29 14:04:42 2016 Maxime Louet
*/

#include "my.h"

char	my_toupper(int c)
{
  if (c >= 'a' && c <= 'z')
    return ((char)(c - 32));
  else
    return ((char)c);
}
