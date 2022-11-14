/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:51:29 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/14 17:00:46 by hakermad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	display(t_game *game)
{
	door_time(game, game->door);
	action(game, game->key);
	thread(game, routine_bg);
	thread(game, routine_raycasting);
	minimap(game);
	display_evil(game, game->evil);
	evil_time(&game->evil[0]);
	numbers(game);
	display_player(game, game->sprite.player[game->player.cur_weapon]);
	messages(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
