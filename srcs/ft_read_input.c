/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:15:48 by fgrea             #+#    #+#             */
/*   Updated: 2020/09/30 20:16:45 by fgrea            ###   ########lyon.fr   */
/*   Updated: 2020/09/30 20:11:34 by lgrandje         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <bsq.h>

char	*ft_realloc(char *ret)
{
	char	*next;
	char	*rendu;

	if (!(next = (char *)malloc(sizeof(char) * (ft_strlen(ret) + BUFF_SIZE + 1))))
		return (0);
	rendu = next;
	while (*ret)
		*next++ = *ret++;
	*next = '\0';
	return (rendu);
}

char	*ft_read_input(int fd)
{
	char	stocking[BUFF_SIZE + 1];
	char	*ret;
	int		len;

	if (!(ret = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (0);
	while ((len = read(fd, stocking, BUFF_SIZE)) > 0)
	{
		stocking[len] = '\0';
		ret = ft_strcat(ret, stocking);
			if (!(ret = ft_realloc(ret)))
				return (0);
	}
	if (len == -1)
		return (0);
	return (ret);
}
