#include "fdf.h"

void	ft_create_text(t_scene *scn)
{
	mlx_string_put(scn->mlx, scn->win, 20, 20, 0xffffff, "Coucou");
}

void	ft_create_menu(t_scene *scn)
{
	int		x;
	int		y;

	y = 5;
	while (y < SIZE_H / 10)
	{
		x = 5;
		while (x < SIZE_W - 5)
		{
			ft_generate_image(scn, x, y, ft_get_color(45, 45, 55, 100));
			x++;
		}
		y++;
	}
}

int		ft_menu(int keycode, t_scene *scn)
{
	if (keycode == KEY_MENU && scn->display_menu == 0)
		scn->display_menu = 1;
	else if (keycode == KEY_MENU && scn->display_menu == 1)
		scn->display_menu = 0;
	ft_draw_all(scn);
	return (1);
}