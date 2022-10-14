/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_evil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:54:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/14 14:43:57 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_evil_values(t_game *game, t_img *evil)
{
	t_pos	dist;
	double	cosi = cos(game->ray.p_angle);
	double	sinu = -sin(game->ray.p_angle);
	
	dist.x = evil->pos.x - game->player.x;
	dist.y = evil->pos.y - game->player.y;
	evil->dist_player = hypot(dist.x, dist.y);
	evil->angle_from_player = atan2(dist.y, dist.x) - atan2(sinu, cosi);
	while (evil->angle_from_player > M_PI)
		evil->angle_from_player -= 2 * M_PI;
	while (evil->angle_from_player < -M_PI)
		evil->angle_from_player += 2 * M_PI;
}

t_pos	calculate_size_on_screen(t_img *evil)
{
	t_pos	size;
	
	size.y = WIN_W / evil->dist_player;
	size.x = size.y * (evil->width / evil->height);
	return (size);
}

double	calculate_x(t_img *evil)
{
	return (evil->angle_from_player + FOV / 2) / FOV * WIN_W;
}

t_pos	get_pos(t_pos pos, t_pos size, t_img *sprite)
{
	t_pos	final;

	final.x = pos.x / (size.x / sprite->width);
	final.y = pos.y / (size.y / sprite->height);
	return (final);
}

void	print_evil(t_game *game, t_img *sprite, t_pos origin, t_pos size)
{
	t_pos	pos;
	int		color;

	pos.y = 0;
	while (pos.y < size.y && pos.y + origin.y < WIN_H)
	{
		pos.x = 0;
		while (pos.x < size.x && pos.x + origin.x < WIN_W)
		{
			color = get_color(*sprite, get_pos(pos, size, sprite));
			if (color != NOT_PIXEL && color != STILL_NOT_PIXEL
				&& is_in_screen(pos.x + origin.x, pos.y + origin.y))
				ft_mlx_pixel_put(&game->img, pos.x + origin.x, pos.y + origin.y, color);
			pos.x++;
		}
		pos.y++;
	}
}

void	display_evil(t_game *game, t_img *evil)
{
	t_pos	origin;
	t_pos	size;

	init_evil_values(game, evil);
	size = calculate_size_on_screen(evil);
	origin.x = calculate_x(evil);
	origin.y = (WIN_H / 2) - (size.y / 2);
	print_evil(game, evil, origin, size);
}
