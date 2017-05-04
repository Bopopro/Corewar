/*
** labels_store.c for asm in src/asm/labels_store.c
**
** Made by Maxime Louet
** Login   <maxime.louet@epitech.eu>
**
** Started on  Sun Apr  2 19:27:06 2017 Maxime Louet
** Last update Sun Apr  2 19:27:06 2017 Maxime Louet
*/

#include "asm.h"
#include "my.h"

static bool	store_label(t_list **list, char *name, size_t mempos,
			    t_options *options)
{
  t_label	*label;

  if ((label = my_calloc(1, sizeof(*label))) == NULL)
    return (false);
  label->name = my_strdup(name);
  label->mempos = mempos;
  *list = add_list(*list, label);
  if (options->flags[DEBUG]->enabled)
    my_printf("\x1B[33m[DEBUG]\x1B[0m Storing label [%s] at %d bytes from the"
	      " start\n",
	      label->name,
	      label->mempos);
  return (true);
}

bool		store_labels(t_list **labels, t_list *lines,
			     t_options *options)
{
  t_line	*line;

  line = NULL;
  while (lines != NULL)
  {
    line = lines->data;
    if (line->label != NULL)
    {
      if (!store_label(labels, line->label, line->mempos, options))
	return (false);
    }
    lines = lines->next;
  }
  return (true);
}
