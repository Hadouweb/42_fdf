#include "fdf.h"

static void	ft_init_matrix(double matrix[4][4])
{
	int 	i;
	int 	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix[i][j] = 0.0;
			j++;
		}
		i++;
	}
}

void	ft_identity_matrix(double matrix[4][4])
{
	ft_init_matrix(matrix);
	matrix[0][0] = 1.0;
	matrix[1][1] = 1.0;
	matrix[2][2] = 1.0;
	matrix[3][3] = 1.0;
}