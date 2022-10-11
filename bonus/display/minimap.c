/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:09:42 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/11 19:28:17 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	tile_final_pos(t_game *game, int x, int y)
{
	t_pos	dist;

	dist.x = (MINI_W / 20 - (game->player.x - x)) * TILE_SIZE + MINI_SIDE;
	dist.y = (MINI_H / 20 - (game->player.y - y)) * TILE_SIZE + MINI_SIDE;
	return (dist);
}

void	draw_minimap(t_game *game)
{
	int		x;
	int		y;
	t_pos	tile;

	y = 0;
	while (game->s_map[y])
	{
		x = 0;
		while (game->s_map[y][x])
		{
			if (game->s_map[y][x] == '1')
			{
				tile = tile_final_pos(game, x, y);
				little_square(game, WHITE, tile);
			}
			else if (game->s_map[y][x] == '0'
				|| is_personage(game->s_map[y][x]))
			{
				tile = tile_final_pos(game, x, y);
				little_square(game, PURPLE, tile);
			}
			else if (game->s_map[y][x] == 'M')
			{
				tile = tile_final_pos(game, x, y);
				little_square(game, RED, tile);
			}
			x++;
		}
		y++;
	}
}

void	init_mini_map(t_game *game)
{
	t_pos	pos;

	pos.x = MINI_W / 2 - 5 + MINI_SIDE;
	pos.y = MINI_H / 2 - 5 + MINI_SIDE;
	minimap_background(game);
	draw_minimap(game);
	little_square(game, RED, pos);
	ft_draw_line(game, game->ray.p_angle + M_PI / 4, pos, 25);
	ft_draw_line(game, game->ray.p_angle - M_PI / 4, pos, 25);
}
