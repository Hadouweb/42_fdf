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

void			ft_init_color(t_scene *scn, t_colorset cs)
{
	int 	y;
	int 	x;
	int 	dist;
	double 	z;

	y = 0;
	dist = abs(scn->map.max - scn->map.min);
	while (y < scn->map.y_max)
	{
		x = 0;
		while (x < scn->map.line[y].x_max)
		{
			z = scn->map.line[y].px[x].z;
			//printf("%f\n", z);
			if (z / dist > 0.1)
				scn->map.line[y].px[x].color = ft_get_color(cs.top.r + fabs(z * 300 ) / dist,
				cs.top.g + fabs(z * 450) / dist, cs.top.b + fabs(z * 500) / dist, cs.top.a);
			else if (z / dist < 0)
				scn->map.line[y].px[x].color = ft_get_color(cs.bot.r, cs.bot.g, cs.bot.b - fabs(z * 300) / dist, cs.bot.a);
			else
				scn->map.line[y].px[x].color = ft_get_color(cs.mid.r, cs.mid.g - fabs(z * 1500) / dist, cs.mid.b, cs.mid.a);
			x++;
		}
		y++;
	}
}