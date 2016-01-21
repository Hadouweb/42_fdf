#include "fdf.h"

void	ft_reload(t_scene scn)
{
	mlx_clear_window(scn.mlx, scn.win);
	ft_draw_x(scn, scn.origin, scn.origin);
	ft_draw_y(scn, scn.origin, scn.origin);
}

void	ft_draw_x(t_scene scn, t_vector a, t_vector b)
{
	int		x;
	int		y;
	int 	h;

	y = 0;
	while (y < scn.map.y_max)
	{
		x = 1;
		a.y -= scn.map.line[y].px[0].z * scn.h;
		while (x < scn.map.line[y].x_max)
		{
			h = -(a.y - b.y);
			b.x += scn.incx;
			b.y += scn.incy - scn.map.line[y].px[x].z * scn.h;
			ft_draw_line(scn, a, b);
			a.x = b.x;
			a.y = b.y;
			b.y += scn.map.line[y].px[x].z * scn.h;
			x++;
		}
		a.x = scn.origin.x -= scn.incx;
		a.y = scn.origin.y += scn.incy;
		b = a;
		y++;
	}
}

void	ft_draw_y(t_scene scn, t_vector a, t_vector b)
{
	int		x;
	int		y;
	int		h;

	b = a;
	x = 0;
	while (x < scn.map.line[0].x_max)
	{
		y = 1;
		a.y -= scn.map.line[0].px[x].z * scn.h;
		while (y < scn.map.y_max)
		{
			h = -(a.y - b.y);
			b.x -= scn.incx;
			b.y += scn.incy - scn.map.line[y].px[x].z * scn.h;
			ft_draw_line(scn, a, b);
			a.x = b.x;
			a.y = b.y;
			b.y += scn.map.line[y].px[x].z * scn.h;
			y++;
		}
		a.x = scn.origin.x += scn.incx;
		a.y = scn.origin.y += scn.incy;
		b = a;
		x++;
	}
}
