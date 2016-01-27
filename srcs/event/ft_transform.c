/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transform.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 02:07:42 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/27 02:07:43 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_translation(t_scene *scn)
{
	scn->trans = ft_vector_sum(scn->trans, scn->v);
	ft_apply_all_matrix(scn);
}

void	ft_rotation(t_scene *scn)
{
	scn->rot = ft_vector_sum(scn->rot, scn->v);
	ft_apply_all_matrix(scn);
}

void	ft_scale(t_scene *scn)
{
	scn->scale = ft_vector_multi(scn->scale, scn->v);
	ft_apply_all_matrix(scn);
}

void	ft_scale_elev(t_scene *scn)
{
	scn->scale = ft_vector_sum_elev(scn->scale, scn->v);
	ft_apply_all_matrix(scn);
}
