#include "fdf.h"

void	ft_generate_image(t_img *obj, int x, int y, t_color color)
{
	if (y < 0 || y > SIZE_H - 1 || x < 0 || x > SIZE_W - 1)
		return ;
	obj->data[y * obj->sizeline + x * obj->bpp / 8] = color.b;
	obj->data[y * obj->sizeline + x * obj->bpp / 8 + 1] = color.g;
	obj->data[y * obj->sizeline + x * obj->bpp / 8 + 2] = color.r;
	obj->data[y * obj->sizeline + x * obj->bpp / 8 + 3] = color.a;
}

void	ft_draw_all(t_scene *scn)
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

void	ft_create_text(t_scene *scn)
{
	mlx_string_put(scn->mlx, scn->win, 20, 10, 0xffffff, "Rotate X Top   : W");
	mlx_string_put(scn->mlx, scn->win, 20, 25, 0xffffff, "Rotate X Bot   : S");
	mlx_string_put(scn->mlx, scn->win, 20, 45, 0xffffff, "Rotate Y Left  : A");
	mlx_string_put(scn->mlx, scn->win, 20, 60, 0xffffff, "Rotate Y Right : D");
	mlx_string_put(scn->mlx, scn->win, 20, 80, 0xffffff, "Rotate Z Left  : Q");
	mlx_string_put(scn->mlx, scn->win, 20, 95, 0xffffff, "Rotate Z Right : E");
	mlx_string_put(scn->mlx, scn->win, 230, 10, 0xffffff, "Translate Top   : ^");
	mlx_string_put(scn->mlx, scn->win, 230, 25, 0xffffff, "Translate Bot   : v");
	mlx_string_put(scn->mlx, scn->win, 230, 40, 0xffffff, "Translate Left  : <");
	mlx_string_put(scn->mlx, scn->win, 230, 55, 0xffffff, "Translate Right : >");
	mlx_string_put(scn->mlx, scn->win, 440, 10, 0xffffff, "Translate Zoom + : R");
	mlx_string_put(scn->mlx, scn->win, 440, 25, 0xffffff, "Translate Zoom - : T");
	mlx_string_put(scn->mlx, scn->win, 440, 45, 0xffffff, "Scale Z Up +     : F");
	mlx_string_put(scn->mlx, scn->win, 440, 60, 0xffffff, "Scale Z Bot -    : G");
	mlx_string_put(scn->mlx, scn->win, 440, 80, 0xffffff, "Exit             : ESC");
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

int		ft_menu(int keycode, t_scene *scn)
{
	if (keycode == KEY_MENU && scn->display_menu == 0)
		scn->display_menu = 1;
	else if (keycode == KEY_MENU && scn->display_menu == 1)
		scn->display_menu = 0;
	ft_draw_all(scn);
	return (1);
}