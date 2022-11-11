/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_floor_roof.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:51:56 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/08 19:31:28 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display_floor_roof(t_game *game, int start, int end)
{
	int	y;

	while (start < end)
	{
		y = 0;
		while (y < WIN_H / 2)
		{
			ft_mlx_pixel_put(&game->img, start, y + (WIN_H / 2),
				game->color_floor);
			ft_mlx_pixel_put(&game->img, start, y, game->color_roof);
			y++;
		}
		start++;
	}
}
