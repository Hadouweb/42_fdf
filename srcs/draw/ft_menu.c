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

t_colorset	ft_get_colorset(t_color top, t_color mid, t_color bot)
{
	t_colorset	colorset;

	colorset.top = top;
	colorset.mid = mid;
	colorset.bot = bot;
	return (colorset);
}

int 	ft_color_hook(int keycode, t_scene *scn)
{
	t_colorset 	colorset;
	int 		key;

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
		colorset = ft_get_colorset(ft_get_color(rand() % 255, rand() % 255, rand() % 255, 0),
			ft_get_color(rand() % 255, rand() % 255, rand() % 255, 0), 
			ft_get_color(rand() % 255, rand() % 255, rand() % 255, 0));
	if (key)
		ft_init_color(scn, colorset);
	return (1);
}

int 	ft_projection(int keycode, t_scene *scn)
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

int 	ft_select_map(int keycode, t_scene *scn)
{
	t_map 	map;
	int 	key;

	key = 0;
	if (keycode == KEY_MAP_1 && ++key)
		map = ft_read_file("maps/42.fdf");
	if (keycode == KEY_MAP_2 && ++key)
		map = ft_read_file("maps/pyramide.fdf");
	if (keycode == KEY_MAP_3 && ++key)
		map = ft_read_file("maps/mars.fdf");
	if (keycode == KEY_MAP_4 && ++key)
		map = ft_read_file("CUSTOM_Japan.OCEAN1.L.fdf");
	if (keycode == KEY_MAP_5 && ++key)
		map = ft_read_file("CUSTOM_France.OCEAN1.XXL.fdf");
	if (key)
	{
		mlx_destroy_window(scn->mlx, scn->win);
		ft_init(map);
	}
	return (1);
}

int		ft_menu(int keycode, t_scene *scn)
{
	printf("%d\n", keycode);
	if (keycode == KEY_MENU && scn->display_menu == 0)
		scn->display_menu = 1;
	else if (keycode == KEY_MENU && scn->display_menu == 1)
		scn->display_menu = 0;
	if (keycode == KEY_RESET)
	{
		scn->scale = ft_get_vector(3.0, 3.0, 0.3, 1.0);
		scn->rot = ft_get_vector(0.0, 0.0, 0.0, 1.0);
		scn->trans = ft_get_vector(1.0, 1.0, 1.0, 1.0);
		ft_apply_all_matrix(scn);
	}
	ft_color_hook(keycode, scn);
	ft_projection(keycode, scn);
	ft_select_map(keycode, scn);
	ft_draw_all(scn);
	return (1);
}