#include "fdf.h"

int		ft_hook_translate(int keycode, t_scene *scn)
{
	int		key;
	double	v;

	key = 0;
	v = SIZE_W / scn->map.y_max + 20;
	if (keycode == 123 && ++key)
		scn->v = ft_get_vector(-v, 0.0, 0.0, 1.0);
	else if (keycode == 124 && ++key)
		scn->v = ft_get_vector(v, 0.0, 0.0, 1.0);
	else if (keycode == 125 && ++key)
		scn->v = ft_get_vector(0.0, v, 0.0, 1.0);
	else if (keycode == 126 && ++key)
		scn->v = ft_get_vector(0.0, -v, 0.0, 1.0);
	if (key)
		ft_translation(scn);
	return (1);
}

int		ft_hook_rotate(int keycode, t_scene *scn)
{
	int		key;

	key = 0;
	if (keycode == KEY_ROTZ_LEFT && ++key)
		scn->v = ft_get_vector(0.0, 0.0, -(5 * M_PI / 180), 1.0);
	if (keycode == KEY_ROTZ_RIGHT && ++key)
		scn->v = ft_get_vector(0.0, 0.0, 5 * M_PI / 180, 1.0);
	if (keycode == KEY_ROTX_TOP && ++key)
		scn->v = ft_get_vector(-(5 * M_PI / 180), 0.0, 0.0, 1.0);
	if (keycode == KEY_ROTX_BOT && ++key)
		scn->v = ft_get_vector(5 * M_PI / 180, 0.0, 0.0, 1.0);
	if (keycode == KEY_ROTY_LEFT && ++key)
		scn->v = ft_get_vector(0.0, -(5 * M_PI / 180), 0.0, 1.0);
	if (keycode == KEY_ROTY_RIGHT && ++key)
		scn->v = ft_get_vector(0.0, 5 * M_PI / 180, 0.0, 1.0);
	if (key)
		ft_rotation(scn);
	return (1);
}

int 	ft_hook_scale(int keycode, t_scene *scn)
{
	int		key;

	key = 0;
	if (keycode == SCALE_UP && ++key)
		scn->v = ft_get_vector(2.0, 2.0, 2.0, 1.0);
	if (keycode == SCALE_DOWN && ++key)
		scn->v = ft_get_vector(0.5, 0.5, 0.5, 1.0);
	if (key)
		ft_scale(scn);
	return (1);
}

int 	ft_hook_elev(int keycode, t_scene *scn)
{
	int		key;
	double	v;

	key = 0;
	v = 5.0 / scn->map.y_max;
	if (keycode == ELEV_UP && ++key)
		scn->v = ft_get_vector(0.0, 0.0, v, 1.0);
	if (keycode == ELEV_DOWN && ++key)
		scn->v = ft_get_vector(0.0, 0.0, -v, 1.0);
	if (key)
		ft_scale_elev(scn);
	return (1);
}

int		ft_hook(int keycode, t_scene *scn)
{
	printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		exit(1);
	ft_hook_translate(keycode, scn);
	ft_hook_rotate(keycode, scn);
	ft_hook_scale(keycode, scn);
	ft_hook_elev(keycode, scn);

	ft_draw_all(scn);
	return (1);
}