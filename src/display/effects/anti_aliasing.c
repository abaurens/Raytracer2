/*
** anti_aliasing.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Thu May  4 13:47:58 2017 Julien Delane
** Last update Sun May 21 15:23:40 2017 Julien Delane
*/

#include "libgraph.h"
#include "rt.h"

static void	init_color(int *color, int ssaa, t_vec2i *screen_size)
{
  init_int(color, 3);
  color[3] = ssaa * ssaa;
  screen_size->x *= ssaa;
  screen_size->y *= ssaa;
}

sfColor		super_sampling(t_scene *scene, t_rt *rt, t_vec2i screen_size,
			       t_vec2i screen_pos_base)
{
  t_result	res;
  t_vec2i	screen_pos;
  t_vec3f	dir_vector;
  int		color[4];
  int		i;
  int		ssaa;

  i = -1;
  ssaa = scene->option->ssaa;
  init_color(color, ssaa, &screen_size);
  while (++i != color[3])
    {
      screen_pos.x = screen_pos_base.x * ssaa + (i % ssaa);
      screen_pos.y = screen_pos_base.y * ssaa + (i / ssaa);
      dir_vector = calc_dir_vector(screen_size.x / (2 * tan(TO_RAD(70.0) / 2)),
				   screen_size, screen_pos);
      dir_vector = rotate_xyz(dir_vector, rt->rot);
      res.i = 0;
      res.camera = rt->pos;
      fill_result(rt, &res, dir_vector, NULL);
      add_direct_light(scene, &res, rt, dir_vector);
      add(color, res.color, 1);
    }
  return (color_rgba(color[0] / color[3], color[1] / color[3],
		     color[2] / color[3], 255));
}
