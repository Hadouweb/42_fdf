#include "fdf.h"

void	ft_generate_image(t_img *obj, int x, int y, t_color color)
{
	if (y < 0 || y > SIZE_H - 1 || x < 0 || x > SIZE_W - 1)
		return ;
	obj->data[y * obj->sizeline + x * obj->bpp / 8] = color.b;
	obj->data[y * obj->sizeline + x * obj->bpp / 8 + 1] = color.g;
	obj->data[y * obj->sizeline + x * obj->bpp / 8 + 2] = color.r;
	obj->data[y * obj->sizeline + x * obj->bpp / 8 + 3] = color.a;
}

t_colorset	ft_get_colorset(t_color top, t_color mid, t_color bot)
{
	t_colorset	colorset;

	colorset.top = top;
	colorset.mid = mid;
	colorset.bot = bot;
	return (colorset);
}

void	ft_draw_all(t_scene *scn)
{
	ft_bzero(scn->obj->data, SIZE_W * SIZE_H * 4);
	ft_bzero(scn->obj->data, (SIZE_W - 5) * 200 * 4);
	ft_apply_all_matrix(scn);
	if (scn->display_menu == 0)
		mlx_clear_window(scn->mlx, scn->win);
	mlx_put_image_to_window(scn->mlx, scn->win, scn->obj->img, 0, 0);
	if (scn->display_menu == 1)
	{
		ft_create_menu(scn);
		mlx_put_image_to_window(scn->mlx, scn->win, scn->menu->img, 5, 0);
	}
	if (scn->display_menu == 1)
		ft_create_text(scn);
}