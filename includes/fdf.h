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

# define SCALE_UP 17
# define SCALE_DOWN 15

# define ELEV_UP 5
# define ELEV_DOWN 3

# define KEY_MENU 6

# define KEY_COLOR_1 18
# define KEY_COLOR_2 19
# define KEY_COLOR_3 20
# define KEY_COLOR_4 21

# define KEY_MAP_1 7
# define KEY_MAP_2 8
# define KEY_MAP_3 9
# define KEY_MAP_4 11
# define KEY_MAP_5 45
# define KEY_MAP_6 46
# define KEY_MAP_7 43

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

typedef	struct		s_inc
{
	int				e;
	int				inc1;
	int				inc2;
	int				dx;
	int				dy;
	int				incx;
	int				incy;
	double			x;
	double			y;
}					t_inc;

typedef struct		s_matrix
{
	double			n[4][4];
}					t_matrix;

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}					t_color;

typedef	struct		s_vector
{
	double			x;
	double			y;
	double			z;
	double			w;
	t_color			color;
}					t_vector;

typedef struct		s_width
{
	t_vector		*px;
	int				x_max;
}					t_width;

typedef struct		s_map
{
	t_width			*line;
	int				y_max;
	int				max;
	int				min;
}					t_map;

typedef struct		s_img
{
	void			*img;
	int				bpp;
	int				sizeline;
	int				endian;
	char			*data;
}					t_img;

typedef	struct		s_colorset
{
	t_color			top;
	t_color			mid;
	t_color			bot;
}					t_colorset;

typedef struct		s_scene
{
	void			*mlx;
	void			*win;
	t_map			map;
	t_vector		**cpy;
	t_vector		scale;
	t_vector		rot;
	t_vector		trans;
	t_vector		v;
	t_vector		center;
	int				projection;
	t_img			*obj;
	t_img			*menu;
	int				display_menu;
}					t_scene;

void				ft_init(t_map map);

t_vector			ft_get_vector(double x, double y, double z, double w);
t_vector			ft_get_center(t_scene scn);
t_vector			ft_vector_multi(t_vector a, t_vector b);
t_vector			ft_vector_sum_elev(t_vector a, t_vector b);
t_vector			ft_vector_sum(t_vector a, t_vector b);

void				ft_exit(void);
void				ft_clear_list(t_line *lst);
t_vector			**ft_cpy_map(t_map *map);

int					get_next_line(int const fd, char **line);

t_width				ft_split_to_int(char *s, char c, int l, t_map *map);

t_map				ft_read_file(char *name);

t_matrix			ft_scale_matrix(t_vector v);
t_matrix			ft_translation_matrix(t_vector v);
t_matrix			ft_rotation_matrix_x(t_vector v);
t_matrix			ft_rotation_matrix_y(t_vector v);
t_matrix			ft_rotation_matrix_z(t_vector v);

t_matrix			ft_init_matrix(void);
t_matrix			ft_identity_matrix(void);

void				ft_apply_all_vector(t_matrix m, t_scene *scn);
t_vector			ft_apply_matrix(double m[4][4], t_vector v,
						t_vector center);

void				ft_apply_all_matrix(t_scene *scn);
t_matrix			ft_muli_matrix(t_matrix a, t_matrix b);

void				ft_translation(t_scene *scn);
void				ft_rotation(t_scene *scn);
void				ft_scale(t_scene *scn);
void				ft_scale_elev(t_scene *scn);

int					ft_event_translate(int keycode, t_scene *scn);
int					ft_event_rotate(int keycode, t_scene *scn);
int					ft_event_scale(int keycode, t_scene *scn);
int					ft_event_elev(int keycode, t_scene *scn);
int					ft_event_repeat(int keycode, t_scene *scn);

int					ft_event_color_(int keycode, t_scene *scn);
int					ft_projection(int keycode, t_scene *scn);
int					ft_select_map(int keycode, t_scene *scn);
int					ft_event(int keycode, t_scene *scn);

void				ft_create_text(t_scene *scn);
void				ft_create_menu(t_scene *scn);

void				ft_draw(t_scene *scn);
void				ft_generate_image(t_img *obj, int x, int y, t_color color);
t_colorset			ft_get_colorset(t_color top, t_color mid, t_color bot);
void				ft_draw_all(t_scene *scn);

t_color				ft_cal_color(t_color a, t_color b, double pos);
t_color				ft_get_color(unsigned char r, unsigned char g,
						unsigned char b, unsigned char a);
void				ft_apply_color(t_scene *scn, t_colorset cs, int y, int x);
void				ft_init_color(t_scene *scn, t_colorset cs);

void				ft_draw_line(t_img *obj, t_vector a, t_vector b);

#endif
