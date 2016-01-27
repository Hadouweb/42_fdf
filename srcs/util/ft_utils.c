/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 02:09:20 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/27 02:09:21 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_exit(void)
{
	ft_putstr("Error\n");
	exit(1);
}

void		ft_clear_list(t_line *lst)
{
	t_line	*l;
	char	*tmp;

	l = NULL;
	while (lst)
	{
		l = lst;
		tmp = l->str;
		lst = lst->next;
		free(l);
		l = NULL;
		ft_strdel(&tmp);
	}
	free(lst);
	lst = NULL;
}

t_vector	**ft_cpy_map(t_map *map)
{
	t_vector	**cpy;
	int			y;
	int			x;

	y = 0;
	cpy = (t_vector **)ft_memalloc(sizeof(t_vector *) * map->y_max);
	while (y < map->y_max)
	{
		x = 0;
		cpy[y] = (t_vector *)ft_memalloc(sizeof(t_vector) * map->line[y].x_max);
		while (x < map->line[y].x_max)
		{
			cpy[y][x] = ft_get_vector(
				map->line[y].px[x].x,
				map->line[y].px[x].y,
				map->line[y].px[x].z,
				map->line[y].px[x].w);
			x++;
		}
		y++;
	}
	return (cpy);
}
