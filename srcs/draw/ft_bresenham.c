#include "fdf.h"

void	ft_generate_image(t_scene *scn, int x, int y, t_color color)
{
	if (y < 0 || y > SIZE_H - 1 || x < 0 || x > SIZE_W - 1)
		return ;
	scn->data[y * scn->sizeline + x * scn->bpp / 8] = color.b;
	scn->data[y * scn->sizeline + x * scn->bpp / 8 + 1] = color.g;
	scn->data[y * scn->sizeline + x * scn->bpp / 8 + 2] = color.r;
}

void 	ft_draw_line(t_scene *scn, t_vector a, t_vector b)
{
	int dx, dy, i, e;
  	int incx, incy, inc1, inc2;
  	double x, y;
  	t_color	c1, c2;

	dx = b.x - a.x;
	dy = b.y - a.y;
	incx = 1;
	incy = 1;

	if(dx < 0) 
		dx = -dx;
	if(dy < 0) 
		dy = -dy;
	if(b.x < a.x) 
		incx = -1;
	if(b.y < a.y) 
		incy = -1;
	x = a.x;
	y = a.y;


		c1 = b.color;
		c2 = a.color;
	
			//printf("%f %f %d\n", a.z, b.z, dist);
	if(dx > dy)
	{
		//ft_generate_image(scn, x, y, color_pos(a.color, b.color, 0));
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for(i = 0; i < dx; i++)
		{
			if(e >= 0)
			{
				y += incy;
				e += inc1;
			}
			else 
				e += inc2;
			x += incx;
			ft_generate_image(scn, x, y, ft_cal_color(c1, c2, i / fabs(b.x - a.x)));
	  	}
	}
	else
	{
		//ft_generate_image(scn, x, y, color_pos(a.color, b.color, 0));
		e = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for(i = 0; i < dy; i++)
		{
			if(e >= 0)
			{
				x += incx;
				e += inc1;
			}
			else 
				e += inc2;
			y += incy;
			ft_generate_image(scn, x, y, ft_cal_color(c1, c2, i / fabs(b.y - a.y)));
		}
	}
}