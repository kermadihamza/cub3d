/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_evil_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:31:55 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/18 12:29:40 by lrondia          ###   ########.fr       */
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
			n++;
		}
		i++;
	}
}
