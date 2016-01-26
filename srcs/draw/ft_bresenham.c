#include "fdf.h"

void 	ft_draw_line(t_img *obj, t_vector a, t_vector b)
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
	
	if(dx > dy)
	{
		ft_generate_image(obj, x, y, ft_cal_color(c1, c2, 0 / fabs(b.x - a.x)));
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
			ft_generate_image(obj, x, y, ft_cal_color(c1, c2, i / fabs(a.x - b.x)));
	  	}
	}
	else
	{
		ft_generate_image(obj, x, y, ft_cal_color(c1, c2, 0 / fabs(b.y - a.y)));
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
			ft_generate_image(obj, x, y, ft_cal_color(c1, c2, i / fabs(a.y - b.y)));
		}
	}
}