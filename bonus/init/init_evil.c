/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_evil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:01:37 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/27 19:52:01 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_evil_pos(t_game *game)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (game->map[i])
	{
		if (game->map[i] == 'M')
			game->nb_evil++;
		i++;
	}
	i = 0;
	game->evil = malloc (sizeof(t_evil) * game->nb_evil);
	while (game->map[i] && n < game->nb_evil)
	{
		if (game->map[i] == 'M')
		{
			game->evil[n].pos = find_pos(game->map, i);
			game->evil[n].life = 3;
			n++;
		}
		i++;
	}
}

void	init_evil_values(t_game *game, t_evil *evil)
{
	t_pos	dist;
	double	cosi;
	double	sinu;

	cosi = cos(game->player.angle);
	sinu = -sin(game->player.angle);
	dist.x = evil->pos.x - game->player.pos.x;
	dist.y = evil->pos.y - game->player.pos.y;
	evil->dist_player_left = hypot(dist.x, dist.y);
	evil->dist_player_right = hypot(dist.x, dist.y);
	evil->angle_from_player = atan2(dist.y, dist.x) - atan2(sinu, cosi);
	while (evil->angle_from_player > M_PI)
		evil->angle_from_player -= 2 * M_PI;
	while (evil->angle_from_player < -M_PI)
		evil->angle_from_player += 2 * M_PI;
	evil->scale.y = WIN_W / evil->dist_player_left;
	evil->scale.x = evil->scale.y * (game->sprite.w / game->sprite.h);
}

t_pos	get_pos(t_pos pos, t_pos size, t_img sprite)
{
	t_pos	final;

	final.x = pos.x / (size.x / sprite.width);
	final.y = pos.y / (size.y / sprite.height);
	return (final);
}
