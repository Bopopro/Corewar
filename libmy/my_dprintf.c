/*
** my_dprintf.c for libmy in my_printf
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Mon Nov  7 09:40:16 2016 Maxime Louet
** Last update Sun Nov 20 22:56:26 2016 Maxime Louet
*/

#include "my.h"

int		my_dprintf(int fd, const char *format, ...)
{
  int		ret;
  va_list	ap;

  if (fd < 0 || format == NULL)
    return (-1);
  va_start(ap, format);
  ret = my_vdprintf(fd, format, ap);
  va_end(ap);
  return (ret);
}
