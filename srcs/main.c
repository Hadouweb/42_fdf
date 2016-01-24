/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 06:43:44 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/11 06:43:45 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_init_vector(t_scene *scn)
{
	scn->scale = ft_get_vector(20.0, 20.0, 10.0, 1.0);
	scn->rot = ft_get_vector(0.0, 0.0, 0.0, 1.0);
	scn->trans = ft_get_vector(1.0, 1.0, 1.0, 1.0);
}

unsigned int	colortohex(t_color color)
{
	return ((unsigned int)(color.r << 16 | color.g << 8 | color.b));
}

t_color			ft_cal_color(t_color a, t_color b, double pos)
{
	t_color		color;

	color.r = b.r + ((a.r - b.r) * pos);
	color.g = b.g + ((a.g - b.g) * pos);
	color.b = b.b + ((a.b - b.b) * pos);
	return (color);
}

t_color 		ft_get_color(unsigned char r, unsigned char g, unsigned char b)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = 0;

	return (color);
}

void			ft_init_color(t_scene *scn)
{
	int 	y;
	int 	x;

	y = 0;
	while (y < scn->map.y_max)
	{
		x = 0;
		while (x < scn->map.line[y].x_max)
		{
			if (scn->map.line[y].px[x].z > 8)
				scn->map.line[y].px[x].color = ft_get_color(255, 255, 255); // white
			else if (scn->map.line[y].px[x].z < 5)
				scn->map.line[y].px[x].color = ft_get_color(0, 0, 255); // blue
			else
				scn->map.line[y].px[x].color = ft_get_color(0, 255, 0); // green
			x++;
		}
		y++;
	}
}

void			ft_init(t_map map, char *name)
{
	t_scene	scn;

	scn.mlx = mlx_init();
	scn.win = mlx_new_window(scn.mlx, SIZE_W, SIZE_H, "FDF");
	scn.map = map;
	scn.h = 1;
	scn.v = ft_get_vector(1.0, 1.0, 1.0, 1.0);
	scn.center = ft_get_center(scn);
	scn.projection = 1;
	scn.name = ft_strdup(name);
	scn.img = mlx_new_image(scn.mlx, SIZE_W, SIZE_H);
	scn.data = mlx_get_data_addr(scn.img, &scn.bpp, &scn.sizeline, &scn.endian);
	ft_bzero(scn.data, SIZE_W * SIZE_H * 4);
	ft_init_vector(&scn);
	ft_init_color(&scn);

	ft_scale(&scn);
	mlx_hook(scn.win, 2, 3, ft_hook, &scn);

	mlx_loop(scn.mlx);
}

int				main(int ac, char **av)
{
	t_map	map;

	if (ac > 1)
		map = ft_read_file(av[1]);
	ft_init(map, av[1]);
	return (0);
}
