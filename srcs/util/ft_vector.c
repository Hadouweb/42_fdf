/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 06:22:03 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/26 06:22:06 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector	ft_get_vector(double x, double y, double z, double w)
{
	t_vector	v;

	v.x = x;
	v.y = y;
	v.z = z;
	v.w = w;
	return (v);
}

t_vector	ft_get_center(t_scene scn)
{
	t_vector	center;
	int			x_max;
	int			y_max;

	x_max = scn.map.line[0].x_max;
	y_max = scn.map.y_max;
	center.x = (scn.map.line[y_max - 1].px[x_max - 1].x +
				scn.map.line[0].px[0].x) / 2;
	center.y = (scn.map.line[y_max - 1].px[x_max - 1].y +
				scn.map.line[0].px[0].y) / 2;
	center.z = 0.0;
	center.w = 0.0;
	return (center);
}

t_vector	ft_vector_multi(t_vector a, t_vector b)
{
	a.x *= b.x;
	a.y *= b.y;
	a.z *= b.z;
	a.w *= b.w;
	return (a);
}

t_vector	ft_vector_sum_elev(t_vector a, t_vector b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;
	return (a);
}

t_vector	ft_vector_sum(t_vector a, t_vector b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	a.w += b.w;

	return (a);
}
