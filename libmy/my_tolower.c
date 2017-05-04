/*
** my_tolower.c for libmy in my_tolower.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Tue Nov 29 14:04:42 2016 Maxime Louet
** Last update Tue Nov 29 14:04:42 2016 Maxime Louet
*/

#include "my.h"

char	my_tolower(int c)
{
  if (c >= 'A' && c <= 'Z')
    return ((char)(c + 32));
  else
    return ((char)c);
}

