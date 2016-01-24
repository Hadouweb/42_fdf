/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nle-bret <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:43:09 by nle-bret          #+#    #+#             */
/*   Updated: 2015/11/25 05:30:51 by nle-bret         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_count_word(char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == c)
		i++;
	if (s[i])
		count++;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i])
				count++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

static int	ft_strlen_split(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

t_width		ft_split_to_int(char *s, char c, int l, t_map *map)
{
	t_width		line;
	size_t		nb_word;
	size_t		i;
	size_t		k;
	int 		size;

	i = 0;
	k = 0;
	nb_word = ft_count_word(s, c);
	line.px = (t_vector *)ft_memalloc(nb_word * sizeof(t_vector) + 1);
	while (i < nb_word)
	{
		while (s[k] && s[k] == c)
			k++;
		size = ft_strlen_split(&s[k], ' ');
		line.px[i].x = i + SIZE_W / 2;
		line.px[i].y = l + SIZE_H / 2;
		line.px[i].z = ft_atoi(&s[k]);
		line.px[i].w = 1;
		if (line.px[i].z > map->max)
			map->max = line.px[i].z;
		if (line.px[i].z < map->min)
			map->min = line.px[i].z;
		k += size;
		i++;
	}
	line.x_max = i;
	return (line);
}
