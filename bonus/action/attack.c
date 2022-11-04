/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 19:55:21 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/04 15:48:28 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_near_evil(t_pos p, t_pos e, int dist)
{
	return (p.x >= e.x - dist && p.x < e.x + dist
		&& p.y >= e.y - dist && p.y < e.y + dist);
}

void	ennemy_kills_us(t_game *game, t_player *p, t_evil *evil)
{
	int	i;

	i = 0;
	while (i < game->nb_evil)
	{
		if (is_near_evil(p->pos, evil[i].pos, 1) && evil[i].life > 0)
		{
			p->life -= 0.1;
			if (p->life <= -3)
				ft_destroy_all(game);
			break ;
		}
		i++;
	}
}

void	we_kill_ennemy(t_game *game, t_player *p, t_evil *evil)
{
	int	i;

	i = 0;
	p->max = 1;
	while (i < game->nb_evil)
	{
		if (is_near_evil(p->pos, evil[i].pos, 2) && evil[i].life >= 0)
		{
			if (p->cur_weapon == 0)
				evil[i].life -= 1;
			else if (p->cur_weapon == 1)
				evil[i].life -= 2;
			else if (p->cur_weapon == 2)
				evil[i].life -= 3;
			else if (p->cur_weapon == 3)
				evil[i].life -= 5;
			game->mess.damage = 1;
			break ;
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
	if (p->attack == 1 && !p->max)
		we_kill_ennemy(game, p, evil);
	p->n_dead = count_dead_evils(game, evil);
	if (p->weapon_max < 3)
	{
		if (p->n_dead > 0 && p->n_dead < 3)
			p->weapon_max = 1;
		else if (p->n_dead >= 3 && p->n_dead < 6)
			p->weapon_max = 2;
		else if (p->n_dead >= 6)
			p->weapon_max = 3;
	}
}
