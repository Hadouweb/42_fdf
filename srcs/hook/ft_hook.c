#include "fdf.h"

int		ft_hook_translate(int keycode, t_scene *scn)
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

int		ft_hook_rotate(int keycode, t_scene *scn)
{
	if (keycode == KEY_ROTZ_LEFT)
		scn->v = ft_get_vector(0.0, 0.0, -(5 * M_PI / 180), 1.0);
	if (keycode == KEY_ROTZ_RIGHT)
		scn->v = ft_get_vector(0.0, 0.0, 5 * M_PI / 180, 1.0);
	if (keycode == KEY_ROTX_TOP)
		scn->v = ft_get_vector(-(5 * M_PI / 180), 0.0, 0.0, 1.0);
	if (keycode == KEY_ROTX_BOT)
		scn->v = ft_get_vector(5 * M_PI / 180, 0.0, 0.0, 1.0);
	if (keycode == KEY_ROTY_LEFT)
		scn->v = ft_get_vector(0.0, -(5 * M_PI / 180), 0.0, 1.0);
	if (keycode == KEY_ROTY_RIGHT)
		scn->v = ft_get_vector(0.0, 5 * M_PI / 180, 0.0, 1.0);
	ft_rotation(*scn, scn->v);
	return (1);
}

int 	ft_hook_scale(int keycode, t_scene *scn)
{
	t_vector v;

	v.w = 1;
	if (keycode == SCALE_UP)
	{
		v.x = 2;
		v.y = 2;
		v.z = 2;
		ft_scale(*scn, v);
	}
	if (keycode == SCALE_DOWN)
	{
		v.x = 0.5;
		v.y = 0.5;
		v.z = 0.5;
		ft_scale(*scn, v);
	}
	return (1);
}

int 	ft_hook_elev(int keycode, t_scene *scn)
{
	t_vector v;

	v.w = 1;
	if (keycode == ELEV_UP)
	{
		v.x = 1;
		v.y = 1;
		v.z = 2;
		ft_scale(*scn, v);
	}
	if (keycode == ELEV_DOWN)
	{
		v.x = 1;
		v.y = 1;
		v.z = 0.5;
		ft_scale(*scn, v);
	}
	return (1);
}

int		ft_hook(int keycode, t_scene *scn)
{
	//printf("%d\n", keycode);
	if (keycode == KEY_ESC)
		exit(1);
	ft_hook_translate(keycode, scn);
	ft_hook_rotate(keycode, scn);
	ft_hook_scale(keycode, scn);
	ft_hook_elev(keycode, scn);
	//ft_reload(scn);
	return (1);
}