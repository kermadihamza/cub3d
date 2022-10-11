/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_evil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:54:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/11 19:33:50 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_evil(t_game *game, t_pos player, t_pos evil)
{
	t_pos	pos;
	int		x = 0;
	int		y;
	double	dist_x;
	double	dist_y;
	double	angle;
	double	len;
	int		color;

	dist_x = evil.x - player.x;
	dist_y = evil.y - player.y;
	len = sqrtf(dist_x * dist_x + dist_y * dist_y);
	angle = (game->ray.p_angle - atan(dist_x / dist_y));
	while (x < game->sprite.evil.width * (WIN_H / len))
	{
		y = 0;
		while (y < game->sprite.evil.height * (WIN_H / len))
		{
			pos.x = x / (WIN_H / len);
			pos.y = y / (WIN_H / len);
	
				color = get_color(game->sprite.evil, pos);
				if (color)
					ft_mlx_pixel_put(&game->img, angle * (WIN_W / M_PI), WIN_H / 4, color);
			y++;
		}
		x++;
	}
}
