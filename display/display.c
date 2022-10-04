/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:51:29 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/04 19:59:03 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	angle_changes(int code, t_ray *ray)
{
	if (code == 123)
	{
		ray->p_angle += 0.1;
		if (ray->p_angle > 2 * M_PI)
			ray->p_angle -= 2 * M_PI;
		ray->adj_x = cos(ray->p_angle);
		ray->adj_y = sin(ray->p_angle);
	}
	if (code == 124)
	{
		ray->p_angle -= 0.1;
		if (ray->p_angle <= 0)
			ray->p_angle += 2 * M_PI;
		ray->adj_x = cos(ray->p_angle);
		ray->adj_y = sin(ray->p_angle);
	}
}

int	key_press(int code, t_game *game)
{
	if (code == 53)
		exit (EXIT_SUCCESS);
	if (code == 0)
		game->key.a = 1;
	if (code == 1 || code == 125)
		game->key.s = 1;
	if (code == 13 || code == 126)
		game->key.w = 1;
	if (code == 2)
		game->key.d = 1;
	angle_changes(code, &game->ray);
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
	return (0);
}

void	key_manager(t_game *game, t_ray *ray, t_key key)
{
	double	side_x;
	double	side_y;

	side_x = cos(ray->p_angle + (M_PI / 2)) / 5;
	side_y = sin(ray->p_angle + (M_PI / 2)) / 5;
	if (key.a == 1 && !is_wall(game, game->player.x + side_x, game->player.y - side_y))
	{
		game->player.x += side_x;
		game->player.y -= side_y;
	}
	if (key.s == 1 && !is_wall(game, game->player.x - ray->adj_x / 5, game->player.y + ray->adj_y / 5))
	{
		game->player.x -= ray->adj_x / 5;
		game->player.y += ray->adj_y / 5;
	}
	if (key.w == 1 && !is_wall(game, game->player.x + ray->adj_x / 5, game->player.y - ray->adj_y / 5))
	{
		game->player.x += ray->adj_x / 5;
		game->player.y -= ray->adj_y / 5;
	}
	if (key.d == 1 && !is_wall(game, game->player.x - side_x, game->player.y + side_y))
	{
		game->player.x -= side_x;
		game->player.y += side_y;
	}
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
