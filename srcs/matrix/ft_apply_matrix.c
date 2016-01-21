#include "fdf.h"

t_vector	ft_apply_matrix(double m[4][4], t_vector *v, t_vector center)
{
	t_vector	tmp;

	v->x -= center.x;
	v->y -= center.y;
	tmp.x = m[0][0] * v->x + m[0][1] * v->y + m[0][2] * v->z + m[0][3] * v->w;
	tmp.y = m[1][0] * v->x + m[1][1] * v->y + m[1][2] * v->z + m[1][3] * v->w;
	tmp.z = m[2][0] * v->x + m[2][1] * v->y + m[2][2] * v->z + m[2][3] * v->w;
	tmp.w = m[3][0] * v->x + m[3][1] * v->y + m[3][2] * v->z + m[3][3] * v->w;
	tmp.x += center.x;
	tmp.y += center.y;
	return (tmp);
}

void		ft_apply_all_vector(double matrix[4][4], t_scene scn)
{
	int 	x;
	int 	y;

	y = 0;
	while (y < scn.map.y_max)
	{
		x = 0;
		while (x < scn.map.line[y].x_max)
		{
			scn.map.line[y].px[x] = ft_apply_matrix(matrix, &scn.map.line[y].px[x], scn.center);
			x++;
		}
		y++;
	}
}
