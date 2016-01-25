#include "fdf.h"

t_color			ft_cal_color(t_color a, t_color b, double pos)
{
	t_color		color;

	color.r = b.r + ((a.r - b.r) * pos);
	color.g = b.g + ((a.g - b.g) * pos);
	color.b = b.b + ((a.b - b.b) * pos);
	//printf("%f\n", (a.r - b.r) * pos);
	return (color);
}

t_color 		ft_get_color(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
{
	t_color		color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.a = a;

	return (color);
}

void			ft_init_color(t_scene *scn)
{
	int 	y;
	int 	x;
	int 	dist;
	double 	z;
	t_color	top;
	t_color	mid;
	t_color	bot;

	top = ft_get_color(90, 30, 0, 0);
	mid = ft_get_color(0, 150, 0, 0);
	bot = ft_get_color(0, 0, 200, 0);

	y = 0;
	dist = abs(scn->map.max - scn->map.min);
	printf("%d\n", dist);
	while (y < scn->map.y_max)
	{
		x = 0;
		while (x < scn->map.line[y].x_max)
		{
			z = scn->map.line[y].px[x].z;
			//printf("%f\n", z);
			if (z / dist > 0.1)
				scn->map.line[y].px[x].color = ft_get_color(top.r + fabs(z * 300 ) / dist, top.g + fabs(z * 450) / dist, top.b + fabs(z * 500) / dist, top.a); // white
			else if (z / dist < 0)
				scn->map.line[y].px[x].color = ft_get_color(bot.r, bot.g, bot.b - fabs(z * 300) / dist, bot.a); // blue
			else
				scn->map.line[y].px[x].color = ft_get_color(mid.r, mid.g - fabs(z * 1500) / dist, mid.b, mid.a); // green
			x++;
		}
		y++;
	}
}