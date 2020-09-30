/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:39:20 by fgrea             #+#    #+#             */
/*   Updated: 2020/09/30 18:34:24 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

t_map	*ft_set_first_line(char *data)
{
	t_map	*map;
	char	*first_line;
	char	*ret;
	int		i;

	i = 0;
	while (data[i] && data[i] != '\n')
		i++;
	if (data[i] != '\n')
		return (0);
	if (!(first_line = (char *)malloc(sizeof(char) * (i))))
		return (0);
	ret = first_line;
	while (*data && *data != '\n')
		*first_line++ = *data++;
	*first_line = '\0';
	if (!(ft_check_first_line(ret)))
		return (0);
	if (!(map = ft_stocking_first_line(ret)))
		return (0);
	if (ret)
		free(ret);
	return (map);
}

t_map	*ft_treat_input(char *data)
{
	t_map	*map;
	int		i;

	i = 0;
	if (!(map = ft_set_first_line(data)))
		return (0);
	if (!(ft_check_map_lines(map, data)))
		return (0);
	if (!(map = ft_stocking_map_lines(map, data)))
		return (0);
	return (map);
}
