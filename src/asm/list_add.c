/*
** add.c for add.c in /home/Zirk/Epitech/linkedLists/liblist
** 
** Made by Christian Chaux
** Login   <Zirk@epitech.net>
** 
** Started on  Sun Oct 23 13:03:02 2016 Christian Chaux
** Last update Thu Mar 30 00:59:17 2017 Zirk
*/

#include <stdlib.h>
#include "asm.h"
#include "mylist.h"

t_list		*add_list(t_list *begin, void *data)
{
  t_list	*copy;
  t_list	*prev;

  copy = begin;
  if (begin)
    {
      while (copy->next != NULL)
	{
	  copy = copy->next;
	}
      prev = copy;
      copy->next = malloc(sizeof(t_list));
      copy = copy->next;
      copy->prev = prev;
    }
  else
    {
      begin = malloc(sizeof(t_list));
      copy = begin;
      copy->prev = NULL;
    }
  copy->data = data;
  copy->next = NULL;
  return (begin);
}
