/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 02:07:34 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/27 02:07:36 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_event_color(int keycode, t_scene *scn)
{
	t_colorset	colorset;
	int			key;

	key = 0;
	if (keycode == KEY_COLOR_1 && ++key)
		colorset = ft_get_colorset(ft_get_color(90, 30, 0, 0),
			ft_get_color(0, 150, 0, 0),
			ft_get_color(0, 0, 200, 0));
	else if (keycode == KEY_COLOR_2 && ++key)
		colorset = ft_get_colorset(ft_get_color(130, 30, 250, 0),
			ft_get_color(130, 180, 50, 0),
			ft_get_color(130, 30, 250, 0));
	else if (keycode == KEY_COLOR_3 && ++key)
		colorset = ft_get_colorset(ft_get_color(200, 200, 200, 0),
			ft_get_color(0, 0, 200, 0),
			ft_get_color(160, 80, 100, 0));
	else if (keycode == KEY_COLOR_4 && ++key)
		colorset = ft_get_colorset(ft_get_color(
			rand() % 255, rand() % 255, rand() % 255, 0),
			ft_get_color(rand() % 255, rand() % 255, rand() % 255, 0),
			ft_get_color(rand() % 255, rand() % 255, rand() % 255, 0));
	if (key)
		ft_init_color(scn, colorset);
	return (1);
}

int		ft_projection(int keycode, t_scene *scn)
{
	if (keycode == KEY_ISO)
	{
		scn->projection = 1;
		scn->rot = ft_get_vector(-1.1, 0.0, 0.80, 1.0);
		ft_apply_all_matrix(scn);
	}
	else if (keycode == KEY_PAR)
	{
		scn->projection = 2;
		scn->rot = ft_get_vector(-1.0, 0.0, 0.0, 1.0);
		ft_apply_all_matrix(scn);
	}
	return (1);
}

int		ft_select_map(int keycode, t_scene *scn)
{
	t_map	map;
	int		key;

	key = 0;
	if (keycode == KEY_MAP_1 && ++key)
		map = ft_read_file("select_map/42.fdf");
	if (keycode == KEY_MAP_2 && ++key)
		map = ft_read_file("select_map/elem.fdf");
	if (keycode == KEY_MAP_3 && ++key)
		map = ft_read_file("select_map/pyra.fdf");
	if (keycode == KEY_MAP_4 && ++key)
		map = ft_read_file("select_map/pyramide.fdf");
	if (keycode == KEY_MAP_5 && ++key)
		map = ft_read_file("select_map/nle-bret.fdf");
	if (keycode == KEY_MAP_6 && ++key)
		map = ft_read_file("select_map/Japan.L.fdf");
	if (keycode == KEY_MAP_7 && ++key)
		map = ft_read_file("select_map/France.XXL.fdf");
	if (key)
	{
		mlx_destroy_window(scn->mlx, scn->win);
		ft_init(map);
	}
	return (1);
}

int		ft_event(int keycode, t_scene *scn)
{
	if (keycode == KEY_ESC)
		exit(1);
	if (keycode == KEY_MENU && scn->display_menu == 0)
		scn->display_menu = 1;
	else if (keycode == KEY_MENU && scn->display_menu == 1)
		scn->display_menu = 0;
	ft_event_color(keycode, scn);
	ft_projection(keycode, scn);
	ft_select_map(keycode, scn);
	ft_draw_all(scn);
	return (1);
}
