/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_factory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 09:32:16 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/02 17:29:15 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	w_h(int *dst_w, int *dst_h, int src_w, int src_h)
{
	*dst_h = src_h;
	*dst_w = src_w;
}

void	init_height_width(t_game *game, t_sprite *sprite)
{
	int	i;

	i = 0;
	sprite->w = (sprite->all_sprites.width) / 15;
	sprite->h = (sprite->all_sprites.height) / 5;
	sprite->table.width = sprite->w;
	sprite->table.height = sprite->h;
	sprite->player.width = sprite->w;
	sprite->player.height = sprite->h;
	sprite->damage.width = sprite->w;
	sprite->damage.height = sprite->h;
	while (i < 10)
	{
		if (i < 3)
		{
			game->mess.mess_w[i].width = sprite->w * 2;
			game->mess.mess_w[i].height = sprite->h;
		}
		if (i < 4)
		{
			sprite->door[i].width = sprite->w * 2;
			sprite->door[i].height = sprite->h;
		}
		if (i < 7)
		{
			sprite->evil[i].width = sprite->w;
			sprite->evil[i].height = sprite->h;
		}
		sprite->num[i].width = sprite->numbers.width / 10;
		sprite->num[i].height = sprite->numbers.height;
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
	init_sprites(game, "./assets/all_sprites.xpm", &game->sprite.all_sprites);
	init_sprites(game, "./assets/numbers.xpm", &game->sprite.numbers);
	init_sprites(game, "./assets/lose.xpm", &game->sprite.lose);
}

void	sprite_blt(t_game *game, t_sprite *sprite, t_img origin)
{
	int	i;

	ft_new_image_blt(game, &origin, &sprite->table, posi(8, 0));
	ft_new_image_blt(game, &origin, &sprite->damage, posi(9, 0));
	ft_new_image_blt(game, &origin, &sprite->player,
		posi(game->player.cur_weapon, 2));
	i = 0;
	while (i < 10)
	{
		if (i < 3)
			ft_new_image_blt(game, &origin, &game->mess.mess_w[i], posi(i, 4));
		if (i < 4)
			ft_new_image_blt(game, &origin, &sprite->door[i], posi(i, 3));
		if (i < 7)
			ft_new_image_blt(game, &origin, &sprite->evil[i], posi(i, 1));
		ft_new_image_blt(game, &sprite->numbers, &sprite->num[i], posi(i, 0));
		i++;
	}
}

void	sprite_factory(t_game *game)
{
	init_color(&game->img, game->color_floor, 'F');
	init_color(&game->img, game->color_roof, 'C');
	init_height_width(game, &game->sprite);
	sprite_blt(game, &game->sprite, game->sprite.all_sprites);
}
