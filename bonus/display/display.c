/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:51:29 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/08 16:52:51 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	display(t_game *game)
{
	game->ray.pos_in_screen = 0;
	door_time(game, game->door);
	sprite_factory(game);
	action(game, &game->ray, game->key);
	// raycasting(game, &game->ray, 0, WIN_W);
	// thread(game, routine_bg);
	thread(game, routine_raycasting);
	init_mini_map(game);
	display_evil(game, game->evil);
	evil_time(&game->evil[0]);
	numbers(game);
	display_player(game, game->sprite.player);
	messages(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
