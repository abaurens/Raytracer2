/*
** set_pos.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/light/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon May  1 14:46:03 2017 Benjamin
** Last update Thu May 18 13:13:33 2017 Benjamin
*/

#include "parse.h"
#include "bs.h"

int	set_light_pos(t_light *light, char **tab)
{
  if (tab && cnt_line_tab(tab) > 3 && !is_str_num(tab[1]) &&
      !is_str_num(tab[2]) && !is_str_num(tab[3]))
    {
      light->parse.pos = 1;
      light->pos.x = my_getfloat(tab[1]);
      light->pos.y = my_getfloat(tab[2]);
      light->pos.z = my_getfloat(tab[3]);
      return (0);
    }
  return (1);
}
