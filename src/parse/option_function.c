/*
** option_function.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/parse/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Fri May 12 15:18:48 2017 Julien Delane
** Last update Sat May 13 15:54:35 2017 Julien Delane
*/

#include "bs.h"
#include "rt.h"

void	parse_ssaa(t_scene *scene, char *str)
{
  scene->option->ssaa = my_getnbr(str);
}

void	parse_reflect(t_scene *scene, char *str)
{
  scene->option->reflect = my_getnbr(str);
}

void	parse_shadow(t_scene *scene, char *str)
{
  scene->option->shadow = my_getnbr(str);
}
