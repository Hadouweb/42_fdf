#include "fdf.h"

void	ft_create_brackground(t_scene *scn)
{
	int		x;
	int		y;

	y = 0;
	while (y < 100)
	{
		x = 0;
		while (x < SIZE_W)
		{
			mlx_pixel_put(scn->mlx, scn->win, x, y, 0x00ff00);
			x++;
		}
		y++;
	}
}

int		ft_menu(int keycode, t_scene *scn)
{
	if (keycode == KEY_MENU && scn->display_menu == 0)
	{
		scn->display_menu = 1;
		mlx_string_put(scn->mlx, scn->win, 20, 20, 0xffffff, "Coucou");
		ft_create_brackground(scn);
	}
	else if (keycode == KEY_MENU && scn->display_menu == 1)
	{
		scn->display_menu = 0;
		mlx_clear_window(scn->mlx, scn->win);
		ft_apply_all_matrix(scn);
	}
	return (1);
}