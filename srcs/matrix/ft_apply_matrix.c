#include "fdf.h"

void		ft_apply_all_matrix(t_scene *scn)
{
	t_matrix	a;
	t_matrix	b;
	t_matrix	m;

	m = ft_init_matrix();
	a = ft_scale_matrix(scn->scale);
	if (scn->projection == 1)
		scn->rot = ft_get_vector(-1.1, 0.0, 0.80, 1.0);
	b = ft_rotation_matrix_z(scn->rot);
	m = ft_muli_matrix(b, a);
	b = ft_rotation_matrix_y(scn->rot);
	m = ft_muli_matrix(b, m);
	b = ft_rotation_matrix_x(scn->rot);
	m = ft_muli_matrix(b, m);
	b = ft_translation_matrix(scn->trans);
	m = ft_muli_matrix(b, m);
	ft_apply_all_vector(m, scn);
}

t_matrix	ft_muli_matrix(t_matrix a, t_matrix b)
{
	int			i;
	int			j;
	int			p;
	t_matrix	m;

	i = 0;
	j = 0;
	p = 0;
	m = ft_init_matrix();
	while (j < 4)
	{
		while (i < 4)
		{
			while (p < 4)
			{
				m.n[j][i] += a.n[j][p] * b.n[p][i];
				p++;
			}
			p = 0;
			i++;
		}
		i = 0;
		j++;
	}
	return (m);
}
