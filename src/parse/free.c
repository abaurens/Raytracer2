/*
** free.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/parse/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Sun May 21 19:36:42 2017 Julien Delane
** Last update Sun May 21 20:10:13 2017 Julien Delane
*/

#include <stdlib.h>
#include "rt.h"

static void	free_mat(t_mat *mat)
{
  t_mat		*tmp;

  while (mat)
    {
      tmp = mat;
      mat = mat->next;
      free(tmp->name);
      free(tmp);
    }
}

void		free_scene(t_scene *scene)
{
  int		i;

  i = -1;
  while (++i != scene->nb_obj)
    {
      free(scene->obj[i].name);
      free(scene->obj[i].mat_name);
    }
  free(scene->obj);
  i = -1;
  while (++i != scene->nb_light)
    free(scene->light[i].name);
  free(scene->light);
  free(scene->option);
  free_mat(scene->mat);
}
