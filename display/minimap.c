/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakermad <hakermad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:09:42 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/14 14:20:47 by hakermad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	little_square(t_game *game, int color, t_pos pos)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mlx_pixel_put(game->mlx, game->win, pos.x + i, pos.y + j, color);
			j++;
		}	
		i++;
	}
}

void	init_mini_map(t_game *game)
{
	int		i;
	t_pos	pos;

	i = 0;
	ft_memset(&pos, 0, sizeof (t_pos));
	while (game->map[i])
	{
		if (game->map[i] == '1' && pos.x < 250 && pos.y < 150)
			little_square(game, 0xFFFFFF, pos);
		else if ((game->map[i] == '0' || is_personage(game->map[i]))
			&& pos.x < 250 && pos.y < 150)
			little_square(game, 0x0000FF, pos);
		pos.x += 10;
		if (game->map[i] == '\n')
		{
			pos.x = 0;
			pos.y += 10;
		}
		i++;
	}
	pos.x = game->player.x * 10;
	pos.y = game->player.y * 10;
	little_square(game, 0xFF0000, pos);
}
