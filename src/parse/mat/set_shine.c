/*
** set_shine.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/mat/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon May 15 14:08:37 2017 Benjamin
** Last update Thu May 18 13:13:08 2017 Benjamin
*/

#include <stdlib.h>
#include "parse.h"
#include "bs.h"

int	set_mat_shine(t_mat *mat, char **tab)
{
  if (cnt_line_tab(tab) > 1 && !is_str_num(tab[1]) &&
      my_getnbr(tab[1]) >= 1 && my_getnbr(tab[1]) <= 2147483647)
    {
      mat->parse.shine = 1;
      mat->shine = my_getnbr(tab[1]);
      return (0);
    }
  return (1);
}
