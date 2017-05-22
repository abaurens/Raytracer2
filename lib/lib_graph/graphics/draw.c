/*
** draw.c for graph in /home/baurens/Work/Tek1/Projects/IGRAPH/wireframe/graphics/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Tue Nov 22 15:07:27 2016 Arthur Baurens
** Last update Mon Feb 13 16:27:23 2017 John Doe
*/

#include <math.h>
#include "libgraph.h"

void		my_put_pixel(t_my_framebuffer *prog, int x, int y, sfColor c)
{
  sfUint8	*pixels;

  pixels = prog->pixels;
  if (x < 0 || y < 0 || x > prog->width || y > prog->height)
    return;
  pixels[4 * (x + y * prog->width) + 0] = c.r;
  pixels[4 * (x + y * prog->width) + 1] = c.g;
  pixels[4 * (x + y * prog->width) + 2] = c.b;
  pixels[4 * (x + y * prog->width) + 3] = c.a;
}

void		place_pixel(t_prog *prog, int x, int y, sfColor color)
{
  sfUint8	*pixels;

  pixels = prog->pix;
  if (x < 0 || y < 0 || x >= prog->w || y >= prog->h)
    return;
  pixels[4 * (x + y * prog->w) + 0] = color.r;
  pixels[4 * (x + y * prog->w) + 1] = color.g;
  pixels[4 * (x + y * prog->w) + 2] = color.b;
  pixels[4 * (x + y * prog->w) + 3] = color.a;
}

void		my_draw_line(t_my_framebuffer *prog, sfVector2i from,
			     sfVector2i to, sfColor c)
{
  double	i;
  double	norme;
  double	len[2];

  i = 0;
  len[0] = from.x - to.x;
  len[1] = from.y - to.y;
  norme = sqrt(len[0] * len[0] + len[1] * len[1]);
  norme = norme == 0 ? 1 : norme;
  while (i <= 1)
    {
      my_put_pixel(prog, (int)(from.x + len[0] * i),
		   (int)(from.y + len[1] * i), c);
      i += (1.0 / norme);
    }
}
