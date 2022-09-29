/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:02:26 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/29 16:57:09 by lrondia          ###   ########.fr       */
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
	game->ray.p_angle = 0;
	game->ray.adj_x = cos(game->ray.p_angle);
	game->ray.adj_y = sin(game->ray.p_angle);
}
