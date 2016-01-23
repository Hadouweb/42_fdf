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
	scn->scale = ft_get_vector(20.0, 20.0, 2.0, 1.0);
	scn->rot = ft_get_vector(0.0, 0.0, 0.0, 1.0);
	scn->trans = ft_get_vector(1.0, 1.0, 1.0, 1.0);
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
	ft_init_vector(&scn);

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
