/*
** set_obj.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon May  1 13:32:44 2017 Benjamin
** Last update Thu May 18 11:49:21 2017 Benjamin
*/

#include <stdlib.h>
#include "parse.h"
#include "bs.h"

int	set_obj(char **tab, char *name, t_obj *obj)
{
  t_obj	*tmp;
  int	err;

  tmp = obj;
  err = 0;
  while (tmp && my_strcmp(tmp->name, name) != 0)
    tmp = tmp->next;
  if (my_strstr(tab[0], "mat"))
    err += set_obj_mat(tmp, tab);
  else if (my_strstr(tab[0], "quad"))
    err += set_obj_quad(tmp, tab);
  else if (my_strstr(tab[0], "pos"))
    err += set_obj_pos(tmp, tab);
  else if (my_strstr(tab[0], "rot"))
    err += set_obj_rot(tmp, tab);
  else if (my_strstr(tab[0], "color"))
    err += set_obj_color(tmp, tab);
  return (err);
}
