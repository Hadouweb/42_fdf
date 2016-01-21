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

void	ft_init(t_map map, char *name, int projection)
{
	t_scene	scn;

	scn.mlx = mlx_init();
	scn.win = mlx_new_window(scn.mlx, SIZE_W, SIZE_H, "FDF");
	scn.map = map;
	scn.h = 14;
	scn.incx = 34;
	scn.incy = 20;
	scn.scale = 20;
	scn.v = ft_get_vector(0.0, 0.0, 0.0, 1.0);
	scn.center = ft_get_center(scn);
	scn.origin.x = scn.center.x + SIZE_W / 2;
	scn.origin.y = scn.center.y;
	scn.origin.z = 0;
	scn.origin.w = 1;
	scn.projection = projection;
	scn.name = ft_strdup(name);

	if (scn.projection == 1)
		ft_reload(scn);
	else
	{
		ft_scale(scn, scn.scale);
		ft_reload_matrix(&scn);
	}
	mlx_hook(scn.win, 2, 3, ft_hook, &scn);

	mlx_loop(scn.mlx);
}

int		main(int ac, char **av)
{
	t_map	map;

	if (ac > 1)
		map = ft_read_file(av[1]);
	ft_init(map, av[1], 1);
	return (0);
}
