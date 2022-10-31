/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_factory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:32:16 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/31 16:56:17 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_height_width(t_game *game)
{
	int	i;

	i = 0;
	game->sprite.w = (game->sprite.all_sprites.width) / 15;
	game->sprite.h = (game->sprite.all_sprites.height) / 5;
	game->sprite.table.width = game->sprite.w;
	game->sprite.table.height = game->sprite.h;
	game->sprite.player.width = game->sprite.w;
	game->sprite.player.height = game->sprite.h;
	game->sprite.damage.width = game->sprite.w;
	game->sprite.damage.height = game->sprite.h;
	while (i < 3)
	{
		game->mess.mess_w[i].width = game->sprite.w * 2;
		game->mess.mess_w[i].height = game->sprite.h;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		game->sprite.door[i].width = game->sprite.w * 2;
		game->sprite.door[i].height = game->sprite.h;
		i++;
	}
	i = 0;
	while (i < 7)
	{
		game->sprite.evil[i].width = game->sprite.w;
		game->sprite.evil[i].height = game->sprite.h;
		i++;
	}
	i = 0;
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
	ft_new_image_blt(game, &game->sprite.all_sprites, &game->sprite.table, posi(8, 0));
	ft_new_image_blt(game, &game->sprite.all_sprites, &game->sprite.damage, posi(9, 0));
	ft_new_image_blt(game, &game->sprite.all_sprites, &game->sprite.player,
		posi(game->player.cur_weapon, 2));
	while (i < 3)
	{
		ft_new_image_blt(game, &game->sprite.all_sprites, &game->mess.mess_w[i], posi(i, 4));
		i++;
	}
	i = 0;
	while (i < 4)
	{
		ft_new_image_blt(game, &game->sprite.all_sprites, &game->sprite.door[i], posi(i, 3));
		i++;
	}
	i = 0;
	while (i < 7)
	{
		ft_new_image_blt(game, &game->sprite.all_sprites, &game->sprite.evil[i], posi(i, 1));
		i++;
	}
	i = 0;
	while (i < 10)
	{
		ft_new_image_blt(game, &game->sprite.numbers, &game->sprite.num[i], posi(i, 0));
		i++;
	}
}

void	sprite_factory(t_game *game)
{
	// init_color_sprite(game);
	init_color(&game->img, game->color_floor, 'F');
	init_color(&game->img, game->color_roof, 'C');
	init_height_width(game);
	sprite_blt(game);
}
