/*
** my_putnbr_base_fd.c for libmy in my_putnbr_base_fd.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Sun Nov 20 19:24:59 2016 Maxime Louet
** Last update Sun Nov 20 19:24:59 2016 Maxime Louet
*/

#include <limits.h>
#include "my.h"

void	my_putnbr_base_fd(int fd, long int nb, const char *base)
{
  int	baselen;
  int	final;

  if (nb <= INT_MIN)
    final = INT_MIN;
  else if (nb >= INT_MAX)
    final = INT_MAX;
  else
    final = (int)nb;
  if (final < 0)
  {
    my_putchar_fd(fd, '-');
    final = -final;
  }
  baselen = (int)my_strlen(base);
  if (final >= baselen)
    my_putnbr_base_fd(fd, final / baselen, base);
  my_putchar_fd(fd, base[final % baselen]);
}
