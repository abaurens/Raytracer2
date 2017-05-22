/*
** color.c for rt in /home/baurens/Work/Tek1/Projects/IGRAPH/raytracer2/
**
** Made by Arthur Baurens
** Login   <arthur.baurens@epitech.eu>
**
** Started on  Thu Mar 30 17:38:38 2017 Arthur Baurens
** Last update Sat May 20 18:38:38 2017 Julien Delane
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include "rt.h"

sfColor		color_rgb(char r, char g, char b)
{
  sfColor	ret;

  ret.a = 255;
  ret.r = r;
  ret.g = g;
  ret.b = b;
  return (ret);
}

sfColor		color_rgba(char r, char g, char b, char a)
{
  sfColor	ret;

  ret.r = r;
  ret.g = g;
  ret.b = b;
  ret.a = a;
  return (ret);
}

sfColor		random_color()
{
  sfColor	ret;

  ret.a = 255;
  ret.r = my_rand() % 256;
  ret.g = my_rand() % 256;
  ret.b = my_rand() % 256;
  return (ret);
}
