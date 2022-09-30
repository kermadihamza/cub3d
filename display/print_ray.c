/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ray.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lrondia <lrondia@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:36:54 by lrondia           #+#    #+#             */
/*   Updated: 2022/09/30 18:45:49 by lrondia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calcul_px(t_ray *ray)
{
	double	res;
	double	percent_pos;
	double	percent_neg;

	percent_pos = ray->ray_len * 10;
	percent_neg = (100 - percent_pos);
	percent_neg /= 100;
	res = percent_neg * WIN_H;
	return (res);
}

void	print_ray(t_game *game, t_ray *ray)
{
	double	y;

	y = 0;
	while (y < WIN_H)
	{
		if (ray->ray_len == -1)
			break ;
		else if (y >= (WIN_H / 2) - (calcul_px(ray) / 2)
			&& y <= (WIN_H / 2) + (calcul_px(ray) / 2))
		{
			if (ray->hor == 1)
				ft_mlx_pixel_put(&game->img, ray->pos_in_screen, y, 0xffaaaa);
			else
				ft_mlx_pixel_put(&game->img, ray->pos_in_screen, y, 0xffffff);
		}
		y++;
	}
}
