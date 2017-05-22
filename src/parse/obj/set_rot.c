/*
** set_rot.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/obj/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon May  1 14:46:16 2017 Benjamin
** Last update Thu May 18 13:14:06 2017 Benjamin
*/

#include "parse.h"
#include "bs.h"

int	set_obj_rot(t_obj *obj, char **tab)
{
  if (tab && cnt_line_tab(tab) > 3 && !is_str_num(tab[1]) &&
      !is_str_num(tab[2]) && !is_str_num(tab[3]))
    {
      obj->parse.pos = 1;
      obj->rot.x = my_getfloat(tab[1]);
      obj->rot.y = my_getfloat(tab[2]);
      obj->rot.z = my_getfloat(tab[3]);
      return (0);
    }
  return (1);
}
