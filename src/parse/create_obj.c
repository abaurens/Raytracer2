/*
** create_obj.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon Apr 17 17:01:21 2017 Benjamin
** Last update Thu May 18 13:39:44 2017 Benjamin
*/

#include <stdlib.h>
#include "my_prtf.h"
#include "parse.h"
#include "bs.h"

static t_obj	*create_new_obj(t_obj *obj, char *name)
{
  t_obj	*tmp;
  t_obj	*new;

  if (!(new = malloc(sizeof(t_obj))))
    return (NULL);
  my_memset(new, 0, sizeof(t_obj));
  obj = (obj) ? obj : new;
  tmp = obj;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = (tmp == new) ? 0 : new;
  new->prev = (tmp == new) ? 0 : tmp;
  new->name = my_strdup(name);
  return (obj);
}

int	create_obj(char *name, t_obj **obj)
{
  t_obj	*tmp;

  tmp = *obj;
  while (tmp)
    {
      if (my_strcmp(tmp->name, name) == 0)
	{
	  my_printf("%s is seen two time.\n", name);
	  return (-1);
	}
      tmp = tmp->next;
    }
  if (!(*obj = create_new_obj(*obj, name)))
    return (-1);
  return (0);
}
