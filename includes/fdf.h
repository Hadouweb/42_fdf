/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 06:43:51 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/11 06:44:14 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include <math.h>

# define SIZE_W 1000
# define SIZE_H 1000
# define BUFF_SIZE 1

# define KEY_ESC 53

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_LEFT 123

# define KEY_ROTZ_LEFT 12
# define KEY_ROTZ_RIGHT 14
# define KEY_ROTX_TOP 13
# define KEY_ROTX_BOT 1
# define KEY_ROTY_LEFT 0
# define KEY_ROTY_RIGHT 2

# define KEY_ISO 34
# define KEY_PAR 35

# define SCALE_UP 45
# define SCALE_DOWN 11

# define ELEV_UP 4
# define ELEV_DOWN 5

typedef struct		s_save
{
	int				fd_num;
	char			*rest;
	struct s_save	*next;
}					t_save;

typedef struct		s_line
{
	struct s_line	*next;
	char			*str;
	int				size;
}					t_line;

typedef struct  	s_matrix
{
	double			n[4][4];
}					t_matrix;

typedef	struct 		s_vector
{
	double			x;
	double			y;
	double			z;
	double			w;
}					t_vector;

typedef struct 		s_width
{
	t_vector 		*px;
	int 			x_max;
}					t_width;

typedef struct 		s_map
{
	t_width 		*line;
	int 			y_max;
}					t_map;

typedef struct  	s_scene
{
	void			*mlx;
	void			*win;
	t_map 			map;
	int 			h;
	t_vector 		scale;
	t_vector		rot;
	t_vector		trans;
	t_vector		v;
	t_vector		center;
	int 			projection;
	char 			*name;
	char 			*data;
	void 			*img;
	int 			bpp;
	int 			sizeline;
	int 			endian;
}					t_scene;

void				ft_init(t_map map, char *name);

t_map				ft_read_file(char *name);
int					get_next_line(int const fd, char **line);
t_width				ft_split_to_int(char *s, char c, int l);

t_vector			ft_get_vector(double x, double y, double z, double w);
t_vector    		ft_get_center(t_scene scn);

void				ft_print_map(t_map map);
void				ft_print_matrix(double m[4][4]);
void				ft_print_vector(t_vector v);
void				ft_clear_list(t_line *lst);

void 				ft_draw_line(t_scene *scn, t_vector a, t_vector b);

t_matrix			ft_scale_matrix(t_vector v);
t_matrix			ft_translation_matrix(t_vector v);
t_matrix			ft_rotation_matrix_x(t_vector v);
t_matrix			ft_rotation_matrix_y(t_vector v);
t_matrix			ft_rotation_matrix_z(t_vector v);

t_matrix			ft_init_matrix(void);
t_matrix			ft_identity_matrix(void);

void				ft_apply_all_vector(t_matrix m, t_scene *scn);
t_vector			ft_apply_matrix(double m[4][4], t_vector v, t_vector center);
t_vector			ft_vector_multi(t_vector a, t_vector b);
t_vector			ft_vector_multi_elev(t_vector a, t_vector b);
t_vector			ft_vector_sum(t_vector a, t_vector b);

void				ft_apply_all_matrix(t_scene *scn);
t_matrix			ft_muli_matrix(t_matrix a, t_matrix b);

int					ft_hook_translate(int keycode, t_scene *scn);
int					ft_hook_rotate(int keycode, t_scene *scn);
int 				ft_hook_scale(int keycode, t_scene *scn);
int 				ft_hook_elev(int keycode, t_scene *scn);
int					ft_hook(int keycode, t_scene *scn);

void 				ft_translation(t_scene *scn);
void				ft_rotation(t_scene *scn);
void				ft_scale(t_scene *scn);
void				ft_scale_elev(t_scene *scn);

# endif
