/*
** rotation.c for raytracer2 in /home/Realague/Delivery/B_MUL/raytracer2/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Wed Apr 26 10:21:45 2017 Julien Delane
** Last update Tue May 16 14:07:15 2017 Julien Delane
*/

#include <math.h>
#include "rt.h"

static void		rotate_x(t_quadra *quad, double x)
{
  t_quadra		old;

  if (x)
    {
      old = *quad;
      quad->c = old.c * cos(x) * cos(x) + old.d * sin(x) * cos(x)
	  + old.b * sin(x) * sin(x);
      quad->b = old.c * sin(x) *sin(x) + old.b * cos(x) * cos(x)
	  - old.d * sin(x) * cos(x);
      quad->d = -2 * old.c * cos(x) * sin(x) + 2 * old.b * cos(x) * sin(x)
	  - old.d * sin(x) * sin(x);
      quad->e = old.e * cos(x) - old.f * sin(x);
      quad->f = old.e * sin(x) + old.f * cos(x);
      quad->h = 2 * old.d * cos(x) * cos(x) + old.h * cos(x) + old.i * sin(x);
      quad->i = -old.h * sin(x) + old.i * cos(x);
    }
}

static void		rotate_y(t_quadra *quad, double y)
{
  t_quadra		old;

  if (y)
    {
      old = *quad;
      quad->a = old.a * cos(y) * cos(y) + old.b * sin(y) * sin(y)
	  - old.e * cos(y) * sin(y);
      quad->b = old.a * sin(y) * sin(y) + old.b * cos(y) * cos(y)
	  + old.e * sin(y) * cos(y);
      quad->d = old.d * cos(y) + old.f * sin(y);
      quad->e = old.a * cos(y) * sin(y) + old.e * cos(y)
	  - old.b * sin(y) * cos(y) - old.e * sin(y) * sin(y);
      quad->f = old.f * cos(y) - old.d * sin(y);
      quad->g = old.g * cos(y) - old.i * sin(y);
      quad->i = old.g * sin(y) + old.i * cos(y);
    }
}

static void		rotate_z(t_quadra *quad, double z)
{
  t_quadra		old;

  if (z)
    {
      old = *quad;
      quad->a = old.a * cos(z) * cos(z) + old.c * sin(z) * sin(z)
	+ old.f * sin(z) * cos(z);
      quad->c = old.a * sin(z) * sin(z)	+ old.c * cos(z) * cos(z)
	  - old.f * sin(z) * cos(z);
      quad->d = old.d * cos(z) - old.e * sin(z);
      quad->e = old.d * sin(z) + old.e * cos(z);
      quad->f = (2 * (old.c - old.a) * sin(z) * cos(z) + old.f *
		 (cos(z) * cos(z) - sin(z) * sin(z)));
      quad->g = old.g * cos(z) + old.h * sin(z);
      quad->h = -old.g * sin(z) + old.h * cos(z);
    }
}

void	rotate(t_quadra *quad, t_vec3f rotation)
{
  rotate_z(quad, TO_RAD(rotation.z));
  rotate_y(quad, TO_RAD(rotation.y));
  rotate_x(quad, TO_RAD(rotation.x));
}
