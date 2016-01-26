#include "fdf.h"

void		ft_draw(t_scene *scn)
{
	int			x;
	int			y;

	y = 0;
	while (y < scn->map.y_max)
	{
		x = 0;
		while (x < scn->map.line[y].x_max - 1)
		{
			ft_draw_line(scn->obj, scn->cpy[y][x], scn->cpy[y][x + 1]);
			x++;
		}
		y++;
	}
	x = 0;
	while (x < scn->map.line[0].x_max)
	{
		y = 0;
		while (y < scn->map.y_max - 1)
		{
			ft_draw_line(scn->obj, scn->cpy[y][x], scn->cpy[y + 1][x]);
			y++;
		}
		x++;
	}
}

void		ft_apply_all_vector(t_matrix m, t_scene *scn)
{
	int			x;
	int			y;

	y = 0;
	while (y < scn->map.y_max)
	{
		x = 0;
		while (x < scn->map.line[y].x_max - 1)
		{
			scn->cpy[y][x] = ft_apply_matrix(m.n,
				scn->map.line[y].px[x], scn->center);
			scn->cpy[y][x + 1] = ft_apply_matrix(m.n,
				scn->map.line[y].px[x + 1], scn->center);
			x++;
		}
		y++;
	}
	ft_draw(scn);
}

t_vector	ft_apply_matrix(double m[4][4], t_vector v, t_vector center)
{
	t_vector	tmp;

	v.x -= center.x;
	v.y -= center.y;
	tmp.x = m[0][0] * v.x + m[0][1] * v.y + m[0][2] * v.z + m[0][3] * v.w;
	tmp.y = m[1][0] * v.x + m[1][1] * v.y + m[1][2] * v.z + m[1][3] * v.w;
	tmp.z = m[2][0] * v.x + m[2][1] * v.y + m[2][2] * v.z + m[2][3] * v.w;
	tmp.w = m[3][0] * v.x + m[3][1] * v.y + m[3][2] * v.z + m[3][3] * v.w;
	tmp.x += center.x;
	tmp.y += center.y;
	tmp.color = v.color;
	return (tmp);
}
