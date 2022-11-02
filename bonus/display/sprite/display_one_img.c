/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_one_img.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 15:37:27 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/02 14:17:24 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_one_img(t_game *game, double mult, t_img sprite, t_pos origin)
{
	int		color;
	t_pos	pos;

	pos.y = 0;
	while (pos.y < sprite.height * mult && pos.y + origin.y < WIN_H)
	{
		pos.x = 0;
		while (pos.x < sprite.width * mult && pos.x + origin.x < WIN_W)
		{
			color = get_color(sprite, posi(pos.x / mult, pos.y / mult));
			if (color != NOT_PIXEL && color != STILL_NOT_PIXEL
				&& is_in_screen(pos.x, pos.y + origin.y))
			{
				ft_mlx_pixel_put(&game->img, pos.x + origin.x,
					pos.y + origin.y, color);
			}
			pos.x++;
		}
		pos.y++;
	}
}
