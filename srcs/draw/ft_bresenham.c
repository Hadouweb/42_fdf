#include "fdf.h"

static void		ft_draw_dx(t_scene scn, t_vector a, t_vector b, int e)
{
	int		i;
	int		dx;
	int		dy;
	int		x;
	int		y;

	i = 0;
	dx = fabs(b.x - a.x);
	dy = fabs(b.y - a.y);
	mlx_pixel_put(scn.mlx, scn.win, a.x, a.y, 0x0000FF00);
	x = a.x;
	y = a.y - 1;
	while (i < dx)
	{
		if(e > 0)
		{
			y += (b.y < a.y) ? -1 : 1;
			e += 2 * (dy - dx);
		}
		else 
			e += 2 * dy;
		x += (b.x < a.x) ? -1 : 1;
		mlx_pixel_put(scn.mlx, scn.win, x, y, 0x0000FF00);
		i++;
  	}
}

static void		ft_draw_dy(t_scene scn, t_vector a, t_vector b, int e)
{
	int		i;
	int		dx;
	int		dy;
	int		x;
	int		y;

	i = 0;
	dx = fabs(b.x - a.x);
	dy = fabs(b.y - a.y);
	mlx_pixel_put(scn.mlx, scn.win, a.x, a.y, 0x0000FF00);
	x = a.x - 1;
	y = a.y;
	while (i < dy)
	{
		if(e > 0)
		{
			x += (b.x < a.x) ? -1 : 1;
			e += 2 * (dx - dy);
		}
		else 
			e += 2 * dx;
		y += (b.y < a.y) ? -1 : 1;
		mlx_pixel_put(scn.mlx, scn.win, x, y, 0x0000FF00);
		i++;
	}
}

void 			ft_draw_line(t_scene scn, t_vector a, t_vector b)
{
	int 	dx;
	int 	dy;
	int 	e;

	dx = abs((int)b.x - (int)a.x);
	dy = abs((int)b.y - (int)a.y);
	e = 2 * abs(dy - dx);

	if(dx > dy)
		ft_draw_dx(scn, a, b, e);
	else
		ft_draw_dy(scn, a, b, e);
}