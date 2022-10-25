/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:45:37 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/25 18:07:48 by lrondia          ###   ########.fr       */
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
	ray->tile_vert.x = floor(player.x + ray->step_x);
	ray->tile_vert.y = -sin(ray->ra) * ray->ray_len + player.y;
	while (!is_outside_map(ray->tile_vert.x, ray->tile_vert.y, game->s_map))
	{
		if (is_door(game, ray->tile_vert.x, ray->tile_vert.y) && game->door_f.len_vert == -1)
		{
			game->door_f.tile_vert = posi(ray->tile_vert.x, ray->tile_vert.y);
			game->door_f.len_vert = ray->ray_len;
		}
		if (is_wall(game, ray->tile_vert.x, ray->tile_vert.y))
			return (ray->ray_len);
		else
		{
			ray->tile_vert.x += ray->step_x;
			ray->ray_len += ray->delta_x;
			ray->tile_vert.y = -sin(ray->ra) * ray->ray_len + player.y;
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
	ray->tile_hor.x = cos(ray->ra) * ray->ray_len + player.x;
	ray->tile_hor.y = floor(player.y + ray->step_y);
	while (!is_outside_map(ray->tile_hor.x, ray->tile_hor.y, game->s_map))
	{
		if (is_door(game, ray->tile_hor.x, ray->tile_hor.y) && game->door_f.len_hor == -1)
		{
			game->door_f.tile_hor = posi(ray->tile_hor.x, ray->tile_hor.y);
			game->door_f.len_hor = ray->ray_len;
		}
		if (is_wall(game, ray->tile_hor.x, ray->tile_hor.y))
			return (ray->ray_len);
		else
		{
			ray->tile_hor.y += ray->step_y;
			ray->ray_len += ray->delta_y;
			ray->tile_hor.x = cos(ray->ra) * ray->ray_len + player.x;
		}
	}
	return (ray->ray_len);
}

void	longuest_ray(t_game *game, t_ray *ray, double horizontal, double vertical)
{
	double	len;
	double	a;

	a = ray->ra - game->player.angle;
	len = 1 / cos(a);
	if (horizontal < vertical)
	{
		ray->hor = 1;
		ray->ray_len = horizontal * cos(a);
	}
	else
		ray->ray_len = vertical * cos(a);
}

void	raycasting(t_game *game, t_ray *ray, t_pos player)
{
	double	small;
	double	horizontal;
	double	vertical;

	ray->pos_in_screen = 0;
	small = game->fov / 2;
	while (ray->pos_in_screen < WIN_W)
	{
		ray->ra = game->player.angle + atan(small);
		init_ray_values(ray);
		horizontal = check_wall_hor(game, ray, player);
		vertical = check_wall_vert(game, ray, player);
		longuest_ray(game, ray, horizontal, vertical);
		print_ray(game, ray);
		small -= game->fov / WIN_W;
		ray->pos_in_screen++;
	}
}
