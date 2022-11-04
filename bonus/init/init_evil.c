/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_evil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:01:37 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/04 16:09:46 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	protection_wall(t_game *game, t_evil *evil, char **map)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] && i < game->nb_evil)
		{
			if (map[y][x] == 'M')
			{
				if (map[y][x - 1] && map[y][x - 1] == '1')
					add_new_pos(&evil[i].pos, 1, 0);
				if (map[y - 1][x] && map[y - 1][x] == '1')
					add_new_pos(&evil[i].pos, 0, 1);
				i++;
			}
			x++;
		}
		y++;
	}
}

void	init_evil_pos(t_game *game)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	game->nb_evil = how_many('M', game->map);
	game->evil = malloc (sizeof(t_evil) * game->nb_evil);
	while (game->map[i] && n < game->nb_evil)
	{
		if (game->map[i] == 'M')
		{
			game->evil[n].pos = find_pos(game->map, i);
			game->evil[n].life = 5;
			game->evil[n].time = 0;
			n++;
		}
		i++;
	}
	protection_wall(game, game->evil, game->s_map);
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
	evil->dist_p = hypot(dist.x, dist.y);
	evil->p_angle = atan2(dist.y, dist.x) - atan2(sinu, cosi);
	while (evil->p_angle > M_PI)
		evil->p_angle -= 2 * M_PI;
	while (evil->p_angle < -M_PI)
		evil->p_angle += 2 * M_PI;
	evil->scale.y = WIN_W / evil->dist_p;
	evil->scale.x = evil->scale.y * (game->sprite.w / game->sprite.h);
}

t_pos	get_pos(t_pos pos, t_pos size, t_img sprite)
{
	t_pos	final;

	final.x = pos.x / (size.x / sprite.width);
	final.y = pos.y / (size.y / sprite.height);
	return (final);
}
