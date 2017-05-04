/*
** my_itoa.c for libmy in my_itoa.c
** 
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
** 
** Started on  Sun Dec  4 15:19:19 2016 Maxime Louet
** Last update Sun Dec  4 15:19:19 2016 Maxime Louet
*/

#include "my.h"

char	*my_itoa(int nb)
{
  int	i;
  int	isneg;
  char	*str;

  isneg = false;
  if ((str = my_calloc(my_nbrlen(nb) + 5, 1)) == NULL)
    return (NULL);
  i = 0;
  if (nb < 0)
  {
    isneg = true;
    nb = -nb;
  }
  while (nb > 0)
  {
    str[i] = (char)(nb % 10 + '0');
    nb = nb / 10;
    i++;
  }
  if (isneg)
    str[i++] = '-';
  str[i] = '\0';
  return (my_revstr(str));
}
