/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_evil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:54:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/11/21 16:11:18 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	can_move_along(t_game *game, t_pos *pos, t_pos origin, t_evil evil)
{
	int	start;

	start = (int)(pos->x + origin.x);
	while (pos->x + origin.x < 0)
		pos->x++;
	if ((game->ray_dist[start] <= evil.dist_p)
		|| (game->door_dist[start] <= evil.dist_p
			&& game->door_dist[start] > 0))
	{
		pos->x++;
		return (0);
	}
	return (1);
}

void	print_evil(t_game *game, t_pos origin, t_evil evil, t_img sprite)
{
	int		color;
	t_pos	pos;

	pos.y = 0;
	while (pos.y < evil.scale.y && pos.y + origin.y < WIN_H)
	{
		pos.x = 0;
		while (pos.x < evil.scale.x && pos.x + origin.x < WIN_W
			&& pos.y + origin.y > 0)
		{
			if (!can_move_along(game, &pos, origin, evil))
				continue ;
			color = get_color(sprite, get_pos(pos, evil.scale, sprite));
			if (color != NOT_PIXEL && color != STILL_NOT_PIXEL
				&& is_in_screen(pos.x + origin.x, pos.y + origin.y))
				ft_mlx_pixel_put(&game->img,
					pos.x + origin.x, pos.y + origin.y, color);
			pos.x++;
		}
		pos.y++;
	}
}

int	find_farthest_evil(t_game *game, t_evil *evil, int prev)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < game->nb_evil)
	{
		if (evil[i].dist_p < evil[res].dist_p)
			res = i;
		i++;
	}
	i = 0;
	while (i < game->nb_evil)
	{
		if (evil[i].dist_p == evil[res].dist_p)
			evil[i].dist_p += 0.001;
		if (evil[i].dist_p >= evil[res].dist_p && prev != -1
			&& evil[i].dist_p < evil[prev].dist_p)
			res = i;
		else if (evil[i].dist_p > evil[res].dist_p && prev == -1)
			res = i;
		i++;
	}
	return (res);
}

void	display_evil(t_game *game, t_evil *evil)
{
	int		i;
	int		n;
	int		cs;
	t_pos	origin;

	i = 0;
	while (i < game->nb_evil)
	{
		init_evil_values(game, &evil[i]);
		i++;
	}
	i = 0;
	n = -1;
	while (i < game->nb_evil)
	{
		n = find_farthest_evil(game, evil, n);
		origin.x = (evil[n].p_angle + game->fov / 2) / game->fov * WIN_W;
		origin.y = (WIN_H / 2) - (evil[n].scale.y / 2);
		cs = choose_evil_sprite(evil[0].time);
		if (evil[n].life > 0)
			print_evil(game, origin, evil[n], game->sprite.evil[cs]);
		i++;
	}
}
