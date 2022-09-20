/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:11:33 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/20 16:49:40 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	debug(t_game *game)
{
	printf("NO ->%s\n", game->north);
	printf("SO ->%s\n", game->south);
	printf("WE ->%s\n", game->west);
	printf("EA ->%s\n", game->east);
	printf("F ->%s\n", game->floor);
	printf("C ->%s\n", game->roof);
	printf("F color ->%d\n", game->color_floor);
	printf("C color ->%d\n\n", game->color_roof);
	printf("map ->%s\n", game->map);
}

void	debug_img(t_img img)
{
	printf("img ->%p\n", img.img);
	printf("addr ->%s\n", img.addr);
	printf("bpp ->%d\n", img.bpp);
	printf("line_length ->%d\n", img.line_length);
	printf("endian ->%d\n\n", img.endian);
}

void	debug_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		printf("->%s\n", split[i]);
		i++;
	}	
}

void	debug_pos(t_pos pos)
{
	printf("x : %f\n", pos.x);
	printf("y : %f\n", pos.y);
}

void	little_square_2(t_game *game, int color, t_pos pos)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			mlx_pixel_put(game->mlx, game->win,
				pos.x * 10 + i, pos.y * 10 + j, color);
			j++;
		}	
		i++;
	}
}
