/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:51:29 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/25 21:54:34 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	display(t_game *game)
{
	sprite_factory(game);
	action(game, &game->ray, game->key);
	raycasting(game, &game->ray, game->player.pos);
	init_mini_map(game);
	display_evil(game, game->evil);
	evil_time(&game->evil[0]);
	if (game->door_f.open)
		door_time(&game->door_f);
	numbers(game);
	display_player(game, game->sprite.player);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
