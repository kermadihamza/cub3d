/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:51:29 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/05 15:46:25 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	angle_changes(t_game *game, t_ray *ray)
{
	if (game->key.turn_l == 1)
	{
		ray->p_angle += 0.1;
		if (ray->p_angle > 2 * M_PI)
			ray->p_angle -= 2 * M_PI;
		ray->adj_x = cos(ray->p_angle) / 5;
		ray->adj_y = sin(ray->p_angle) / 5;
	}
	if (game->key.turn_r == 1)
	{
		ray->p_angle -= 0.1;
		if (ray->p_angle <= 0)
			ray->p_angle += 2 * M_PI;
		ray->adj_x = cos(ray->p_angle) / 5;
		ray->adj_y = sin(ray->p_angle) / 5;
	}
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
	return (0);
}

void	key_manager(t_game *game, t_ray *ray, t_key key)
{
	double	side_x;
	double	side_y;

	side_x = cos(ray->p_angle + (M_PI / 2)) / 5;
	side_y = sin(ray->p_angle + (M_PI / 2)) / 5;
	if (key.a == 1 && !is_wall(game, game->player.x + side_x,
			game->player.y - side_y))
		add_new_pos(&game->player, side_x, -side_y);
	if (key.s == 1 && !is_wall(game, game->player.x - ray->adj_x,
			game->player.y + ray->adj_y))
		add_new_pos(&game->player, -ray->adj_x, ray->adj_y);
	if (key.w == 1 && !is_wall(game, game->player.x + ray->adj_x,
			game->player.y - ray->adj_y))
		add_new_pos(&game->player, ray->adj_x, -ray->adj_y);
	if (key.d == 1 && !is_wall(game, game->player.x - side_x,
			game->player.y + side_y))
		add_new_pos(&game->player, -side_x, side_y);
	angle_changes(game, ray);
}

int	display(t_game *game)
{
	init_color_sprite(game);
	key_manager(game, &game->ray, game->key);
	raycasting(game, &game->ray, game->player);
	init_mini_map(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
