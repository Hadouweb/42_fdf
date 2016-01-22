#include "fdf.h"

void	ft_scale_matrix(double matrix[4][4], t_vector v)
{
	ft_print_vector(v);
	matrix[0][0] = v.x;
	matrix[1][1] = v.y;
	matrix[2][2] = v.z;
	matrix[3][3] = 1.0;
}

void	ft_translation_matrix(t_vector v, double matrix[4][4])
{
	matrix[0][3] = v.x;
	matrix[1][3] = v.y;
	matrix[2][3] = v.z;
	matrix[3][3] = v.w;
}

void	ft_rotation_matrix_x(double rot, double m[4][4])
{
	m[1][1] = cos(rot);
	m[1][2] = sin(rot);
	m[2][1] = -sin(rot);
	m[2][2] = cos(rot);
}

void	ft_rotation_matrix_y(double rot, double m[4][4])
{
	m[0][0] = cos(rot);
	m[0][2] = sin(rot);
	m[2][0] = -sin(rot);
	m[2][2] = cos(rot);
}

void	ft_rotation_matrix_z(double rot, double m[4][4])
{
	m[0][0] = cos(rot);
	m[0][1] = -sin(rot);
	m[1][0] = sin(rot);
	m[1][1] = cos(rot);
}