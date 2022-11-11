/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_pos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 21:02:26 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/08 18:57:16 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player_pos(t_game *game, t_player *p)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (is_personage(game->map[i]))
			p->pos = find_pos(game->map, i);
		i++;
	}
	if (p->dir == 'N')
		p->angle = M_PI / 2 + 0.01;
	else if (p->dir == 'S')
		p->angle = (3 * M_PI) / 2 + 0.01;
	else if (p->dir == 'E')
		p->angle = 0.01;
	else if (p->dir == 'W')
		p->angle = M_PI + 0.01;
	p->adj_x = cos(p->angle) / 5;
	p->adj_y = sin(p->angle) / 5;
	p->weapon_max = 0;
	game->key.third_p = 1;
	p->life = ME_LIFE;
	p->max = 0;
}
