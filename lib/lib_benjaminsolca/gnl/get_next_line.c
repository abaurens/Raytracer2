/*
** get_next_line.c for get_next_line in /home/prodjia/Dropbox/CPE_2016_getnextline
**
** Made by Benjamin
** Login   <prodjia@epitech.net>
**
** Started on  Mon Jan  2 10:33:24 2017 Benjamin
** Last update Thu Apr  6 09:20:07 2017 Benjamin
*/

#include <stdlib.h>
#include <unistd.h>
#include "gnl.h"

static int	len(char *str, int bool)
{
  int	i;

  i = -1;
  if (bool == 1)
    {
      while (str[++i] != '\0');
      return (i);
    }
  else
    while (str[++i] == '\0')
      if (str[i] == '\n')
	return (1);
  return (0);
}

static int	in_the_rope(char **str, char c)
{
  int		i;
  char		*tmp;

  i = -1;
  if (!(tmp = malloc(sizeof(char) * (len(*str, 1) + 1))))
    return (84);
  while ((*str)[++i] != '\0')
    tmp[i] = (*str)[i];
  tmp[i] = '\0';
  free(*str);
  if (!((*str) = malloc(sizeof(char) * (len(tmp, 1) + 2))))
    return (84);
  i = -1;
  while (tmp[++i] != '\0')
    (*str)[i] = tmp[i];
  (*str)[i] = c;
  (*str)[i + 1] = '\0';
  free(tmp);
  return (1);
}

static char	cut_the_rope(const int fd, int *end, int *r)
{
  static char   memo[READ_SIZE_GNL + 1] = "\0";
  static int    i = 0;
  char          c;

  if (memo[i] == '\0')
    {
      if ((*r) != READ_SIZE_GNL && len(memo, 0) != 1)
	(*end) = 1;
      if (((*r) = read(fd, memo, READ_SIZE_GNL)) == -1)
	return (0);
      if ((*r) != READ_SIZE_GNL)
	memo[*r] = '\0';
      memo[READ_SIZE_GNL] = '\0';
      if ((*r) == 0 && len(memo, 1) == 0)
	(*end) = 1;
      i = 0;
    }
  c = memo[i];
  i++;
  return (c);
}

char		*get_next_line(const int fd)
{
  static char	bn[2] = "\n\0";
  static int	r = READ_SIZE_GNL;
  static int    end = 0;
  char          c;
  char          *str;

  if (!(str = malloc(sizeof(char))))
    return (NULL);
  str[0] = '\0';
  c = cut_the_rope(fd, &end, &r);
  while (c != '\n' && c != '\0' && end != 1 && r != 0)
    {
      if (!(in_the_rope(&str, c)))
	return (NULL);
      c = cut_the_rope(fd, &end, &r);
    }
  return (end == 1 && r == 0 ? NULL : (c == '\n'
				       && str[0] == '\0') ? bn : str);
}
