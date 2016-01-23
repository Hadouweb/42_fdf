#include "fdf.h"

void	ft_generate_image(t_scene *scn, int x, int y, int color)
{
	if (y < 0 || y > SIZE_H - 1 || x < 0 || x > SIZE_W - 1)
		return ;
	int r;
	int g;
	int b;
	r = (0x0000ff & (color >> 16));
	g = (0x0000ff & (color >> 8));
	b = (0x0000ff & color);
	scn->data[y * scn->sizeline + x * scn->bpp / 8] = b;
	scn->data[y * scn->sizeline + x * scn->bpp / 8 + 1] = g;
	scn->data[y * scn->sizeline + x * scn->bpp / 8 + 2] = r;
}



void 	ft_draw_line(t_scene *scn, t_vector a, t_vector b)
{
	int dx, dy, i, e;
  	int incx, incy, inc1, inc2;
  	double x, y;

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

	if(dx > dy)
	{
		ft_generate_image(scn, x, y, 0x0000ff);
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
			ft_generate_image(scn, x, y, 0x0000ff);
	  	}
	}
	else
	{
		ft_generate_image(scn, x, y, 0x0000ff);
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
			ft_generate_image(scn, x, y, 0x0000ff);
		}
	}
}