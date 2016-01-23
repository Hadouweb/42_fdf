#include "fdf.h"

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
	scn->scale = ft_vector_multi(scn->scale, scn->v);
	ft_apply_all_matrix(*scn);
}

void	ft_scale_elev(t_scene *scn)
{
	scn->scale = ft_vector_multi_elev(scn->scale, scn->v);
	ft_apply_all_matrix(*scn);
}