/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:15:04 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/14 16:51:43 by hakermad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	angle_changes(t_game *game)
{
	if (game->key.turn_l == 1)
	{
		game->player.angle += 0.1;
		if (game->player.angle > 2 * M_PI)
			game->player.angle -= 2 * M_PI;
		game->player.adj_x = cos(game->player.angle) / 5;
		game->player.adj_y = sin(game->player.angle) / 5;
	}
	if (game->key.turn_r == 1)
	{
		game->player.angle -= 0.1;
		if (game->player.angle <= 0)
			game->player.angle += 2 * M_PI;
		game->player.adj_x = cos(game->player.angle) / 5;
		game->player.adj_y = sin(game->player.angle) / 5;
	}
}

int	can_go(t_game *game, t_pos start, double side_x, double side_y)
{
	int		i;
	t_pos	pos;

	i = 0;
	side_x *= 2;
	side_y *= 2;
	pos = posi(start.x + side_x, start.y + side_y);
	while (i < game->nb_door)
	{
		if (is_same_tile(game->door[i].pos, pos))
			break ;
		i++;
	}
	if (!is_wall(game, pos.x, pos.y) && (!is_door(game, pos.x, pos.y)
			|| (is_door(game, pos.x, pos.y) && game->door[i].time > 2 * SPEED)))
		return (1);
	return (0);
}

void	move(t_game *game, t_player *p, t_key key)
{
	int		i;
	double	side_x;
	double	side_y;
	t_pos	dist;

	i = 0;
	side_x = cos(p->angle + (M_PI / 2)) / 5;
	side_y = sin(p->angle + (M_PI / 2)) / 5;
	if (key.a == 1 && can_go(game, p->pos, side_x, -side_y))
		add_new_pos(&p->pos, side_x, -side_y);
	if (key.s == 1 && can_go(game, p->pos, -p->adj_x, p->adj_y))
		add_new_pos(&p->pos, -p->adj_x, p->adj_y);
	if (key.w == 1 && can_go(game, p->pos, p->adj_x, -p->adj_y))
		add_new_pos(&p->pos, p->adj_x, -p->adj_y);
	if (key.d == 1 && can_go(game, p->pos, -side_x, side_y))
		add_new_pos(&p->pos, -side_x, side_y);
	while (i < game->nb_door)
	{
		dist.x = game->door[i].pos.x - p->pos.x;
		dist.y = game->door[i].pos.y - p->pos.y;
		game->door[i].dist_p = hypot(dist.x, dist.y);
		i++;
	}
}
