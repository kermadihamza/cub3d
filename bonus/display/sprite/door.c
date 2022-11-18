/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:35:38 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/18 17:35:08 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_color_in_door(t_ray *ray, double y, t_img sprite)
{
	t_pos	pos;
	double	expand_y;
	double	wall_min_y;

	expand_y = WIN_H / sprite.height;
	if (is_hor_closer(ray->door_hor, ray->door_vert))
		pos.x = ray->door_tile_hor.x - floor(ray->door_tile_hor.x);
	else
		pos.x = ray->door_tile_vert.y - floor(ray->door_tile_vert.y);
	pos.x *= sprite.height;
	wall_min_y = (WIN_H / 2) - (WIN_H / ray->door) / 2;
	pos.y = ((y - wall_min_y) * ray->door) / expand_y;
	return (get_color(sprite, pos));
}

void	door_time(t_game *game, t_door *door)
{
	int	i;

	i = 0;
	while (i < game->nb_door)
	{
		if (door[i].time < 4 * SPEED && door[i].open && door[i].dist_p < 3)
			door[i].time++;
		else if (door[i].time > 0 && !door[i].open && door[i].dist_p < 3)
			door[i].time--;
		i++;
	}
}

static int	choose_sprite(t_game *game, t_ray *ray, t_door *door)
{
	int	i;

	i = 0;
	while (i < game->nb_door)
	{
		if (is_same_tile(door[i].pos, ray->door_tile))
			break ;
		i++;
	}
	if (door[i].time / SPEED < 4)
		return (door[i].time / SPEED);
	else
		return (3);
}

void	print_door_loop(t_game *game, t_ray *ray, t_door *door)
{
	int		y;
	int		cs;
	int		color;
	double	rescale;

	y = 0;
	cs = 0;
	rescale = WIN_H / ray->door;
	while (y < WIN_H)
	{
		cs = choose_sprite(game, ray, door);
			color = find_color_in_door(ray, y, game->sprite.door[cs]);
		if (y >= (WIN_H / 2) - (rescale / 2) && y <= (WIN_H / 2) + (rescale / 2)
			&& (color != NOT_PIXEL && color != STILL_NOT_PIXEL))
			ft_mlx_pixel_put(&game->img, ray->pos_in_screen, y, color);
		y++;
	}
}

void	print_door(t_game *game, t_ray *ray, t_door *door)
{
	if (is_hor_closer(ray->door_hor, ray->door_vert))
	{
		ray->door = ray->door_hor * cos(ray->ra - game->player.angle);
		ray->door_tile = ray->door_tile_hor;
	}
	else
	{
		ray->door = ray->door_vert * cos(ray->ra - game->player.angle);
		ray->door_tile = ray->door_tile_vert;
	}
	if (ray->door > ray->ray_len)
	{
		door_re_init(ray);
		return ;
	}
	print_door_loop(game, ray, door);
	door_re_init(ray);
}
