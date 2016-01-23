#include "fdf.h"

void	ft_apply_all_matrix(t_scene scn)
{
	t_matrix	a;
	t_matrix	b;
	t_matrix	m;

	m = ft_init_matrix();

	a = ft_identity_matrix();
	a = ft_scale_matrix(scn.scale);

	b = ft_identity_matrix();
	b = ft_rotation_matrix_z(scn.rot);

	m = ft_muli_matrix(a, b);
	ft_apply_all_vector(m, scn);
}

void 	ft_translation(t_scene *scn)
{
	scn->trans = ft_vector_sum(scn->trans, scn->v);
	ft_apply_all_matrix(*scn);
}

void	ft_rotation(t_scene *scn)
{
	scn->rot = ft_vector_sum(scn->rot, scn->v);
	ft_apply_all_matrix(*scn);
}

void	ft_scale(t_scene *scn)
{
	scn->scale = ft_vector_sum(scn->scale, scn->v);
	ft_apply_all_matrix(*scn);
}
