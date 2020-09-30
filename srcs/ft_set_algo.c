/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:18:42 by fgrea             #+#    #+#             */
/*   Updated: 2020/09/30 20:47:40 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int		ft_set_algo(t_map *map)
{
	t_sqr	*sqr;

	printf("set\n");
	if (!(sqr = ft_find_sqr(map)))
		return (0);
	printf("set\n");
	ft_show_completed_map(map, sqr);
	printf("set\n");
	return (1);
}
