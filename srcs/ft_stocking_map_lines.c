/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stocking_map_lines.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 22:55:24 by fgrea             #+#    #+#             */
/*   Updated: 2020/09/30 18:34:43 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

t_map	*ft_fill_map(t_map *map, char *data, char **arr)
{
	char			**ret;
	unsigned int	i;
	unsigned int	j;

	ret = arr;
	j = 0;
	while (*data)
	{
		i = 0;
		while (*data != '\n' && *data)
			ret[j][i++] = *data++;
		ret[j][i] = '\0';
		j++;
		data++;
	}
	map->empty_map = arr;
	return (map);
}

t_map	*ft_stocking_map_lines(t_map *map, char *data)
{
	char			**arr;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (*data != '\n')
		data++;
	data++;
	if (!(arr = (char **)malloc(sizeof(char *) * (map->line_nbr + 1))))
		return (0);
	while (data[i] != '\n')
		i++;
	while (j < map->line_nbr)
		if (!(arr[j++] = (char *)malloc(sizeof(char) * (i + 1))))
			return (0);
	arr[j] = 0;
	return (ft_fill_map(map, data, arr));
}
