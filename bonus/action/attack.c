/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:55:21 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/25 21:22:07 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ennemy_kills_us(t_game *game, t_player *p, t_evil *evil)
{
	int	i;

	i = 0;
	while (i < game->nb_evil)
	{
		if (p->pos.x >= evil[i].pos.x - 1 && p->pos.x < evil[i].pos.x + 1
			&& p->pos.y >= evil[i].pos.y - 1 && p->pos.y < evil[i].pos.y + 1
			&& evil[i].life > 0)
		{
			p->life -= 0.1;
			if (p->life <= 0)
				exit (EXIT_SUCCESS);
			break;
		}
		i++;
	}
}

void	we_kill_ennemy(t_game *game, t_player *p, t_evil *evil)
{
	int	i;

	i = 0;
	while (i < game->nb_evil)
	{
		if (p->pos.x >= evil[i].pos.x - 2 && p->pos.x < evil[i].pos.x + 2
			&& p->pos.y >= evil[i].pos.y - 2 && p->pos.y < evil[i].pos.y + 2
			&& evil[i].life >= 0)
		{
			evil[i].life -= 1;
			break;
		}
		i++;
	}
}

int	count_dead_evils(t_game *game, t_evil *evil)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (i < game->nb_evil)
	{
		if (evil[i].life <= 0)
			n++;
		i++;
	}
	return (n);
}

void	attack(t_game *game, t_player *p, t_evil *evil)
{
	if (p->attack == 0)
		ennemy_kills_us(game, p, evil);
	if (p->attack == 1)
		we_kill_ennemy(game, p, evil);
		p->n_dead = count_dead_evils(game, evil);
	if (p->weapon_max < 3)
		p->weapon_max = p->n_dead;
}
