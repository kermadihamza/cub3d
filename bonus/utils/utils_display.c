/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:10:12 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/17 16:26:04 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	minimap_background(t_game *game)
{
	int	i;
	int	j;

	i = 7;
	while (i < MINI_W + MINI_SIDE * 2 + 4)
	{
		j = 7;
		while (j < MINI_H + MINI_SIDE * 2 + 4)
		{
			if (j < MINI_SIDE || j > MINI_H + MINI_SIDE * 2
				|| i < MINI_SIDE || i > MINI_W + MINI_SIDE * 2)
				ft_mlx_pixel_put(&game->img, i, j, BLACK);
			else
				ft_mlx_pixel_put(&game->img, i, j, WHITE);
			j++;
		}	
		i++;
	}
}

void	little_square(t_game *game, int color, t_pos pos)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			if (pos.x + i < MINI_W + MINI_SIDE && pos.x + i > MINI_SIDE * 2
				&& pos.y + j > MINI_SIDE * 2 && pos.y + j < MINI_H + MINI_SIDE)
				ft_mlx_pixel_put(&game->img, pos.x + i, pos.y + j, color);
			j++;
		}	
		i++;
	}
}

void	ft_draw_line(t_game *game, double angle, t_pos pos, int len)
{
	double	bx;
	double	by;
	double	d;
	double	pente;

	bx = cos(angle);
	by = sin(angle);
	d = 0;
	if (bx < 0.05 && bx > -0.05)
		bx = 0.05;
	pente = by / bx;
	while (hypot(d * pente, d) <= len)
	{
		ft_mlx_pixel_put(&game->img, pos.x + d + 5,
			pos.y - (d * pente) + 5, BLACK);
		if (bx < 0)
			d -= 0.025;
		else
			d += 0.025;
	}
}
