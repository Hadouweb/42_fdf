#include "fdf.h"

int		ft_translate_hmatrix(int keycode, t_scene *scn)
{
	if (keycode == 123)
	{
		scn->v = ft_get_vector(-10.0, 0.0, 0.0, 1.0);
		ft_translation(*scn, scn->v);
	}
	else if (keycode == 124)
	{
		scn->v = ft_get_vector(10.0, 0.0, 0.0, 1.0);
		ft_translation(*scn, scn->v);
	}
	else if (keycode == 125)
	{
		scn->v = ft_get_vector(0.0, 10.0, 0.0, 1.0);
		ft_translation(*scn, scn->v);
	}
	else if (keycode == 126)
	{
		scn->v = ft_get_vector(0.0, -10.0, 0.0, 1.0);
		ft_translation(*scn, scn->v);
	}
	return (1);
}

int		ft_rotate_hmatrix(int keycode, t_scene *scn)
{
	if (keycode == KEY_ROTZ_LEFT)
		ft_rotation(*scn, -(5 * M_PI / 180), 'z');
	if (keycode == KEY_ROTZ_RIGHT)
		ft_rotation(*scn, 5 * M_PI / 180, 'z');
	if (keycode == KEY_ROTX_TOP)
		ft_rotation(*scn, -(5 * M_PI / 180), 'x');
	if (keycode == KEY_ROTX_BOT)
		ft_rotation(*scn, 5 * M_PI / 180, 'x');
	if (keycode == KEY_ROTY_LEFT)
		ft_rotation(*scn, -(5 * M_PI / 180), 'y');
	if (keycode == KEY_ROTY_RIGHT)
		ft_rotation(*scn, 5 * M_PI / 180, 'y');
	return (1);
}

int 	ft_scale_hmatrix(int keycode, t_scene *scn)
{
	if (keycode == SCALE_UP)
		ft_scale(*scn, 2);
	if (keycode == SCALE_DOWN)
		ft_scale(*scn, 0.5);
	return (1);
}

int		ft_hook(int keycode, t_scene *scn)
{
	printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		exit(1);
	ft_translate_hmatrix(keycode, scn);
	ft_rotate_hmatrix(keycode, scn);
	ft_scale_hmatrix(keycode, scn);
	ft_reload_matrix(scn);
	return (1);
}