#include "fdf.h"

int		ft_translate_hiso(int keycode, t_scene *scn)
{
	if (keycode == KEY_UP)
		scn->origin.y -= 10;
	if (keycode == KEY_DOWN)
		scn->origin.y += 10;
	if (keycode == KEY_RIGHT)
		scn->origin.x += 10;
	if (keycode == KEY_LEFT)
		scn->origin.x -= 10;
	return (1);
}

int		ft_elevation_hiso(int keycode, t_scene *scn)
{
	if (keycode == SCALE_UP)
		scn->h -= 1;
	if (keycode == SCALE_DOWN)
		scn->h += 1;
	return (1);
}

int		ft_scale_hiso(int keycode, t_scene *scn)
{
	if (keycode == ELEV_UP)
	{
		scn->incx *= 2;
		scn->incy *= 2;
		scn->h *= 2;
	}
	if (keycode == ELEV_DOWN)
	{
		scn->incx /= 2;
		scn->incy /= 2;
		scn->h /= 2;
		if (scn->incx <= 8)
			scn->incx = 8;
		if (scn->incy <= 8)
			scn->incy = 4;
		if (scn->h <= 0)
			scn->incx = 0;
	}
	return (1);
}

int		ft_hook(int keycode, t_scene *scn)
{
	printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		exit(1);
	if (scn->projection == 1)
	{
		ft_translate_hiso(keycode, scn);
		ft_elevation_hiso(keycode, scn);
		ft_scale_hiso(keycode, scn);
		ft_reload(*scn);
	}
	if (scn->projection == 2)
	{
		ft_translate_hmatrix(keycode, scn);
		ft_rotate_hmatrix(keycode, scn);
		ft_scale_hmatrix(keycode, scn);
		ft_reload_matrix(scn);
	}
	if (keycode == KEY_PAR)
	{
		mlx_destroy_window(scn->mlx, scn->win);
		scn->map = ft_read_file(scn->name);
		ft_init(scn->map, scn->name, 2);
		ft_scale(*scn, scn->scale);
		ft_reload_matrix(scn);
	}
	if (keycode == KEY_ISO)
	{
		mlx_destroy_window(scn->mlx, scn->win);
		scn->map = ft_read_file(scn->name);
		ft_init(scn->map, scn->name, 1);
		scn->projection = 1;
		ft_reload(*scn);
	}
	return (1);
}