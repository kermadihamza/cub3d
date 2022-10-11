/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:02:26 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/06 18:03:59 by lrondia          ###   ########.fr       */
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
			game->player = find_pos(game->map, i);
		i++;
	}
	if (game->player_dir == 'N')
		game->ray.p_angle = M_PI / 2 + 0.01;
	else if (game->player_dir == 'S')
		game->ray.p_angle = (3 * M_PI) / 2 + 0.01;
	else if (game->player_dir == 'E')
		game->ray.p_angle = 0.01;
	else if (game->player_dir == 'W')
		game->ray.p_angle = M_PI + 0.01;
	game->ray.adj_x = cos(game->ray.p_angle) / 5;
	game->ray.adj_y = sin(game->ray.p_angle) / 5;
}
