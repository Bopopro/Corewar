/*
** my_printf.c for libmy in my_printf.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Mon Dec  5 13:18:04 2016 Maxime Louet
** Last update Mon Dec  5 13:18:04 2016 Maxime Louet
*/

#include "my.h"

int		my_printf(const char *format, ...)
{
  int		ret;
  va_list	ap;

  if (format == NULL)
    return (-1);
  va_start(ap, format);
  ret = my_vdprintf(1, format, ap);
  va_end(ap);
  return (ret);
}
