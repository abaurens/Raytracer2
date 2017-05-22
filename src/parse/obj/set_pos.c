/*
** set_pos.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/obj/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon May  1 14:46:03 2017 Benjamin
** Last update Thu May 18 17:23:06 2017 Julien Delane
*/

#include "parse.h"
#include "bs.h"

int	set_obj_pos(t_obj *obj, char **tab)
{
  my_show_tab(tab);
  if (tab && cnt_line_tab(tab) > 3 && !is_str_num(tab[1]) &&
      !is_str_num(tab[2]) && !is_str_num(tab[3]))
    {
      obj->parse.pos = 1;
      obj->pos.x = my_getfloat(tab[1]);
      obj->pos.y = my_getfloat(tab[2]);
      obj->pos.z = my_getfloat(tab[3]);
      //printf("TESTY: %f\n", obj->pos.x);
      return (0);
    }
  return (1);
}
