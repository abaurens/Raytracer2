/*
** light.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/obj_functions/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Thu Apr 27 09:56:28 2017 Julien Delane
** Last update Sat May 20 22:07:20 2017 Julien Delane
*/

#include <math.h>
#include <stdlib.h>
#include "rt.h"

double		get_light_coef(t_vec3f light_vector, t_vec3f normal_vector)
{
  double	light_norm;
  double	normal_norm;
  double	light_coef;

  light_norm = sqrt(light_vector.x * light_vector.x
		    + light_vector.y * light_vector.y
		    + light_vector.z * light_vector.z);
  normal_norm = sqrt(normal_vector.x * normal_vector.x
		     + normal_vector.y * normal_vector.y
		     + normal_vector.z * normal_vector.z);
  light_coef = (normal_vector.x * light_vector.x + normal_vector.y *
		light_vector.y + normal_vector.z * light_vector.z) /
  (normal_norm * light_norm);
  return (light_coef);
}

sfColor		add_effects(t_result *res, t_light *light,
			    t_vec3f light_vector)
{
  sfColor	color;
  double	coef;
  double	coef_b;
  t_vec3f	reflect;

  coef = get_light_coef(light_vector, res->normal);
  if (coef < AMBIENT)
    coef = AMBIENT;
  color = color_rgba(res->color.r * coef, res->color.g * coef,
		     res->color.b * coef, 255);
  if (coef == AMBIENT)
    return (color);
  reflect = reflect_vector(light_vector, res->normal);
  if ((coef_b = get_light_coef(res->dir_vector, reflect)) > 0)
    coef_b = 0;
  else
    coef_b = -coef_b;
  coef_b = pow(coef_b, res->obj->mat->shine);
  color.r = color.r * (1 - coef_b) + coef_b * light->color.r;
  color.g = color.g * (1 - coef_b) + coef_b * light->color.g;
  color.b = color.b * (1 - coef_b) + coef_b * light->color.b;
  return (color);
}

void		apply_diffuse(t_rt *rt, t_result *res)
{
  t_vec3f	light_vector;
  int		color[3];
  int		i;
  double	coef;

  init_int(color, 3);
  i = -1;
  while (++i != rt->scene->nb_light)
    {
      light_vector = get_dir_vector(res->intersect,
				    rt->scene->light[i].pos, 0);
      if ((coef = get_light_coef(light_vector, res->normal)) < AMBIENT)
	coef = AMBIENT;
      add(color, res->color, coef);
    }
  res->color = color_rgba(color[0] / rt->scene->nb_light,
			  color[1] / rt->scene->nb_light,
			  color[2] / rt->scene->nb_light, 255);
}

void		set_brightness(t_result *res, t_rt *rt)
{
  int		*value;
  int		i;
  int		color[3];

  init_int(color, 4);
  i = -1;
  while (++i != rt->scene->nb_light)
    {
      value = rand_shadow(res, &rt->scene->light[i], rt->scene);
      add_int(color, value);
      free(value);
    }
  res->color = color_rgba(color[0] / rt->scene->nb_light,
			  color[1] / rt->scene->nb_light,
			  color[2] / rt->scene->nb_light, 255);
}
