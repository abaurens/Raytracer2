/*
** set_transparency.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/mat/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon May 15 14:08:37 2017 Benjamin
** Last update Thu May 18 13:13:14 2017 Benjamin
*/

#include <stdlib.h>
#include "parse.h"
#include "bs.h"

int	set_mat_transparency(t_mat *mat, char **tab)
{
  if (cnt_line_tab(tab) > 1 && !is_str_num(tab[1]) &&
      my_getfloat(tab[1]) >= 0 && my_getfloat(tab[1]) <= 1)
    {
      mat->parse.transparency = 1;
      mat->transparency = my_getfloat(tab[1]);
      return (0);
    }
  return (1);
}
