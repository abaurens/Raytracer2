/*
** parse.h for rt2 in /home/benjamin/Dropbox/raytracer2/include/
**
** Made by Benjamin
** Login   <benjamin.solca@epitech.eu>
**
** Started on  Mon Apr 17 11:22:42 2017 Benjamin
** Last update Sat May 20 18:15:09 2017 Julien Delane
*/

#ifndef PARSE_H_
# define PARSE_H_

# include "libgraph.h"

typedef struct		s_parse
{
  int			opt;
}			t_parse;

typedef struct
{
  double		x;
  double		y;
  double		z;
}			t_vec3f;

typedef struct		s_mat t_mat;
typedef struct		s_obj t_obj;
typedef struct		s_light t_light;

typedef struct		s_quadra
{
  double		a;
  double		b;
  double		c;
  double		d;
  double		e;
  double		f;
  double		g;
  double		h;
  double		i;
  double		j;
}			t_quadra;

typedef struct		s_parse_mat
{
  int			name;
  int			color;
  int			transparency;
  int			reflect;
  int			refract;
  int			shine;
}			t_parse_mat;

struct			s_mat
{
  char			*name;
  sfColor		color;
  float			transparency;
  float			reflect;
  float			refract;
  unsigned int		shine;
  t_parse_mat		parse;
  t_mat			*next;
  t_mat			*prev;
};

typedef struct		s_parse_obj
{
  int			name;
  int			mat_name;
  int			mat;
  int			quad;
  int			color;
  int			pos;
  int			rot;
}			t_parse_obj;

struct 			s_obj
{
  char			*name;
  char			*mat_name;
  struct s_mat		*mat;
  t_quadra		quadra;
  sfColor		color;
  t_vec3f		pos;
  t_vec3f		rot;
  t_parse_obj		parse;
  t_obj			*next;
  t_obj			*prev;
};

typedef struct		s_parse_light
{
  int			name;
  int			pos;
  int			intensity;
  int			color;
}			t_parse_light;

struct			s_light
{

  char			*name;
  t_vec3f		pos;
  unsigned int		intensity;
  sfColor		color;
  t_parse_light		parse;
  t_light		*next;
  t_light		*prev;
};

typedef struct		s_option
{
  int			shadow;
  int			ssaa;
  int			reflect;
}			t_option;

typedef struct		s_scene
{
  t_light		*light;
  t_obj			*obj;
  t_mat			*mat;
  int			nb_obj;
  int			nb_light;
  t_option		*option;
}			t_scene;

/*
** FUNCTIONS
*/
void	apply_rot_translate(t_scene *scene);

void	print_scene(t_scene *tmp);

int	create_light(char *name, t_light **light);
int	create_mat(char *name, t_mat **mat);
int	create_obj(char *name, t_obj **obj);
int	parse_file(int ac, char **av, t_parse *parse, t_scene *scene);
int	parse_what_to_do(char **tab, t_parse *parse, t_scene *scene);

int	set_light(char **tab, char *name, t_light *light);
int	set_light_color(t_light *light, char **tab);
int	set_light_intensity(t_light *light, char **tab);
int	set_light_pos(t_light *light, char **tab);

int	set_mat(char **tab, char *name, t_mat *mat);
int	set_mat_color(t_mat *mat, char **tab);
int	set_mat_transparency(t_mat *mat, char **tab);
int	set_mat_reflect(t_mat *mat, char **tab);
int	set_mat_refract(t_mat *mat, char **tab);
int	set_mat_shine(t_mat *mat, char **tab);

int	set_obj(char **tab, char *name, t_obj *obj);
int	set_obj_color(t_obj *obj, char **tab);
int	set_obj_mat(t_obj *obj, char **tab);
int	set_obj_pos(t_obj *obj, char **tab);
int	set_obj_quad(t_obj *obj, char **tab);
int	set_obj_rot(t_obj *obj, char **tab);

#endif /* !PARSE_H_ */
