/*
** set_color.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/mat/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Wed Apr 19 14:21:01 2017 Benjamin
** Last update Thu May 18 13:12:49 2017 Benjamin
*/

#include <stdlib.h>
#include "parse.h"
#include "bs.h"

int	set_mat_color(t_mat *mat, char **tab)
{
  if (cnt_line_tab(tab) > 4 && !is_str_num(tab[1]) && !is_str_num(tab[2])
      && !is_str_num(tab[3]) && !is_str_num(tab[4]) &&
      my_getnbr(tab[1]) >= 0 && my_getnbr(tab[1]) <= 255 &&
      my_getnbr(tab[2]) >= 0 && my_getnbr(tab[2]) <= 255 &&
      my_getnbr(tab[3]) >= 0 && my_getnbr(tab[3]) <= 255 &&
      my_getnbr(tab[4]) >= 0 && my_getnbr(tab[4]) <= 255)
    {
      mat->parse.color = 1;
      mat->color.r = my_getnbr(tab[1]);
      mat->color.g = my_getnbr(tab[2]);
      mat->color.b = my_getnbr(tab[3]);
      mat->color.a = my_getnbr(tab[4]);
      return (0);
    }
  return (1);
}
