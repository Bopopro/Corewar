/*
** add.c for add.c in /home/Zirk/Epitech/linkedLists/liblist
** 
** Made by Christian Chaux
** Login   <Zirk@epitech.net>
** 
** Started on  Sun Oct 23 13:03:02 2016 Christian Chaux
** Last update Thu Mar 30 01:06:06 2017 Zirk
*/

#include <stdlib.h>
#include "mylist.h"

static t_list	*move_forward(t_list *copy, int index)
{
  int		i;

  i = 0;
  while (i < index && copy->next != NULL)
    {
      copy = copy->next;
      i++;
    }
  return (copy);
}

static t_list		*remove_next(t_list *copy)
{
  copy = copy->next;
  (copy->prev->prev != NULL) ?
    (copy->prev = copy->prev->prev) : (copy->prev = NULL);
  return (copy);
}

t_list		*remove_list(t_list *begin, int index)
{
  t_list	*copy;
  t_list	*to_delete;

  copy = begin;
  if (begin)
    {
      if (begin->next == NULL)
	return (NULL);
      copy = move_forward(copy, index);
      to_delete = copy;
      if (copy->prev != NULL)
	{
	  copy = copy->prev;
	  (copy->next->next != NULL) ?
	    (copy->next = copy->next->next) : (copy->next = NULL);
	  copy = to_delete;
	}
      else
	begin = begin->next;
      if (copy->next != NULL)
	{
	  copy = remove_next(copy);
	}
    }
  return (begin);
}
