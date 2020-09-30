/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 23:19:25 by fgrea             #+#    #+#             */
/*   Updated: 2020/09/30 20:48:46 by fgrea            ###   ########lyon.fr   */
/*   Updated: 2020/09/30 20:11:36 by lgrandje         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int		main(int ac, char **av)
{
	t_map	*map;
	int		i;

	i = 1;
	if (ac == 1)
	{
		if (!(map = ft_set_data(0)))
		{
			ft_map_error();
			return (0);
		}
		if (!ft_set_algo(map))
			return (0);
		printf("%u\n", map->line_nbr);
		printf("%c\n", map->empty);
		printf("%c\n", map->barrier);
		printf("%c\n", map->full);
		for (int i = 0; map->empty_map[i]; i++)
			printf("%s\n", map->empty_map[i]);
		if (map->empty_map)
			free(map->empty_map);
		if (map)
			free(map);
	}
	else
	{
		while (i < ac)
		{
			if (!(map = ft_set_data(av[i])))
				ft_map_error();
			else
			{
				if (!ft_set_algo(map))
					return (0);
				//	printf("%u\n", map->line_nbr);
				printf("%c\n", map->empty);
				printf("%c\n", map->barrier);
				printf("%c\n", map->full);
				for (int i = 0; map->empty_map[i]; i++)
					printf("%s\n", map->empty_map[i]);
				if (map->empty_map)
					free(map->empty_map);
				if (map)
					free(map);
			}
			i++;
		}
	}
	return (0);
}
