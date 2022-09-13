/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:51:29 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/13 21:39:09 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int code, t_key *key)
{
	if (code == 0)
		key->a = 1;
	if (code == 1)
		key->s = 1;
	if (code == 13)
		key->w = 1;
	if (code == 2)
		key->d = 1;
	return (0);
}

int	key_release(int code, t_key *key)
{
	printf("key : %d\n", code);
	if (code == 0)
		key->a = 0;
	if (code == 1)
		key->s = 0;
	if (code == 13)
		key->w = 0;
	if (code == 2)
		key->d = 0;
	return (0);
}

void	key_manager(t_game *game, t_key key)
{
	if (key.a == 1)
		game->player.x -= 0.1;
	if (key.s == 1)
		game->player.y += 0.1;
	if (key.w == 1)
		game->player.y -= 0.1;
	if (key.d == 1)
		game->player.x += 0.1;
}

int	display(t_game *game)
{
	key_manager(game, game->key);
	init_mini_map(game);
	return (0);
}
