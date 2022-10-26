/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:15:04 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/26 20:55:25 by lrondia          ###   ########.fr       */
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

int	can_go(t_game *game, double side_x, double side_y)
{
	t_pos	pos;
	int	i;

	i = 0;
	pos = posi(game->player.pos.x + side_x, game->player.pos.y + side_y);
	while (i < game->nb_door)
	{
		if (is_same_tile(game->door[i].pos, pos))
			break;
		i++;
	}
	if (!is_wall(game, pos.x, pos.y) && (!is_door(game, pos.x, pos.y)
	|| (is_door(game, pos.x, pos.y) && game->door[i].time > 2 * SPEEDI)))
		return (1);
	return (0);
}

void	move(t_game *game, t_ray *ray, t_key key)
{
	int		i;
	double	side_x;
	double	side_y;
	t_pos	dist;

	i = 0;
	side_x = cos(game->player.angle + (M_PI / 2)) / 5;
	side_y = sin(game->player.angle + (M_PI / 2)) / 5;
	if (key.a == 1 && can_go(game, side_x, -side_y))
		add_new_pos(&game->player.pos, side_x, -side_y);
	if (key.s == 1 && can_go(game, -ray->adj_x, side_y))
		add_new_pos(&game->player.pos, -ray->adj_x, ray->adj_y);
	if (key.w == 1 && can_go(game, side_x, -ray->adj_y))
		add_new_pos(&game->player.pos, ray->adj_x, -ray->adj_y);
	if (key.d == 1 && can_go(game, -side_x, side_y))
		add_new_pos(&game->player.pos, -side_x, side_y);
	while (i < game->nb_door)
	{
		dist.x = game->door[i].pos.x - game->player.pos.x;
		dist.y = game->door[i].pos.y - game->player.pos.y;
		game->door[i].dist_p = hypot(dist.x, dist.y);
		i++;
	}
}
