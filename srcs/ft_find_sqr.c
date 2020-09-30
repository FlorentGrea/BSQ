/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_sqr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:03:39 by fgrea             #+#    #+#             */
/*   Updated: 2020/09/30 21:18:55 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int		ft_grow_sqr(t_map *map, t_ui x, t_ui y, t_ui line)
{
	t_ui	i;
	t_ui	j;

	i = x - 1;
	j = y - 1;
	while (++j < y + line)
	{
		printf("i = %u\n", i);
		while (++i < x + line)
		{
		printf("j = %u\n", j);
			if (!map->empty_map[j][i] || map->empty_map[j][i] == map->barrier)
				return (0);
		}
		i = x - 1;
	}
	printf("sortie\n");
	return (1);
}

t_sqr	*ft_set_sqr(t_map *map, t_sqr *sqr, t_ui x, t_ui y, t_ui line)
{
	int		stop;

	stop = 0;
	while (ft_grow_sqr(map, x, y, line))
		line++;
	printf("line = %u\n", line);
	if (line > sqr->line)
	{
		sqr->x = x;
		sqr->y = y;
		sqr->line = line;
	}
	return (sqr);
}

t_sqr	*ft_find_sqr(t_map *map)
{
	t_sqr			*sqr;
	unsigned int	x;
	unsigned int	y;
	unsigned int	line;

	x = 0;
	y = 0;
	line = 0;
	printf("coucou1\n");
	if (!(sqr = ft_alloc_sqr()))
		return (0);
	printf("coucou2\n");
	while (map->empty_map[y + sqr->line])
	{
	printf("coucou3\n");
		if	(!map->empty_map[y][x + sqr->line])
			y++;
		else if (map->empty_map[y][x] == map->barrier)
			x++;
		else
		{
	printf("coucou4\n");
			sqr = ft_set_sqr(map, sqr, x, y, line);
			x++;
		}
	}
	return (sqr);
}
