/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:49:53 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/14 17:43:05 by hakermad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sides(t_game *game, char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '0' || is_personage(map[i])
			|| map[i] == 'P' || map[i] == 'M')
		{
			if (map[i - 1] && (map[i - 1] == ' ' || map[i - 1] == '\n'))
				handle_errors(game, OPEN_WALL, map);
			else if ((map[i + 1] && (map[i + 1] == '\n'
				|| map[i + 1] == ' ')) || !map[i + 1])
				handle_errors(game, OPEN_WALL, map);
		}
		i++;
	}
}

void	check_coord(t_game *game, int i, int j, char *map)
{
	if (i == 0 || !game->s_map[i + 1]
		|| !game->s_map[i - 1][j] || !game->s_map[i + 1][j])
		handle_errors(game, OPEN_WALL, map);
	else if (game->s_map[i - 1][j] == ' ' || game->s_map[i - 1][j] == '\n')
		handle_errors(game, OPEN_WALL, map);
	else if (game->s_map[i + 1][j] == ' ' || game->s_map[i + 1][j] == '\n')
		handle_errors(game, OPEN_WALL, map);
}

void	bottom(t_game *game, char *map)
{
	int		i;
	int		j;

	i = 0;
	while (game->s_map[i])
	{
		j = 0;
		while (game->s_map[i][j])
		{
			if (game->s_map[i][j] == '0' || is_personage(game->s_map[i][j]))
				check_coord(game, i, j, map);
			j++;
		}
		i++;
	}
}

void	holes_in_walls(t_game *game, char *map)
{
	sides(game, map);
	bottom(game, map);
}
