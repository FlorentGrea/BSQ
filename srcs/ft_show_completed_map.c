/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_completed_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:37:30 by fgrea             #+#    #+#             */
/*   Updated: 2020/09/30 20:20:35 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

void	ft_show_completed_map(t_map *map, t_sqr *sqr)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	z;

	i = sqr->x - 1;
	j = sqr->y - 1;
	z = -1;
	while (++j < sqr->y + sqr->line)
		while (++i < sqr->x + sqr->line)
			map->empty_map[j][i] = map->full;
	while (map->empty_map[++z])
		ft_putstr(map->empty_map[z]);
}
