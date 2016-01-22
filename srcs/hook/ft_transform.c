#include "fdf.h"


void 	ft_translation(t_scene scn, t_vector v)
{
	double	matrix[4][4];

	ft_identity_matrix(matrix);
	ft_translation_matrix(v, matrix);
	ft_apply_all_vector(matrix, scn);
}

void	ft_rotation(t_scene scn, double rot, char c)
{
	double		matrix[4][4];
	int 		i;

	i = 0;
	ft_identity_matrix(matrix);
	if (c == 'z')
		ft_rotation_matrix_z(rot, matrix);
	if (c == 'x')
		ft_rotation_matrix_x(rot, matrix);
	if (c == 'y')
		ft_rotation_matrix_y(rot, matrix);
	ft_apply_all_vector(matrix, scn);
}

void	ft_scale(t_scene scn, t_vector v)
{
	double	matrix[4][4];

	ft_identity_matrix(matrix);
	ft_scale_matrix(matrix, v);
	ft_apply_all_vector(matrix, scn);
}

void	ft_up_z(t_scene scn, int h)
{
	int			x;
	int			y;

	y = 0;
	while (y < scn.map.y_max)
	{
		x = 0;
		while (x < scn.map.line[y].x_max)
		{
			if (scn.map.line[y].px[x].z > 0)
				scn.map.line[y].px[x].z *= h;
			x++;
		}
		y++;
	}
}