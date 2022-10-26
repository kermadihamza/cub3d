/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:16:20 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/26 18:50:38 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	open_door(t_game *game, t_door *door, int code)
{
	int	i;

	i = 0;
	while (i < game->nb_door)
	{
		if (door[i].dist_p < 3)
		{
			if (code == 12 && !door[i].open)
				door[i].open = 1;
			else if (code == 12 && door[i].open)
				door[i].open = 0;
		}
		i++;
	}
}

int	key_press(int code, t_game *game)
{
	if (code == 53)
		ft_destroy_all(game);
	if (code == 0)
		game->key.a = 1;
	if (code == 1 || code == 125)
		game->key.s = 1;
	if (code == 13 || code == 126)
		game->key.w = 1;
	if (code == 2)
		game->key.d = 1;
	if (code == 123)
		game->key.turn_l = 1;
	if (code == 124)
		game->key.turn_r = 1;
	if (code == 48 && game->key.third_p == 0)
		game->key.third_p = 1;
	else if (code == 48 && game->key.third_p == 1)
		game->key.third_p = 0;
	if (code == 14)
		handle_weapon(&game->player);
	if (code == 49 && game->player.attack == 0)
		game->player.attack = 1;
	open_door(game, game->door, code);
	// printf("%d\n", code);
	return (0);
}

int	key_release(int code, t_game *game)
{
	if (code == 0)
		game->key.a = 0;
	if (code == 1 || code == 125)
		game->key.s = 0;
	if (code == 13 || code == 126)
		game->key.w = 0;
	if (code == 2)
		game->key.d = 0;
	if (code == 123)
		game->key.turn_l = 0;
	if (code == 124)
		game->key.turn_r = 0;
	if (code == 49 && game->player.attack == 1)
		game->player.attack = 0;
	return (0);
}
