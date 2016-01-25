#include "fdf.h"

void	ft_print_map(t_map map)
{
	int 	x;
	int 	y;

	y = 0;
	while (y < map.y_max)
	{
		x = 0;
		//printf("%d\n", map.line[y].x_max);
		while (x < map.line[y].x_max)
		{
			printf("{%.0f,", map.line[y].px[x].x);
			printf("%.0f,", map.line[y].px[x].y);	
			printf("%.0f}", map.line[y].px[x].z);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	ft_print_matrix(double m[4][4])
{
	int 	i;
	int 	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%f\t", m[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("%f\n", sin(90 * M_PI/180));
}

void		ft_print_vector(t_vector v)
{
	printf("{%f, %f, %f, %f}\n", v.x, v.y, v.z, v.w);
	printf("\n");
}

void 		ft_exit(void)
{
	ft_putstr("Error\n");
	exit(1);
}