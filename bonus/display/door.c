/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:35:38 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/25 14:28:20 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	find_color_in_door(t_door *door, double y, t_img sprite)
{
	t_pos	pos;
	double	expand_y;
	double	wall_min_y;

	expand_y = WIN_H / sprite.height;
	if (door->len_hor < door->len_vert)
		pos.x = door->tile_hor.x - floor(door->tile_hor.x);
	else
		pos.x = door->tile_vert.y - floor(door->tile_vert.y);
	pos.x *= sprite.height;
	wall_min_y = (WIN_H / 2) - (WIN_H / door->len) / 2;
	pos.y = ((y - wall_min_y) * door->len) / expand_y;
	return (get_color(sprite, pos));
}


void	print_door(t_game *game, t_door *door)
{
	int	y;
	int	color;
	double	rescale;

	y = 0;
	if (door->len_hor < door->len_vert)
		door->len = door->len_hor * cos (game->ray.ra - game->player.angle);
	else
		door->len = door->len_vert * cos(game->ray.ra - game->player.angle);
	if (door->len > game->ray.ray_len)
		return ;
	rescale = WIN_H / door->len;
	while (y < WIN_H)
	{
		color = find_color_in_door(door, y, game->sprite.door);
		if (y >= (WIN_H / 2) - (rescale / 2) && y <= (WIN_H / 2) + (rescale / 2)
			&& (color != NOT_PIXEL && color != STILL_NOT_PIXEL))
			ft_mlx_pixel_put(&game->img, game->ray.pos_in_screen, y, color);
		y++;
	}
	door->len_hor = 1000;
	door->len_vert = 1000;
}

void	display_door(t_game *game, t_evil *door)
{
	int		i;
	t_pos	origin;

	i = 0;
	while (i < game->nb_door)
	{
		init_evil_values(game, &game->door[i]);
		i++;
	}
	i = 0;
	while (i < game->nb_door)
	{
		origin.x = (door[i].angle_from_player + game->fov / 2) / game->fov * WIN_W;
		origin.y = (WIN_H / 2) - (door[i].scale.y / 2);
		print_evil(game, origin, door[i], game->sprite.door);
		i++;
	}
}
