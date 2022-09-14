/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:51:29 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/14 12:44:08 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	angle_changes(int code, t_ray *ray)
{
	if (code == 123)
	{
		ray->p_angle -= 0.1;
		if (ray->p_angle < 0)
			ray->p_angle += 2*PI;
		ray->delta_x = cos(ray->p_angle);
		ray->delta_y = sin(ray->p_angle);
	}
	if (code == 124)
	{
		ray->p_angle += 0.1;
		if (ray->p_angle > 2*PI)
			ray->p_angle -= 2*PI;
		ray->delta_x = cos(ray->p_angle);
		ray->delta_y = sin(ray->p_angle);
	}
}

int	key_press(int code, t_game *game)
{
	if (code == 53)
		exit (EXIT_SUCCESS);
	if (code == 0)
		game->key.a = 1;
	if (code == 1)
		game->key.s = 1;
	if (code == 13)
		game->key.w = 1;
	if (code == 2)
		game->key.d = 1;
	angle_changes(code, &game->ray);
	return (0);
}

int	key_release(int code, t_key *key)
{
	if (code == 0)
		key->a = 0;
	if (code == 1)
		key->s = 0;
	if (code == 13)
		key->w = 0;
	if (code == 2)
		key->d = 0;
	return (0);
}

void	key_manager(t_game *game, t_key key)
{
	if (key.a == 1)
		game->player.x -= 0.1;
	if (key.s == 1)
		game->player.y += 0.1;
	if (key.w == 1)
		game->player.y -= 0.1;
	if (key.d == 1)
		game->player.x += 0.1;
}

int	display(t_game *game)
{
	key_manager(game, game->key);
	init_mini_map(game);
	return (0);
}
