/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:41:55 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/14 16:56:13 by hakermad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_weapon(t_player *p)
{
	if (p->cur_weapon < p->weapon_max)
		p->cur_weapon++;
	else
		p->cur_weapon = 0;
}

void	third_person(t_game *game)
{
	if (game->key.third_p == 0)
		game->fov = M_PI / 1.7;
	else
		game->fov = M_PI / 2;
}

void	action(t_game *game, t_key key)
{
	move(game, &game->player, key);
	third_person(game);
	attack(game, &game->player, game->evil);
	angle_changes(game);
}
