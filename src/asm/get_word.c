/*
** get_word.c for corewar in /home/zirk/epitech/CPE_2016_corewar/src/asm
** 
** Made by Zirk
** Login   <zirk@epitech.net>
** 
** Started on  Wed Mar 22 14:34:01 2017 Zirk
** Last update Mon Mar 27 11:28:11 2017 Zirk
*/

#include <stdlib.h>
#include "parse_string.h"
#include "my.h"
#include "op.h"

/*
** We can have Word for free with our student mail :).
*/
char	*get_word(const char *line, int ini_pos)
{
  int	i;
  char	*word;

  while (my_isspace(line[ini_pos]))
    ini_pos++;
  i = ini_pos;
  while (line[i] != '\0' && !my_isspace(line[i]))
    i++;
  if (i - ini_pos == 0)
    return (NULL);
  if ((word = malloc(i - ini_pos + 1)) == NULL)
      return (NULL);
  my_strncpy(word, &line[ini_pos], i - ini_pos);
  return (word);
}

char	*get_instruction(const char *line, int ini_pos)
{
  int	i;
  char	*word;

  while (my_isspace(line[ini_pos]))
    ini_pos++;
  i = ini_pos;
  while (line[i] != '\0' && line[i] != SEPARATOR_CHAR &&
	 line[i] != COMMENT_CHAR)
    i++;
  i--;
  while (i > 0 && line[i] != '\0' && my_isspace(line[i]))
    i--;
  i++;
  if (i - ini_pos <= 0)
    return (NULL);
  if ((word = malloc(i - ini_pos + 1)) == NULL)
      return (NULL);
  my_strncpy(word, &line[ini_pos], i - ini_pos);
  return (word);
}
