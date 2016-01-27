/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 02:07:25 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/27 02:07:27 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_create_text(t_scene *scn)
{
	mlx_string_put(scn->mlx, scn->win, 20, 10, 0xffffff, "Rotate X Top   : W");
	mlx_string_put(scn->mlx, scn->win, 20, 25, 0xffffff, "Rotate X Bot   : S");
	mlx_string_put(scn->mlx, scn->win, 20, 45, 0xffffff, "Rotate Y Left  : A");
	mlx_string_put(scn->mlx, scn->win, 20, 60, 0xffffff, "Rotate Y Right : D");
	mlx_string_put(scn->mlx, scn->win, 20, 80, 0xffffff, "Rotate Z Left  : Q");
	mlx_string_put(scn->mlx, scn->win, 20, 95, 0xffffff, "Rotate Z Right : E");
	mlx_string_put(scn->mlx, scn->win, 20, 140, 0xffffff, "Projection Iso      : I");
	mlx_string_put(scn->mlx, scn->win, 20, 155, 0xffffff, "Projection Parallel : P");
	mlx_string_put(scn->mlx, scn->win, 230, 10, 0xffffff, "Translate Top   : ^");
	mlx_string_put(scn->mlx, scn->win, 230, 25, 0xffffff, "Translate Bot   : v");
	mlx_string_put(scn->mlx, scn->win, 230, 40, 0xffffff, "Translate Left  : <");
	mlx_string_put(scn->mlx, scn->win, 230, 55, 0xffffff, "Translate Right : >");
	mlx_string_put(scn->mlx, scn->win, 310, 140, 0xffffff, "Color 1 : !");
	mlx_string_put(scn->mlx, scn->win, 310, 155, 0xffffff, "Color 2 : @");
	mlx_string_put(scn->mlx, scn->win, 480, 140, 0xffffff, "Color 3      : #");
	mlx_string_put(scn->mlx, scn->win, 480, 155, 0xffffff, "Color Random : $");
	mlx_string_put(scn->mlx, scn->win, 440, 10, 0xffffff, "Translate Zoom + : R");
	mlx_string_put(scn->mlx, scn->win, 440, 25, 0xffffff, "Translate Zoom - : T");
	mlx_string_put(scn->mlx, scn->win, 440, 45, 0xffffff, "Scale Z Up +     : F");
	mlx_string_put(scn->mlx, scn->win, 440, 60, 0xffffff, "Scale Z Bot -    : G");
	mlx_string_put(scn->mlx, scn->win, 700, 10, 0xffffff, "Map 10-2        : X");
	mlx_string_put(scn->mlx, scn->win, 700, 25, 0xffffff, "Map 42          : C");
	mlx_string_put(scn->mlx, scn->win, 700, 40, 0xffffff, "Map elem        : V");
	mlx_string_put(scn->mlx, scn->win, 700, 55, 0xffffff, "Map 100-6       : B");
	mlx_string_put(scn->mlx, scn->win, 700, 70, 0xffffff, "Map pyra        : N");
	mlx_string_put(scn->mlx, scn->win, 700, 85, 0xffffff, "Map pyramide    : M");
	mlx_string_put(scn->mlx, scn->win, 700, 100, 0xffffff, "Map nle-bret    : <");
	mlx_string_put(scn->mlx, scn->win, 700, 115, 0xffffff, "Map Japan_L     : >");
	mlx_string_put(scn->mlx, scn->win, 700, 130, 0xffffff, "Map France_XXL  : ?");
	mlx_string_put(scn->mlx, scn->win, 700, 150, 0xffffff, "Exit            : ESC");
}

void	ft_create_menu(t_scene *scn)
{
	int		x;
	int		y;

	y = 5;
	while (y < 200)
	{
		x = 0;
		while (x < SIZE_W - 5)
		{
			ft_generate_image(scn->menu, x, y, ft_get_color(45, 45, 55, 100));
			x++;
		}
		y++;
	}
}
