/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgrandje <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:19:16 by lgrandje          #+#    #+#             */
/*   Updated: 2020/09/30 20:11:28 by lgrandje         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		tracker(char** tab, int mapsize)
{
    int i;
    int j;
    int square;
	char** bigger_sqr;
	int si;
	int sj;

    i = 0;
    j = 0;
    square = 1;
    while(tab[i][j])
    {
		si = i;
    	while(i <= square && j <= square)
		{
			if (i == square && j < mapsize)
				j++;
			i++;
		}
		square++;
	}
	return (si);
}

int 	main()
{
	char** tab;
	tab[0] = "1355658";
	tab[1] = "1928457";
	tab[2] = "1807346";
	printf("%d", tracker(tab, 100));
}
