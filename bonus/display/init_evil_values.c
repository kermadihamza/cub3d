/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_evil_values.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:01:37 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/18 12:25:04 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_evil_values(t_game *game, t_evil *evil)
{
	t_pos	dist;
	double	cosi = cos(game->ray.p_angle);
	double	sinu = -sin(game->ray.p_angle);
	
	dist.x = evil->pos.x - game->player.x;
	dist.y = evil->pos.y - game->player.y;
	evil->dist_player_left = hypot(dist.x, dist.y);
	evil->dist_player_right = hypot(dist.x + 1, dist.y);
	evil->angle_from_player = atan2(dist.y, dist.x) - atan2(sinu, cosi);
	while (evil->angle_from_player > M_PI)
		evil->angle_from_player -= 2 * M_PI;
	while (evil->angle_from_player < -M_PI)
		evil->angle_from_player += 2 * M_PI;
}

t_pos	calculate_size_on_screen(t_evil evil, t_img	evil_sprite)
{
	t_pos	size;
	
	size.y = WIN_W / evil.dist_player_left;
	size.x = size.y * (evil_sprite.width / evil_sprite.height);
	return (size);
}

t_pos	get_pos(t_pos pos, t_pos size, t_img sprite)
{
	t_pos	final;

	final.x = pos.x / (size.x / sprite.width);
	final.y = pos.y / (size.y / sprite.height);
	return (final);
}
