/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocking_first_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 13:11:56 by fgrea             #+#    #+#             */
/*   Updated: 2020/09/30 00:36:18 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

t_map	*ft_stocking_first_line(char *str)
{
	t_map	*map;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	map->line_nbr = 0;
	while (*str >= '0' && *str <= '9')
		map->line_nbr = map->line_nbr * 10 + (*str++ - 48);
	if (map->line_nbr == 0)
		return (0);
	map->empty = *str++;
	map->barrier = *str++;
	map->full = *str;
	map->empty_map = 0;
	return (map);
}
