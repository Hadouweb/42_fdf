#include "fdf.h"

void	ft_reload(t_scene *scn)
{
	mlx_clear_window(scn->mlx, scn->win);
	scn->center = ft_get_center(*scn);
	ft_draw_map(*scn);
}

void	ft_draw_map(t_scene scn)
{
	int			x;
	int			y;

	y = 0;
	while (y < scn.map.y_max)
	{
		x = 0;
		while (x < scn.map.line[y].x_max - 1)
		{
			ft_draw_line(scn, scn.map.line[y].px[x], scn.map.line[y].px[x + 1]);
			x++;
		}
		y++;
	}
	x = 0;
	while (x < scn.map.line[0].x_max)
	{
		y = 0;
		while (y < scn.map.y_max - 1)
		{
			ft_draw_line(scn, scn.map.line[y].px[x], scn.map.line[y + 1].px[x]);
			y++;
		}
		x++;
	}
}