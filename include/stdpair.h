/*
** stdpair.h for corewar in /home/zirk/Epitech/CPE_2016_corewar
** 
** Made by Zirk
** Login   <zirk@epitech.net>
** 
** Started on  Tue Mar 14 23:53:03 2017 Zirk
** Last update Wed Mar 15 02:02:25 2017 Zirk
*/

#include <stdbool.h>

/*
** Pair a bool and a string
*/
typedef struct	s_stdpair
{
  bool		enabled;
  char		*name;
}		t_stdpair;
