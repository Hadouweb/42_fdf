/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 02:07:20 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/27 02:07:22 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_draw(t_scene *scn)
{
	int			x;
	int			y;

	y = 0;
	while (y < scn->map.y_max)
	{
		x = 0;
		while (x < scn->map.line[y].x_max - 1)
		{
			ft_draw_line(scn->obj, scn->cpy[y][x], scn->cpy[y][x + 1]);
			x++;
		}
		y++;
	}
	x = 0;
	while (x < scn->map.line[0].x_max)
	{
		y = 0;
		while (y < scn->map.y_max - 1)
		{
			ft_draw_line(scn->obj, scn->cpy[y][x], scn->cpy[y + 1][x]);
			y++;
		}
		x++;
	}
}

void		ft_generate_image(t_img *obj, int x, int y, t_color color)
{
	if (y < 0 || y > SIZE_H - 1 || x < 0 || x > SIZE_W - 1)
		return ;
	obj->data[y * obj->sizeline + x * obj->bpp / 8] = color.b;
	obj->data[y * obj->sizeline + x * obj->bpp / 8 + 1] = color.g;
	obj->data[y * obj->sizeline + x * obj->bpp / 8 + 2] = color.r;
	obj->data[y * obj->sizeline + x * obj->bpp / 8 + 3] = color.a;
}

t_colorset	ft_get_colorset(t_color top, t_color mid, t_color bot)
{
	t_colorset	colorset;

	colorset.top = top;
	colorset.mid = mid;
	colorset.bot = bot;
	return (colorset);
}

void		ft_draw_all(t_scene *scn)
{
	ft_bzero(scn->obj->data, SIZE_W * SIZE_H * 4);
	ft_bzero(scn->obj->data, (SIZE_W - 5) * 200 * 4);
	ft_apply_all_matrix(scn);
	if (scn->display_menu == 0)
		mlx_clear_window(scn->mlx, scn->win);
	mlx_put_image_to_window(scn->mlx, scn->win, scn->obj->img, 0, 0);
	if (scn->display_menu == 1)
	{
		ft_create_menu(scn);
		mlx_put_image_to_window(scn->mlx, scn->win, scn->menu->img, 5, 0);
	}
	if (scn->display_menu == 1)
		ft_create_text(scn);
}
