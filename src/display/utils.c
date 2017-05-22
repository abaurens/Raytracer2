/*
** utils.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Mon May  8 11:03:12 2017 Julien Delane
** Last update Sat May 20 22:07:31 2017 Julien Delane
*/

#include "libgraph.h"
#include "rt.h"

void	add_int(int *a, int *b)
{
  a[0] += b[0];
  a[1] += b[1];
  a[2] += b[2];
}

void	remove_int(int *a, int b)
{
  a[0] /= b;
  a[1] /= b;
  a[2] /= b;
}

void	add(int *i, sfColor color, double coef)
{
  if (coef != 0)
    {
      if (coef != 1)
	{
	  i[0] += color.r * coef;
	  i[1] += color.g * coef;
	  i[2] += color.b * coef;
	}
      else
	{
	  i[0] += color.r;
	  i[1] += color.g;
	  i[2] += color.b;
	}
    }
}

void	init_int(int *color, int size)
{
  int		i;

  i = -1;
  while (++i != size)
    color[i] = 0;
}
