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

static const t_pf_fts	g_fts[] = {
  {'c', "", pf_character},
  {'s', "", pf_string},
  {'d', "", pf_decintsigned},
  {'i', "", pf_decintsigned},
  {'u', "", pf_decintunsigned},
  {'p', "", pf_pointer},
  {'%', "", pf_percent},
  {'%', "", pf_percent}
};

static size_t	get_formatter(char c)
{
  size_t	i;

  i = 0;
  while (g_fts[i].flag != c && i < MYPRINTF_FLAGS_NB - 1)
    i++;
  return (i);
}

static void	handle_percent(int fd, const char *format, size_t *i,
			       va_list ap)
{
  if ((format[*i] >= 9 && format[*i] <= 13) ||
      get_formatter(format[*i]) == MYPRINTF_FLAGS_NB - 1)
  {
    my_putchar_fd(fd, '%');
    my_putchar_fd(fd, format[*i]);
    return ;
  }
  g_fts[get_formatter(format[*i])].p(fd, ap);
}

int		my_vdprintf(int fd, const char *format, va_list ap)
{
  size_t	i;
  size_t	laststart;

  i = 0;
  laststart = 0;
  if (fd < 0 || format == NULL)
    return (-1);
  while (format[i] != '\0')
  {
    if (format[i] == '%' && format[i + 1] != '\0')
    {
      if (i > 0 && laststart != i)
	my_putnstr_fd(fd, &format[laststart], i - 1 - laststart);
      i++;
      handle_percent(fd, format, &i, ap);
      laststart = i + 1;
    }
    i++;
  }
  if (laststart != i)
    my_putnstr_fd(fd, &format[laststart], i - laststart);
  return (0);
}
