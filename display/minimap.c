/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:09:42 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/14 16:15:55 by lrondia          ###   ########.fr       */
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

void	ft_draw_line(t_game *game, double angle)
{
	float	bx;
	float	by;
	float	d;
	float	pente;

	bx = cos(angle);
	by = sin(angle);
	d = 0;
	if (bx < 0.05 && bx > -0.05)
		bx = 0.05;
	pente = by / bx;
	while (sqrtf(((d * pente) * (d * pente)) + d * d) <= 25)
	{
		mlx_pixel_put(game->mlx, game->win, (game->player.x * 10 + 5) - d * pente, (game->player.y * 10 + 5) + d, 0xFF00000);
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
	ft_draw_line(game, game->ray.p_angle + (PI/6));
	ft_draw_line(game, game->ray.p_angle - (PI/6));
}
