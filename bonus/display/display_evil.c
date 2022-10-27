/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_evil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:54:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/27 19:51:53 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_there_a_wall_ahead(t_game *game, t_evil evil, double small)
{
	double	horizontal;
	double	vertical;
	t_ray	ray;

	ray.door_hor = -1;
	ray.door_vert = -1;
	ray.ra = (game->player.angle - evil.angle_from_player) - small;
	init_ray_values(&ray);
	horizontal = check_wall_hor(game, &ray, game->player.pos);
	vertical = check_wall_vert(game, &ray, game->player.pos);
	if (horizontal < vertical)
		ray.ray_len = horizontal;
	else
		ray.ray_len = vertical;
	if ((small != 0 && ray.ray_len < evil.dist_player_right)
		|| (small == 0 && ray.ray_len < evil.dist_player_left))
		return (1);
	else if ((ray.door_hor < evil.dist_player_left && ray.door_hor != -1)
		|| (ray.door_vert < evil.dist_player_left && ray.door_vert != -1))
		return (1);
	return (0);
}

void	print_evil(t_game *game, t_pos origin, t_evil evil, t_img sprite)
{
	t_pos	pos;
	int		color;
	double	small;
	int		copy;

	pos.y = 0;
	small = game->fov / (WIN_W / evil.scale.x);
	if (is_there_a_wall_ahead(game, evil, small)
		|| is_there_a_wall_ahead(game, evil, 0))
		return ;
	if (evil.life <= 0)
		return ;
	while (pos.y < evil.scale.y && pos.y + origin.y < WIN_H)
	{
		pos.x = 0;
		while (pos.x < evil.scale.x && pos.x + origin.x < WIN_W)
		{
			if (pos.x / 2 == 1)
				color = copy;
			else
				color = get_color(sprite,
					get_pos(pos, evil.scale, sprite));
			copy = color;
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
		if (evil[i].dist_player_left < evil[res].dist_player_left)
			res = i;
		i++;	
	}
	i = 0;
	while (i < game->nb_evil)
	{
		if (evil[i].dist_player_left > evil[res].dist_player_left && prev != -1
			&& evil[i].dist_player_left < evil[prev].dist_player_left)
			res = i;
		else if (evil[i].dist_player_left > evil[res].dist_player_left && prev == -1)
			res = i;
		i++;
	}
	return (res);
}

static int	choose_sprite(t_evil evil)
{
	if (evil.time / SPEED < 4)
		return (evil.time / SPEED);
	else if (evil.time / SPEED == 4)
		return (3);
	else if (evil.time / SPEED == 5)
		return (2);
	else if (evil.time / SPEED == 6)
		return (1);
	else if (evil.time / SPEED == 7 || evil.time / SPEED == 8 || evil.time / SPEED == 15)
		return (0);
	else if (evil.time / SPEED == 9)
		return (4);
	else if (evil.time / SPEED == 10)
		return (5);
	else if (evil.time / SPEED == 11 || evil.time / SPEED == 12)
		return (6);
	else if (evil.time / SPEED == 13)
		return (5);
	else if (evil.time / SPEED == 14)
		return (4);
	else
		return (0);
}

void	evil_time(t_evil *evil)
{
	evil->time++;
	if (evil->time >= 16 * SPEED)
		evil->time = 0;
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
		origin.x = (evil[n].angle_from_player + game->fov / 2) / game->fov * WIN_W;
		origin.y = (WIN_H / 2) - (evil[n].scale.y / 2);
		cs = choose_sprite(evil[0]);
		print_evil(game, origin, evil[n], game->sprite.evil[cs]);
		i++;
	}
}
