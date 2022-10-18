/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_evil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 17:54:28 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/18 14:17:25 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_there_a_wall_ahead(t_game *game, t_evil evil, double small)
{
	double	horizontal;
	double	vertical;
	t_ray	ray;
	t_pos	pos;

	pos.x = MINI_W / 2 - 5 + MINI_SIDE;
	pos.y = MINI_H / 2 - 5 + MINI_SIDE;
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
	return (0);
}

void	print_evil(t_game *game, t_pos origin, t_pos size, t_evil evil)
{
	t_pos	pos;
	int		color;
	double	small;

	pos.y = 0;
	small = FOV / (WIN_W / size.x);
	if (is_there_a_wall_ahead(game, evil, small)
		|| is_there_a_wall_ahead(game, evil, 0))
		return ;
	while (pos.y < size.y && pos.y + origin.y < WIN_H)
	{
		pos.x = 0;
		while (pos.x < size.x && pos.x + origin.x < WIN_W)
		{
			color = get_color(game->sprite.evil,
					get_pos(pos, size, game->sprite.evil));
			if (color != NOT_PIXEL && color != STILL_NOT_PIXEL
				&& is_in_screen(pos.x + origin.x, pos.y + origin.y))
				ft_mlx_pixel_put(&game->img,
					pos.x + origin.x, pos.y + origin.y, color);
			pos.x++;
		}
		pos.y++;
	}
}

void	display_evil(t_game *game, t_evil *evil)
{
	int		i;
	t_pos	origin;
	t_pos	size;

	i = 0;
	while (i < game->nb_evil)
	{
		init_evil_values(game, &evil[i]);
		size = calculate_size_on_screen(evil[i], game->sprite.evil);
		origin.x = (evil[i].angle_from_player + FOV / 2) / FOV * WIN_W;
		origin.y = (WIN_H / 2) - (size.y / 2);
		print_evil(game, origin, size, evil[i]);
		i++;
	}
}
