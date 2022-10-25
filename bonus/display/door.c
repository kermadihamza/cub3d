/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:35:38 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/25 22:02:47 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_hor_closer(double hor, double vert)
{
	return ((hor < vert && hor != -1 && vert != -1) || vert == -1);
}

int	find_color_in_door(t_door *door, double y, t_img sprite)
{
	t_pos	pos;
	double	expand_y;
	double	wall_min_y;

	expand_y = WIN_H / sprite.height;
	if (is_hor_closer(door->len_hor, door->len_vert))
		pos.x = door->tile_hor.x - floor(door->tile_hor.x);
	else
		pos.x = door->tile_vert.y - floor(door->tile_vert.y);
	pos.x *= sprite.height;
	wall_min_y = (WIN_H / 2) - (WIN_H / door->len) / 2;
	pos.y = ((y - wall_min_y) * door->len) / expand_y;
	return (get_color(sprite, pos));
}

static int	choose_sprite(t_door *door)
{
	// printf("door : %d\n", door->time);
	if (door->time / SPEEDI < 4)
		return (door->time / SPEEDI);
	else
		return (3);
}

void	door_time(t_door *door)
{
	if (door->time <= 4 * SPEEDI)
		door->time++;
	if (door->time >= 4 * SPEEDI)
		door->open = 0;
}

void	print_door(t_game *game, t_door *door)
{
	int	y;
	int	cs;
	int	color;
	double	rescale;

	y = 0;
	if (is_hor_closer(door->len_hor, door->len_vert))
		door->len = door->len_hor * cos (game->ray.ra - game->player.angle);
	else
		door->len = door->len_vert * cos(game->ray.ra - game->player.angle);
	if (door->len > game->ray.ray_len)
		return ;
	cs = 0;
	rescale = WIN_H / door->len;
	while (y < WIN_H)
	{
		cs = choose_sprite(door);
		color = find_color_in_door(door, y, game->sprite.door[cs]);
		if (y >= (WIN_H / 2) - (rescale / 2) && y <= (WIN_H / 2) + (rescale / 2)
			&& (color != NOT_PIXEL && color != STILL_NOT_PIXEL))
			ft_mlx_pixel_put(&game->img, game->ray.pos_in_screen, y, color);
		y++;
	}
	door->len_hor = -1;
	door->len_vert = -1;
}
