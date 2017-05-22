/*
** set_mat.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon Apr 17 18:35:44 2017 Benjamin
** Last update Thu May 18 12:09:54 2017 Benjamin
*/

#include <stdlib.h>
#include "parse.h"
#include "bs.h"

int	set_mat(char **tab, char *name, t_mat *mat)
{
  t_mat	*tmp;
  int	err;

  tmp = mat;
  err = 0;
  while (tmp && my_strcmp(tmp->name, name) != 0)
    tmp = tmp->next;
  if (my_strstr(tab[0], "color"))
    err += set_mat_color(tmp, tab);
  else if (my_strstr(tab[0], "transpa"))
    err += set_mat_transparency(tmp, tab);
  else if (my_strstr(tab[0], "reflect"))
    err += set_mat_reflect(tmp, tab);
  else if (my_strstr(tab[0], "refract"))
    err += set_mat_refract(tmp, tab);
  else if (my_strstr(tab[0], "shine"))
    err += set_mat_shine(tmp, tab);
  return (err);
}
