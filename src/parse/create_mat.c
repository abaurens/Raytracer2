/*
** create_mat.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon Apr 17 16:58:45 2017 Benjamin
** Last update Thu May 18 13:12:06 2017 Benjamin
*/

#include <stdlib.h>
#include "my_prtf.h"
#include "parse.h"
#include "bs.h"

static t_mat	*create_new_mat(t_mat *mat, char *name)
{
  t_mat	*tmp;
  t_mat	*new;

  if (!(new = malloc(sizeof(t_mat))))
    return (NULL);
  my_memset(new, 0, sizeof(t_mat));
  mat = (mat) ? mat : new;
  tmp = mat;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = (tmp == new) ? 0 : new;
  new->prev = (tmp == new) ? 0 : tmp;
  new->name = my_strdup(name);
  return (mat);
}

int	create_mat(char *name, t_mat **mat)
{
  t_mat	*tmp;

  tmp = *mat;
  while (tmp)
    {
      if (my_strcmp(tmp->name, name) == 0)
	{
	  my_printf("%s is seen two time.\n", name);
	  return (-1);
	}
      tmp = tmp->next;
    }
  if (!(*mat = create_new_mat(*mat, name)))
    return (-1);
  return (0);
}
