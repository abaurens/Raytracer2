/*
** raytracing_core.c for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu Mar 30 17:55:31 2017 Arthur Baurens
** Last update Sun May 21 15:24:24 2017 Julien Delane
*/

#include <stdio.h>
#include <math.h>
#include "rt.h"
#include "libgraph.h"

static void	fill_result_debug(t_rt *rt, t_result *res, t_vec3f dir_vector)
{
  double	distance;
  int		i;

  res->dist = -1;
  i = -1;
  res->color = sfBlack;
  while (++i != rt->scene->nb_obj)
    {
      distance = intersect(rt->scene->obj[i].quadra, dir_vector, res->camera);
      if (distance > 0 && (distance < res->dist || res->dist == -1))
	{
	  res->dist = distance;
	  res->obj = &rt->scene->obj[i];
	}
    }
  if (res->dist == -1)
    return ;
  res->intersect = get_pos_res(res->camera, res->dist, dir_vector);
  res->normal = calc_normal_vector(res->obj->quadra, res->intersect);
  res->color = res->obj->color;
  apply_diffuse(rt, res);
}

static void	fill_res(t_result *res, t_vec3f dir_vector)
{
  res->dir_vector = dir_vector;
  res->color = res->obj->color;
  res->intersect = get_pos_res(res->camera, res->dist, dir_vector);
  res->normal = calc_normal_vector(res->obj->quadra, res->intersect);
}

void		fill_result(t_rt *rt, t_result *res,
			    t_vec3f dir_vector, t_obj *obj)
{
  double	distance;
  int		i;

  res->dist = -1;
  i = -1;
  res->color = sfBlack;
  while (++i != rt->scene->nb_obj)
    {
      distance = intersect(rt->scene->obj[i].quadra, dir_vector, res->camera);
      if (obj != &rt->scene->obj[i] && distance > 0 &&
	  (distance < res->dist || res->dist == -1))
	{
	  res->dist = distance;
	  res->obj = &rt->scene->obj[i];
	}
    }
  if (res->dist == -1)
    return ;
  fill_res(res, dir_vector);
  if (rt->scene->nb_light > 0)
    set_brightness(res, rt);
  reflection(rt, res);
  refraction(rt, res);
}

static t_vec2i	init_vector(int x, int y, t_vec2i *screen_pos, t_prog *prog)
{
  t_vec2i	screen_size;

  screen_pos->x = x;
  screen_pos->y = y;
  screen_size.x = prog->w;
  screen_size.y = prog->h;
  return (screen_size);
}

void		get_pixel_color(t_prog *prog, int x, int y)
{
  t_rt		*rt;
  t_vec2i	s_s;
  t_vec2i	s_p;
  t_vec3f	dir_vector;
  t_result	res;

  rt = (t_rt *)prog->data;
  s_s = init_vector(x, y, &s_p, prog);
  if (rt->scene->option->ssaa > 1 && rt->render_mode)
    {
      place_pixel(prog, x, y, super_sampling(rt->scene, rt, s_s, s_p));
      return ;
    }
  dir_vector = calc_dir_vector(s_s.x / (2 * tan(TO_RAD(70.0) / 2)), s_s, s_p);
  dir_vector = rotate_xyz(dir_vector, rt->rot);
  res.camera = rt->pos;
  if (rt->render_mode)
    {
      res.i = 0;
      fill_result(rt, &res, dir_vector, NULL);
      add_direct_light(rt->scene, &res, rt, dir_vector);
    }
  else
    fill_result_debug(rt, &res, dir_vector);
  place_pixel(prog, x, y, res.color);
}
