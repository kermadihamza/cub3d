/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_factory_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:49:20 by hakermad          #+#    #+#             */
/*   Updated: 2022/11/08 19:28:00 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	height_width_loop(t_game *game, t_sprite *sprite)
{
	int	i;

	i = 0;
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

void	init_height_width(t_game *game, t_sprite *sprite)
{
	sprite->w = (sprite->all_sprites.width) / 15;
	sprite->h = (sprite->all_sprites.height) / 5;
	sprite->table.width = sprite->w;
	sprite->table.height = sprite->h;
	sprite->player.width = sprite->w;
	sprite->player.height = sprite->h;
	sprite->damage.width = sprite->w;
	sprite->damage.height = sprite->h;
	height_width_loop(game, sprite);
}
