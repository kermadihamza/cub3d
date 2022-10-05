/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 20:09:42 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/05 20:22:33 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_square(t_game *game)
{
	int	i;
	int	j;

	i = 7;
	while (i < MINI_W + MINI_SIDE * 2 + 4)
	{
		j = 7;
		while (j < MINI_H + MINI_SIDE * 2 + 4)
		{
			if (j < MINI_SIDE || j > MINI_H + MINI_SIDE * 2 || i < MINI_SIDE || i > MINI_W + MINI_SIDE * 2)
				ft_mlx_pixel_put(&game->img, i, j, PURPLE);
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
		ft_mlx_pixel_put(&game->img, pos.x + d, pos.y - (d * pente), RED);
		if (bx < 0)
			d -= 0.025;
		else
			d += 0.025;
	}
}

int	is_inside_map(t_game *game, int x, int y)
{
	double	max_hor;
	double	max_vert;
	double	dist_x;
	double	dist_y;

	max_hor = MINI_W / 10;
	max_vert = MINI_H / 10;
	dist_x = fabs(game->player.x - x);
	dist_y = fabs(game->player.y - y);
	if (dist_x <= max_hor / 2 && dist_y <= max_vert / 2)
		return (1);
	return (0);
}

t_pos	dist_player_tile(t_game *game, int x, int y)
{
	t_pos	dist;

	dist.x = (MINI_W / 20 - (game->player.x - x)) * 10 + MINI_SIDE;
	dist.y = (MINI_H / 20 - (game->player.y - y)) * 10 + MINI_SIDE;
	return (dist);
}

void	draw_minimap(t_game *game)
{
	int		x;
	int		y;
	t_pos	tile;

	y = 0;
	while (game->s_map[y])
	{
		x = 0;
		while (game->s_map[y][x])
		{
			if (is_inside_map(game, x, y) && game->s_map[y][x] == '1')
			{
				tile = dist_player_tile(game, x, y);
				little_square(game, WHITE, tile);
			}
			else if (is_inside_map(game, x, y) && (game->s_map[y][x] == '0' || is_personage(game->s_map[y][x])))
			{
				tile = dist_player_tile(game, x, y);
				little_square(game, PURPLE, tile);
			}
			x++;
		}
		y++;
	}
}

void	init_mini_map(t_game *game)
{
	t_pos	pos;

	pos.x = MINI_W / 2 - 5 + MINI_SIDE;
	pos.y = MINI_H / 2 - 5 + MINI_SIDE;
	map_square(game);
	draw_minimap(game);
	little_square(game, RED, pos);
	ft_draw_line(game, game->ray.p_angle, pos, 25);
}
