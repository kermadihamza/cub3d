/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:49:53 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/18 18:30:27 by lrondia          ###   ########.fr       */
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

void	check_coord(t_game *game, int y, int x)
{
	if (y == 0 || !game->s_map[y + 1]
		|| !game->s_map[y - 1][x] || !game->s_map[y + 1][x])
		handle_errors(game, OPEN_WALL, game->map);
	else if (game->s_map[y - 1][x] == ' ' || game->s_map[y - 1][x] == '\n')
		handle_errors(game, OPEN_WALL, game->s_map[y]);
	else if (game->s_map[y + 1][x] == ' ' || game->s_map[y + 1][x] == '\n')
		handle_errors(game, OPEN_WALL, game->s_map[y]);
	else if (x > max_hor(game->s_map, y + 1)
		|| (game->s_map[y - 1] && x > max_hor(game->s_map, y - 1)))
		handle_errors(game, OPEN_WALL, game->s_map[y]);
}

void	bottom(t_game *game, char **map)
{
	int		y;
	int		x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0' || is_personage(map[y][x]))
				check_coord(game, y, x);
			x++;
		}
		y++;
	}
}

void	new_line_and_open_map(t_game *game, char *map)
{
	int	i;
	int	n;

	i = 0;
	while (map[i])
	{
		n = i;
		while ((map[i] == '0' || is_personage(map[i])) && map[n])
		{
			n++;
			if (map[n] == '\n' && map[n + 1] && map[n + 1] == '\n')
				handle_errors(game, OPEN_WALL, map);
			else if (map[n] == '\n' && map[n + 1] && map[n + 1] != '\n')
				break ;
		}
		i++;
	}
}

void	holes_in_walls(t_game *game, char *map)
{
	sides(game, map);
	bottom(game, game->s_map);
	new_line_and_open_map(game, map);
}
