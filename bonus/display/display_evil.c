/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_evil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:54:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/13 12:37:25 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_near_player(double player, double other)
{
	double	max;
	double	min;

	max = player + (M_PI / 4);
	min = player - (M_PI / 4);
	return (other >= min && other <= max);
}

int	is_in_screen(double x, double y)
{
	return (x >= 0 && x <= WIN_W && y >= 0 && y <= WIN_H);
}

t_pos	calculate_size_on_screen(t_pos player, t_pos evil)
{
	double	dist_x;
	double	dist_y;
	double	temp;
	t_pos	size;
	
	dist_x = evil.x - player.x;
	dist_y = evil.y - player.y;
	temp = hypot(dist_x, dist_y);
	size.x = WIN_H / temp;
	size.y = WIN_W / temp;
	return (size);
}

double	calculate_posx_on_screen(t_game *game, t_pos player, t_pos evil)
{
	double	dist_x;
	double	dist_y;
	double	angle;
	double	diff;
	double	opp;
	
	dist_x = fabs(evil.x - player.x);
	dist_y = fabs(evil.y - player.y);
	angle = atan(dist_y / dist_x);
	if (game->ray.p_angle <= M_PI)
		diff = (game->ray.p_angle - angle);
	else
		diff = -fabs((2 * M_PI - game->ray.p_angle) + angle);

	printf("angle %f, diff %f\n", angle, diff);

	opp = hypot(dist_x, dist_y) * sin(diff);
	if (diff <= M_PI / 4 && diff >= -(M_PI / 4))
		return ((WIN_W / 2) + (opp * (WIN_W / hypot(dist_x, dist_y))));
	else
		return (-1);
}

double	calculate_posy_on_screen(double	size)
{
	double	y;

	y = (WIN_H / 2) - (size / 2);
	return (y);
}

void	print_evil(t_game *game, t_img sprite, t_pos origin, t_pos size)
{
	int		color;
	int		x;
	int		y;
	t_pos	pos;

	y = 0;
	while (y < sprite.height * (size.y / sprite.height) && y + origin.y < WIN_H && y + origin.y >= 0)
	{
		x = 0;
		while (x < sprite.width  * (size.x / sprite.width) && x + origin.x < WIN_W && x + origin.x >= 0)
		{
			pos.x = x;
			pos.y = y;
			if (pos.x < 4 || pos.y < 4)
				color = RED;
			else
				color = WHITE;
			// color = get_color(sprite, pos);
			// if (color && is_in_screen(pos.x + origin.x, pos.y + origin.y))
				ft_mlx_pixel_put(&game->img, pos.x + origin.x, pos.y + origin.y, color);
			x++;
		}
		y++;
	}
}

void	display_evil(t_game *game, t_pos player, t_pos evil)
{
	t_pos	origin;
	t_pos	size;

	size = calculate_size_on_screen(player, evil);
	origin.x = calculate_posx_on_screen(game, player, evil);
	origin.y = calculate_posy_on_screen(size.y);
	print_evil(game, game->sprite.evil, origin, size);
	printf("origin x %f\n", origin.x);
	printf("origin y %f\n\n", origin.y);
}
