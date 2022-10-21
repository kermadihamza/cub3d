/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:02:26 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/20 21:58:53 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player_pos(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (is_personage(game->map[i]))
			game->player.pos = find_pos(game->map, i);
		i++;
	}
	if (game->player.dir == 'N')
		game->player.angle = M_PI / 2 + 0.01;
	else if (game->player.dir == 'S')
		game->player.angle = (3 * M_PI) / 2 + 0.01;
	else if (game->player.dir == 'E')
		game->player.angle = 0.01;
	else if (game->player.dir == 'W')
		game->player.angle = M_PI + 0.01;
	game->ray.adj_x = cos(game->player.angle) / 5;
	game->ray.adj_y = sin(game->player.angle) / 5;
	game->player.weapon_max = 1;
	game->key.third_p = 1;
	game->player.life = 3;
}
