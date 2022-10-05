/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:45:37 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/05 13:55:18 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	check_wall_vert(t_game *game, t_ray *ray, t_pos player)
{
	if (ray->step_x == 1)
		ray->ray_len = (floor(player.x + ray->step_x) - player.x)
			* ray->delta_x;
	else
		ray->ray_len = (player.x - floor(player.x)) * ray->delta_x;
	ray->tile.x = floor(player.x + ray->step_x);
	ray->tile.y = -sin(ray->ra) * ray->ray_len + player.y;
	while (10)
	{
		if (is_outside_map(ray->tile.x, ray->tile.y, game->s_map))
			return (ray->ray_len);
		if (is_wall(game, ray->tile.x, ray->tile.y))
			return (ray->ray_len);
		else
		{
			ray->tile.x += ray->step_x;
			ray->ray_len += ray->delta_x;
			ray->tile.y = -sin(ray->ra) * ray->ray_len + player.y;
		}
	}
	return (ray->ray_len);
}

double	check_wall_hor(t_game *game, t_ray *ray, t_pos player)
{
	if (ray->step_y == 1)
		ray->ray_len = (floor(player.y + ray->step_y) - player.y)
			* ray->delta_y;
	else
		ray->ray_len = (player.y - floor(player.y)) * ray->delta_y;
	ray->tile.x = cos(ray->ra) * ray->ray_len + player.x;
	ray->tile.y = floor(player.y + ray->step_y);
	while (10)
	{
		if (is_outside_map(ray->tile.x, ray->tile.y, game->s_map))
			return (ray->ray_len);
		if (is_wall(game, ray->tile.x, ray->tile.y))
			return (ray->ray_len);
		else
		{
			ray->tile.y += ray->step_y;
			ray->ray_len += ray->delta_y;
			ray->tile.x = cos(ray->ra) * ray->ray_len + player.x;
		}
	}
	return (ray->ray_len);
}

void	raycasting(t_game *game, t_ray *ray, t_pos player)
{
	double	small;
	double	horizontal;
	double	vertical;

	ray->pos_in_screen = 0;
	small = M_PI / 4;
	while (ray->pos_in_screen < WIN_W)
	{
		ray->ra = ray->p_angle + small;
		init_ray_values(ray);
		horizontal = check_wall_hor(game, ray, player);
		vertical = check_wall_vert(game, ray, player);
		if (horizontal < vertical)
		{
			ray->hor = 1;
			ray->ray_len = horizontal * cos(ray->ra - ray->p_angle);
		}
		else
			ray->ray_len = vertical * cos(ray->ra - ray->p_angle);
		print_ray(game, ray);
		small -= (M_PI / 2) / WIN_W;
		ray->pos_in_screen++;
	}
}
