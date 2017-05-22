/*
** parse.c for raytracer2 in /home/benjamin/Dropbox/raytracer2
**
** Made by
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon Apr 17 11:14:00 2017
** Last update Mon Apr 17 11:25:31 2017 Benjamin
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "parse.h"
#include "bs.h"
#include "gnl.h"

static void	set_parse_struct(t_parse *parse)
{
  parse->opt = 0;
}

static char	**get_gnl(int fd)
{
  char		**tab;
  char		*gnl;
  char		*str;

  tab = NULL;
  while ((gnl = get_next_line(fd)) != NULL && gnl[0] == '\n');
  if (gnl)
    {
      str = my_epur_str(gnl);
      free(gnl);
      tab = my_str_to_wordtab(str, " :;");
      free(str);
    }
  return (gnl ? tab : NULL);
}

int	parse_file(int ac, char **av, t_parse *parse, t_scene *scene)
{
  int	i;
  int	fd;
  char	**tab;

  i = 0;
  my_memset(scene, 0, sizeof(t_scene));
  set_parse_struct(parse);
  while (++i < ac)
    {
      if (av[i][0] != '-')
	{
	  if ((fd = open(av[i], O_RDONLY)) == -1)
	    return (84);
	  while ((tab = get_gnl(fd)))
	    {
	      parse_what_to_do(tab, parse, scene);
	      my_free_tab(tab);
	    }
	  if (close(fd))
	    return (84);
	}
    }
  print_scene(scene);
  apply_rot_translate(scene);
  return (0);
}
