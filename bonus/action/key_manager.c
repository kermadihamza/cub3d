/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:41:55 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/20 20:16:26 by lrondia          ###   ########.fr       */
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

void	handle_weapon(t_player *p)
{
	if (p->cur_weapon < p->weapon_max)
		p->cur_weapon++;
	else
		p->cur_weapon = 0;
}

int	key_press(int code, t_game *game)
{
	if (code == 53)
		ft_destroy_all(game);
	if (code == 0)
		game->key.a = 1;
	if (code == 1 || code == 125)
		game->key.s = 1;
	if (code == 13 || code == 126)
		game->key.w = 1;
	if (code == 2)
		game->key.d = 1;
	if (code == 123)
		game->key.turn_l = 1;
	if (code == 124)
		game->key.turn_r = 1;
	if (code == 48 && game->key.third_p == 0)
		game->key.third_p = 1;
	else if (code == 48 && game->key.third_p == 1)
		game->key.third_p = 0;
	if (code == 14)
		handle_weapon(&game->player);
	if (code == 49 && game->player.attack == 0)
		game->player.attack = 1;
	// printf("%d\n", code);
	return (0);
}

int	key_release(int code, t_game *game)
{
	if (code == 0)
		game->key.a = 0;
	if (code == 1 || code == 125)
		game->key.s = 0;
	if (code == 13 || code == 126)
		game->key.w = 0;
	if (code == 2)
		game->key.d = 0;
	if (code == 123)
		game->key.turn_l = 0;
	if (code == 124)
		game->key.turn_r = 0;
	if (code == 49 && game->player.attack == 1)
		game->player.attack = 0;
	return (0);
}

void	third_person(t_game *game)
{
	if (game->key.third_p == 0)
		game->fov = M_PI / 3;
	else
		game->fov = M_PI / 2;
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

void	key_manager(t_game *game, t_ray *ray, t_key key)
{
	move(game, ray, key);
	third_person(game);
	action(game, &game->player, game->evil);
	angle_changes(game, ray);
}