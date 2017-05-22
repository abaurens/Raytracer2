/*
** set_mat.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/obj/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon May  1 14:00:38 2017 Benjamin
** Last update Thu May 18 13:13:48 2017 Benjamin
*/

#include "parse.h"
#include "bs.h"

int	set_obj_mat(t_obj *obj, char **tab)
{
  if (cnt_line_tab(tab) > 1 && !is_str_printable(tab[1]))
    {
      obj->parse.mat = 1;
      obj->mat_name = my_strdup(tab[1]);
      return (0);
    }
  return (1);
}
