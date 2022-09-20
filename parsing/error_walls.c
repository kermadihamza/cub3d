/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:49:53 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/20 13:51:10 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sides(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '0' || is_personage(map[i]))
		{
			if (map[i - 1] && (map[i - 1] == ' ' || map[i - 1] == '\n'))
				handle_errors(OPEN_WALL, map);
			else if ((map[i + 1] && (map[i + 1] == '\n'
						|| map[i + 1] == ' ')) || !map[i + 1])
				handle_errors(OPEN_WALL, map);
		}
		i++;
	}
}

void	check_coord(char **matric, int i, int j, char *map)
{
	if (i == 0 || !matric[i + 1] || !matric[i - 1][j] || !matric[i + 1][j])
		handle_errors(OPEN_WALL, map);
	else if (matric[i - 1][j] == ' ' || matric[i - 1][j] == '\n')
		handle_errors(OPEN_WALL, map);
	else if (matric[i + 1][j] == ' ' || matric[i + 1][j] == '\n')
		handle_errors(OPEN_WALL, map);
}

void	bottom(char *map)
{
	int		i;
	int		j;
	char	**matric;

	i = 0;
	matric = ft_split(map, '\n');
	while (matric[i])
	{
		j = 0;
		while (matric[i][j])
		{
			if (matric[i][j] == '0' || is_personage(matric[i][j]))
				check_coord(matric, i, j, map);
			j++;
		}
		i++;
	}
	free_split(matric);
}

void	holes_in_walls(char *map)
{
	sides(map);
	bottom(map);
}
