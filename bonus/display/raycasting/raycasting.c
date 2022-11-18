/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:45:37 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/18 17:43:28 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	check_wall_vert(t_game *g, t_ray *ray, t_pos player)
{
	if (ray->step_x == 1)
		ray->ray_len = (floor(player.x + ray->step_x) - player.x)
			* ray->delta_x;
	else
		ray->ray_len = (player.x - floor(player.x)) * ray->delta_x;
	ray->tile_vert.x = floor(player.x + ray->step_x);
	ray->tile_vert.y = -sin(ray->ra) * ray->ray_len + player.y;
	while (!is_outside_map(ray->tile_vert.x, ray->tile_vert.y, g->s_map))
	{
		if (is_door(g, ray->tile_vert.x, ray->tile_vert.y)
			&& !ray->door_vert)
		{
			ray->door_tile_vert = posi(ray->tile_vert.x, ray->tile_vert.y);
			ray->door_vert = ray->ray_len;
		}
		if (is_wall(g, ray->tile_vert.x, ray->tile_vert.y))
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

double	check_wall_hor(t_game *g, t_ray *ray, t_pos player)
{
	if (ray->step_y == 1)
		ray->ray_len = (floor(player.y + ray->step_y) - player.y)
			* ray->delta_y;
	else
		ray->ray_len = (player.y - floor(player.y)) * ray->delta_y;
	ray->tile_hor.x = cos(ray->ra) * ray->ray_len + player.x;
	ray->tile_hor.y = floor(player.y + ray->step_y);
	while (!is_outside_map(ray->tile_hor.x, ray->tile_hor.y, g->s_map))
	{
		if (is_door(g, ray->tile_vert.x, ray->tile_vert.y)
			&& !ray->door_hor)
		{
			ray->door_tile_hor = posi(ray->tile_vert.x, ray->tile_vert.y);
			ray->door_hor = ray->ray_len;
		}
		if (is_wall(g, ray->tile_hor.x, ray->tile_hor.y))
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

void	longuest_ray(t_game *g, t_ray *ray, double hor, double vert)
{
	double	a;

	a = ray->ra - g->player.angle;
	if (hor < vert)
	{
		ray->hor = 1;
		ray->ray_len = hor * cos(a);
	}
	else
		ray->ray_len = vert * cos(a);
}

void	raycasting(t_game *g, t_ray *ray, int start, int end)
{
	double	small;
	double	horizontal;
	double	vertical;

	small = (g->fov / 2) - (g->fov / WIN_W) * start;
	while (start < end)
	{
		ray->pos_in_screen = start;
		ray->ra = g->player.angle + atan(small);
		init_ray_values(ray);
		horizontal = check_wall_hor(g, ray, g->player.pos);
		vertical = check_wall_vert(g, ray, g->player.pos);
		longuest_ray(g, ray, horizontal, vertical);
		g->ray_dist[start] = ray->ray_len / cos(ray->ra - g->player.angle);
		if ((ray->door_hor <= ray->door_vert && ray->door_hor && ray->door_vert)
			|| (!ray->door_vert && ray->door_hor))
			g->door_dist[start] = ray->door_hor;
		if ((ray->door_vert < ray->door_hor && ray->door_vert && ray->door_hor)
			|| (!ray->door_hor && ray->door_vert))
			g->door_dist[start] = ray->door_vert;
		print_ray(g, ray);
		small -= g->fov / WIN_W;
		start ++;
	}
}
