/*
** vector.c for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Fri Mar 31 21:00:07 2017 Arthur Baurens
** Last update Wed May 17 10:36:59 2017 Julien Delane
*/

#include <math.h>
#include "rt.h"

t_vec3f		reflect_vector(t_vec3f v, t_vec3f n)
{
  t_vec3f	reflect;
  double	dot_product;

  dot_product = sqrt(v.x * v.x + v.y * v.y + v.z * v.z)
      * sqrt(n.x * n.x + n.y * n.y + n.z * n.z);
  reflect.x = 2 * n.x * dot_product - v.x;
  reflect.y = 2 * n.y * dot_product - v.y;
  reflect.z = 2 * n.z * dot_product - v.z;
  return (reflect);
}

t_vec3f	*v_add(t_vec3f *v1, t_vec3f *v2, double fact)
{
  v1->x += (v2->x * fact);
  v1->y += (v2->y * fact);
  v1->z += (v2->z * fact);
  return (v1);
}

t_vec3f	*normalize(t_vec3f *vector)
{
  float	norm;

  norm = sqrt(vector->x * vector->x + vector->y * vector->y
	      + vector->z * vector->z);
  vector->x = vector->x / norm;
  vector->y = vector->y / norm;
  vector->z = vector->z / norm;
  return (vector);
}

t_vec3f		get_dir_vector(t_vec3f a, t_vec3f b, int i)
{
  t_vec3f	dir_vector;

  dir_vector.x = b.x - a.x;
  dir_vector.y = b.y - a.y;
  dir_vector.z = b.z - a.z;
  if (i)
    normalize(&dir_vector);
  return (dir_vector);
}

t_vec3f		get_pos_res(t_vec3f eye_pos, float distance,
			    t_vec3f dir_vector)
{
  t_vec3f	pos;

  pos.x = eye_pos.x + distance * dir_vector.x;
  pos.y = eye_pos.y + distance * dir_vector.y;
  pos.z = eye_pos.z + distance * dir_vector.z;
  return (pos);
}
