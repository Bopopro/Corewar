/*
** parse_string.c for corewar in /home/zirk/epitech/CPE_2016_corewar/src/asm
** 
** Made by Zirk
** Login   <zirk@epitech.net>
** 
** Started on  Wed Mar 15 23:37:25 2017 Zirk
** Last update Fri Mar 24 10:31:30 2017 Zirk
*/

#include <stdlib.h>
#include "asm.h"
#include "my.h"
#include "parse_string.h"

int	first_char_pos(const char *line)
{
  int	i;

  i = 0;
  if (line == NULL)
    return (-1);
  while (my_isspace(line[i]))
    i++;
  while (line[i] == '\0' || line[i] == COMMENT_CHAR)
    return (-1);
  return (i);
}

static bool	is_quote_correct(const char *str, int pos)
{
  int		i;
  int		nb_backslash;

  i = pos - 1;
  nb_backslash = 0;
  while (i > 0 && str[i] == '\\')
  {
    nb_backslash++;
    i--;
  }
  if (nb_backslash == 0 || nb_backslash % 2 != 0)
    return (true);
  else
    return (false);
}

static int	get_malloc_size(int pos1, int pos2, const char *str)
{
  int		y;
  bool		is_escape;
  int		size_malloc;

  size_malloc = pos2 - pos1;
  y = 0;
  is_escape = true;
  while (y < pos2 - pos1)
  {
    if (str[pos1 + y] == '\\' && is_escape)
      size_malloc--;
    if (str[pos1 + y] == '\\')
      is_escape = !is_escape;
    else
      is_escape = true;
    y++;
  }
  return (size_malloc);
}

static char	*return_string_given_pos(int pos1, int pos2, const char *str)
{
   char		*new_str;
   int		y;
   bool		is_escape;
   const int	size_malloc = get_malloc_size(pos1, pos2, str);
   int		offset;

   y = 0;
   is_escape = true;
   offset = 0;
   if ((new_str = malloc(size_malloc + 1)) == NULL)
     return (NULL);
   new_str[size_malloc] = '\0';
   while (y < pos2 - pos1)
   {
     if (str[pos1 + y] != '\\' || (str[pos1 + y] == '\\' && !is_escape))
       new_str[y - offset] = str[pos1 + y];
     else
       offset++;
     if (str[pos1 + y] == '\\')
       is_escape = !is_escape;
     else
       is_escape = true;
     y++;
   }
   return (new_str);
}

char	*get_string(const char *str, int ini_pos)
{
  int	i;

  i = ini_pos;
  if (i >= (int)my_strlen(str))
    return (NULL);
  while (str[i] && str[i] != '\"')
    i++;
  i++;
  ini_pos = i;
  while (str[i] != '\0' && (str[i] != '\"'
			|| (str[i] == '\"' && is_quote_correct(str, i))))
    i++;
  i--;
  return (return_string_given_pos(ini_pos, i, str));
}
