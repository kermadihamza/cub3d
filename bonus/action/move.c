/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:15:04 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/25 21:22:52 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	angle_changes(t_game *game, t_ray *ray)
{
	if (game->key.turn_l == 1)
	{
		game->player.angle += 0.1;
		if (game->player.angle > 2 * M_PI)
			game->player.angle -= 2 * M_PI;
		ray->adj_x = cos(game->player.angle) / 5;
		ray->adj_y = sin(game->player.angle) / 5;
	}
	if (game->key.turn_r == 1)
	{
		game->player.angle -= 0.1;
		if (game->player.angle <= 0)
			game->player.angle += 2 * M_PI;
		ray->adj_x = cos(game->player.angle) / 5;
		ray->adj_y = sin(game->player.angle) / 5;
	}
}

void	move(t_game *game, t_ray *ray, t_key key)
{
	double	side_x;
	double	side_y;

	side_x = cos(game->player.angle + (M_PI / 2)) / 5;
	side_y = sin(game->player.angle + (M_PI / 2)) / 5;
	
	if (key.a == 1 && !is_wall(game, game->player.pos.x + side_x,
			game->player.pos.y - side_y))
		add_new_pos(&game->player.pos, side_x, -side_y);
	if (key.s == 1 && !is_wall(game, game->player.pos.x - ray->adj_x,
			game->player.pos.y + ray->adj_y))
		add_new_pos(&game->player.pos, -ray->adj_x, ray->adj_y);
	if (key.w == 1 && !is_wall(game, game->player.pos.x + ray->adj_x,
			game->player.pos.y - ray->adj_y))
		add_new_pos(&game->player.pos, ray->adj_x, -ray->adj_y);
	if (key.d == 1 && !is_wall(game, game->player.pos.x - side_x,
			game->player.pos.y + side_y))
		add_new_pos(&game->player.pos, -side_x, side_y);
}
