# include "fdf.h"

void		ft_apply_all_vector(t_matrix m, t_scene *scn)
{
	int 		x;
	int 		y;
	t_vector	tmp;
	t_vector	tmp2;

	y = 0;
	while (y < scn->map.y_max)
	{
		x = 0;
		while (x < scn->map.line[y].x_max - 1)
		{
			tmp = ft_apply_matrix(m.n, scn->map.line[y].px[x], scn->center);
			tmp2 = ft_apply_matrix(m.n, scn->map.line[y].px[x + 1], scn->center);
			ft_draw_line(scn, tmp, tmp2);
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
			tmp = ft_apply_matrix(m.n, scn->map.line[y].px[x], scn->center);
			tmp2 = ft_apply_matrix(m.n, scn->map.line[y + 1].px[x], scn->center);
			ft_draw_line(scn, tmp, tmp2);
			y++;
		}
		x++;
	}
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

t_vector	ft_vector_multi(t_vector a, t_vector b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return (a);
}

t_vector	ft_vector_sum_elev(t_vector a, t_vector b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return (a);
}

t_vector	ft_vector_sum(t_vector a, t_vector b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;

	return (a);
}