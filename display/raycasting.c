/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:45:37 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/30 12:05:28 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	check_wall_vert(t_game *game, t_ray *ray, t_pos player)
{
	int	dof;

	dof = 0;
	if (ray->step_x == 1)
		ray->ray_len = (floor(player.x + ray->step_x) - player.x) * ray->delta_x;
	else
		ray->ray_len = (player.x - floor(player.x)) * ray->delta_x;
	ray->tile.x = floor(player.x + ray->step_x);
	ray->tile.y = sin(ray->ra) * ray->ray_len + player.y;
	while (dof < 10)
	{
		if (is_outside_map(ray->tile.x, ray->tile.y, game->s_map))
			return (ray->ray_len);
		if (is_wall(game, ray->tile.x, ray->tile.y))
			dof = 10;
		else
		{
			ray->tile.x += ray->step_x;
			ray->ray_len += ray->delta_x;
			ray->tile.y = sin(ray->ra) * ray->ray_len + player.y;
		}
		dof ++;
	}
	return (ray->ray_len);
}

double	check_wall_hor(t_game *game, t_ray *ray, t_pos player)
{
	int	dof;

	dof = 0;
	if (ray->step_y == 1)
		ray->ray_len = (floor(player.y + ray->step_y) - player.y) * ray->delta_y;
	else
		ray->ray_len = (player.y - floor(player.y)) * ray->delta_y;
	ray->tile.x = cos(ray->ra) * ray->ray_len + player.x;
	ray->tile.y = floor(player.y + ray->step_y);
	while (dof < 10)
	{
		if (is_outside_map(ray->tile.x, ray->tile.y, game->s_map))
			return (ray->ray_len);
		if (is_wall(game, ray->tile.x, ray->tile.y))
			dof = 10;
		else
		{
			ray->tile.y += ray->step_y;
			ray->ray_len += ray->delta_y;
			ray->tile.x = cos(ray->ra) * ray->ray_len + player.x;
		}
		dof ++;
	}
	return (ray->ray_len);
}

void	ray_test(t_game *game, t_ray *ray, t_pos player)
{
	double	small;
	double	ray_hor;
	double	ray_vert;

	ray->pos_in_screen = 0;
	small = -(M_PI / 4);
	ray->ray_len = -1;
	while (ray->pos_in_screen < WIN_W)
	{
		ray->ra = ray->p_angle + small;
		if (ray->p_angle > 2 * M_PI)
			ray->p_angle -= 2 * M_PI;
		else if (ray->p_angle <= 0)
			ray->p_angle += 2 * M_PI;
		init_ray_values(ray, player);
		ray_hor = check_wall_hor(game, ray, player);
		ray_vert = check_wall_vert(game, ray, player);
		if (ray_hor <= ray_vert)
			ray->ray_len = ray_hor;
		else
			ray->ray_len = ray_vert;
		print_ray(game, ray);
		small += (M_PI / 2) / WIN_W;
		ray->pos_in_screen++;
	}
}
