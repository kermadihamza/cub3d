/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:09:42 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/20 13:51:10 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_square(t_game *game, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 250)
	{
		j = 0;
		while (j < 150)
		{
			ft_mlx_pixel_put(&game->img, i, j, color);
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
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
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
	while (sqrtf(((d * pente) * (d * pente)) + d * d) <= len)
	{
		ft_mlx_pixel_put(&game->img, pos.x + d, pos.y - (d * pente), 0xFF0000);
		if (bx < 0)
			d -= 0.025;
		else
			d += 0.025;
	}
}

void	init_mini_map(t_game *game)
{
	int		i;
	t_pos	pos;

	i = 0;
	ft_memset(&pos, 0, sizeof (t_pos));
	map_square(game, 0xFFFFFF);
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
	ft_draw_line(game, game->ray.p_angle, pos, 25);
}
