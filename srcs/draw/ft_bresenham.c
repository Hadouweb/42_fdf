#include "fdf.h"

void 	ft_draw_line(t_scene scn, t_vector a, t_vector b)
{
	int dx, dy, i, e;
  	int incx, incy, inc1, inc2;
  	int x, y;

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
		mlx_pixel_put(scn.mlx, scn.win, x, y, 0X000000FF);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for(i = 0; i < dx; i++)
		{
			if(e >= 0)
			{
				y += incy;
						//printf("y %d\n", y);
				e += inc1;
			}
			else 
				e += inc2;
			x += incx;
			mlx_pixel_put(scn.mlx, scn.win, x, y, 0X000000FF);
	  	}
	}
	else
	{
		mlx_pixel_put(scn.mlx, scn.win, x, y, 0X000000FF);
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
								//	printf("2y %d\n", y);
			mlx_pixel_put(scn.mlx, scn.win, x, y, 0X000000FF);
		}
	}
}