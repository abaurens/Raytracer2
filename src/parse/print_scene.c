/*
** print_scene.c for rt2 in /home/benjamin/Dropbox/raytracer2/parse/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Thu May 18 13:42:55 2017 Benjamin
** Last update Thu May 18 17:29:06 2017 Julien Delane
*/

#include <stdio.h>
#include "parse.h"

void		print_scene(t_scene *tmp)
{
  t_scene	scene;

  scene = *tmp;
  while (scene.mat)
    {
      printf("Nom du mat: %s\n", scene.mat->name);
      printf("Color: %d %d %d %d\n", scene.mat->color.r, scene.mat->color.g, scene.mat->color.b, scene.mat->color.a);
      printf("Transparency: %f\n", scene.mat->transparency);
      printf("Reflect: %f\n", scene.mat->reflect);
      printf("Refract: %f\n", scene.mat->refract);
      printf("Shine: %d\n\n", scene.mat->shine);
      scene.mat = scene.mat->next;
    }
  while (scene.light)
    {
      printf("Nom du light: %s\n", scene.light->name);
      printf("Pos: %f %f %f\n", scene.light->pos.x, scene.light->pos.y, scene.light->pos.z);
      printf("Intensity: %d\n", scene.light->intensity);
      printf("Color: %d %d %d %d\n\n", scene.light->color.r, scene.light->color.g, scene.light->color.b, scene.light->color.a);
      scene.light = scene.light->next;
    }
  while (scene.obj)
    {
      printf("Nom du obj: %s\n", scene.obj->name);
      printf("Mat Name: %s\n", scene.obj->mat_name);
      printf("quadra: %e %e %e %e %e %e %e %e %e %e\n", scene.obj->quadra.a, scene.obj->quadra.b, scene.obj->quadra.c, scene.obj->quadra.d, scene.obj->quadra.e, scene.obj->quadra.f, scene.obj->quadra.g, scene.obj->quadra.h, scene.obj->quadra.i, scene.obj->quadra.j);
      printf("Color: %d %d %d %d\n", scene.obj->color.r, scene.obj->color.g, scene.obj->color.b, scene.obj->color.a);
      printf("Pos: %f %f %f\n", scene.obj->pos.x, scene.obj->pos.y, scene.obj->pos.z);
      printf("Rot: %f %f %f \n\n", scene.obj->rot.x, scene.obj->rot.y, scene.obj->rot.z);
      scene.obj = scene.obj->next;
    }
}
