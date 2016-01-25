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
	scn->scale = ft_get_vector(3.0, 3.0, 0.3, 1.0);
	scn->rot = ft_get_vector(0.0, 0.0, 0.0, 1.0);
	scn->trans = ft_get_vector(1.0, 1.0, 1.0, 1.0);
}

t_img			*ft_get_img_info(t_scene *scn, int width, int height)
{
	t_img	*obj;

	obj = (t_img *)ft_memalloc(sizeof(t_img));
	obj->img = mlx_new_image(scn->mlx, width, height);
	obj->data = mlx_get_data_addr(obj->img, &obj->bpp, &obj->sizeline, &obj->endian);
	ft_bzero(obj->data, width * height * 4);
	return (obj);
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
	scn.obj = ft_get_img_info(&scn, SIZE_W, SIZE_H);
	scn.menu = ft_get_img_info(&scn, SIZE_W - 10, 200);
	ft_init_vector(&scn);
	ft_init_color(&scn);
	scn.display_menu = 0;
	scn.already_display = 0;

	ft_scale(&scn);
	ft_draw_all(&scn);
	mlx_hook(scn.win, 2, 3, ft_hook, &scn);
	mlx_key_hook(scn.win, ft_menu, &scn);

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
