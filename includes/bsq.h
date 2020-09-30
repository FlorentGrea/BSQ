/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgrea <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:45:55 by fgrea             #+#    #+#             */
/*   Updated: 2020/09/30 20:21:11 by fgrea            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFF_SIZE 2048

typedef unsigned int	t_ui;

typedef struct	s_map
{
	unsigned int	line_nbr;
	char			empty;
	char			barrier;
	char			full;
	char			**empty_map;

}				t_map;

typedef struct	s_sqr
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	line;

}				t_sqr;

/*
** main functions
*/

int				ft_set_algo(t_map *map);
t_map			*ft_treat_input(char *data);
t_map			*ft_set_data(char *input);

/*
** stocking functions
*/

t_sqr			*ft_find_sqr(t_map *map);
t_map			*ft_stocking_first_line(char *str);
t_map			*ft_stocking_map_lines(t_map *map, char *data);

/*
** reading functions
*/

char			*ft_read_input(int fd);

/*
** error checking functions
*/

int				ft_check_first_line(char *str);
int				ft_check_map_lines(t_map *map, char *data);

/*
** utility functions
*/

void			ft_show_completed_map(t_map *map, t_sqr *sqr);
t_sqr			*ft_alloc_sqr(void);
void			ft_putstr(char *str);
int				ft_strlen(char *str);
char			*ft_strcat(char *dest, char *src); 

/*
** error return functions
*/

int				ft_map_error(void);

#endif
