/*
** create_light.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon Apr 17 17:00:37 2017 Benjamin
** Last update Thu May 18 14:16:28 2017 Benjamin
*/

#include <stdlib.h>
#include "my_prtf.h"
#include "parse.h"
#include "bs.h"

static t_light	*create_new_light(t_light *light, char *name)
{
  t_light	*tmp;
  t_light	*new;

  if (!(new = malloc(sizeof(t_light))))
    return (NULL);
  my_memset(new, 0, sizeof(t_light));
  light = (light) ? light : new;
  tmp = light;
  while (tmp->next)
    tmp = tmp->next;
  tmp->next = (tmp == new) ? 0 : new;
  new->prev = (tmp == new) ? 0 : tmp;
  new->name = my_strdup(name);
  return (light);
}

int	create_light(char *name, t_light **light)
{
  t_light	*tmp;

  tmp = *light;
  while (tmp)
    {
      if (my_strcmp(tmp->name, name) == 0)
	{
	  my_printf("%s is seen two time.\n", name);
	  return (-1);
	}
      tmp = tmp->next;
    }
  if (!(*light = create_new_light(*light, name)))
    return (-1);
  return (0);
}
