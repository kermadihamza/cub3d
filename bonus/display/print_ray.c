/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:36:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/10/25 14:28:37 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	if_no_sprite(t_game *game, t_ray *ray, double y)
{
	if (ray->hor == 1 && is_north(ray->ra))
		ft_mlx_pixel_put(&game->img, ray->pos_in_screen, y, PINK);
	else if (ray->hor == 1 && !is_north(ray->ra))
		ft_mlx_pixel_put(&game->img, ray->pos_in_screen, y, YELLOW);
	else if (ray->hor == 0 && is_west(ray->ra))
		ft_mlx_pixel_put(&game->img, ray->pos_in_screen, y, WHITE);
	else if (ray->hor == 0 && !is_west(ray->ra))
		ft_mlx_pixel_put(&game->img, ray->pos_in_screen, y, WHITE);
}

void	with_sprite(t_game *game, t_ray *ray, double y)
{
	if (ray->hor == 1 && is_north(ray->ra))
		ft_mlx_pixel_put(&game->img, ray->pos_in_screen, y,
			find_color_in_sprite(ray, y, game->sprite.north));
	else if (ray->hor == 1 && !is_north(ray->ra))
		ft_mlx_pixel_put(&game->img, ray->pos_in_screen, y,
			find_color_in_sprite(ray, y, game->sprite.south));
	else if (ray->hor == 0 && is_west(ray->ra))
		ft_mlx_pixel_put(&game->img, ray->pos_in_screen, y,
			find_color_in_sprite(ray, y, game->sprite.west));
	else if (ray->hor == 0 && !is_west(ray->ra))
		ft_mlx_pixel_put(&game->img, ray->pos_in_screen, y,
			find_color_in_sprite(ray, y, game->sprite.east));
}

void	print_ray(t_game *game, t_ray *ray)
{
	double	y;
	double	rescale;

	y = 0;
	rescale = WIN_H / ray->ray_len;
	while (y < WIN_H)
	{
		if (y >= (WIN_H / 2) - (rescale / 2)
			&& y <= (WIN_H / 2) + (rescale / 2))
				with_sprite(game, ray, y);
		y++;
	}
	if (game->door_f.len_hor != 1000 || game->door_f.len_vert != 1000)
		print_door(game, &game->door_f);
}
