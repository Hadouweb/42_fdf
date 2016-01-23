#include "fdf.h"

t_matrix	ft_init_matrix(void)
{
	int 		i;
	int 		j;
	t_matrix	m;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m.n[i][j] = 0.0;
			j++;
		}
		i++;
	}
	return (m);
}

t_matrix	ft_identity_matrix(void)
{
	t_matrix	m;

	m = ft_init_matrix();
	m.n[0][0] = 1.0;
	m.n[1][1] = 1.0;
	m.n[2][2] = 1.0;
	m.n[3][3] = 1.0;
	return (m);
}