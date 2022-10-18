/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:06:33 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/17 15:07:10 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	max_vert(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i - 1);
}

int	max_hor(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
		j++;
	return (j);
}

int	is_outside_map(int x, int y, char **map)
{
	return (y < 0 || y > max_vert(map) || x < 0 || x > max_hor(map, y));
}

