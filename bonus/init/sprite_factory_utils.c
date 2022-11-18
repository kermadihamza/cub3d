/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_factory_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:49:20 by hakermad          #+#    #+#             */
/*   Updated: 2022/11/16 15:39:52 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	h_w(int max, t_img *dest, t_pos src)
{
	int	i;

	i = 0;
	while (i < max)
	{
		dest[i].width = (int)src.x;
		dest[i].height = (int)src.y;
		i++;
	}
}

void	init_height_width(t_game *game, t_sprite *sprite)
{
	sprite->w = (sprite->all_sprites.width) / 15;
	sprite->h = (sprite->all_sprites.height) / 5;
	sprite->table.width = sprite->w;
	sprite->table.height = sprite->h;
	sprite->damage.width = sprite->w;
	sprite->damage.height = sprite->h;
	h_w(3, game->mess.mess_w, posi(sprite->w * 2, sprite->h));
	h_w(4, sprite->player, posi(sprite->w, sprite->h));
	h_w(4, sprite->door, posi(sprite->w * 2, sprite->h));
	h_w(7, sprite->evil, posi(sprite->w, sprite->h));
	h_w(10, sprite->num, posi(sprite->numbers.width / 10,
			sprite->numbers.height));
}
