/*
** mylist.h for mylist.h in /home/xwilarg/CPool_Day11/includes
** 
** Made by Christian Chaux
** Login   <xwilarg@epitech.net>
** 
** Started on  Mon Oct 17 13:47:38 2016 Christian Chaux
** Last update Thu Mar 30 02:44:41 2017 Zirk
*/

#ifndef MYLIST_H_
# define MYLIST_H_

typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

struct s_list	*add_list(struct s_list *begin, void *data);
struct s_list	*remove_list(struct s_list *begin, int index);

#endif /* !MYLIST_H_ */
