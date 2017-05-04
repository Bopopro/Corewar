/*
** parse_string.h for corewar in /home/zirk/epitech/CPE_2016_corewar/include
** 
** Made by Zirk
** Login   <zirk@epitech.net>
** 
** Started on  Sun Mar 19 15:18:15 2017 Zirk
** Last update Sun Mar 26 21:44:28 2017 Zirk
*/

#ifndef PARSE_STRING_H_
# define PARSE_STRING_H_

# include <stdbool.h>

char	*get_string(const char *str, int ini_pos);
char	*get_word(const char *line, int ini_pos);
char	*get_instruction(const char *line, int ini_pos);
int	first_char_pos(const char *line);
int	is_strn_number(const char *str, int ini_pos);

#endif /* !PARSE_STRING_H_ */
