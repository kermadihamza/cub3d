/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_evil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:54:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/13 19:50:26 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_evil_values(t_game *game, t_img *evil)
{
	t_pos	dist;
	double	cosi = fabs(cos(game->ray.p_angle));
	double	sinu = fabs(sin(game->ray.p_angle));
	
	dist.x = fabs(evil->pos.x - game->player.x);
	dist.y = fabs(evil->pos.y - game->player.y);
	evil->dist_player = hypot(dist.x, dist.y);
	evil->angle_from_player = acos((dist.x * cosi + dist.y * sinu) / (evil->dist_player * hypot(cosi, sinu)));
	while (evil->angle_from_player <= 0)
		evil->angle_from_player += 2 * M_PI;
	while (evil->angle_from_player >= 2 * M_PI)
		evil->angle_from_player -= 2 * M_PI;
	// printf("angle %f\nplayer angle: %f\n\n", evil->angle_from_player, game->ray.p_angle);
}

t_pos	calculate_size_on_screen(t_img *evil)
{
	t_pos	size;
	
	size.x = WIN_H / evil->dist_player;
	size.y = WIN_W / evil->dist_player;
	return (size);
}

double	calculate_x(double p_angle, t_img *evil)
{
	// double	diff;
	double	opp;
	
	(void) p_angle;
	// if (p_angle <= M_PI)
	// 	diff = p_angle - evil->angle_from_player;
	// else
	// 	diff = -fabs((2 * M_PI - p_angle) + evil->angle_from_player);

	opp = evil->dist_player * sin(evil->angle_from_player);
	if (tan(evil->angle_from_player) > tan(p_angle))
		opp = -fabs(opp);
	else
	opp = fabs(opp);
	// printf("opp %f\n", opp);
	return ((WIN_W / 2) + (opp * (WIN_W / evil->dist_player)));
}

void	print_evil(t_game *game, t_img sprite, t_pos origin, t_pos size)
{
	t_pos	pos;
	int		color;

	pos.y = 0;
	while (pos.y < sprite.height * (size.y / sprite.height) && pos.y + origin.y < WIN_H && pos.y + origin.y >= 0)
	{
		pos.x = 0;
		while (pos.x < sprite.width  * (size.x / sprite.width) && pos.x + origin.x < WIN_W && pos.x + origin.x >= 0)
		{
			color = WHITE;
			// color = get_color(sprite, pos);
			// if (color && is_in_screen(pos.x + origin.x, pos.y + origin.y))
				ft_mlx_pixel_put(&game->img, pos.x + origin.x, pos.y + origin.y, color);
			pos.x++;
		}
		pos.y++;
	}
}

void	display_evil(t_game *game, t_img *evil)
{
	t_pos	origin;
	t_pos	size;

	init_evil_values(game, evil);
	size = calculate_size_on_screen(evil);
	origin.x = calculate_x(game->ray.p_angle, evil);
	origin.y = (WIN_H / 2) - (size.y / 2);
	print_evil(game, game->sprite.evil, origin, size);
}
