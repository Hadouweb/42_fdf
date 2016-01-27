/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 02:08:55 by nle-bret          #+#    #+#             */
/*   Updated: 2016/01/27 02:08:57 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_line	*ft_create_elem(char *str, int size)
{
	t_line	*list;

	list = (t_line *)ft_memalloc(sizeof(t_line));
	if (list)
	{
		list->str = ft_strdup(str);
		list->size = size;
		list->next = NULL;
	}
	return (list);
}

static void		ft_list_push_back(t_line **begin_list, char *str, int size)
{
	t_line	*list;

	list = *begin_list;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_create_elem(str, size);
	}
	else
		*begin_list = ft_create_elem(str, size);
}

static t_map	ft_save_map(t_line *lst, int nb_line)
{
	t_map		map;
	t_width		*line;
	t_line		*l;
	int			i;

	line = (t_width *)ft_memalloc(nb_line * sizeof(t_width) + 1);
	l = lst;
	i = 0;
	map.max = 0;
	map.min = 0;
	while (l)
	{
		line[i] = ft_split_to_int(l->str, ' ', i, &map);
		l = l->next;
		i++;
	}
	map.y_max = i;
	map.line = line;
	return (map);
}

t_map			ft_read_file(char *name)
{
	char	*line;
	t_map	map;
	t_line	*lst;
	int		fd;
	int		i;

	lst = NULL;
	line = NULL;
	fd = open(name, O_RDONLY);
	i = 1;
	while (get_next_line(fd, &line) > 0)
	{
		ft_list_push_back(&lst, line, ft_strlen(line));
		ft_strdel(&line);
		i++;
	}
	if (i == 1)
		ft_exit();
	map = ft_save_map(lst, i);
	ft_clear_list(lst);
	return (map);
}
