/*
** set_color.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/obj/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon May  1 14:46:27 2017 Benjamin
** Last update Thu May 18 13:13:42 2017 Benjamin
*/

#include "parse.h"
#include "bs.h"

int	set_obj_color(t_obj *obj, char **tab)
{
  if (cnt_line_tab(tab) > 4 && !is_str_num(tab[1]) && !is_str_num(tab[2])
      && !is_str_num(tab[3]) && !is_str_num(tab[4]) &&
      my_getnbr(tab[1]) >= 0 && my_getnbr(tab[1]) <= 255 &&
      my_getnbr(tab[2]) >= 0 && my_getnbr(tab[2]) <= 255 &&
      my_getnbr(tab[3]) >= 0 && my_getnbr(tab[3]) <= 255 &&
      my_getnbr(tab[4]) >= 0 && my_getnbr(tab[4]) <= 255)
    {
      obj->parse.color = 1;
      obj->color.r = my_getnbr(tab[1]);
      obj->color.g = my_getnbr(tab[2]);
      obj->color.b = my_getnbr(tab[3]);
      obj->color.a = my_getnbr(tab[4]);
      return (0);
    }
  return (1);
}
