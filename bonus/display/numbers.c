/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 20:33:07 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/21 11:29:09 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_number(t_game *game, t_img *num, int i, t_pos origin)
{
	t_pos	pos;
	int	mult;
	int	color;

	mult = 3;
	if (i >= 10)
	{
		set_number(game, num, i / 10, posi(origin.x - 16 * mult, origin.y));
		set_number(game, num, i % 10, posi(origin.x, origin.y));
	}
	if (i < 10)
	{
		pos.y = 0;
		while (pos.y < num[i].height * mult && pos.y + origin.y < WIN_H)
		{
			pos.x = 0;
			while (pos.x < num[i].width * mult && pos.x + origin.x < WIN_W)
			{
				color = get_color(num[i], posi(pos.x / mult, pos.y /mult));
				if (color != NOT_PIXEL && color != STILL_NOT_PIXEL
					&& is_in_screen(pos.x, pos.y + origin.y))
					ft_mlx_pixel_put(&game->img, pos.x + origin.x, pos.y + origin.y, color);
				pos.x++;
			}
			pos.y++;
		}
	}
}

void	numbers(t_game *game)
{
	set_number(game, game->sprite.num, game->player.n_dead, posi(WIN_W - 150, 50));
}
