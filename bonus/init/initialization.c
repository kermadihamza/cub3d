/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:54:02 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/18 15:53:36 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialization(t_game *game)
{
	init_player_pos(game, &game->player);
	init_evil_pos(game);
	init_door_pos(game);
	init_color_sprite(game);
	init_height_width(game, &game->sprite);
	sprite_blt(game, &game->sprite, game->sprite.all_sprites);
	game->ray_dist = malloc(sizeof(double) * WIN_W);
	ft_memset(game->ray_dist, 0, sizeof(double) * WIN_W);
	game->door_dist = malloc(sizeof(double) * WIN_W);
}
