/*
** my_rand.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Fri May 12 18:34:59 2017 Julien Delane
** Last update Thu May 18 16:57:37 2017 Julien Delane
*/

#include "rt.h"

int		my_rand()
{
  static unsigned int	random = 8;
  static int		i = 0;
  unsigned int		a;
  unsigned int		b;
  unsigned int		m;

  if (i == 0)
    {
      random = time(NULL);
      i = 1;
    }
  b = 0;
  a = 16807;
  m = 0x7FFFFFFF;
  random = (a * random + b) % m;
  return (random);
}

t_vec3f		get_random(t_vec3f light_pos)
{
  int		x;
  int		y;
  int		z;

  x = my_rand() % 2;
  y = my_rand() % 2;
  z = my_rand() % 2;
  if (x)
    x = -1;
  else
    x = 1;
  if (y)
    y = -1;
  else
    y = 1;
  if (z)
    z = -1;
  else
    z = 1;
  light_pos.x = light_pos.x + (double)(my_rand() % 100) / 500 * x;
  light_pos.y = light_pos.y + (double)(my_rand() % 100) / 500 * y;
  light_pos.z = light_pos.z + (double)(my_rand() % 100) / 500 * z;
  return (light_pos);
}
