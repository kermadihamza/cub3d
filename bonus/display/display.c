/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:51:29 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/18 17:00:23 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	display(t_game *game)
{
	ft_memset(game->door_dist, 0, sizeof(double) * WIN_W);
	door_time(game, game->door);
	action(game, game->key);
	thread(game, routine_bg);
	thread(game, routine_raycasting);
	minimap(game);
	display_evil(game, game->evil);
	if (game->nb_evil > 0)
		evil_time(&game->evil[0]);
	numbers(game);
	display_player(game, game->sprite.player[game->player.cur_weapon]);
	messages(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
