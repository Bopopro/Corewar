/*
** my_putnbr_fd.c for libmy in my_putnbr_fd.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Sun Nov 20 19:25:35 2016 Maxime Louet
** Last update Sun Nov 20 19:25:35 2016 Maxime Louet
*/

#include "my.h"

void	my_putnbr_fd(int fd, long int nb)
{
  my_putnbr_base_fd(fd, nb, "0123456789");
}
