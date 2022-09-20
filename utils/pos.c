/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:30:23 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/20 16:48:51 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	find_pos(char *map, int i)
{
	int		j;
	int		count;
	t_pos	pos;

	j = i;
	count = 0;
	while (j >= 0)
	{
		if (map[j] == '\n')
			count++;
		if (map[j] == '\n' && count == 1)
			pos.x = i - j - 1;
		j--;
	}	
	pos.y = count;
	return (pos);
}

int	max_vert(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int	max_hor(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
		j++;
	return (j);
}
