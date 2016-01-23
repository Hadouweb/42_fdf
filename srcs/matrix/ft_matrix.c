#include "fdf.h"

t_matrix	ft_scale_matrix(t_vector v)
{
	t_matrix 	m;

	m.n[0][0] = v.x;
	m.n[1][1] = v.y;
	m.n[2][2] = v.z;
	m.n[3][3] = 1.0;
	return (m);
}

t_matrix	ft_translation_matrix(t_vector v)
{
	t_matrix 	m;

	m.n[0][3] = v.x;
	m.n[1][3] = v.y;
	m.n[2][3] = v.z;
	m.n[3][3] = v.w;
	return (m);
}

t_matrix	ft_rotation_matrix_x(t_vector v)
{
	t_matrix 	m;

	m.n[1][1] = cos(v.x);
	m.n[1][2] = sin(v.x);
	m.n[2][1] = -sin(v.x);
	m.n[2][2] = cos(v.x);
	return (m);
}

t_matrix	ft_rotation_matrix_y(t_vector v)
{
	t_matrix 	m;

	m.n[0][0] = cos(v.y);
	m.n[0][2] = sin(v.y);
	m.n[2][0] = -sin(v.y);
	m.n[2][2] = cos(v.y);
	return (m);
}

t_matrix	ft_rotation_matrix_z(t_vector v)
{
	t_matrix 	m;

	m.n[0][0] = cos(v.z);
	m.n[0][1] = -sin(v.z);
	m.n[1][0] = sin(v.z);
	m.n[1][1] = cos(v.z);
	return (m);
}