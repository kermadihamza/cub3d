/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 12:24:51 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/21 12:31:18 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_door_pos(t_game *game)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (game->map[i])
	{
		if (game->map[i] == 'P')
			game->nb_door++;
		i++;
	}
	i = 0;
	game->door = malloc (sizeof(t_door) * game->nb_door);
	while (game->map[i] && n < game->nb_door)
	{
		if (game->map[i] == 'P')
		{
			game->door[n].pos = find_pos(game->map, i);
			game->door[n].life = 1;
			n++;
		}
		i++;
	}
}
