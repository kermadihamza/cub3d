/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:09:42 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/17 16:41:24 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_pos	tile_final_pos(t_game *game, int x, int y)
{
	t_pos	dist;

	dist.x = (MINI_W / 20 - (game->player.pos.x - x)) * TILE_SIZE + MINI_SIDE;
	dist.y = (MINI_H / 20 - (game->player.pos.y - y)) * TILE_SIZE + MINI_SIDE;
	return (dist);
}

void	draw_minimap(t_game *game)
{
	int		x;
	int		y;

	y = 0;
	while (game->s_map[y])
	{
		x = 0;
		while (game->s_map[y][x])
		{
			if (game->s_map[y][x] == '1')
				little_square(game, ORANGE, tile_final_pos(game, x, y));
			else if (game->s_map[y][x] == '0' || game->s_map[y][x] == 'M'
				|| is_personage(game->s_map[y][x]))
				little_square(game, WHITE, tile_final_pos(game, x, y));
			else if (game->s_map[y][x] == 'P')
				little_square(game, VIOLET, tile_final_pos(game, x, y));
			x++;
		}
		y++;
	}
}

void	minimap(t_game *game)
{
	t_pos	pos;

	pos.x = MINI_W / 2 - 5 + MINI_SIDE;
	pos.y = MINI_H / 2 - 5 + MINI_SIDE;
	minimap_background(game);
	draw_minimap(game);
	// little_square(game, BLACK, pos);
	ft_draw_line(game, game->player.angle + game->fov / 2, pos, 25);
	ft_draw_line(game, game->player.angle - game->fov / 2, pos, 25);
}
