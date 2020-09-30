/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:49:14 by fgrea             #+#    #+#             */
/*   Updated: 2020/09/30 20:16:58 by fgrea            ###   ########lyon.fr   */
/*   Updated: 2020/09/30 18:25:58 by lgrandje         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

t_map	*ft_set_data(char *input)
{
	t_map	*map;
	char	*data;
	int		fd;

	fd = 0;
	if (!input)
	{
		if (!(data = ft_read_input(fd)))
			return (0);
	}
	else
	{
		if ((fd = open(input, O_RDONLY)) == -1)
			return (0);
		if (!(data = ft_read_input(fd)))
			return (0);
		if (close(fd) == -1)
			return (0);
	}
	if (!(map = ft_treat_input(data)))
		return (0);
	if (data)
		free(data);
	return (map);
}
