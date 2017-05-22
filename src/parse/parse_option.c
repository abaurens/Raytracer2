/*
** parse_option.c for rt2 in /home/Realague/Delivery/B_MUL/raytracer2/src/
**
** Made by Julien Delane
** Login   <Realague@epitech.net>
**
** Started on  Thu May  4 18:16:45 2017 Julien Delane
** Last update Sat May 20 18:32:23 2017 Julien Delane
*/

#include <unistd.h>
#include <stdlib.h>
#include "bs.h"
#include "rt.h"

static const t_option_func	g_func[] =
{
  {"-ssaa=", 6, parse_ssaa},
  {"-reflect=", 9, parse_reflect},
  {"-shadow=", 8, parse_shadow},
  {NULL, -1, NULL}
};

static int	is_nbr(char *str)
{
  int		i;

  i = -1;
  while (str[++i])
    {
      if (str[i] > '9' || str[i] < '0')
	return (-1);
    }
  return (0);
}

static void	fill_option(t_option *option)
{
  option->reflect = 1;
  option->ssaa = 1;
  option->shadow = 1;
}

int		parse_option(t_scene *scene, char **av, int i)
{
  int		o;

  if ((scene->option = malloc(sizeof(t_option))) == NULL)
    return (84);
  fill_option(scene->option);
  while (av[++i])
    {
      if (av[i][0] && av[i][0] == '-')
	{
	  o = -1;
	  while (g_func[++o].str
		 && my_strncmp(av[i], g_func[o].str, g_func[o].size));
	  if (o == 3 || is_nbr(&av[i][g_func[o].size]))
	    {
	      write(2, "Error: Wrong argument\n.", 22);
	      return (84);
	    }
	  else
	    g_func[o].func(scene, &av[i][g_func[o].size]);
	}
    }
  if (scene->option->shadow < 1)
    scene->option->shadow = 1;
  return (0);
}
