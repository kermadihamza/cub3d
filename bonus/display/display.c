/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:51:29 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/26 17:15:26 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	display(t_game *game)
{
	sprite_factory(game);
	action(game, &game->ray, game->key);
	door_time(game, game->door);
	raycasting(game, &game->ray, game->player.pos);
	init_mini_map(game);
	display_evil(game, game->evil);
	evil_time(&game->evil[0]);
	numbers(game);
	display_player(game, game->sprite.player);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
