/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 02:07:15 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/27 02:07:17 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_color		ft_cal_color(t_color a, t_color b, double pos)
{
	t_color		color;

	color.r = b.r + ((a.r - b.r) * pos);
	color.g = b.g + ((a.g - b.g) * pos);
	color.b = b.b + ((a.b - b.b) * pos);
	return (color);
}

t_color		ft_get_color(unsigned char r, unsigned char g,
	unsigned char b, unsigned char a)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;
	return (color);
}

void		ft_apply_color(t_scene *scn, t_colorset cs, int y, int x)
{
	int		d;
	double	z;

	d = abs(scn->map.max - scn->map.min);
	z = scn->map.line[y].px[x].z;
	if (z / d > 0.1)
		scn->map.line[y].px[x].color = ft_get_color(
			cs.top.r + fabs(z * 300) / d,
			cs.top.g + fabs(z * 450) / d,
			cs.top.b + fabs(z * 500) / d, cs.top.a);
	else if (z / d < 0)
		scn->map.line[y].px[x].color = ft_get_color(cs.bot.r, cs.bot.g,
			cs.bot.b - fabs(z * 300) / d, cs.bot.a);
	else
		scn->map.line[y].px[x].color = ft_get_color(cs.mid.r,
			cs.mid.g - fabs(z * 1500) / d, cs.mid.b, cs.mid.a);
}

void		ft_init_color(t_scene *scn, t_colorset cs)
{
	int		y;
	int		x;

	y = 0;
	while (y < scn->map.y_max)
	{
		x = 0;
		while (x < scn->map.line[y].x_max)
		{
			ft_apply_color(scn, cs, y, x);
			x++;
		}
		y++;
	}
}
