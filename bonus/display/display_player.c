/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:46:57 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/20 19:23:44 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_player(t_game *game, t_img sprite)
{
	t_pos	pos;
	t_pos	origin;
	int		color;
	int		mult;

	if (game->key.third_p == 0)
		return ;
	pos.y = 0;
	mult = 10;
	origin = posi(WIN_W / 2 - (sprite.width * mult) / 2, WIN_H - (sprite.height * mult));
	while (pos.y < sprite.height * mult && pos.y + origin.y < WIN_H)
	{
		pos.x = 0;
		while (pos.x < sprite.width * mult && pos.x + origin.x < WIN_W)
		{
			color = get_color(sprite, posi(pos.x / mult, pos.y /mult));
			if (color != NOT_PIXEL && color != STILL_NOT_PIXEL
				&& is_in_screen(pos.x + origin.x, pos.y + origin.y))
				ft_mlx_pixel_put(&game->img,
					pos.x + origin.x, pos.y + origin.y, color);
			pos.x++;
		}
		pos.y++;
	}
}
