/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_first_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:39:02 by fgrea             #+#    #+#             */
/*   Updated: 2020/09/30 00:35:05 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

int		ft_check_first_line(char *str)
{
	int	i;

	while (*str >= '0' && *str <= '9')
		str++;
	if (ft_strlen(str) != 3)
		return (0);
	while (*str)
	{
		if (*str < 32 || *str == 127)
			return (0);
		i = 1;
		while (str[i])
			if (*str == str[i++])
				return (0);
		str++;
	}
	return (1);
}
