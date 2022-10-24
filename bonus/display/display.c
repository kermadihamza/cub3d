/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:51:29 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/24 10:57:57 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	display(t_game *game)
{
	sprite_factory(game);
	key_manager(game, &game->ray, game->key);
	raycasting(game, &game->ray, game->player.pos);
	init_mini_map(game);
	display_evil(game, game->evil);
	// display_door(game, game->door);
	numbers(game);
	display_player(game, game->sprite.player);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
