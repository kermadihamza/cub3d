/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:57:23 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/17 16:53:48 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_in_screen(double x, double y)
{
	return (x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H);
}

int	is_wall(t_game *game, int x, int y)
{
	if (!is_outside_map(x, y, game->s_map) && game->s_map[y][x]
		&& game->s_map[y][x] == '1')
		return (1);
	return (0);
}

int	is_north(double ray)
{
	while (ray >= 2 * M_PI)
		ray -= 2 * M_PI;
	while (ray < 0)
		ray += 2 * M_PI;
	if (ray > 0 && ray <= M_PI)
		return (1);
	else
		return (0);
}

int	is_west(double ray)
{
	while (ray >= 2 * M_PI)
		ray -= 2 * M_PI;
	while (ray < 0)
		ray += 2 * M_PI;
	if (ray > M_PI / 2 && ray <= (3 * M_PI) / 2)
		return (1);
	else
		return (0);
}
