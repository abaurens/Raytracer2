/*
** shadow.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Mon May  1 15:30:20 2017 Julien Delane
** Last update Mon May 22 10:09:26 2017 Julien Delane
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libgraph.h"
#include "rt.h"

int		*rand_shadow(t_result *res, t_light *light, t_scene *scene)
{
  int		*color;
  sfColor	value;
  int		o;
  t_vec3f	light_vector;

  if ((color = malloc(sizeof(int) * 3)) == NULL)
    return (NULL);
  o = -1;
  init_int(color, 3);
  light_vector = get_dir_vector(res->intersect, light->pos, 0);
  while (++o != scene->option->shadow)
    {
      if (!shadow(res, scene, light_vector))
	{
	  value = add_effects(res, light, light_vector);
	  add(color, value, 1);
	}
      light_vector = get_dir_vector(res->intersect, get_random(light->pos), 0);
    }
  remove_int(color, o);
  return (color);
}

int		check_in_front(t_scene *scene,
			       t_vec3f dir, t_vec3f camera)
{
  double	distance;
  int		i;

  distance = -1;
  i = -1;
  while (++i != scene->nb_obj && (distance > 1 || distance < 0))
    distance = intersect(scene->obj[i].quadra, dir, camera);
  if (distance > 1 || distance < 0)
    return (0);
  return (1);
}

int		shadow(t_result *res, t_scene *scene, t_vec3f dir)
{
  double	distance;
  int		i;

  distance = -1;
  i = -1;
  while (++i != scene->nb_obj && (distance > 1 || distance < 0))
    {
      if (&res->obj->quadra != &scene->obj[i].quadra)
	distance = intersect(scene->obj[i].quadra, dir, res->intersect);
    }
  if (distance > 1 || distance < 0)
    return (0);
  return (1);
}
