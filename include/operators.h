/*
** operators.h for operators in include/operators.h
** 
** Made by Robin Houssais
** Login   <robin.houssais@epitech.eu>
** 
** Started on  Wed Mar 29 10:19:36 2017 Robin Houssais
** Last update Wed Mar 29 10:19:36 2017 Robin Houssais
*/

#ifndef OPERATORS_H_
# define OPERATORS_H_

#include "vm.h"

void	live(t_machine *machine, t_champ **champs, t_fork*);
void	ld(t_machine *machine, t_champ *champ, t_fork *f, int *reg);
void	st(t_machine *machine, t_champ *champ, t_fork *f, int *reg);
void	add(t_machine *machine, t_champ *champ, t_fork *f, int *reg);
void	sub(t_machine *machine, t_champ *champ, t_fork *f, int *reg);
void	my_and(t_machine *machine, t_champ *champ, t_fork *f, int *reg);
void	my_or(t_machine *machine, t_champ *champ, t_fork *f, int *reg);
void	my_xor(t_machine *machine, t_champ *champ, t_fork *f, int *reg);
void	zjmp(t_machine *machine, t_champ *champ, t_fork *f, int *reg);
void	ldi(t_machine *machine, t_champ *champ, t_fork *f, int *reg);
void	sti(t_machine *machine, t_champ *champ, t_fork *f, int *reg);
void	my_fork(t_machine *machine, t_champ *champ, t_fork *f, int *reg);
void	lld(t_machine *machine, t_champ *champ, t_fork *f, int *reg);
void	lldi(t_machine *machine, t_champ *champ, t_fork *f, int *reg);
void	my_lfork(t_machine *machine, t_champ *champ, t_fork *f, int *reg);
void	aff(t_machine *machine, t_champ *champ, t_fork *f, int *reg);

#endif /* !OPERATORS_H_ */
