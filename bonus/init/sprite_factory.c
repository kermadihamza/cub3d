/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_factory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:32:16 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/24 16:06:03 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_height_width(t_game *game)
{
	int	i;

	i = 0;
	game->sprite.w = (game->sprite.all_sprites.width) / 10;
	game->sprite.h = (game->sprite.all_sprites.height) / 5;
	game->sprite.evil.width = game->sprite.w;
	game->sprite.evil.height = game->sprite.h;
	game->sprite.door.width = game->sprite.w * 2;
	game->sprite.door.height = game->sprite.h;
	game->sprite.player.width = game->sprite.w;
	game->sprite.player.height = game->sprite.h;
	while (i < 10)
	{
		game->sprite.num[i].width = game->sprite.numbers.width / 10;
		game->sprite.num[i].height = game->sprite.numbers.height;
		i++;
	}
}

void	init_color_sprite(t_game *game)
{
	init_color(&game->img, game->color_floor, 'F');
	init_color(&game->img, game->color_roof, 'C');
	init_sprites(game, game->sprite.north.path, &game->sprite.north);
	init_sprites(game, game->sprite.south.path, &game->sprite.south);
	init_sprites(game, game->sprite.east.path, &game->sprite.east);
	init_sprites(game, game->sprite.west.path, &game->sprite.west);
	init_sprites(game, "./sprites/all_sprites.xpm", &game->sprite.all_sprites);
	init_sprites(game, "./sprites/numbers.xpm", &game->sprite.numbers);
}

void	sprite_blt(t_game *game)
{
	int	i;

	i = 0;
	ft_new_image_blt(game, &game->sprite.all_sprites, &game->sprite.door, posi(4, 1));
	ft_new_image_blt(game, &game->sprite.all_sprites, &game->sprite.evil, posi(1, 1));
	ft_new_image_blt(game, &game->sprite.all_sprites, &game->sprite.door, posi(1, 3));
	ft_new_image_blt(game, &game->sprite.all_sprites, &game->sprite.player,
		posi(game->player.cur_weapon, 2));
	while (i < 10)
	{
		ft_new_image_blt(game, &game->sprite.numbers, &game->sprite.num[i], posi(i, 0));
		i++;
	}
}

void	sprite_factory(t_game *game)
{
	init_height_width(game);
	init_color_sprite(game);
	sprite_blt(game);
}
