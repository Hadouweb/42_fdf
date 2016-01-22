#include "fdf.h"


t_vector	ft_vector_sum(t_vector a, t_vector b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;

	return (a);
}

void	muli_mat4x4(double a[4][4], double b[4][4])
{
	int i;
	int j;
	int p;

	i = 0;
	j = 0;
	p = 0;
	while (j < 4)
	{
		while (i < 4)
		{
			while (p < 4)
			{
				a[j][p] *= b[p][i];
				p++;
			}
			p = 0;
			i++;
		}
		i = 0;
		j++;
	}
}

void	ft_apply_all_matrix(t_scene scn)
{
	double	matrix[4][4];
	double	matrix2[4][4];

	ft_identity_matrix(matrix);
	ft_scale_matrix(matrix, scn.scale);
	ft_print_matrix(matrix);

	ft_identity_matrix(matrix2);
	ft_rotation_matrix_z(scn.rot.z, matrix2);
	ft_print_matrix(matrix2);

	muli_mat4x4(matrix, matrix2);
	ft_print_matrix(matrix);

	ft_apply_all_vector(matrix, scn);

	/*ft_identity_matrix(matrix);
	ft_rotation_matrix_x(scn.rot.x, matrix);
	ft_apply_all_vector(matrix, scn);

	ft_identity_matrix(matrix);
	ft_rotation_matrix_y(scn.rot.y, matrix);
	ft_apply_all_vector(matrix, scn);

	ft_identity_matrix(matrix);
	ft_translation_matrix(matrix, scn.trans);
	ft_apply_all_vector(matrix, scn);*/
}

void 	ft_translation(t_scene scn, t_vector v)
{
	scn.trans = ft_vector_sum(scn.trans, v);
	ft_apply_all_matrix(scn);
}

void	ft_rotation(t_scene scn, t_vector rot)
{
	scn.rot = ft_vector_sum(scn.rot, rot);
	ft_apply_all_matrix(scn);
}

void	ft_scale(t_scene scn, t_vector v)
{
	scn.scale = ft_vector_sum(scn.scale, v);
	ft_apply_all_matrix(scn);
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