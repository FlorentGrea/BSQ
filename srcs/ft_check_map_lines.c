/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 22:39:39 by fgrea             #+#    #+#             */
/*   Updated: 2020/09/30 21:09:59 by fgrea            ###   ########lyon.fr   */
/*   Updated: 2020/09/30 18:58:32 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int		ft_iterative_check(t_map *map, char *data, unsigned int line_max, \
		unsigned int line_count)
{
	unsigned int	i;
	while (data[line_max] != '\n')
		line_max++;
	i = 0;
	while (*data)
	{
		if (*data != map->empty && *data != map->barrier && *data != '\n')
		return (0);
		if (*data == '\n' && i == line_max)
		{
			line_count++;
			if (i != line_max)
			{
				return (0);
			}
			i = 0;
		}
		else
			i++;
		data++;
	}
	return (line_count != map->line_nbr ? 0 : 1);
}

int		ft_check_possibility(t_map *map, char *data)
{
	int		empty;
	empty = 0;
	while (*data)
		if (*data++ == map->empty)
			empty++;
	return (empty == 0 ? 0 : 1);
}

int		ft_check_map_lines(t_map *map, char *data)
{
	unsigned int	line_max;
	unsigned int	line_count;

	line_max = 0;
	line_count = 0;
	while (*data && *data != '\n')
		data++;
	if (!*data)
		return (0);
	data++;
	if (!(ft_check_possibility(map, data)))
		return (0);
	return (ft_iterative_check(map, data, line_max, line_count));
}
